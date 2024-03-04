/* generated thread header file - do not edit */
#ifndef USB_NETWORK_THREAD_H_
#define USB_NETWORK_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void usb_network_thread_entry(void);
                #else
extern void usb_network_thread_entry(void);
#endif
#include "r_usb_basic.h"
#include "r_usb_basic_api.h"
#include "ux_api.h"
#include "nxd_http_server.h"
FSP_HEADER
/* Basic on USB Instance. */
extern const usb_instance_t g_basic0;

/** Access the USB instance using these structures when calling API functions directly (::p_api is not used). */
extern usb_instance_ctrl_t g_basic0_ctrl;
extern const usb_cfg_t g_basic0_cfg;

#ifndef NULL
void NULL(void*);
#endif

#if 2 == BSP_CFG_RTOS
#ifndef NULL
void NULL(usb_event_info_t *, usb_hdl_t, usb_onoff_t);
#endif
#endif
#define G_HTTP_SERVER0_STACK_SIZE (4096)

void g_http_server0_quick_setup();
FSP_FOOTER
#endif /* USB_NETWORK_THREAD_H_ */
