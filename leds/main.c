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
int main ()
	{
  	init ();
		while(1)
		{
			if( (GPIO_PORTF_DATA_R&0x11) == 0x10) //sw2 pin0
			{ 
				GPIO_PORTF_DATA_R =RED;
			}	
			else if ((GPIO_PORTF_DATA_R&0x11) == 0x01) //sw1 pin4
			{
				GPIO_PORTF_DATA_R =BLUE;
			}
		else if ((GPIO_PORTF_DATA_R&0x11) == 0x00 ) //2 SW
			{
				GPIO_PORTF_DATA_R =GREEN;
			}
				else
				{
					GPIO_PORTF_DATA_R =0;
				}
		}
	}
