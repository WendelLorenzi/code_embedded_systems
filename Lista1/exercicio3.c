/*
Desenvolva um código em C para o PIC18F4550 que acenda sequencialmente os LEDs
da PORTA D, em forma de anel, alterando o estado a cada 500 ms. 
 *
 */


#include <xc.h>

#pragma config FOSC=HS
#pragma config CPUDIV=OSC1_PLL2
#pragma config IESO = OFF
#pragma config PWRT = ON
#pragma configWDT = OFF
#pragma config BOR = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF
#define _XTAL_FREQ 20000000

void main(void) {
    TRISD = 0x00;
    for(;;){
        for (unsigned char i = 0; i < 8; i++)
        {
           LATD = 1 << i;
            __delay_ms(500);
        }    
    }
}