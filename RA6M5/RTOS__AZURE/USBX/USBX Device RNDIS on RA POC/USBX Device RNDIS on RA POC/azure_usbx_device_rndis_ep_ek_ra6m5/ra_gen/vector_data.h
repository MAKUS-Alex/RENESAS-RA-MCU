/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#ifdef __cplusplus
        extern "C" {
        #endif
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (8)
#endif
/* ISR prototypes */
void ether_eint_isr(void);
void usbfs_interrupt_handler(void);
void usbfs_resume_handler(void);
void usbfs_d0fifo_handler(void);
void usbfs_d1fifo_handler(void);
void usbhs_interrupt_handler(void);
void usbhs_d0fifo_handler(void);
void usbhs_d1fifo_handler(void);

/* Vector table allocations */
#define VECTOR_NUMBER_EDMAC0_EINT ((IRQn_Type) 0) /* EDMAC0 EINT (EDMAC 0 interrupt) */
#define EDMAC0_EINT_IRQn          ((IRQn_Type) 0) /* EDMAC0 EINT (EDMAC 0 interrupt) */
#define VECTOR_NUMBER_USBFS_INT ((IRQn_Type) 1) /* USBFS INT (USBFS interrupt) */
#define USBFS_INT_IRQn          ((IRQn_Type) 1) /* USBFS INT (USBFS interrupt) */
#define VECTOR_NUMBER_USBFS_RESUME ((IRQn_Type) 2) /* USBFS RESUME (USBFS resume interrupt) */
#define USBFS_RESUME_IRQn          ((IRQn_Type) 2) /* USBFS RESUME (USBFS resume interrupt) */
#define VECTOR_NUMBER_USBFS_FIFO_0 ((IRQn_Type) 3) /* USBFS FIFO 0 (DMA transfer request 0) */
#define USBFS_FIFO_0_IRQn          ((IRQn_Type) 3) /* USBFS FIFO 0 (DMA transfer request 0) */
#define VECTOR_NUMBER_USBFS_FIFO_1 ((IRQn_Type) 4) /* USBFS FIFO 1 (DMA transfer request 1) */
#define USBFS_FIFO_1_IRQn          ((IRQn_Type) 4) /* USBFS FIFO 1 (DMA transfer request 1) */
#define VECTOR_NUMBER_USBHS_USB_INT_RESUME ((IRQn_Type) 5) /* USBHS USB INT RESUME (USBHS interrupt) */
#define USBHS_USB_INT_RESUME_IRQn          ((IRQn_Type) 5) /* USBHS USB INT RESUME (USBHS interrupt) */
#define VECTOR_NUMBER_USBHS_FIFO_0 ((IRQn_Type) 6) /* USBHS FIFO 0 (DMA transfer request 0) */
#define USBHS_FIFO_0_IRQn          ((IRQn_Type) 6) /* USBHS FIFO 0 (DMA transfer request 0) */
#define VECTOR_NUMBER_USBHS_FIFO_1 ((IRQn_Type) 7) /* USBHS FIFO 1 (DMA transfer request 1) */
#define USBHS_FIFO_1_IRQn          ((IRQn_Type) 7) /* USBHS FIFO 1 (DMA transfer request 1) */
#ifdef __cplusplus
        }
        #endif
#endif /* VECTOR_DATA_H */
