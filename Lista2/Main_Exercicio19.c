/*
Faça um programa utilizando FreeRTOS e grupo de eventos para fazer as funções:
• Quando a temperatura estiver acima de 25 graus e o botão RB0 for apertado, deve-se
ligar o cooler (RC2);
• Quando a temperatura estiver abaixo de 25 graus e o botão RB0 for apertado, deve-se
ligar o heater (RC5);
A temperatura deve ser monitorada através da aquisição ADC, no pino RA2.
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

void vTemperatureTask(void);
void vButtonTask(void);
void vCoolerControlTask(void);
void vHeaterControlTask(void);
int read_Analog(void);

EventGroupHandle_t xEventGroup;
SemaphoreHandle_t xTemperatureMutex;

float fTemperature;
int nButtonState;

void main(void) {
    ADCON1bits.PCFG3 = 1; // Configura o pino RA2 como entrada analógica
    TRISCbits.RC2 = 0; // Configura o pino RC2 como saída para o cooler
    TRISCbits.RC5 = 0; // Configura o pino RC5 como saída para o heater
    TRISBbits.RB0 = 1; // Configura RB0 como entrada

    xEventGroup = xEventGroupCreate();
    xTemperatureMutex = xSemaphoreCreateMutex();

    xTaskCreate(vTemperatureTask, "Temperature", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(vButtonTask, "Button", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(vCoolerControlTask, "CoolerControl", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);
    xTaskCreate(vHeaterControlTask, "HeaterControl", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);

    vTaskStartScheduler();
}

int read_Analog(void) {
    ADCON0bits.GO = 1; // Inicia a conversão AD
    while (ADCON0bits.GO); // Espera a conversão ser concluída
    return (ADRESH << 8) | ADRESL; // Retorna o valor lido
}

void vTemperatureTask(void) {
    while (1) {
        xSemaphoreTake(xTemperatureMutex, portMAX_DELAY);
        fTemperature = 20 + (read_Analog() * 0.48876);
        xSemaphoreGive(xTemperatureMutex);

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void vButtonTask(void) {
    while (1) {
        int buttonState = PORTBbits.RB0;
        xEventGroupSetBits(xEventGroup, buttonState); // Define o bit de evento com o estado do botão

        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void vCoolerControlTask(void) {
    while (1) {
        EventBits_t eventBits = xEventGroupWaitBits(xEventGroup, 0x01, pdTRUE, pdTRUE, portMAX_DELAY);

        if ((eventBits & 0x01) && (fTemperature > 25)) {
            // Ligar o cooler
            PORTCbits.RC2 = 1;
        } else {
            // Desligar o cooler
            PORTCbits.RC2 = 0;
        }

        vTaskDelay(200 / portTICK_PERIOD_MS);
    }
}

void vHeaterControlTask(void) {
    while (1) {
        EventBits_t eventBits = xEventGroupWaitBits(xEventGroup, 0x01, pdTRUE, pdTRUE, portMAX_DELAY);

        if ((eventBits & 0x01) && (fTemperature < 25)) {
            // Ligar o heater
            PORTCbits.RC5 = 1;
        } else {
            // Desligar o heater
            PORTCbits.RC5 = 0;
        }

        vTaskDelay(200 / portTICK_PERIOD_MS);
    }
}