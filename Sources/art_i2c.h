/***********************************

	HEADER FILE FOR I2C1 (art_i2c.h)

	    BY ARTEKO ELECTRONICS
***********************************/
#ifndef ART_I2C_H
#define ART_I2C_H
#include "MKL25Z4.h"

	
uint8_t config(void);
uint8_t i2c1init(void);
uint8_t EEPROMWrite(uint8_t addrWrite, uint8_t data);
uint8_t EEPROMRead(uint8_t addrRead, uint8_t *data);
uint8_t i2cWrite(uint8_t i2cdata);
uint8_t SendStart(void);
void SendStop(void);
uint8_t GetACK(void);
uint8_t GetNACK(void);
#endif
