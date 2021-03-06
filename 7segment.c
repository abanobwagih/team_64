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
                }
    delay(500);
    GPIO_PORTA_DATA_R &= 0xBF;
    GPIO_PORTA_DATA_R |= 0xA0;
    switch (tens)
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
    }
  delay(500);
    GPIO_PORTA_DATA_R &= 0xDF;
    GPIO_PORTA_DATA_R |= 0xC0;
    switch (units)
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
    }
    delay(500);
}
}

void init()
{
    uint32_t delay;
    SYSCTL_RCGCGPIO_R |= 0x03;
    delay = 1;
    GPIO_PORTA_LOCK_R = 0x4C4F434B;
    GPIO_PORTA_CR_R |= 0xE0;
    GPIO_PORTB_LOCK_R = 0x4C4F434B;
    GPIO_PORTB_CR_R = 0xFF;
    GPIO_PORTB_DIR_R = 0xFF;
    GPIO_PORTB_DEN_R = 0xFF;
    GPIO_PORTA_DIR_R = 0xE0;
    GPIO_PORTA_DEN_R = 0xE0;
    GPIO_PORTB_AMSEL_R = 0;
    GPIO_PORTB_AFSEL_R = 0;
    GPIO_PORTB_PCTL_R = 0;
    GPIO_PORTA_AMSEL_R &= 0x1F;
    GPIO_PORTA_AFSEL_R &= 0x1F;
    GPIO_PORTA_PCTL_R &= 0x1F;
}

int main()
{
    init();
    seven_segment(1,2,3);
}
