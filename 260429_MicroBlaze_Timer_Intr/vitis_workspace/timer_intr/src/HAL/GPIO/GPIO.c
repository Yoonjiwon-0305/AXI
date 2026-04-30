/*
 역할 : 레지스터 직접 제어
 명령 받는 곳 : 없음 (최하위 sw)
 명령 주는 곳 : HW 레지스터
 */
#include "GPIO.h"

// CR 레지스터 제어 (방향 설정)
void GPIO_SetMode(GPIO_Typedef_t *GPIOx, uint32_t GPIO_Pin,int GPIO_Dir)
{
	if(GPIO_Dir == OUTPUT ){
		GPIOx -> CR |= GPIO_Pin; //OUTPUT → 해당 비트 1
	} else {
		GPIOx -> CR &= ~(GPIO_Pin); // INPUT → 해당 비트 0
	}
}

// ODR 레지스터 제어 (핀 출력)
void GPIO_WritePin(GPIO_Typedef_t *GPIOx, uint32_t GPIO_Pin,int level){
	if(level == SET) {
		GPIOx -> ODR |= GPIO_Pin; // SET -> 해당 비트 1 (HIGH)
	}else {
		GPIOx -> ODR &= ~GPIO_Pin; // RESET -> 해당 비트 0 (LOW)
	}
}

// IDR 레지스터 읽기 (핀 입력)
uint32_t GPIO_ReadPin(GPIO_Typedef_t *GPIOx, uint32_t GPIO_Pin){
	return (GPIOx -> IDR & GPIO_Pin) ? 1 : 0;
}

// ODR 전체 쓰기 (포트 출력)
// 8비트 한번에 덮어씀 -> FND 세그먼트 패턴 출력용
void GPIO_WritePort(GPIO_Typedef_t *GPIOx,int data)
{
	GPIOx -> ODR = data;
}

// IDR 전체 읽기 (포트 입력)
// 8개 핀 상태 한번에 반환
uint32_t GPIO_ReadPort(GPIO_Typedef_t *GPIOx){
	return GPIOx -> IDR;
}
