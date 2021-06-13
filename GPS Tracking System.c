#include "stdint.h"
#include "math.h"
#include"C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "stdlib.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define PI 3.14159265
#define R 6371000

void SystemInit() {}
void readGPSModule();
double Distance;
double Dis;
unsigned char c;
int num[10];
double lat = 0;
double lon = 0;
int flag = 0;
char longitudeIs[20], latitudeIs[20];
char dist[20];

double pastlat = 0;
double pastlon = 0;
// Mili seconds delay function
void delay_ms(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < 3180; j++)
        {
        }
}

// Micro seconds delay function
void delay_us(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < 3; j++)
        {
        }
}


void LCD_command(unsigned char com)
{

    GPIO_PORTA_DATA_R = 0;        //Rs=0 send command, Rw=0 write, E=0 initially enable=0
    delay_ms(1);
    GPIO_PORTA_DATA_R |= 0x40;   // E=1 (low to high) without affecting other pins
    delay_ms(1);
    GPIO_PORTB_DATA_R = com;      // send command to the screen
    delay_us(1);
    GPIO_PORTA_DATA_R = 0;        // E=0 agian
    delay_us(1);

}



void LCD_char(unsigned char data)
{
    GPIO_PORTA_DATA_R = 0x80;        //Rs=1 send data, Rw=0 write,E=0 initially enable=0
    delay_ms(1);
    GPIO_PORTA_DATA_R |= 0x40;      // E=1 (low to high) without affecting other pins
    delay_ms(1);
    GPIO_PORTB_DATA_R = data;        // send data to the screen
    delay_us(1);
    GPIO_PORTA_DATA_R = 0;           //Rs=0 Rw=0 E=0(back to the beginning)
    delay_us(50);
}


void LCD_string(char* str) // to print string (pointer to elements of array of char)
{
    int i;
    for (i = 0; str[i] != 0; i++)  /* Send each char of string  */
    {
        LCD_char(str[i]);  /* Call LCD data write */
        delay_ms(20);
    }
}

void LCD_integers(int data)
{
    int p;
    int k = 0;
    while (data > 0)
    {
        num[k] = data % 10;
        data = data / 10;
        k++;
    }
    k--;
    for (p = k; p >= 0; p--)
    {
        c = num[p] + 48;

        GPIO_PORTA_DATA_R = 0x80;       //Rs=1 send data, Rw=0 write,E=0 initially enable=0
        delay_ms(1);
        GPIO_PORTA_DATA_R |= 0x40;      // E=1 (low to high) without affecting other pins
        delay_ms(1);
        GPIO_PORTB_DATA_R = c;           // send data to the screen
        delay_us(1);
        GPIO_PORTA_DATA_R = 0;           //Rs=0 Rw=0 E=0(back to the beginning)
        delay_us(50);
    }
}


void LCD_separating_double(double deci)
{
    int integer_part = deci;
    int decimal_part = (deci - integer_part) * 100000;

    LCD_integers(integer_part);
    LCD_char('.');
    LCD_integers(decimal_part);
}

