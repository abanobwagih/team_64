#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */
#include"stdint.h"
#include <TM4C123.h>
#include"C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#define RED 0x02
void SystemInit(){}
	void init (void)
		{
		uint32_t delay;
		SYSCTL_RCGCGPIO_R |=0x20;
		delay =1; 
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
	double theta ; // central angle
double distance; // the distance between the two coordinates
double Xi,Xf,Yi,Yf,X,Y,M,O;//initial and final coordinates of the target 
double displacement;// shortest distance between the initial and final positions double r=6371;
double r=6378;
   
// the 2 upcoming lines is to get the distance between latitudes and  longitudes 
 
    M=(110*(Xf-Xi)); 
	O=(110*(Yf-Yi));

X = M*M;
Y = O*O;
displacement = X+Y;
theta=acos((2*r*r - displacement)/(2*r*r)); // cos rule
distance=(theta*r);  	

init ();
while (1)
{
 if (distance >= 100) 
 {    
   GPIO_PORTF_DATA_R =RED;
}
else 
{
					GPIO_PORTF_DATA_R =0;

}
     }
     }
