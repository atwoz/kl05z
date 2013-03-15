
#include "derivative.h" /* include peripheral declarations */
#include "MCU_init.h"

int main(void)
{
	init();
	
	int i;   
	
	while(1)
	{
		for(i=0;i<100000;i++);
		Led_Neg(BLUE);
	}
	
	return 0;
}
