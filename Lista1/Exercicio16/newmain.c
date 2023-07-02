/* include do FreeRTOS. */
#include "FreeRTOS/include/queue.h"
#include "FreeRTOS/include/task.h"
#include "FreeRTOS/include/FreeRTOS.h"

#include <stdio.h>
#include <stdlib.h>
#include <p18f4550.h>

//LCD PORTD
#define RS PORTEbits.RE2
#define EN PORTEbits.RE1

//Definicao dos comandos do LCD
#define linha1 0x80 // Posicao dos caracteres no LCD
#define linha2 0xc0 // +----+----+----+----+----+-----+----+
#define limpa_lcd 0x01 // |0x80|0x81|0x82|0x83|0x84| ... |0x8f|
#define cursor_piscando 0x0f // +----+----+----+----+----+-----+----+
#define cursor_off 0x0c // |0xc0|0xc1|0xc2|0xc3|0xc4| ... |0xcf|
#define cursor_on 0x0e // +----+----+----+----+----+-----+----+
#define rotaciona_direita 0x1c
#define _XTAL_FREQ 20000000
#define LED_D14 PORTDbits.RD0
#define LED_D15 PORTDbits.RD1
#define LED_D16 PORTDbits.RD2
#define LED_D17 PORTDbits.RD3

/* configura��o do uC */
#pragma config FOSC = HS
#pragma config CPUDIV = OSC1_PLL2
#pragma config WDT = OFF
#pragma config BOR = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF
#pragma config DEBUG = OFF
#pragma config MCLRE = OFF

void vTASK0(void);

void INVERT_D14(void);
void INVERT_D15(void);
void INVERT_D16(void);
void INVERT_D17(void);

void main(void) {
    TRISD = 0b00000000;
    LED_D14 = 1;
    LED_D15 = 1;
    LED_D16 = 1;
    
    xTaskCreate(vTASK0, (const char * const) "T0", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);
    
    vTaskStartScheduler();
}

void vTASK0(void){
    while(1){
        INVERT_D14();
        INVERT_D15();
        INVERT_D16();
        INVERT_D17();
        vTaskDelay(100/portTICK_RATE_MS);
        INVERT_D14();
        vTaskDelay(100/portTICK_RATE_MS);
        INVERT_D16();
        vTaskDelay(150/portTICK_RATE_MS);
        INVERT_D17();
        vTaskDelay(450/portTICK_RATE_MS);
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
