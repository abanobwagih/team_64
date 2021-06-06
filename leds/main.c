#include"stdint.h"
#include <TM4C123.h>
#include"C:/Keil_v5/EE319Kware/inc/tm4c123gh6pm.h"
#define RED 0x02
#define BLUE 0x04
#define GREEN 0x08
void SystemInit(){}
	void init (void)
		{
		uint32_t delay;
		SYSCTL_RCGCGPIO_R |=0x20;
		delay =1; // dummy var 
		GPIO_PORTF_LOCK_R=0x4C4F434B;
		GPIO_PORTF_CR_R=0x1F;
		GPIO_PORTF_AFSEL_R =0;
		GPIO_PORTF_PCTL_R=0;
		GPIO_PORTF_AMSEL_R=0;
		GPIO_PORTF_DIR_R=0x0E;
		GPIO_PORTF_DEN_R=0x1F;
		GPIO_PORTF_PUR_R=0x11;
	
	}
