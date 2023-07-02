/*
Implemente no microcontrolador PIC18F4550 um programa composto por uma tarefa, uma
interrupção e um semáforo, conforme:
TAREFA 1: Deve esperar por 5 segundos, alternando o led RD0;
Interrupção: Deve coletar um dado em AN2 (temperatura no PICSIMLAB) após 5 segundos;
*/

/* include do FreeRTOS. */
#include "FreeRTOS/include/FreeRTOS.h"
#include "FreeRTOS/include/task.h"
#include "FreeRTOS/include/semphr.h"

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
SemaphoreHandle_t S0;

void main(void) {
    TRISD = 0b00000000;
    S0=xSemaphoreCreateBinary();
    xSemaphoreGive(S0);
    xTaskCreate(vTASK0, (const char * const) "T0", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);
    vTaskStartScheduler();
}

void vTASK0(void){
    while(1){
        if (xSemaphoreTake(S0, portMAX_DELAY) == pdTRUE) {
            PORTDbits.RD0^=1;
            vTaskDelay(5000/portTICK_RATE_MS);
            xSemaphoreGive(S0);
        }
        
    }
}
