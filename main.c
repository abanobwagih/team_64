#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "C:/Keil_v5/EE319Kware/inc/tm4c123gh6pm.h"
void SystemInit() {}

void delay(int x)
{
    int i = 0;
    int j = 0;
    for (i; i < x; i++)
    {
        for (j; j < x; j++)
        {

        }

    }
}

void seven_segment ( int hundreds , int tens , int units)
{
while(1)
{
    GPIO_PORTA_DATA_R &= 0x7F;
    GPIO_PORTA_DATA_R |= 0x60;
    switch (hundreds)
    {
        case 0 : GPIO_PORTB_DATA_R = 0x7E;
        break;
        case 1 : GPIO_PORTB_DATA_R = 0x30;
        break;
        case 2 : GPIO_PORTB_DATA_R = 0x6D;
        break;
        case 3 : GPIO_PORTB_DATA_R = 0x79;
        break;
        case 4 : GPIO_PORTB_DATA_R = 0x33;
        break;
        case 5 : GPIO_PORTB_DATA_R = 0x5B;
        break;
        case 6 : GPIO_PORTB_DATA_R = 0x5F;
        break;
        case 7 : GPIO_PORTB_DATA_R = 0x70;
        break;
        case 8 : GPIO_PORTB_DATA_R = 0x7F;
        break;
        case 9 : GPIO_PORTB_DATA_R = 0x73;
        break;