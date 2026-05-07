#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>

// Vivado Address Editor에서 할당된 I2C_0의 Base Address
// (만약 주소가 다르다면 이 값을 변경해주세요)
#define I2C_BASEADDR 0x44A30000

void I2C_Init(void);
void I2C_Start(void);
void I2C_Write(uint8_t data);
uint8_t I2C_Read(uint8_t ack_in);
void I2C_Stop(void);

#endif /* I2C_H_ */
