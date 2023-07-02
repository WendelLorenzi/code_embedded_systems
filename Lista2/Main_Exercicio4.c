// Exercicio 4
/*
    Execute no microcontrolador PIC18F4550, por meio do PICSimLab, utilizando o RTOS e a
    fila de mensagens as seguintes tarefas:
    - verificar se o botão INT0 foi pressionado e em seguida liberado, aguardando um task delay de
    (100/portTICK_RATE_MS) entre o apertar e liberar;
    - verificar se o botão INT1 foi pressionado e em seguida liberado, aguardando um task delay de
    (100/portTICK_RATE_MS) entre o apertar e liberar;
    - verificar se o botão INT2 foi pressionado e em seguida liberado, aguardando um task delay de
    (100/portTICK_RATE_MS) entre o apertar e liberar;
    - se o botão INT0 foi pressionado e em seguida liberado, o buzzer deve ser acionado com uma
    frequência de 12,5Hz e DC 50% por 2s. Caso seja o botão INT1, o buzzer deve ser acionado
    com uma frequência de 25Hz e DC 50% por 2s. Caso seja o botão INT2, o buzzer deve ser
    acionado com uma frequência de 50Hz e DC 50% por 2s.
    Obs1: é importante que independente do número de vezes que os botões forem pressionados e
    liberados de forma seguida, o buzzer seja acionado o mesmo número de vezes e na ordem em
    que os botões foram pressionados;
    Obs2: os botões INT0, INT1 e INT2 estão interfaceados com os pinos RB0, RB1 e RB2. Botão
    pressionado equivale ao nível lógico 0;
    Obs3: o buzzer está interfaceado com o pino RC1. 

*/
/* include do FreeRTOS. */
#include "FreeRTOS/include/FreeRTOS.h"
#include "FreeRTOS/include/task.h"
#include "FreeRTOS/include/queue.h"
//#include <stdio.h>
//#include <stdlib.h>
#include <p18f4550.h>

#pragma config PLLDIV = 1 // PLL Prescaler Selection bits (No prescale(4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits([Primary Oscillator Src : / 1][96 MHz PLL Src : / 2])
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator(HS))
#pragma config BOR = ON // Brown-out Reset Enable bits (Brownout Reset enabled in hardware only(SBOREN is disabled))
#pragma config BORV = 3 // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config WDT = OFF // Watchdog Timer Enable bit (WDT disabled(control is placed on the SWDTEN bit))
#pragma config PBADEN = OFF // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config MCLRE = ON // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
#pragma config LVP = OFF // Single-Supply ICSP Enable bit (Single - Supply ICSP enabled)

void vTask0(void);
void vTask1(void);
void vTask2(void);
void vTask3(void);

xQueueHandle Fila1;

void main(void){
    TRISB = 0b00000111;
    TRISC=  0b00000000;
    
    INTCON2bits.RBPU=0;
    
    Fila1=xQueueCreate(10, sizeof(unsigned char));
    
    xTaskCreate(vTask0,(const char * const)"Botao 1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(vTask1,(const char * const)"Botao 2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(vTask2,(const char * const)"Botao 3", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(vTask3,(const char * const)"Buzzer", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    
    vTaskStartScheduler();
}

void vTask0(){
    while(1){
        if(PORTBbits.RB0==0){
            vTaskDelay(100/portTICK_RATE_MS);
            if(PORTBbits.RB0==1)
                xQueueSend(Fila1,1,portMAX_DELAY);
        }
    }
}

void vTask1(){
    while(1){
        if(PORTBbits.RB1==0){
            vTaskDelay(100/portTICK_RATE_MS);
            if(PORTBbits.RB1==1)
                xQueueSend(Fila1,2,portMAX_DELAY);
        }
    }
}

void vTask2(){
    while(1){
        if(PORTBbits.RB2==0){
            vTaskDelay(100/portTICK_RATE_MS);
            if(PORTBbits.RB2==1)
                xQueueSend(Fila1,4,portMAX_DELAY);
        }
    }
}

void vTask3(){
    unsigned char dado=0;
    unsigned char cont=0;
    while(1){
        xQueueReceive(Fila1,&dado,portMAX_DELAY);
        if(dado==1 || dado==2 || dado==4){
            for(cont=0;cont<50*dado;cont++){
                PORTCbits.RC1=!PORTCbits.RC1;
                vTaskDelay((40/dado)/portTICK_RATE_MS);
            }
        }
    }
}
