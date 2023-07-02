/*
Utilizando como base o exercício anterior, altere o código para que:
- O led D14 deve permanecer 300ms ligado e 300ms desligado;
- O led D15 deve permanecer 550ms ligado e 550ms desligado;
- O led D16 deve permanecer 600ms ligado e 600ms desligado; 
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
#define LED_D14 PORTDbits.RD0
#define LED_D15 PORTDbits.RD1
#define LED_D16 PORTDbits.RD2

void main(void) {
    TRISD = 0x00;
    LED_D14 = 0;
    LED_D15 = 0;
    LED_D16 = 0;
    for(;;){
        LED_D14 = 1;
        LED_D15 = 1;
        LED_D16 = 1;
        __delay_ms(300);
        LED_D14 = 0;
        __delay_ms(250);
         LED_D15 = 0;
         __delay_ms(50);
         LED_D16 = 0;
         __delay_ms(600);
    }
}