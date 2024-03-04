/*
 * usbx_rndis_ep.h
 *
 *  Created on: Jul 27, 2022
 *      Author: a5123412
 */

#ifndef USBX_PRNDIS_EP_H_
#define USBX_PRNDIS_EP_H_

/******************************************************************************
 Macro definitions
 ******************************************************************************/
/* To display EP info on the RTT viewer */
#define EP_INFO        "\r\nThis project demonstrate how to enable the USBx Device RNDIS running on Renesas RA MCUs based on FSP using AzureRTOS.\r\n"\
                       "By running the application, the RA device will have two network interfaces.\r\n"\
                       "First network interface is over Ethernet connectivity, and the RA end IP address is at 192.168.2.3.\r\n"\
                       "Second network interface is over USB interface, and the RA end IP address is at 192.168.1.3.\r\n"\
                       "User should assign the PC end with the IP address within 192.168.1.x subnet.\r\n"\

#define LINK_ENABLE_WAIT_TIME                   (1000U)

#define MEMPOOL_SIZE                            (65536U)

#define BYTE_SIZE                               (4U)

#define HTTP_SERVER_STACK_SIZE                  (4096U)

#define DEVICE_FRAME_LENGTH_FULL_SPEED          (93U)

#define DEVICE_FRAME_LENGTH_HI_SPEED            (93U)

#define STRING_FRAMEWORK_LENGTH                 (61U)

#define LANGUAGE_ID_FRAME_WORK_LENGTH           (2U)

#define USB_CONNECTION_FLAG                     ((ULONG) 0x0001)
#define USB_NETWORK_ACTIVATE_FLAG               ((ULONG) 0x0004)

#endif /* USBX_PRNDIS_EP_H_ */
