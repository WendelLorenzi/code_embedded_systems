/* Utilizando o código do exercício 17, implemente a necessidade de se apertar três botões
(RB0, RB1 e RB2) simultaneamente para alternar o LED do RB3 entre aceso por 2 segundos e
apagado por mais 2 segundos. Caso qualquer um dos três botões for apertado, alterne o LED
do RB4 por 3 segundos aceso e 3 segundos apagado. */

/* include do FreeRTOS. */
#include "FreeRTOS/include/FreeRTOS.h"
#include "FreeRTOS/include/queue.h"
#include "FreeRTOS/include/task.h"
#include "FreeRTOS/include/semphr.h"
#include "FreeRTOS/include/event_groups.h"
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
void vTASK2(void);
void vTASK3(void);
EventGroupHandle_t xCreatedEventGroup;

void main(void) {
    TRISB = 0x07;  // RB0, RB1 e RB2 como entrada
    TRISBbits.RB3 = 0;  // RB3 como saída
    TRISBbits.RB4 = 0;  // RB4 como saída

    xCreatedEventGroup = xEventGroupCreate();

    xTaskCreate(vTASK0, (const char *const) "T0", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);
    xTaskCreate(vTASK1, (const char *const) "T1", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);
    xTaskCreate(vTASK2, (const char *const) "T2", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);
    xTaskCreate(vTASK3, (const char *const) "T3", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);

    vTaskStartScheduler();
}

void vTASK0(void) {
    while (1) {
        xEventGroupWaitBits(xCreatedEventGroup, 0x07, pdTRUE, pdTRUE, portMAX_DELAY);

        // Alterna o LED do RB3 entre aceso por 2 segundos e apagado por mais 2 segundos
        PORTBbits.RB3 = 1;
        vTaskDelay(2000 / portTICK_RATE_MS);
        PORTBbits.RB3 = 0;
        vTaskDelay(2000 / portTICK_RATE_MS);
    }
}

void vTASK1(void) {
    while (1) {
        if (PORTBbits.RB0) {
            vTaskDelay(200 / portTICK_RATE_MS);
            if (PORTBbits.RB0 == 0)
                xEventGroupSetBits(xCreatedEventGroup, 1);
        }
    }
}

void vTASK2(void) {
    while (1) {
        if (PORTBbits.RB1) {
            vTaskDelay(200 / portTICK_RATE_MS);
            if (PORTBbits.RB1 == 0)
                xEventGroupSetBits(xCreatedEventGroup, 2);
        }
    }
}

void vTASK3(void) {
    while (1) {
        if (PORTBbits.RB2) {
            vTaskDelay(200 / portTICK_RATE_MS);
            if (PORTBbits.RB2 == 0)
                xEventGroupSetBits(xCreatedEventGroup, 4);
        }
    }
}