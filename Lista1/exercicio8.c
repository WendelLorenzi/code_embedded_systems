/*
– Para o exercício 7, acrescentar uma quarta tarefa onde o led D17 deve permanecer 350ms
ligado e 350ms desligado; 

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
#define LED_D17 PORTDbits.RD3

void INVERT_D14(void);
void INVERT_D15(void);
void INVERT_D16(void);
void INVERT_D17(void);

void main(void) {
    TRISD = 0x00;
    LED_D14 = 0;
    LED_D15 = 0;
    LED_D16 = 0;
    LED_D17 = 0;
    for(;;){
        LED_D16 = 0;
        __delay_ms(200);
        INVERT_D14();
        __delay_ms(100);
        INVERT_D16();
        __delay_ms(50);
        INVERT_D17();
        __delay_ms(50);
         INVERT_D15();
        __delay_ms(200);
        INVERT_D14();
        INVERT_D15();
        __delay_ms(100);
    }
}

void INVERT_D14(void){
 LED_D14 =! LED_D14;
}

void INVERT_D15(void){
 LED_D15 =! LED_D15;
}

void INVERT_D16(void){
 LED_D16 =! LED_D16;
}

void INVERT_D17(void){
 LED_D17 =! LED_D17;
}