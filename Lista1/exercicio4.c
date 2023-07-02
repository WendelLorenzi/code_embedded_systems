/*
Implemente no microcontrolador PIC18F4550, uma estrutura “SINGLE LOOP”, na qual as
seguintes tarefas devem ser implementadas:
- O led D14 deve permanecer 200ms ligado e 200ms desligado;
- O led D15 deve permanecer 400ms ligado e 400ms desligado;
- O led D16 deve permanecer 300ms ligado e 600ms desligado;
Observação 1: em cada intervalo de tempo só podem ser executadas no máximo 2 tarefas.

Observação 2: os leds D14, D15, D16, D17 e D18 são controlados pelos pinos de I/O RD4, RD3,
RD2, RD1 e RD0 respectivamente. Nível lógico 1 apaga os leds e nível lógico 0 acende os
mesmos.
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
        LED_D16 = 0;
        __delay_ms(200);
        LED_D14 = 0;
        __delay_ms(100);
         LED_D16 = 1;
        __delay_ms(100);
         LED_D15 = 0;
        __delay_ms(200);
    }
}