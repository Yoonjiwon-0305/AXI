/*
 * intrrupt.c
 *
 *  Created on: 2026. 4. 29.
 *      Author: kccistc
 */
#include "intrrupt.h"

XIntc IntrController;

// 1khz -> 1msec interrupt serivce routine
void TMR1_ISR(void *CallbackRef)  // 인터럽트가 발생하면 실행되는 함수
{
	millis_inc();
	UpCounter_DispLoop();
}

// 10msec interrupt serivce routine
void TMR2_ISR(void *CallbackRef)  // 인터럽트가 발생하면 실행되는 함수
{
	TimeClock_IncTime();
}

int SetupInterruptSystem()  // 인터럽트 콘트롤러 설정, microBlaze 인터럽트 설정 절차
{
	int status;

	//1. 인터럽트 컨트롤러 초기화
	status = XIntc_Initialize(&IntrController, INTC_DEV_ID);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	//2-1. TMR1_ISR 함수를 Intc와 연결 // (void *) 0 => 받는 매개변수가 없는 null 포인터 , 아무의미없는 주소 및 포인터
	status = XIntc_Connect(&IntrController, TMR1_DEV_ID, (XInterruptHandler)TMR1_ISR, (void *) 0);
	if(status != XST_SUCCESS){
			return XST_FAILURE;
		}
	//2-2. TMR1_ISR 함수를 Intc와 연결
	status = XIntc_Connect(&IntrController, TMR2_DEV_ID, (XInterruptHandler)TMR2_ISR, (void *) 0);
	if(status != XST_SUCCESS){
			return XST_FAILURE;
		}

	//3. Interrupt Controller 시작 (Hardware Mode)
	status = XIntc_Start(&IntrController,XIN_REAL_MODE);
	if(status != XST_SUCCESS){
			return XST_FAILURE;
	}
	//4. 각각의 인터럽트 채널 활성화
	XIntc_Enable(&IntrController, TMR1_DEV_ID);
	XIntc_Enable(&IntrController, TMR2_DEV_ID);

	//5. MicroBlaze 의 Exception 초기화 및 활성화  < 설정  >
	Xil_ExceptionInit();
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
			(Xil_ExceptionHandler)XIntc_InterruptHandler,
			&IntrController);
	Xil_ExceptionEnable();

	return XST_SUCCESS;
}
