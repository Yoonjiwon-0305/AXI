#include "ap_main.h"
#include "xil_printf.h"
#include "../HAL/GPIO/GPIO.h"
#include "../HAL/I2C/I2C.h"
#include "../HAL/TMR/TMR.h"
#include "../driver/FND/FND.h"
#include "intrrupt.h"

#define SLAVE_ADDR 0x12

void ap_init() {
    FND_Init();
    I2C_Init();
    SetupInterruptSystem();

    TMR_SetPSC(TMR0, 100 - 1);
    TMR_SetARR(TMR0, 1000 - 1);
    TMR_StartIntr(TMR0);
    TMR_StartTimer(TMR0);

    xil_printf("I2C Master Application Started.\n\r");
}

void ap_excute() {
    uint8_t sw_val = 0;
    uint8_t rx_data = 0;
    uint8_t prev_sw_val = 0xFF;

    while (1) {
        sw_val = GPIO_ReadPort(GPIOA) & 0xFF;

        if (sw_val != prev_sw_val) {
            if (sw_val & 0x80) {
                xil_printf("READ Mode: Requesting data...\n\r");

                I2C_Start();
                I2C_Write((SLAVE_ADDR << 1) | 1);
                rx_data = I2C_Read(1);
                I2C_Stop();

                FND_SetNum(rx_data);
                xil_printf("Received Data: 0x%02X\n\r", rx_data);

            } else {
                uint8_t data_to_send = sw_val & 0x7F;

                xil_printf("WRITE Mode: Sending 0x%02X\n\r", data_to_send);

                I2C_Start();
                I2C_Write((SLAVE_ADDR << 1) | 0);
                I2C_Write(data_to_send);
                I2C_Stop();

                FND_SetNum(data_to_send);
            }

            prev_sw_val = sw_val;
        }

        for (volatile int i = 0; i < 500000; i++);
    }
}
