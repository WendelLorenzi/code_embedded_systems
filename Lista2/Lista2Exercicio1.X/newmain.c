/* include do FreeRTOS. */
#include "FreeRTOSConfig.h"
#include "FreeRTOS/include/task.h"
#include "FreeRTOS/include/queue.h"

#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator (HS))
#pragma config BOR = ON         // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config PBADEN = OFF      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
#pragma config LVP = OFF         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)

void vTASK0( void ); 
void vTASK1( void ); 
xQueueHandle L1; 
 
void main( void ){ 
	TRISD=0b00000011; 
	L1=xQueueCreate(6, sizeof(char)); 
	xTaskCreate(vTASK0,(const char*const)"T0",configMINIMAL_STACK_SIZE,NULL,(tskIDLE_PRIORITY+1),NULL); 
	xTaskCreate(vTASK1,(const char*const)"T1",configMINIMAL_STACK_SIZE,NULL,(tskIDLE_PRIORITY+1),NULL); 
	vTaskStartScheduler(); 
} 

void vTASK0( void ){ 
	while(1){ 
		if(PORTBbits.RB0==1){ 
			vTaskDelay(100/portTICK_RATE_MS); 
			if(PORTBbits.RB0==0) 
				xQueueSend(L1,1,portMAX_DELAY); 
		}
	}
} 

void vTASK1( void ){ 
	char data=0; 
	while(1) { 
		xQueueReceive(L1,&data,portMAX_DELAY); 
		PORTBbits.RB2=1; 
		vTaskDelay(1000/portTICK_RATE_MS); 
		PORTBbits.RB2=0; 
		vTaskDelay(1000/portTICK_RATE_MS); 
	}
} 

