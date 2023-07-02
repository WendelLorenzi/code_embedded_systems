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
void main(void) {
 RCONbits.IPEN = 1;
 INTCONbits.GIEL = 1;
 INTCONbits.GIEH = 1;
 TXSTAbits.BRGH = 1;
 BAUDCONbits.BRG16 = 0;
 SPBRG = 129; //Configura o bau-date para 19200 // 40 MHz
 TXSTAbits.SYNC = 0; //Habilita comunicação assíncrona
 RCSTAbits.SPEN = 1; //Habilita os pinos de I/O para a serial
 TRISCbits.TRISC7 = 1; //Habilita o pino RX como entrada
 PIR1bits.RCIF = 0;
 IPR1bits.RCIP = 1;
 PIE1bits.RCIE = 1;
 RCSTAbits.CREN = 1;
 TRISCbits.TRISC6 = 1; //Habilita o pino TX como entrada
 TXSTAbits.TXEN = 1;
 xTaskCreate(vTASK0, (const char * const) "T0",
configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);
 xTaskCreate(vTASK1, (const char * const) "T1",
configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);
 vTaskStartScheduler();
}
void vTASK0() {
 while (1) {
 taskENTER_CRITICAL();
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'P';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'R';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'I';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'M';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'E';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'I';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'R';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'A';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = ' ';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'M';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'E';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'N';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'S';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'A';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'G';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'E';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'M';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 0x0D;
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 0x0A;
 taskEXIT_CRITICAL();
 }
}
void vTASK1() {
 while (1) {
 taskENTER_CRITICAL();
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'S';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'E';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'G';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'U';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'N';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'D';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'A';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = ' ';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'M';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'E';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'N';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'S';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'A';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'G';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'E';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 'M';
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 0x0D;
 while (TXSTAbits.TRMT == 0) {
 }
 TXREG = 0x0A;
 taskEXIT_CRITICAL();
 }
}
