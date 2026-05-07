#ifndef SRC_HAL_GPIO_GPIO_H_
#define SRC_HAL_GPIO_GPIO_H_

#include <stdint.h>
#include "xparameters.h"

typedef struct {
	uint32_t CR;
	uint32_t IDR;
	uint32_t ODR;
} GPIO_Typedef_t;

// xparameters.h 기준 매크로 이름 수정 반영
#define GPIOA_BASE_ADDR 	XPAR_GPIO_8BIT_0_S00_AXI_BASEADDR // 0x44A00000 (스위치)
#define GPIOB_BASE_ADDR 	XPAR_GPIO_8BIT_1_S00_AXI_BASEADDR // 0x44A10000 (LED)
#define GPIOC_BASE_ADDR 	XPAR_GPIO_0_S00_AXI_BASEADDR      // 0x44A20000 (FND - 이름 변경됨)

#define GPIOA ((GPIO_Typedef_t *) (GPIOA_BASE_ADDR))
#define GPIOB ((GPIO_Typedef_t *) (GPIOB_BASE_ADDR))
#define GPIOC ((GPIO_Typedef_t *) (GPIOC_BASE_ADDR))

#define GPIO_PIN_0	0x001
#define GPIO_PIN_1	0x002
#define GPIO_PIN_2	0x004
#define GPIO_PIN_3	0x008
#define GPIO_PIN_4	0x010
#define GPIO_PIN_5	0x020
#define GPIO_PIN_6	0x040
#define GPIO_PIN_7	0x080
#define GPIO_PIN_8	0x100
#define GPIO_PIN_9	0x200
#define GPIO_PIN_10	0x400
#define GPIO_PIN_11	0x800

#define INPUT   0
#define OUTPUT  1

#define RESET 	0
#define SET		1

void GPIO_SetMode(GPIO_Typedef_t *GPIOx, uint32_t GPIO_Pin, int GPIO_Dir);
void GPIO_WritePin(GPIO_Typedef_t *GPIOx, uint32_t GPIO_Pin, int level);
uint32_t GPIO_ReadPin(GPIO_Typedef_t *GPIOx, uint32_t GPIO_Pin);
void GPIO_WritePort(GPIO_Typedef_t *GPIOx, int data);
uint32_t GPIO_ReadPort(GPIO_Typedef_t *GPIOx);

#endif /* SRC_HAL_GPIO_GPIO_H_ */
