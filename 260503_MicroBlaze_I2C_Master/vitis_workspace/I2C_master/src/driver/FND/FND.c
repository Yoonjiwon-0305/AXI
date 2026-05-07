#include "FND.h"

uint16_t fndNumData = 0;
uint8_t fndDpData = 0;

void FND_Init()
{
	GPIO_SetMode(FND_PORT, FND_COM_DIG_1|FND_COM_DIG_2|FND_COM_DIG_3|FND_COM_DIG_4 |
						   SEG_PIN_A|SEG_PIN_B|SEG_PIN_C|SEG_PIN_D|
						   SEG_PIN_E|SEG_PIN_F|SEG_PIN_G|SEG_PIN_DP, OUTPUT);
	FND_DispALLOff();
}

void FND_SetDp(uint8_t digit, uint8_t on_off)
{
	if (digit == FND_DIGIT_1) {
		if (!on_off) fndDpData |= 1<<0;
		else fndDpData &= ~(1<<0);
	}
	else if (digit == FND_DIGIT_10) {
		if (!on_off) fndDpData |= 1<<1;
		else fndDpData &= ~(1<<1);
	}
	else if (digit == FND_DIGIT_100) {
		if (!on_off) fndDpData |= 1<<2;
		else fndDpData &= ~(1<<2);
	}
	else if (digit == FND_DIGIT_1000) {
		if (!on_off) fndDpData |= 1<<3;
		else fndDpData &= ~(1<<3);
	}
}

void FND_DispDP(uint8_t digit)
{
}

void FND_DispDigit()
{
	static uint8_t fndDigState = 0;
	fndDigState = (fndDigState + 1) % 4;

	switch (fndDigState)
	{
	case 0:
		FND_DispDigit_1();
		break;
	case 1:
		FND_DispDigit_10();
		break;
	case 2:
		FND_DispDigit_100();
		break;
	case 3:
		FND_DispDigit_1000();
		break;
	default:
		FND_DispDigit_1();
		break;
	}
}

void FND_DispDigit_1()
{
	uint8_t fndFont[16] = {0xC0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
	uint32_t digitData1 = fndNumData % 10;
	uint32_t segData = fndFont[digitData1];

	if(fndDpData & (1<<0)) segData &= ~SEG_PIN_DP;

	uint32_t outData = (0x0F00 & ~FND_COM_DIG_1) | segData;
	GPIO_WritePort(FND_PORT, outData);
}

void FND_DispDigit_10()
{
	uint8_t fndFont[16] = {0xC0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
	uint32_t digitData10 = (fndNumData / 10) % 10;
	uint32_t segData = fndFont[digitData10];

	if(fndDpData & (1<<1)) segData &= ~SEG_PIN_DP;

	uint32_t outData = (0x0F00 & ~FND_COM_DIG_2) | segData;
	GPIO_WritePort(FND_PORT, outData);
}

void FND_DispDigit_100()
{
	uint8_t fndFont[16] = {0xC0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
	uint32_t digitData100 = (fndNumData / 100) % 10;
	uint32_t segData = fndFont[digitData100];

	if(fndDpData & (1<<2)) segData &= ~SEG_PIN_DP;

	uint32_t outData = (0x0F00 & ~FND_COM_DIG_3) | segData;
	GPIO_WritePort(FND_PORT, outData);
}

void FND_DispDigit_1000()
{
	uint8_t fndFont[16] = {0xC0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
	uint32_t digitData1000 = (fndNumData / 1000) % 10;
	uint32_t segData = fndFont[digitData1000];

	if(fndDpData & (1<<3)) segData &= ~SEG_PIN_DP;

	uint32_t outData = (0x0F00 & ~FND_COM_DIG_4) | segData;
	GPIO_WritePort(FND_PORT, outData);
}

void FND_SetNum(uint16_t num)
{
	fndNumData = num;
}

void FND_DispALLOn()
{
	uint32_t outData = (0x0F00 & ~(FND_COM_DIG_1|FND_COM_DIG_2|FND_COM_DIG_3|FND_COM_DIG_4)) | 0x00;
	GPIO_WritePort(FND_PORT, outData);
}

void FND_DispALLOff()
{
	uint32_t outData = 0x0FFF;
	GPIO_WritePort(FND_PORT, outData);
}
