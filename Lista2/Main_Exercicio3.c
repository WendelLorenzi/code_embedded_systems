// Exercicio 3
/*
    Implemente no microcontrolador PIC18F4550 um programa composto por duas tarefas e uma
    fila, conforme:
    TAREFA 1: Deve alternar o LED em RD0 a cada 500ms e, a cada ciclo de LED ligado/desligado,
    enviar à fila um número contador de ciclos;
    TAREFA 2: Deve receber o valor do contador, armazenado na fila pela TAREFA 1, e verificar se
    já foram rodados 50 ciclos de LED ligado e desligado, caso tenha alcançado 50 ciclos, acionar
    um buzzer na RC1 por um segundo e colocar o valor 0 na fila para zerar o contador; 
*/

/* include do FreeRTOS. */
#include "FreeRTOS/include/FreeRTOS.h"
#include "FreeRTOS/include/queue.h"
#include "FreeRTOS/include/task.h"

#include <stdio.h>
#include <stdlib.h>
#include <p18f4550.h>

/* configuração do uC */
#pragma config FOSC = HS
#pragma config CPUDIV = OSC1_PLL2
#pragma config WDT = OFF
#pragma config BOR = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF
#pragma config DEBUG = OFF
#pragma config MCLRE = OFF

void vTASK0(void);
void vTASK1(void);
xQueueHandle L1;

#define BUZZER_PIN TRISCbits.RC1

void main(void) {
    TRISD = 0b00000000;
    L1=xQueueCreate(10, sizeof(int)); 
    xTaskCreate(vTASK0, (const char * const) "T0", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);
    xTaskCreate(vTASK1, (const char * const) "T1", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);
    vTaskStartScheduler();
}

void vTASK0(void){
    int cycleCount = 0;
    while(1){
        PORTDbits.RD0^=1;
        vTaskDelay(500/portTICK_RATE_MS);
        
        cycleCount++;
        xQueueSend(L1, &cycleCount, portMAX_DELAY);
        if (cycleCount > 50) {
            cycleCount = 0;
        }
    }
}

void vTASK1(void){
    int cycleCount;
    while(1){
        if (xQueueReceive(L1, &cycleCount, portMAX_DELAY) == pdPASS) {
            if (cycleCount == 50) {
                BUZZER_PIN = 1;
                vTaskDelay(1000/portTICK_RATE_MS);
                BUZZER_PIN = 0;
                cycleCount = 0;
                xQueueSend(L1, &cycleCount, portMAX_DELAY);
               }
            }
        }
    }