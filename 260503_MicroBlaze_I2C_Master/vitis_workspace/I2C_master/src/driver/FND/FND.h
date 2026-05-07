#ifndef SRC_DRIVER_FND_FND_H_
#define SRC_DRIVER_FND_FND_H_

#include <stdint.h>
#include "../../HAL/GPIO/GPIO.h"

#define FND_PORT GPIOC

#define FND_COM_DIG_1  GPIO_PIN_8
#define FND_COM_DIG_2  GPIO_PIN_9
#define FND_COM_DIG_3  GPIO_PIN_10
#define FND_COM_DIG_4  GPIO_PIN_11

#define SEG_PIN_A   GPIO_PIN_0
#define SEG_PIN_B   GPIO_PIN_1
#define SEG_PIN_C   GPIO_PIN_2
#define SEG_PIN_D   GPIO_PIN_3
#define SEG_PIN_E   GPIO_PIN_4
#define SEG_PIN_F   GPIO_PIN_5
#define SEG_PIN_G   GPIO_PIN_6
#define SEG_PIN_DP  GPIO_PIN_7

#define ON      0
#define OFF     1

#define FND_DIGIT_1     0x01
#define FND_DIGIT_10    0x02
#define FND_DIGIT_100   0x04
#define FND_DIGIT_1000  0x08

void FND_Init();
void FND_SetDp(uint8_t digit, uint8_t on_off);
void FND_DispDP(uint8_t digit);
void FND_DispDigit();
void FND_DispDigit_1();
void FND_DispDigit_10();
void FND_DispDigit_100();
void FND_DispDigit_1000();
void FND_SetNum(uint16_t num);
void FND_DispALLOn();
void FND_DispALLOff();

#endif
