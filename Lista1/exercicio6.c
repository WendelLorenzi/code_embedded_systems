/*
Implemente no microcontrolador PIC18F4550, por meio do software PICSimLab, uma
estrutura “SINGLE LOOP” ou “SISTEMA CONTROLADO POR INTERRUPÇÕES” com as
seguintes tarefas:
- O motor DC deve ser acionado por um PWM com frequência de 5Hz e DC = 50%; (ou seja,
100ms em sinal alto e 100ms em sinal baixo)
- O motor de passo deve alterar sua posição a cada 200ms;
- O led D0 deve permanecer 600ms ligado e 1200ms desligado;
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
void TAREFA2(void);
void TAREFA3(void);
int motor=0;
int aux2=0;
void main (void){
 TRISD = 0x00; //Port D como saída
 TRISC = 0x00; //Port C como saída
 TRISA = 0x00; //PORT A como saída
 PORTA = 0x00; //PORT A começa zerado (MOTOR DE PASSO)
 PORTDbits.RD0 = 0; //RD0 começa desligado (LED DE KEEP-ALIVE)
 PORTCbits.RC0 = 0; //RC0 começa desligado (MOTOR DC)
 for(;;){
 TAREFA1();
 TAREFA2();
 TAREFA3();
 __delay_ms(100);
 }
}

void TAREFA1(void){
 PORTCbits.RC0=!PORTCbits.RC0;
}

void TAREFA2(void){
 motor++;
 if(motor==2) PORTA=0b00000001;
 else if(motor==4) PORTA=0b00000010;
 else if(motor==6) PORTA=0b00000100;
 else if(motor==8){
 PORTA = 0b00001000;
 motor = 0;
 }
}

void TAREFA3(void){
 if(aux2==6) PORTDbits.RD0 = 0;
 else if (aux2==18){
 aux2=0;
 PORTDbits.RD0 = 1;
 }
 aux2++;
}