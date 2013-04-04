/*
 * CODE I2C- EEPROM 24AA01T (READ AND WRITE OPERATIONS) CREATED BY ARTEKO ELECTRONICS
 *
 */

#include "derivative.h" // Include peripheral declarations 
#include "art_i2c.h"    // Include programm functions

uint8_t config(void);

int main(void)
{
	uint32_t i;
	uint8_t d;

	//Start Hardware configuration
	config(); 

	// Oscillator stabilization delay
	for(i=0;i<=400; i++); 

	//Start I2C Configuration
	i2c1init(); 

	// Write to EEPROM function
	EEPROMWrite(0x7F, 0xAA); //EEPROMWrite(uint8_t address, uint8_t data);

	// Read from EEPROM function
	d = EEPROMRead(0x03);
}

uint8_t config(void)
{
	//Configuration

		//Enables clock gate for ports to enable pin routing 
		SIM_SCGC5 |=   SIM_SCGC5_PORTE_MASK |
		               SIM_SCGC5_PORTD_MASK |
		               SIM_SCGC5_PORTC_MASK |
		               SIM_SCGC5_PORTB_MASK |
		               SIM_SCGC5_PORTA_MASK;  

		// SIM_SOPT1: OSC32KSEL=3
 		// Sets the 32kHz clock to LPO 1kHz. 
		SIM_SOPT1 |= SIM_SOPT1_OSC32KSEL(0x03);   

		// SIM_SOPT2: PLLFLLSEL=0, TPMSRC=1
		// Selects FLL as a clock source for various peripherals and set the TPM clock
		SIM_SOPT2 &= (uint32_t)~(uint32_t)(SIM_SOPT2_PLLFLLSEL_MASK); 
 		SIM_SOPT2 = (uint32_t)((SIM_SOPT2 & (uint32_t)~(uint32_t)(
		               SIM_SOPT2_TPMSRC(0x02)
		              )) | (uint32_t)(
		               SIM_SOPT2_TPMSRC(0x01)
		              )); 

 		// SIM_CLKDIV1: OUTDIV1 (Bit 31-28)=0000,Reserved (Bits 27,-19)=0,OUTDIV4 (Bits 18-16)=000,Reserved (Bits 15-0)=0 
		// Sets the divide values for core/system clock, bush/flash clocks and the clock 4 output
		SIM_CLKDIV1 = 0x00U;

		/* Switch to FEI Mode */

		// MCG_C1: CLKS (Bits 7-6)=01, FRDIV (Bits 5-3)=0, IREFS (Bit 2)=1, IRCLKEN (Bit 1)=1, IREFSTEN (Bit 0)=0 
		//Enables the slow internal reference clock and activates the MCGIRCLK (internal clock)
		MCG_C1 |= (MCG_C1_IREFS_MASK | MCG_C1_IRCLKEN_MASK| MCG_C1_CLKS(1)); 

		// MCG_C2: LOCRE0 (Bit 7)=0, Reserved (Bit 6)=0, RANGE0 ( Bits 5-4)=0, HGO0 (Bit 3)=0, EREFS0 (Bit 2)=0, LP (Bit 1)=0,IRCS (Bit 0)=0 
		// Selects low frequency range for the cristal oscillator for low-power operations and slow internal reference clock 
		MCG_C2 = 0x00U; 

		// MCG_C4: DMX32 (Bit 7)=0, DRST_DRS (Bits 6-5)=0
		// Sets DCO maximun frequency and selects DCO range 
		MCG_C4 &= (uint8_t)~(uint8_t)((MCG_C4_DMX32_MASK | MCG_C4_DRST_DRS(0x03)));  
                                                  
		// MCG_C5: Reserved (Bit 7)=0, PLLCLKEN0 (Bit 6)=0, PLLSTEN0 (Bit 5)=0, PRDIV0 (Bits 4-0)=0 
		// Inactivates the PLL clock and sets the PLL external reference divider factor to 1 
		MCG_C5 = 0x00U; 

		// MCG_C6: LOLIE0 (Bit 7)=0,PLLS (Bit 6)=0,CME0 (Bit 5)=0,VDIV0 (Bits 4-0)=0
		// Selects FLL mode, disables external clock monitor for OSC0 and selects the divide factor for the VCO output of the PLL
		MCG_C6 = 0x00U;

		// OSC0_CR: ERCLKEN (bit 7)=1, Reserved (Bit 6)=0, EREFSTEN (Bit 5)=0, Reserved (Bit 4)=0, SC2P (Bit 3)=0, SC4P (Bit 2)=0, SC8P (Bit 1)=0, SC16P (Bit 0)=0
		// Enables external reference clock
		OSC0_CR = OSC_CR_ERCLKEN_MASK; 

		//Check that the source of the FLL reference clock is the internal reference clock
		while((MCG_S & MCG_S_IREFST_MASK) == 0x00U);
		
		// Wait until output of the FLL is selected 
		while((MCG_S & 0x0CU) != 0x00U);

}
