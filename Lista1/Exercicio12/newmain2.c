/* Scheduler include files. */
#include "FreeRTOS/include/FreeRTOS.h"
#include "FreeRTOS/include/task.h"

#pragma config WDT = OFF
#pragma config OSC = HSPLL

static void vTask1(void *pvParameters) {
    while (1) {
        LATD ^= 0x1;
        vTaskDelay(1000);
    }
}

/*
 * 
 */
void main(void) {
    /* Power up Configuration*/
    TRISD = 0;
    LATD = 0;
    /* Create tasks */
    xTaskCreate(vTask1, "T1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

    /* Start the scheduler.  Will never return here. */
    vTaskStartScheduler();
    return 0;
}

