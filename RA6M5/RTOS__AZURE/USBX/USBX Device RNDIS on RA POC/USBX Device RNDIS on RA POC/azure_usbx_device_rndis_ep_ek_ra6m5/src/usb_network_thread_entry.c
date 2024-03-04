#include "usb_network_thread.h"
#include "common_utils.h"
#include "usbx_prndis_ep.h"
#include "ux_network_driver.h"
#include "ux_device_class_rndis.h"

extern UINT authentication_check(struct NX_HTTP_SERVER_STRUCT *server_ptr, UINT request_type, CHAR *resource, CHAR **name, CHAR **password, CHAR **realm);
extern UINT request_notify(NX_HTTP_SERVER *server_ptr, UINT request_type, CHAR *resource, NX_PACKET *packet_ptr);

extern uint32_t usb_peri_usbx_initialize(uint32_t dcd_io);

extern uint8_t g_device_framework_full_speed[];
extern uint8_t g_device_framework_hi_speed[];
extern uint8_t g_language_id_framework[];
extern uint8_t g_string_framework[];

#define ETHERNET_INTERFACE_DEVICE_IP_ADDRESS        IP_ADDRESS(192,168,1,3)
#define USB_RNDIS_INTERFACE_DEVICE_IP_ADDRESS       IP_ADDRESS(192,168,1,3)

#define ETHERNET_INTERFACE_INDEX                    (0)
#define RNDIS_INTERFACE_INDEX                       (1)

/* Global variables */
UINT usbx_status_callback (ULONG status);

/* IP instance */
NX_IP g_ip;

/* Stack memory for g_ip0. */
uint8_t g_ip_stack_memory[G_IP_TASK_STACK_SIZE] BSP_PLACE_IN_SECTION(".stack.g_ip0") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);

/* ARP cache memory for g_ip0. */
uint8_t g_ip_arp_cache_memory[G_IP_ARP_CACHE_SIZE] BSP_ALIGN_VARIABLE(4);

/* Packet pool instance (If this is a Trustzone part, the memory must be placed in Non-secure memory). */
NX_PACKET_POOL g_packet_pool0;
uint8_t g_packet_pool0_pool_memory[G_PACKET_POOL0_PACKET_NUM * (G_PACKET_POOL0_PACKET_SIZE + sizeof(NX_PACKET))] BSP_ALIGN_VARIABLE(4) ETHER_BUFFER_PLACE_IN_SECTION;

/* HTTP Server instance. */
NX_HTTP_SERVER g_http_server0;

uint8_t g_http_server0_stack_memory[HTTP_SERVER_STACK_SIZE] BSP_PLACE_IN_SECTION(".stack.g_http_server0") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);

FX_MEDIA g_fx_media0;

/* Mempool size of 18k is required for USBX device class pre built libraries
 * and it is valid only if it with default USBX configurations. */
static uint32_t g_ux_pool_memory[MEMPOOL_SIZE / BYTE_SIZE];

static bool b_print_status = false;

static void usb_connection_status_check(void);

/*******************************************************************************************************************//**
 * @brief     Initialization of NetX system.
 * @param[IN] None
 * @retval    None
 **********************************************************************************************************************/
static void nx_common_init0(void)
{
    /* Initialize the NetX system. */
    nx_system_initialize ();
}

/*******************************************************************************************************************//**
 * @brief     Create the packet pool.
 * @param[IN] None
 * @retval    None
 **********************************************************************************************************************/
static void packet_pool_init0(void)
{
    /* Create the packet pool. */
    UINT status = nx_packet_pool_create(&g_packet_pool0,
                                        "g_packet_pool0 Packet Pool",
                                        G_PACKET_POOL0_PACKET_SIZE,
                                        &g_packet_pool0_pool_memory[0],
                                        G_PACKET_POOL0_PACKET_NUM * (G_PACKET_POOL0_PACKET_SIZE + sizeof(NX_PACKET)));
    if(NX_SUCCESS != status)
    {
        app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_packet_pool_create failed."), "nx_packet_pool_create failed.");
        app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }
}

/*******************************************************************************************************************//**
 * @brief     Create the ip instance and enables ARP,UDP,ICMP.
 * @param[IN] None
 * @retval    None
 **********************************************************************************************************************/
static void ip_init0(void)
{
    UINT status = NX_SUCCESS;
    ULONG       actual_status;

    /* Create the ip instance. */
    status = nx_ip_create(&g_ip,
                          "g_ip0 IP Instance",
                          G_IP_ADDRESS,
                          G_IP_SUBNET_MASK,
                          &g_packet_pool0,
                          g_netxduo_ether_0,
                          &g_ip_stack_memory[0],
                          G_IP_TASK_STACK_SIZE,
                          G_IP_TASK_PRIORITY);
    if(NX_SUCCESS != status)
    {
        app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_ip_create failed."), "nx_ip_create failed.");
        app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }

    /* Set the gateway address if it is configured. */
    if (IP_ADDRESS(0, 0, 0, 0) != G_IP_GATEWAY_ADDRESS)
    {
        status = nx_ip_gateway_address_set (&g_ip, G_IP_GATEWAY_ADDRESS);
        if(NX_SUCCESS != status)
        {
            app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_ip_gateway_address_set failed."), "nx_ip_gateway_address_set failed.");
            app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
        }
    }

    /* Enables Address Resolution Protocol (ARP).*/
    status = nx_arp_enable(&g_ip, &g_ip_arp_cache_memory[0], G_IP_ARP_CACHE_SIZE);
    if(NX_SUCCESS != status)
    {
        app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_arp_enable failed."), "nx_arp_enable failed.");
        app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }

    /* Enable tcp.*/
    status = nx_tcp_enable (&g_ip);
    if (NX_SUCCESS != status)
    {
        app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_tcp_enable failed."), "nx_tcp_enable failed.");
        app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }

    /* Enable udp.*/
    status = nx_udp_enable(&g_ip);
    if(NX_SUCCESS != status)
    {
        app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_udp_enable failed."), "nx_udp_enable failed.");
        app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }

    /* Enable icmp.*/
    status = nx_icmp_enable(&g_ip);
    if(NX_SUCCESS != status)
    {
        app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_icmp_enable failed."), "nx_icmp_enable failed.");
        app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }

    /* Check the Ethernet interface link status is active */
    status = nx_ip_status_check(&g_ip, NX_IP_LINK_ENABLED, &actual_status, 2000);
    if (NX_SUCCESS != status)
    {
        PRINT_INFO_STR("Ethernet interface link is off");
    }
    else
    {
        PRINT_INFO_STR("Ethernet interface link is enabled");
    }
}

static void ux_common_init0(void)
{
    UINT status_ux_init;

    /** Initialize the USBX system. */
    status_ux_init = ux_system_initialize(g_ux_pool_memory, MEMPOOL_SIZE, UX_NULL, RESET_VALUE);
    if (UX_SUCCESS != status_ux_init)
    {
        PRINT_ERR_STR("_ux_system_initialize api failed..");
        ERROR_TRAP(status_ux_init);
    }
}

/*******************************************************************************************************************//**
 * @brief     Initialization function that the user can choose to have called automatically during thread entry.
 *            The user can call this function at a later time if desired using the prototype below.
 *            - void http_server_init0(void)
 **********************************************************************************************************************/
static void http_server_init0(void)
{
    UINT g_http_server0_err;
    /* Create HTTP Server. */
    g_http_server0_err = nx_http_server_create (&g_http_server0, "g_http_server0 HTTP Server", &g_ip, &g_fx_media0,
                                                &g_http_server0_stack_memory[0], HTTP_SERVER_STACK_SIZE, &g_packet_pool0,
                                                authentication_check, request_notify);
    if (NX_SUCCESS != g_http_server0_err)
    {
        PRINT_ERR_STR("nx_http_server_create api failed..");
        ERROR_TRAP(g_http_server0_err);
    }
}

/* USB Network Thread entry function */
void usb_network_thread_entry(void)
{
    /* TODO: add your own code here */
    UINT        status;
    ULONG       actual_status;

    /* To check fsp api return status */
    fsp_err_t err = FSP_SUCCESS;

    err = R_IOPORT_PinWrite(&g_ioport_ctrl, LED1, BSP_IO_LEVEL_LOW);
    err = R_IOPORT_PinWrite(&g_ioport_ctrl, LED2, BSP_IO_LEVEL_LOW);
    err = R_IOPORT_PinWrite(&g_ioport_ctrl, LED3, BSP_IO_LEVEL_LOW);

    /* Initialize the RTT Thread.*/
    rtt_thread_init_check();
    /* print the banner and EP info. */
    app_rtt_print_data(RTT_OUTPUT_MESSAGE_BANNER, RESET_VALUE, NULL);

    /* Initialize the NetX system.*/
    nx_common_init0();

    /* Initialize the packet pool.*/
    packet_pool_init0();

    /* create the ip instance.*/
    ip_init0();

    app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_INFO_STR, sizeof("Network Initialization completed successfully."), "NetX Duo Stack Initialization completed successfully.");

    /* Initialize the USBX system.*/
    ux_common_init0();

    /* Initialize the HTTP server.*/
    http_server_init0();

    /* Initialize the RNDIS parameters */
    UX_SLAVE_CLASS_RNDIS_PARAMETER parameter;

    /* Set the parameters for callback when insertion/extraction of an RNDIS
    device. Set to NULL.*/
    parameter.ux_slave_class_rndis_instance_activate = UX_NULL;
    parameter.ux_slave_class_rndis_instance_deactivate = UX_NULL;
    /* Define a local NODE ID. */
    parameter.ux_slave_class_rndis_parameter_local_node_id[0] = 0x00;
    parameter.ux_slave_class_rndis_parameter_local_node_id[1] = 0x1e;
    parameter.ux_slave_class_rndis_parameter_local_node_id[2] = 0x58;
    parameter.ux_slave_class_rndis_parameter_local_node_id[3] = 0x41;
    parameter.ux_slave_class_rndis_parameter_local_node_id[4] = 0xb8;
    parameter.ux_slave_class_rndis_parameter_local_node_id[5] = 0x78;
    /* Define a remote NODE ID. */
    parameter.ux_slave_class_rndis_parameter_remote_node_id[0] = 0x00;
    parameter.ux_slave_class_rndis_parameter_remote_node_id[1] = 0x1e;
    parameter.ux_slave_class_rndis_parameter_remote_node_id[2] = 0x58;
    parameter.ux_slave_class_rndis_parameter_remote_node_id[3] = 0x41;
    parameter.ux_slave_class_rndis_parameter_remote_node_id[4] = 0xb8;
    parameter.ux_slave_class_rndis_parameter_remote_node_id[5] = 0x79;

    /* Set extra parameters used by the RNDIS query command with certain
       OIDs. */
    parameter.ux_slave_class_rndis_parameter_vendor_id = 0x045b ;
    parameter.ux_slave_class_rndis_parameter_driver_version = 0x1127;
    ux_utility_memory_copy(parameter.ux_slave_class_rndis_parameter_vendor_description, "ELOGIC RNDIS", 12);

    /* ux_device stack initialization */
    status = ux_device_stack_initialize(g_device_framework_hi_speed,
                                        DEVICE_FRAME_LENGTH_HI_SPEED,
                                        g_device_framework_full_speed,
                                        DEVICE_FRAME_LENGTH_FULL_SPEED,
                                        g_string_framework,
                                        STRING_FRAMEWORK_LENGTH,
                                        g_language_id_framework,
                                        LANGUAGE_ID_FRAME_WORK_LENGTH,
                                        &usbx_status_callback);
    if(UX_SUCCESS != status)
    {
        PRINT_ERR_STR("ux_device_stack_initialize api failed..");
        ERROR_TRAP(status);
    }

    app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_INFO_STR, sizeof("USBX Device Initialization completed successfully."), "USBX Device Initialization completed successfully.");

    /* Initialise the device rndis class. */
    status = ux_device_stack_class_register(_ux_system_slave_class_rndis_name,
                                            _ux_device_class_rndis_entry, 1, 0,
                                            &parameter);
    if(UX_SUCCESS != status)
    {
        PRINT_ERR_STR("ux_device_stack_class_register api failed..");
        ERROR_TRAP(status);
    }

    /* Perform the initialisation of the network driver. This will initialise the USBX network layer.*/
    status = ux_network_driver_init();
    if(UX_SUCCESS != status)
    {
        PRINT_ERR_STR("ux_network_driver_init api failed..");
        ERROR_TRAP(status);
    }

    /* Open usb driver */
    err = R_USB_Open(&g_basic0_ctrl, &g_basic0_cfg);
    /* Error Handle */
    if (FSP_SUCCESS != err)
    {
        PRINT_ERR_STR("R_USB_OPEN api failed..");
        ERROR_TRAP(status);
    }

    PRINT_INFO_STR("USB driver opened successfully!");

    /* Attach the secondary interface to the IP instance, fixed IP address */
    status =  nx_ip_interface_attach(&g_ip, "RNDIS_PORT", USB_RNDIS_INTERFACE_DEVICE_IP_ADDRESS, 0xFFFFFF00UL, _ux_network_driver_entry);
    if (NX_SUCCESS != status)
    {
        PRINT_ERR_STR("nx_ip_interface_attach api failed..");
        ERROR_TRAP(status);
    }

    PRINT_INFO_STR("USB network interface is attached");

    usb_connection_status_check();

    status = nx_ip_interface_status_check(&g_ip, RNDIS_INTERFACE_INDEX, NX_IP_LINK_ENABLED, &actual_status, TX_WAIT_FOREVER);
    if (NX_SUCCESS != status)
    {
        SEGGER_RTT_printf(0, "nx_ip_status_check gets failed\n");
    }

    PRINT_INFO_STR("USB network link is enabled");

    status =  nx_http_server_start(&g_http_server0);
    if (NX_SUCCESS != status)
    {
        PRINT_ERR_STR("nx_http_server_start api failed..");
        ERROR_TRAP(status);
    }

    ULONG reset_code = 0x00000000UL;

    while (1)
    {
        tx_queue_receive(&g_reset_queue, &reset_code, TX_WAIT_FOREVER);
        if (reset_code == 0xF0F0F0F0UL)
        {
            tx_thread_sleep(200);
            NVIC_SystemReset();
        }
    }
}

/*******************************************************************************************************************//**
 * @brief     In this function, usb callback events will be captured into one variable.
 * @param[IN] status    Whenever any event occurred, status gets update
 * @retval    zero
 **********************************************************************************************************************/
UINT usbx_status_callback (ULONG status)
{
    switch (status)
    {
        case UX_DEVICE_ATTACHED:
        {
            tx_event_flags_set(&g_usb_event_flags, USB_CONNECTION_FLAG, TX_OR);
            /* Turn GREEN LED ON */
            R_IOPORT_PinWrite(&g_ioport_ctrl, LED2, BSP_IO_LEVEL_HIGH);
            R_IOPORT_PinWrite(&g_ioport_ctrl, LED3, BSP_IO_LEVEL_LOW);
        }
        break;

        case UX_DEVICE_REMOVED:
        {
            tx_event_flags_set(&g_usb_event_flags, ~USB_CONNECTION_FLAG, TX_AND);
            /* Turn RED LED ON */
            R_IOPORT_PinWrite(&g_ioport_ctrl, LED2, BSP_IO_LEVEL_LOW);
            R_IOPORT_PinWrite(&g_ioport_ctrl, LED3, BSP_IO_LEVEL_HIGH);
        }
        break;

        default:
        {
            /* do nothing */
        }
        break;
    }
    return 0;
}

/*******************************************************************************************************************//**
 * @brief     In this function, checks the USB device status and notifies the user by printing the status message
 * @param[IN] none
 * @retval    none
 **********************************************************************************************************************/
static void usb_connection_status_check(void)
{
    ULONG actual_flags = RESET_VALUE;
    /* wait for usb connection event */
    tx_event_flags_get (&g_usb_event_flags, USB_CONNECTION_FLAG, TX_OR, &actual_flags, TX_WAIT_FOREVER);
    if(actual_flags & USB_CONNECTION_FLAG)
    {

        if (true != b_print_status)
        {
            PRINT_INFO_STR("Status of USB Device is Attached");
            b_print_status = true;    //flag is updated
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        b_print_status = false; //clear the flag
        PRINT_INFO_STR("Status of USB Device is removed");
    }

}

