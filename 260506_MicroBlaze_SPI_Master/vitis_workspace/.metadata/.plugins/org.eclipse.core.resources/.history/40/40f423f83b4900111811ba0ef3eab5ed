#ifndef SRC_HAL_SPI_SPI_H_
#define SRC_HAL_SPI_SPI_H_

#include <stdint.h>
#include "xparameters.h"

// SPI 레지스터 맵
typedef struct {
    uint32_t CTRL;    // 0x00 cpol[2], cpha[1], start[0]
    uint32_t TXDATA;  // 0x04 송신 데이터
    uint32_t RXDATA;  // 0x08 수신 데이터
    uint32_t STATUS;  // 0x0C busy[1], done[0]
} SPI_Typedef_t;

#define SPI_BASE    XPAR_SPI_MASTER_0_S00_AXI_BASEADDR
#define SPI         ((SPI_Typedef_t *)(SPI_BASE))

// CTRL 비트
#define SPI_START   0x01
#define SPI_CPHA    0x02
#define SPI_CPOL    0x04

// STATUS 비트
#define SPI_DONE    0x01
#define SPI_BUSY    0x02

void     SPI_Init(void);
void     SPI_Transfer(uint8_t data);
uint8_t  SPI_GetRxData(void);

#endif /* SRC_HAL_SPI_SPI_H_ */
