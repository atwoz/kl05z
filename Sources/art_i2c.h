/***********************************

	HEADER FILE FOR I2C1 (art_i2c.h)

	    BY ARTEKO ELECTRONICS
***********************************/
#ifndef ART_I2C_H
#define ART_I2C_H

uint8_t config(void);
uint8_t i2cinit(void);
void EEPROMWrite(uint8_t addrWrite, uint8_t data);
uint8_t EEPROMRead(uint8_t addrRead);
void i2cWrite(uint8_t i2cdata);
void SendStart(void);
void SendStop(void);

#endif
