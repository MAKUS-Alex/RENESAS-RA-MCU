################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/microsoft/azure-rtos/netxduo/addons/auto_ip/nx_auto_ip.c 

C_DEPS += \
./ra/microsoft/azure-rtos/netxduo/addons/auto_ip/nx_auto_ip.d 

OBJS += \
./ra/microsoft/azure-rtos/netxduo/addons/auto_ip/nx_auto_ip.o 


# Each subdirectory must supply rules for building sources it contributes
ra/microsoft/azure-rtos/netxduo/addons/auto_ip/%.o: ../ra/microsoft/azure-rtos/netxduo/addons/auto_ip/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -DUSB_CFG_PCDC_USE -DADD_USB_RNDIS_MODIFIED -D_RA_CORE=CM4 -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/src" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/src/ux_device_class_rndis_src" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/src/ux_network_driver_src" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/inc" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/inc/api" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/inc/instances" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/src/rm_threadx_port" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/threadx/common/inc" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_gen" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_cfg/fsp_cfg/bsp" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_cfg/fsp_cfg" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_cfg/fsp_cfg/azure/tx" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/src/r_usb_basic/src/driver/inc" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/src/rm_usbx_port" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/inc/ports" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/filex/common/inc" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/src/rm_netxduo_ether" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/pop3" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/snmp" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/nat" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/mqtt" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/ftp" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/tftp" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/sntp" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/smtp" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/web" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/auto_ip" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/telnet" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/dns" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/dhcp" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/http" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/common/inc" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/ports/cortex_m4" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/cloud" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_cfg/fsp_cfg/azure/fx" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_cfg/ra_gen" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_cfg/fsp_cfg/middleware" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_cfg/fsp_cfg/azure/nxd" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/usbx/common/usbx_device_classes/inc" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/usbx/common/core/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

