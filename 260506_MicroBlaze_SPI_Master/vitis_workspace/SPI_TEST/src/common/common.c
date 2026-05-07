#include "common.h"

void delay_ms(uint32_t msec) {
    delay_us(msec * 1000);
}

void delay_us(uint32_t usec) {
    volatile uint32_t i;
    for (i = 0; i < usec ; i++);
}
