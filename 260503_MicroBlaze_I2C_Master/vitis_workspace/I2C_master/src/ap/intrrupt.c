#include "intrrupt.h"

XIntc IntrController;

// 1ms (1kHz) 주기로 실행되어 FND의 4자리를 빠르게 번갈아가며 켜줌
void TMR0_ISR(void *CallbackRef)
{
    // FND.c 에 있는 함수. 호출될 때마다 다음 자릿수(COM)를 켬
    FND_DispDigit();
}

int SetupInterruptSystem()
{
    int status;

    // 1. 인터럽트 컨트롤러 초기화
    status = XIntc_Initialize(&IntrController, INTC_DEV_ID);
    if(status != XST_SUCCESS){
        return XST_FAILURE;
    }

    // 2. TMR0_ISR 함수를 Intc와 연결 (인터럽트 발생 시 TMR0_ISR 실행)
    status = XIntc_Connect(&IntrController, TMR0_INTR_ID,
                           (XInterruptHandler)TMR0_ISR, (void *)0);
    if(status != XST_SUCCESS){
        return XST_FAILURE;
    }

    // 3. Interrupt Controller 시작 (Hardware Mode)
    status = XIntc_Start(&IntrController, XIN_REAL_MODE);
    if(status != XST_SUCCESS){
        return XST_FAILURE;
    }

    // 4. TMR0 인터럽트 채널 활성화
    XIntc_Enable(&IntrController, TMR0_INTR_ID);

    // 5. MicroBlaze 의 Exception 초기화 및 활성화
    Xil_ExceptionInit();
    Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
                                 (Xil_ExceptionHandler)XIntc_InterruptHandler,
                                 &IntrController);
    Xil_ExceptionEnable();

    return XST_SUCCESS;
}
