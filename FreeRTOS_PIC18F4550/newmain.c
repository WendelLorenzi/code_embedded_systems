#include "FreeRTOS/include/FreeRTOS.h"
#include "FreeRTOS/include/task.h"
#include "FreeRTOS/include/semphr.h"
#include "FreeRTOS/include/event_groups.h"
#include <stdio.h>
#include <stdlib.h>
#include <p18f4550.h>

/* Configuração do uC */
#pragma config FOSC = HS
#pragma config CPUDIV = OSC1_PLL2
#pragma config WDT = OFF
#pragma config BOR = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF
#pragma config DEBUG = OFF
#pragma config MCLRE = OFF

EventGroupHandle_t xEventGroup;
TaskHandle_t xTaskHandleLEDs;
TaskHandle_t xTaskHandleRelays;

void vLEDsTask(void *pvParameters);
void vButtonsTask(void *pvParameters);
void vRelaysTask(void *pvParameters);

int main(void) {
    xEventGroup = xEventGroupCreate();

    xTaskCreate(vLEDsTask, "LEDsTask", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &xTaskHandleLEDs);
    xTaskCreate(vButtonsTask, "ButtonsTask", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);
    xTaskCreate(vRelaysTask, "RelaysTask", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 3, &xTaskHandleRelays);

    vTaskStartScheduler();

    while (1) {
    }
}

void vLEDsTask(void *pvParameters) {
    (void)pvParameters;

    while (1) {
        for (int i = 0; i < 8; i++) {
            LATD = 0xFF << i;
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }
}

void vButtonsTask(void *pvParameters) {
    (void)pvParameters;

    while (1) {
        if (!PORTBbits.RB0) {
            vTaskDelay(100 / portTICK_PERIOD_MS);
            if (!PORTBbits.RB0) {
                xEventGroupSetBits(xEventGroup, 0x01);
                xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);
                xEventGroupClearBits(xEventGroup, 0x01);
            }
        }

        if (!PORTBbits.RB1) {
            vTaskDelay(100 / portTICK_PERIOD_MS);
            if (!PORTBbits.RB1) {
                xEventGroupSetBits(xEventGroup, 0x02);
                xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);
                xEventGroupClearBits(xEventGroup, 0x02);
            }
        }

        if (!PORTBbits.RB2) {
            vTaskDelay(100 / portTICK_PERIOD_MS);
            if (!PORTBbits.RB2) {
                xEventGroupSetBits(xEventGroup, 0x04);
                xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);
                xEventGroupClearBits(xEventGroup, 0x04);
            }
        }
    }
}

void vRelaysTask(void *pvParameters) {
    (void)pvParameters;

    while (1) {
        xEventGroupWaitBits(xEventGroup, 0x01 | 0x02 | 0x04, pdTRUE, pdTRUE, portMAX_DELAY);

        LATCbits.LC0 = 0; // Aciona o relé RC0 (nível lógico 0)
        LATEbits.LE0 = 0; // Aciona o relé RE0 (nível lógico 0)

        vTaskDelay(5000 / portTICK_PERIOD_MS);

        LATCbits.LC0 = 1; // Desliga o relé RC0 (nível lógico 1)
        LATEbits.LE0 = 1; // Desliga o relé RE0 (nível lógico 1)
    }
}