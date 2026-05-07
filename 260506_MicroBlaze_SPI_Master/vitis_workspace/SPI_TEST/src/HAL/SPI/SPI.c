#include "SPI.h"
#include "xil_printf.h"

void SPI_Init(void) {
    // MODE 0 (cpol=0, cpha=0) ¼³Á¤
    SPI->CTRL = 0x00;
}

void SPI_Transfer(uint8_t data) {
    SPI->TXDATA = data;
    SPI->CTRL = SPI_START;  // start=1
    SPI->CTRL = 0;
    // ÂªÀº µô·¹ÀÌ Ãß°¡ (start ÆÞ½º À¯Áö)

    // done ´ë±â
    while((SPI->STATUS & SPI_BUSY));
    xil_printf("TXD F\n");
   	xil_printf("%x\n",SPI->RXDATA);
}

uint8_t SPI_GetRxData(void) {
    return (uint8_t)(SPI->RXDATA);
}
