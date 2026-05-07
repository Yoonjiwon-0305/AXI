/*
 * I2C.c
 *
 *  Created on: 2026. 5. 7.
 *      Author: kccistc
 */


#include "I2C.h"
#include "xil_io.h"
#include "sleep.h" // usleep() 함수 사용을 위해 포함

// 레지스터 오프셋 정의 (하드웨어의 slv_reg0 ~ 3 매핑)
#define I2C_CTRL_REG    0x00
#define I2C_TX_REG      0x04
#define I2C_STATUS_REG  0x08
#define I2C_RX_REG      0x0C

// 제어 비트 정의 (slv_reg0)
#define CMD_START 0x01
#define CMD_WRITE 0x02
#define CMD_READ  0x04
#define CMD_STOP  0x08
#define ACK_IN    0x10

void I2C_Init(void) {
    // 초기화 시 모든 제어 비트를 0으로 초기화
    Xil_Out32(I2C_BASEADDR + I2C_CTRL_REG, 0x00);
}

/* * [중요한 내부 함수] 명령 펄스 생성 및 대기
 * 하드웨어에서 발생시키는 'done' 신호가 1 클럭(10ns) 짜리 짧은 펄스이므로,
 * C 코드의 while 루프(Polling)로 잡기 어려울 수 있습니다.
 * 따라서 I2C 통신 속도(100kHz)에 맞춰 충분한 대기 시간(usleep)을 주는 방식을 사용합니다.
 */
static void I2C_Command(uint32_t cmd, uint32_t wait_us) {
    // 1. 명령 비트 ON
    Xil_Out32(I2C_BASEADDR + I2C_CTRL_REG, cmd);

    // 2. 명령 비트 OFF (Pulse 형태로 하드웨어에 전달)
    Xil_Out32(I2C_BASEADDR + I2C_CTRL_REG, 0x00);

    // 3. 하드웨어가 통신을 마칠 때까지 대기
    usleep(wait_us);
}

void I2C_Start(void) {
    // Start 조건 생성은 1~2 클럭이 소요되므로 20us 대기
    I2C_Command(CMD_START, 20);
}

void I2C_Write(uint8_t data) {
    // 1. TX 레지스터에 보낼 데이터 기록
    Xil_Out32(I2C_BASEADDR + I2C_TX_REG, data);

    // 2. Write 명령 실행 (데이터 8비트 + ACK 1비트 = 총 9비트)
    // 100kHz 속도에서 1비트는 10us 소요 -> 9비트 = 90us. 여유 있게 100us 대기.
    I2C_Command(CMD_WRITE, 100);
}

uint8_t I2C_Read(uint8_t ack_in) {
    uint32_t cmd = CMD_READ;

    // ack_in이 1이면 (마지막 데이터 수신 후) NACK을 전송하여 통신 종료 알림
    if (ack_in) {
        cmd |= ACK_IN;
    }

    // Read 명령 실행 (약 100us 소요)
    I2C_Command(cmd, 100);

    // RX 레지스터에서 수신된 데이터를 읽어서 반환
    return (uint8_t)(Xil_In32(I2C_BASEADDR + I2C_RX_REG) & 0xFF);
}

void I2C_Stop(void) {
    // Stop 조건 생성 대기
    I2C_Command(CMD_STOP, 20);
}
