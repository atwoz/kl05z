/*****************************
    I2C1 Header Functions

	BY ARTEKO ELECTRONICS
 ****************************/

#include "art_i2c.h"
#include "MKL25Z4.h"

uint8_t i2c1init(void)
{

	// I2C initialisation

	 	// SIM_SCGC4: I2C1=1 
	    // Enables I2C1 clock gate
	  	SIM_SCGC4 |= SIM_SCGC4_I2C1_MASK;  

	  	// I2C1_C1: IICEN (Bit 7)=0, IICIE (Bit 6)=0, MST (Bit 5)=0, TX (Bit 4)=0, TXAK (Bit 3)=0, RSTA (Bit 2)=0, WUEN (Bit 1)=0, DMAEN (Bit 0)=0 
	  	// Clears control register 
	  	I2C1_C1 = 0x00U;

	  	// I2C1_FLT: SHEN (Bit 7)=0, STOPF (Bit 6)=1, STOPIE (Bit 5)=0, FLT (Bits 4-0)=0
	  	// Clears bus status interrupt flags 
	  	I2C1_FLT = I2C_FLT_STOPF_MASK;       

	  	// I2C1_S: TCF (Bit 7)=0, IAAS (Bit 6)=0, BUSY (Bit 5)=0, ARBL (Bit 4)=0, RAM (Bit 3)=0, SRW (Bit 2)=0, IICIF (Bit 1)=1, RXAK (Bit 0)=0 
	  	// Clears interrupt flag 
	  	I2C1_S = I2C_S_IICIF_MASK;           


	  	// PORTE_PCR25: ISF=0,MUX=5 
	  	// Sets the E1 pin ready for I2C1 (SCL)
	    PORTE_PCR1 = 	(uint32_t)((PORTE_PCR0 & (uint32_t)~(uint32_t)(
	    				PORT_PCR_ISF_MASK |
						PORT_PCR_MUX(0x02)
					   )) | (uint32_t)(
						PORT_PCR_MUX(0x06)
					   ));          

	    // PORTE_PCR24: ISF=0,MUX=5 
	    // Sets the E0 pin ready for I2C1 (SDA)
	    PORTE_PCR0 = (uint32_t)((PORTE_PCR0 & (uint32_t)~(uint32_t)(
	                   PORT_PCR_ISF_MASK |
	                   PORT_PCR_MUX(0x02)
	                  )) | (uint32_t)(
	                   PORT_PCR_MUX(0x06)
	                  ));                   
	

	  	// I2C1_C2: GCAEN (Bit 7)=0, ADEXT (Bit 6)=0, HDRS (Bit 5)=0, SBRC (Bit 4)=0, RMEN (Bit 3)=0, AD (Bits 2-0)=0
	  	// Sets the 7-bit address extension and disables general call address
	    I2C1_C2 = 0x00U;   

	    // I2C1_FLT: SHEN (Bit 7)=0, STOPF (Bit 6)=0, STOPIE (Bit 5)=0, FLT (Bit 4)=0 
	    // Set glitch filter register 
	    I2C1_FLT = 0x00U;  

	    // I2C1_SMB: FACK (Bit 7)=0, ALERTEN (Bit 6)=0, SIICAEN (Bit 5)=0, TCKSEL (Bit 4)=0, SLTF (Bit 3)=1, SHTF1 (Bit 2)=0, SHTF2 (Bit 1)=0, SHTF2IE (Bit 0)=0 
	    // Clears the SCL Low timeout flag
	    I2C1_SMB = I2C_SMB_SLTF_MASK;

	    // I2C1_F: MULT (Bits 7-6)=0, ICR (Bits 5-0)=0 
	    // Set prescaler bits for mul = 1 and ICR OOh; THIS IS IMPORTANT DUE TO THE NEED OF A REPEATED START ON THE I2C1_SDA LINE. CHECK ERRATA.
	    I2C1_F = 0x00U;                      

	    // Enables I2C1 module operation
	    I2C1_C1 |=(I2C_C1_IICEN_MASK|I2C_C1_TXAK_MASK);

}

uint8_t EEPROMWrite(uint8_t addrWrite, uint8_t data)
{ uint8_t error;
	SendStart(); //Generates Start Signal
	error = i2cWrite(0xA0); //Send Call Address

		if(GetACK()) //If ACK received
		{
			error = i2cWrite(addrWrite); //Send Address destination
			if(GetACK()) //If ACK received
			{
				error = i2cWrite(data); //Send data to write
				if(GetACK()) //if ACK received
				{
					SendStop(); //Generates Stop Signal
				}//end if((I2C1_S & I2C_S_RXAK_MASK) == 0x00)
			}//end if((I2C1_S & I2C_S_RXAK_MASK) == 0x00)
		}//end if((I2C1_S & I2C_S_RXAK_MASK) == 0x00)

		else if(GetNACK()) // Checks if there is a NACK in the SDA-Line
		{
			SendStop(); // If there is a NACK, system sends stop
		}

	return error;
}

uint8_t EEPROMRead(uint8_t addrRead, uint8_t *data)
{
	int i = 0;
	uint8_t error;

	SendStart(); //Generates Start Signal
	error = i2cWrite(0xA0); //Send Call Address

		if(GetACK()) //If ACK received
		{
			error = i2cWrite(addrRead); //Send Address destination
			if(GetACK()) //If ACK received
			{
				I2C1_C1 |= I2C_C1_RSTA_MASK;//Repeat Start Generated
				error = i2cWrite(0xA1); //Send Call Address
				if(GetACK()) //If ACK received
				{								
					I2C1_C1 &= ~(I2C_C1_TX_MASK);  //Disable Transmit
					*data = I2C1_D;

					while(!(I2C1_S & I2C_S_TCF_MASK)) //Waits until transfer is started
					{ 
						i++;

						if(i>4000)
						return 1;
					}

					I2C1_C1 |= I2C_C1_TXAK_MASK; //Generates a Not ACK signal
					SendStop();//generates Stop Signal

				}
			}
		}

		else if(GetNACK()) // Checks if there is a NACK in the SDA-Line
		{
			SendStop(); // If there is a NACK, system sends stop
		}

	return error;	
}

uint8_t i2cWrite(uint8_t i2cdata)
{   
	int i;
	I2C1_D = i2cdata; //Send Write Command to EEPROM (Addr. 1010xxx0)
	while((I2C1_S & I2C_S_TCF_MASK)) //Waits until transfer is started
	{ 
		i++;
		if(i>4000)
		return 1;
	}

	while(!(I2C1_S & I2C_S_TCF_MASK)) //Waits until transfer is started
	{ 
		i++;
		if(i>4000)
		return 1;
	}
	return 0;
}

uint8_t SendStart()
{ 	
	int i;
	while(!(I2C1_S & I2C_S_TCF_MASK)) //Waits until transfer is started
	{ 
		i++;
		if(i>4000)
		return 1;
	}
	
	I2C1_C1 |= I2C_C1_TX_MASK;  //Enable Transmit
	I2C1_C1 |= I2C_C1_MST_MASK; //Enable Master Mode (Send Start Signal)

return 0;
}

void SendStop()
{
	 I2C1_C1 &= ~(I2C_C1_MST_MASK); //Disable Master Mode (Send Stop Signal)
	 I2C1_C1 &= ~(I2C_C1_TX_MASK);  //Disable Transmit
} 

uint8_t GetACK()
{
	return !(I2C1_S & I2C_S_RXAK_MASK); //Checks Acknowledge bit in the Register
}
uint8_t GetNACK()
{
	return (I2C1_S & I2C_S_RXAK_MASK); //Checks Acknowledge bit in the Register
}
