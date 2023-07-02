/* include do FreeRTOS. */
#include "FreeRTOS/include/FreeRTOS.h" 
#include "FreeRTOS/include/queue.h" 
#include "FreeRTOS/include/task.h" 
#include "FreeRTOS/include/semphr.h" 

/* configuração do uC */ 
#pragma config FOSC = HS 
#pragma config CPUDIV = OSC1_PLL2 
#pragma config WDT = OFF 
#pragma config BOR = OFF 
#pragma config LVP = OFF 
#pragma config PBADEN = OFF 
#pragma config DEBUG = OFF 
#pragma config MCLRE = OFF 

xSemaphoreHandle S1; 

char A=0; 

void vSerialRxISRf( void ); 
void vTASK0(void); 
void vTASK1(void);

void main(void) { 
    TRISB=0b00000000; 
    TXSTAbits.BRGH=1; 
    BAUDCONbits.BRG16=0; 
    SPBRG=129;    
    TXSTAbits.SYNC=0;  
    RCSTAbits.SPEN=1;  
    TRISCbits.TRISC7=1;  
    PIR1bits.RCIF=0; 
    IPR1bits.RCIP=1; 
    PIE1bits.RCIE=1; 
    RCSTAbits.CREN=1; 
    TRISCbits.TRISC6=1;  
    TXSTAbits.TXEN=1; 
    //Configura o baudrate para 9600 
    //Habilita comunicação assíncrona 
    //Habilita os pinos de I/O para a serial 
    //Habilita o pino RX como entrada 
    //Habilita o pino TX como entrada 
    vSemaphoreCreateBinary(S1); 
    xTaskCreate(vTASK0,(const char*const)"T0",configMINIMAL_STACK_SIZE,NULL,(tskIDLE_PRIORITY+1),NULL); 
    xTaskCreate(vTASK1,(const char*const)"T1",configMINIMAL_STACK_SIZE,NULL,(tskIDLE_PRIORITY+1),NULL); 
    vTaskStartScheduler(); 
} 

void vTASK0( ){ 
    while(1) { 
        PORTBbits.RB2=!PORTBbits.RB2; 
        vTaskDelay(100/portTICK_RATE_MS); 
    } 
} 

void vTASK1( ){ 
    while(1) { 
        xSemaphoreTake(S1,portMAX_DELAY); 
        PORTBbits.RB4=1; 
        vTaskDelay((A*200)/portTICK_RATE_MS); 
        PORTBbits.RB4=0; 
        while (TXSTAbits.TRMT==0) {} 
        TXREG='O'; 
        while (TXSTAbits.TRMT==0) {} 
        TXREG='K'; 
    } 
} 

#pragma interruptlow vSerialRxISRf 
void vSerialRxISRf( void ){ 
    portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE; 
    PIR1bits.RCIF=0; 
    if (RCREG=='1' || RCREG=='2') { 
        A=(RCREG-0x30); 
        xSemaphoreGiveFromISR(S1,NULL); 
    } 
} 