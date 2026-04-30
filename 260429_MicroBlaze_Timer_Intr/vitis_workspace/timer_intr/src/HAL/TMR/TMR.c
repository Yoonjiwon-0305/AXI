/*
 * TMR.c
 *
 *  Created on: 2026. 4. 29.
 *      Author: kccistc
 */
#include "TMR.h"

uint32_t TMR_GetCNT(TMR_typedef_t *TMRx)
{
	return TMRx ->CNT;
}
void TMR_SetPSC (TMR_typedef_t *TMRx, uint32_t psc)
{
	TMRx->PSC = psc;
}

void TMR_SetARR (TMR_typedef_t *TMRx,uint32_t arr)
{
	TMRx->ARR = arr;
}

void TMR_StartIntr(TMR_typedef_t *TMRx)
{
	TMRx->CR |= 1<<TMR_INTR_BIT;
}

void TMR_StopIntr(TMR_typedef_t *TMRx)
{
	TMRx->CR &= ~(1<<TMR_INTR_BIT);
}

void TMR_StartTimer(TMR_typedef_t *TMRx)
{
	TMRx->CR |= 1<<TMR_ENABLE_BIT;
}

void TMR_StopTimer(TMR_typedef_t *TMRx)
{
	TMRx->CR &= ~(1<<TMR_ENABLE_BIT);
}

void TMR_ClearTimer(TMR_typedef_t *TMRx)
{
	TMRx->CR |=   1<<TMR_CLEAR_BIT;
	TMRx->CR &= ~(1<<TMR_CLEAR_BIT);
}


