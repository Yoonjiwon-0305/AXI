#include "ap_main.h"
#include "../HAL/GPIO/GPIO.h"
#include "../HAL/SPI/SPI.h"
#include "../driver/Button/Button.h"
#include "../driver/LED/LED.h"
#include "../driver/FND/FND.h"
#include "xil_printf.h"
#include "sleep.h"

hBtn_t hBtnSend;

void ap_init() {
    GPIO_SetMode(GPIOA, 0xFF, INPUT);   // sw
    GPIO_SetMode(GPIOB, 0xFF, INPUT);   // btn
    GPIO_SetMode(GPIOC, 0xFF, OUTPUT);  // fnd 세그먼트
    GPIO_SetMode(GPIOD, 0xFF, OUTPUT);  // led
    GPIO_SetMode(GPIOE, 0xFF, OUTPUT);  // fnd digit ← 추가!


    LED_Init();
    FND_Init();

    Button_Init(&hBtnSend, GPIOB, GPIO_PIN_0);
    SPI_Init();
    // TMR 코드 전부 삭제!
}

void ap_excute() {
    uint8_t sw_val;
    uint16_t rx_val=0;

    while (1) {

        if (Button_GetState(&hBtnSend) == ACT_PUSHED) {
        	xil_printf("BTN S\n");
            sw_val = GPIO_ReadPort(GPIOA);
            SPI_Transfer(sw_val);
            rx_val = SPI_GetRxData();
            xil_printf("SW=%d RX=%d\n", sw_val, rx_val);
            FND_SetNum(rx_val);
        }

        FND_DispDigit();
        usleep(1000);
    }
}
