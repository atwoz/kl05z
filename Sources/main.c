/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */

int config(void);
int i2cinit(void);
void EEPROMWrite(uint8_t addrWrite, uint8_t data);
int EEPROMRead(uint8_t addrRead);
void i2cWrite(uint8_t i2cdata);
void SendStart(void);
void SendStop(void);
int main(void)
{
	int i;
	uint8_t d;
	config(); //Start Hardware configuration
	for(i=0;i<=400; i++);
	i2cinit(); //Start I2C Configuration

//	EEPROMWrite(0x7F, 0xAA); //EEPROMWrite(uint8_t addr, uint8_t data);

	
	d = EEPROMRead(0x03);

}

int config(void)
{
	//Configuration
		SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK |
		               SIM_SCGC5_PORTD_MASK |
		               SIM_SCGC5_PORTC_MASK |
		               SIM_SCGC5_PORTB_MASK |
		               SIM_SCGC5_PORTA_MASK;   /* Enable clock gate for ports to enable pin routing */
		  /* SIM_CLKDIV1: OUTDIV1=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,OUTDIV4=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
		  SIM_CLKDIV1 = 0x00U;                 /* Update system prescalers */
		  /* SIM_SOPT2: PLLFLLSEL=0 */
		  SIM_SOPT2 &= (uint32_t)~(uint32_t)(SIM_SOPT2_PLLFLLSEL_MASK); /* Select FLL as a clock source for various peripherals */
		  /* SIM_SOPT1: OSC32KSEL=3 */
		  SIM_SOPT1 |= SIM_SOPT1_OSC32KSEL(0x03); /* LPO 1kHz oscillator drives 32 kHz clock for various peripherals */
		  /* SIM_SOPT2: TPMSRC=1 */
		  SIM_SOPT2 = (uint32_t)((SIM_SOPT2 & (uint32_t)~(uint32_t)(
		               SIM_SOPT2_TPMSRC(0x02)
		              )) | (uint32_t)(
		               SIM_SOPT2_TPMSRC(0x01)
		              ));                      /* Set the TPM clock */
		  /* Switch to FEI Mode */
		  /* MCG_C1: CLKS=0,FRDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
		  MCG_C1 |= (MCG_C1_IREFS_MASK | MCG_C1_IRCLKEN_MASK|MCG_C1_CLKS(1)); 
//		  MCG_C1 |= (MCG_C1_IREFS_MASK | MCG_C1_IRCLKEN_MASK);
		  /* MCG_C2: LOCRE0=0,??=0,RANGE0=0,HGO0=0,EREFS0=0,LP=0,IRCS=0 */
		  MCG_C2 = 0x00U;                                                   
		  /* MCG_C4: DMX32=0,DRST_DRS=0 */
		  MCG_C4 &= (uint8_t)~(uint8_t)((MCG_C4_DMX32_MASK | MCG_C4_DRST_DRS(0x03)));                                                   
		  /* OSC0_CR: ERCLKEN=1,??=0,EREFSTEN=0,??=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
		  OSC0_CR = OSC_CR_ERCLKEN_MASK;                                                   
		  /* MCG_C5: ??=0,PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=0 */
		  MCG_C5 = 0x00U;                                                   
		  /* MCG_C6: LOLIE0=0,PLLS=0,CME0=0,VDIV0=0 */
		  MCG_C6 = 0x00U;         
		 // MCG_SC = 0x02;
		  while((MCG_S & MCG_S_IREFST_MASK) == 0x00U) { /* Check that the source of the FLL reference clock is the internal reference clock. */
		   }
		   while((MCG_S & 0x0CU) != 0x00U) {    /* Wait until output of the FLL is selected */
		   }
//		  PORTB_PCR19 = 0x00000140; //PIN PTB 19
//		  PORTB_PCR18 = 0x00000140; //PIN PTB 18
//		  GPIOB_PDDR = 0xFFFFFFFF; //PORT B output
//		  GPIOB_PDOR = 0xFFFFFFFF;

}
int i2cinit(void)
{
	 /* SIM_SCGC4: I2C0=1 */
	  SIM_SCGC4 |= SIM_SCGC4_I2C1_MASK;                                                   
	  /* I2C0_C1: IICEN=0,IICIE=0,MST=0,TX=0,TXAK=0,RSTA=0,WUEN=0,DMAEN=0 */
	  I2C1_C1 = 0x00U;                     /* Clear control register */
	  /* I2C0_FLT: SHEN=0,STOPF=1,STOPIE=0,FLT=0 */
	  I2C1_FLT = I2C_FLT_STOPF_MASK;       /* Clear bus status interrupt flags */
	  /* I2C0_S: TCF=0,IAAS=0,BUSY=0,ARBL=0,RAM=0,SRW=0,IICIF=1,RXAK=0 */
	  I2C1_S = I2C_S_IICIF_MASK;           /* Clear interrupt flag */
//	 PORTE_PCR0 &= ~(PORT_PCR_MUX_MASK);
//	 PORTE_PCR0 |= (PORT_PCR_MUX(6));
//	 
//	 PORTE_PCR1 &= ~(PORT_PCR_MUX_MASK);
//	 PORTE_PCR1 |= (PORT_PCR_MUX(6));
	  
	  /* PORTE_PCR25: ISF=0,MUX=5 */
	    PORTE_PCR1 = (uint32_t)((PORTE_PCR1 & (uint32_t)~(uint32_t)(
	                   PORT_PCR_ISF_MASK |
	                   PORT_PCR_MUX(0x02)
	                  )) | (uint32_t)(
	                   PORT_PCR_MUX(0x06)
	                  ));                                                  
	    /* PORTE_PCR24: ISF=0,MUX=5 */
	    PORTE_PCR0 = (uint32_t)((PORTE_PCR0 & (uint32_t)~(uint32_t)(
	                   PORT_PCR_ISF_MASK |
	                   PORT_PCR_MUX(0x02)
	                  )) | (uint32_t)(
	                   PORT_PCR_MUX(0x06)
	                  ));                   
//	

	  
	  /* I2C0_C2: GCAEN=0,ADEXT=0,HDRS=0,SBRC=0,RMEN=0,AD=0 */
	    I2C1_C2 = 0x00U;                                                   
	    /* I2C0_FLT: SHEN=0,STOPF=0,STOPIE=0,FLT=0 */
	    I2C1_FLT = 0x00U;                    /* Set glitch filter register */
	    /* I2C0_SMB: FACK=0,ALERTEN=0,SIICAEN=0,TCKSEL=0,SLTF=1,SHTF1=0,SHTF2=0,SHTF2IE=0 */
	    I2C1_SMB = I2C_SMB_SLTF_MASK;                                                   
	    /* I2C0_F: MULT=0,ICR=0 */
	    I2C1_F = 0x00U;                      /* Set prescaler bits */
	    
	    I2C1_C1 |=(I2C_C1_IICEN_MASK|I2C_C1_TXAK_MASK);
	    
}
void EEPROMWrite(uint8_t addrWrite, uint8_t data)
{
		SendStart(); //Generates Start Signal
		i2cWrite(0xA0); //Send Call Address

			if((I2C1_S & I2C_S_RXAK_MASK) == 0x00) //If ACK received
			  {
				i2cWrite(addrWrite); //Send Address destination
		
				if((I2C1_S & I2C_S_RXAK_MASK) == 0x00) //If ACK received
					 {
					  i2cWrite(data); //Send data to write
						  
						  if((I2C1_S & I2C_S_RXAK_MASK) == 0x00) //if ACK received
							  {
								  SendStop(); //Generates Stop Signal
							  }//end if((I2C1_S & I2C_S_RXAK_MASK) == 0x00)
					 }//end if((I2C1_S & I2C_S_RXAK_MASK) == 0x00)
			  }//end if((I2C1_S & I2C_S_RXAK_MASK) == 0x00)
}
int EEPROMRead(uint8_t addrRead){
	int i;
	uint8_t d;
		SendStart(); //Generates Start Signal
		i2cWrite(0xA0); //Send Call Address
			if((I2C1_S & I2C_S_RXAK_MASK) == 0x00) //If ACK received
				 {
					i2cWrite(addrRead); //Send Address destination
					if((I2C1_S & I2C_S_RXAK_MASK) == 0x00) //If ACK received
						 {
							I2C1_C1 |= I2C_C1_RSTA_MASK;//Repeat Start Generated
							i2cWrite(0xA1); //Send Call Address
							if((I2C1_S & I2C_S_RXAK_MASK) == 0x00) //If ACK received
								 {
//									
									I2C1_C1 &= ~(I2C_C1_TX_MASK);  //Disable Transmit
									d = I2C1_D;
									while(!(I2C1_S & I2C_S_TCF_MASK)); //Waits until transfer is finished
												
									I2C1_C1 |= I2C_C1_TXAK_MASK;
									SendStop();
									
								 }
						 }
				 }
		return d;	
}

void i2cWrite(uint8_t i2cdata){

	I2C1_D = i2cdata; //Send Write Command to EEPROM (Addr. 1010xxx0)
	while((I2C1_S & I2C_S_TCF_MASK)); //Waits until transfer is finished
	while(!(I2C1_S & I2C_S_TCF_MASK)); //Waits until transfer is finished
}
void SendStart(){
	
	while(!(I2C1_S & I2C_S_TCF_MASK)); //Waits until transfer is finished
	I2C1_C1 |= I2C_C1_TX_MASK;  //Enable Transmit
	I2C1_C1 |= I2C_C1_MST_MASK; //Enable Master Mode (Send Start Signal)
}
void SendStop(){
	
	 I2C1_C1 &= ~(I2C_C1_MST_MASK); //Disable Master Mode (Send Stop Signal)
	 I2C1_C1 &= ~(I2C_C1_TX_MASK);  //Disable Transmit
}
