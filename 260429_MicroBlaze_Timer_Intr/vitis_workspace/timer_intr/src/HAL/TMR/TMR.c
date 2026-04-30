/*
역할 : 타이머 레지스터 직접 제어 (HAL)
명령 받는 곳 : ap_main.c
명령 주는 곳: HW 타이머 레지스터
 */

#include "TMR.h"

//CNT 레지스터 읽기 (현재 카운터 값)
//TMR0 에서 사용 -> 경과 시간 측정용
uint32_t TMR_GetCNT(TMR_typedef_t *TMRx)
{
	return TMRx ->CNT;
}

// PSC 레지스터 쓰기 (분주비 설정)
// 100M / (PSC+1) -> 클럭 속도 조절
void TMR_SetPSC (TMR_typedef_t *TMRx, uint32_t psc)
{
	TMRx->PSC = psc;
}

// ARR 레지스터 쓰기 (카운터 최대값 설정)
// ARR 도달 시 인터럽트 발생 -> 자동 리셋
void TMR_SetARR (TMR_typedef_t *TMRx,uint32_t arr)
{
	TMRx->ARR = arr;
}

// CR 레지스터 intr 비트 1 (인터럽트 ON)
// intr_en = 1 → AND gate 통과 → 인터럽트 발생
void TMR_StartIntr(TMR_typedef_t *TMRx)
{
	TMRx->CR |= 1<<TMR_INTR_BIT;
}

// CR 레지스터 intr 비트 0 (인터럽트 OFF)
// intr_en = 0 → AND gate 차단 → 인터럽트 안발생
void TMR_StopIntr(TMR_typedef_t *TMRx)
{
	TMRx->CR &= ~(1<<TMR_INTR_BIT);
}

// CR 레지스터 cnt_en 비트 1 (카운터 ON)
// cnt_en = 1 → PSC 카운팅 시작
void TMR_StartTimer(TMR_typedef_t *TMRx)
{
	TMRx->CR |= 1<<TMR_ENABLE_BIT;
}

// CR 레지스터 cnt_en 비트 0 (카운터 OFF)
// cnt_en = 0 → PSC 카운팅 정지
void TMR_StopTimer(TMR_typedef_t *TMRx)
{
	TMRx->CR &= ~(1<<TMR_ENABLE_BIT);
}

// CR 레지스터 clear 비트 1→0 (카운터 초기화)
// cnt_clear = 1 → count = 0 → cnt_clear = 0
void TMR_ClearTimer(TMR_typedef_t *TMRx)
{
	TMRx->CR |=   1<<TMR_CLEAR_BIT;
	TMRx->CR &= ~(1<<TMR_CLEAR_BIT);
}


