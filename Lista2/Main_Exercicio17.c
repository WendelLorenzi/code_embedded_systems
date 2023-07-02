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
EventGroupHandle_t xCreatedEventGroup;

void main( void ){
    TRISB=0x03;
    xCreatedEventGroup = xEventGroupCreate();
    xTaskCreate(vTASK0,(const char
    *const)"T0",configMINIMAL_STACK_SIZE,NULL,(tskIDLE_PRIORITY+1),NULL);
    xTaskCreate(vTASK1,(const char
    *const)"T1",configMINIMAL_STACK_SIZE,NULL,(tskIDLE_PRIORITY+1),NULL);
    xTaskCreate(vTASK2,(const char
    *const)"T2",configMINIMAL_STACK_SIZE,NULL,(tskIDLE_PRIORITY+1),NULL);
    vTaskStartScheduler();
}
void vTASK0(void){
    while(1){
        xEventGroupWaitBits(xCreatedEventGroup,1|2,pdTRUE,pdTRUE,
        portMAX_DELAY);
        PORTBbits.RB2=1;
        vTaskDelay(1000 /portTICK_RATE_MS);
        PORTBbits.RB2=0;
    }
}
void vTASK1(void){
    while(1){
        if(PORTBbits.RB0){
            vTaskDelay(200 /portTICK_RATE_MS);
            if(PORTBbits.RB0==0)
                xEventGroupSetBits(xCreatedEventGroup,1);
        }
    }
}
void vTASK2(void){
    while(1){
        if(PORTBbits.RB1){
            vTaskDelay(200/portTICK_RATE_MS);
            if(PORTBbits.RB1==0) xEventGroupSetBits(xCreatedEventGroup,2);
        }
    }
}