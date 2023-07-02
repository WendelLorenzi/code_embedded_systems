/*
Desenvolva um código em C para o PIC18F4550 que oscile o LED D0 do PicSimLab
entre ligado ao desligado ao apertar o botão RB0. 
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

void TAREFA1(void);

void main(void) {
    TRISD = 0x00;
    TRISBbits.TRISB0 = 1;
    PORTDbits.RD0 = 0;
    for(;;){
        if(PORTBbits.RB0 == 0) {
            TAREFA1();
        }
        __delay_ms(10);
    }
}
void TAREFA1(void){
    PORTDbits.RD0 =! PORTDbits.RD0;
}