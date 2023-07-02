/* include do FreeRTOS. */
#include "FreeRTOS/include/FreeRTOS.h"
#include "FreeRTOS/include/queue.h"
#include "FreeRTOS/include/task.h"
#include "FreeRTOS/include/semphr.h"

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

xSemaphoreHandle S0;
xSemaphoreHandle S1;
static void vTASK0(void);
static void vTASK1(void);
static void vTASK2(void);
static void vTASK3(void);

void main(void) {
 TRISB=0b00000011;
 
 
 S0=xSemaphoreCreateCounting(5,0);
 S1=xSemaphoreCreateCounting(5,0);
 xTaskCreate(vTASK0,(const
char*const)"T0",configMINIMAL_STACK_SIZE,NULL,(tskIDLE_PRIORITY+1),NUL
L);
 xTaskCreate(vTASK1,(const
char*const)"T1",configMINIMAL_STACK_SIZE,NULL,(tskIDLE_PRIORITY+1),NUL
L);
 xTaskCreate(vTASK2,(const
char*const)"T2",configMINIMAL_STACK_SIZE,NULL,(tskIDLE_PRIORITY+1),NUL
L);
 xTaskCreate(vTASK3,(const
char*const)"T3",configMINIMAL_STACK_SIZE,NULL,(tskIDLE_PRIORITY+1),NUL
L);
  xTaskCreate(vTASK4,(const
char*const)"T4",configMINIMAL_STACK_SIZE,NULL,(tskIDLE_PRIORITY+1),NUL
L);
  
 vTaskStartScheduler();
} 

static void vTASK0(void){
    while(1){
        if(PORTBbits.RB0==1){
            vTaskDelay(100/portTICK_RATE_MS);
            if(PORTBbits.RB0==0) xSemaphoreGive(S0);
        }
    }
}
static void vTASK1(void){
 while(1){
    if(PORTBbits.RB1==1){
            vTaskDelay(100/portTICK_RATE_MS);
            if(PORTBbits.RB1==0) xSemaphoreGive(S1);
        }
    }
}
static void vTASK2(void){
 while(1) {
    xSemaphoreTake(S0,portMAX_DELAY);
    PORTBbits.RB2=1;
    vTaskDelay(2000/portTICK_RATE_MS);
    PORTBbits.RB2=0;
    vTaskDelay(2000/portTICK_RATE_MS);
    }
}
static void vTASK3(void){
 while(1) {
    xSemaphoreTake(S1,portMAX_DELAY);
    PORTBbits.RB3=1;
    vTaskDelay(2000/portTICK_RATE_MS);
    PORTBbits.RB3=0;
    vTaskDelay(2000/portTICK_RATE_MS);
 }
} 