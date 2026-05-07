/*
 * LED.c
 *
 *  Created on: 2026. 4. 30.
 *      Author: kccistc
 */
#include "LED.h"

static uint8_t ledData = 0;

void LED_Init() {
    GPIO_SetMode(LED_PORT,
        LED_PIN_0|LED_PIN_1|LED_PIN_2|LED_PIN_3|
        LED_PIN_4|LED_PIN_5|LED_PIN_6|LED_PIN_7, OUTPUT);
    ledData = 0;
    GPIO_WritePort(LED_PORT, ledData);
}

void LED_SetPin(uint8_t pin, uint8_t on_off) {
    if (on_off == LED_ON) ledData |= pin;
    else                  ledData &= ~pin;
    GPIO_WritePort(LED_PORT, ledData);
}

void LED_WritePort(uint8_t data) {
    ledData = (ledData & 0xF0) | (data & 0x0F);
    GPIO_WritePort(LED_PORT, ledData);
}


