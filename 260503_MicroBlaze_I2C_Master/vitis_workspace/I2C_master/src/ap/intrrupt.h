#ifndef SRC_COMMON_INTERRUPT_H_
#define SRC_COMMON_INTERRUPT_H_

#include "xparameters.h"
#include "xintc.h"
#include "xil_exception.h"
#include "../driver/FND/FND.h" // FND 다이나믹 제어(잔상 효과)용

#define INTC_DEV_ID     XPAR_INTC_0_DEVICE_ID
// xparameters.h에서 확인한 TMR_0 인터럽트 ID
#define TMR0_INTR_ID    XPAR_INTC_0_TMR_0_VEC_ID

void TMR0_ISR(void *CallbackRef);
int SetupInterruptSystem();

#endif /* SRC_COMMON_INTERRUPT_H_ */
