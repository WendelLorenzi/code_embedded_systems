/* 
Imagine que você está desenvolvendo uma bancada para ignição de um motor de foguete
espacial. A ignição será iniciada pelo acionamento de dois relés. O lançamento só pode ser
iniciado após um protocolo de segurança. O protocolo de segurança é aguardar o “OK” de três
fiscais, que serão recebidos pelo acionamento dos botões INT0, INT1 e INT2.
 Execute no microcontrolador PIC18F4550, por meio do software PICSimLab, utilizando o RTOS
e o grupo de eventos as seguintes tarefas:
• Acender os leds D0 a D7;
• Verificar se o botão RB0 foi pressionado e em seguida liberado, aguardando um delay
de (100/portTICK_PERIOD_MS) entre o apertar e liberar;
• Verificar se o botão RB1 foi pressionado e em seguida liberado, aguardando um delay
de (100/portTICK_PERIOD_MS) entre o apertar e liberar;
• Verificar se o botão RB2 foi pressionado e em seguida liberado, aguardando um delay
de (100/portTICK_PERIOD_MS) entre o apertar e liberar;
• Apagar cada um dos leds a cada 1s, iniciando com o led D0;
• Após todos o leds estarem apagados, acionar os relés (pinos RC0 e RE0) por 5s;
Obs1: é importante que a execução de uma tarefa que “dependa” de outra tarefa fique no estado
bloqueado sempre que possível e após o início do lançamento não haja nenhuma tarefa ativa.
Obs2: os botões INT0, INT1 e INT2 estão interfaceados com os pinos RB0, RB1 e RB2. Botão
pressionado equivale ao nível lógico 0;
Obs3: os relés são acionados com nível lógico ‘0’
*/

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