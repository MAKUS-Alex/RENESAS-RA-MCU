################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ux_device_class_rndis_src/ux_device_class_rndis_activate.c \
../src/ux_device_class_rndis_src/ux_device_class_rndis_bulkin_thread.c \
../src/ux_device_class_rndis_src/ux_device_class_rndis_bulkout_thread.c \
../src/ux_device_class_rndis_src/ux_device_class_rndis_control_request.c \
../src/ux_device_class_rndis_src/ux_device_class_rndis_deactivate.c \
../src/ux_device_class_rndis_src/ux_device_class_rndis_entry.c \
../src/ux_device_class_rndis_src/ux_device_class_rndis_initialize.c \
../src/ux_device_class_rndis_src/ux_device_class_rndis_interrupt_thread.c \
../src/ux_device_class_rndis_src/ux_device_class_rndis_msg_initialize.c \
../src/ux_device_class_rndis_src/ux_device_class_rndis_msg_keep_alive.c \
../src/ux_device_class_rndis_src/ux_device_class_rndis_msg_query.c \
../src/ux_device_class_rndis_src/ux_device_class_rndis_msg_reset.c \
../src/ux_device_class_rndis_src/ux_device_class_rndis_msg_set.c \
../src/ux_device_class_rndis_src/ux_device_class_rndis_write.c 

C_DEPS += \
./src/ux_device_class_rndis_src/ux_device_class_rndis_activate.d \
./src/ux_device_class_rndis_src/ux_device_class_rndis_bulkin_thread.d \
./src/ux_device_class_rndis_src/ux_device_class_rndis_bulkout_thread.d \
./src/ux_device_class_rndis_src/ux_device_class_rndis_control_request.d \
./src/ux_device_class_rndis_src/ux_device_class_rndis_deactivate.d \
./src/ux_device_class_rndis_src/ux_device_class_rndis_entry.d \
./src/ux_device_class_rndis_src/ux_device_class_rndis_initialize.d \
./src/ux_device_class_rndis_src/ux_device_class_rndis_interrupt_thread.d \
./src/ux_device_class_rndis_src/ux_device_class_rndis_msg_initialize.d \
./src/ux_device_class_rndis_src/ux_device_class_rndis_msg_keep_alive.d \
./src/ux_device_class_rndis_src/ux_device_class_rndis_msg_query.d \
./src/ux_device_class_rndis_src/ux_device_class_rndis_msg_reset.d \
./src/ux_device_class_rndis_src/ux_device_class_rndis_msg_set.d \
./src/ux_device_class_rndis_src/ux_device_class_rndis_write.d 

OBJS += \
./src/ux_device_class_rndis_src/ux_device_class_rndis_activate.o \
./src/ux_device_class_rndis_src/ux_device_class_rndis_bulkin_thread.o \
./src/ux_device_class_rndis_src/ux_device_class_rndis_bulkout_thread.o \
./src/ux_device_class_rndis_src/ux_device_class_rndis_control_request.o \
./src/ux_device_class_rndis_src/ux_device_class_rndis_deactivate.o \
./src/ux_device_class_rndis_src/ux_device_class_rndis_entry.o \
./src/ux_device_class_rndis_src/ux_device_class_rndis_initialize.o \
./src/ux_device_class_rndis_src/ux_device_class_rndis_interrupt_thread.o \
./src/ux_device_class_rndis_src/ux_device_class_rndis_msg_initialize.o \
./src/ux_device_class_rndis_src/ux_device_class_rndis_msg_keep_alive.o \
./src/ux_device_class_rndis_src/ux_device_class_rndis_msg_query.o \
./src/ux_device_class_rndis_src/ux_device_class_rndis_msg_reset.o \
./src/ux_device_class_rndis_src/ux_device_class_rndis_msg_set.o \
./src/ux_device_class_rndis_src/ux_device_class_rndis_write.o 


# Each subdirectory must supply rules for building sources it contributes
src/ux_device_class_rndis_src/%.o: ../src/ux_device_class_rndis_src/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -DUSB_CFG_PCDC_USE -DADD_USB_RNDIS_MODIFIED -D_RA_CORE=CM4 -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/src" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/src/ux_device_class_rndis_src" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/src/ux_network_driver_src" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/inc" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/inc/api" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/inc/instances" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/src/rm_threadx_port" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/threadx/common/inc" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_gen" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_cfg/fsp_cfg/bsp" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_cfg/fsp_cfg" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_cfg/fsp_cfg/azure/tx" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/src/r_usb_basic/src/driver/inc" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/src/rm_usbx_port" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/inc/ports" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/filex/common/inc" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/fsp/src/rm_netxduo_ether" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/pop3" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/snmp" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/nat" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/mqtt" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/ftp" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/tftp" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/sntp" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/smtp" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/web" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/auto_ip" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/telnet" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/dns" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/dhcp" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/http" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/common/inc" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/ports/cortex_m4" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/netxduo/addons/cloud" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_cfg/fsp_cfg/azure/fx" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_cfg/ra_gen" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_cfg/fsp_cfg/middleware" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra_cfg/fsp_cfg/azure/nxd" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/usbx/common/usbx_device_classes/inc" -I"C:/Users/alex/e2_studio/workspace/rndis/USBX Device RNDIS on RA POC/USBX Device RNDIS on RA POC/azure_usbx_device_rndis_ep_ek_ra6m5/ra/microsoft/azure-rtos/usbx/common/core/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

