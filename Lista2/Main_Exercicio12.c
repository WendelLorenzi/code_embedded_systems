/* Com base no exercício 11, crie uma nova tarefa que apresente no display LCD o valor de
S0 e S1.  */

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

//LCD PORTD
#define RS PORTEbits.RE2
#define EN PORTEbits.RE1

//Definicao dos comandos do LCD
#define linha1 0x80 // Posicao dos caracteres no LCD
#define linha2 0xc0 // +----+----+----+----+----+-----+----+
#define limpa_lcd 0x01 // |0x80|0x81|0x82|0x83|0x84| ... |0x8f|
#define cursor_piscando 0x0f // +----+----+----+----+----+-----+----+
#define cursor_off 0x0c // |0xc0|0xc1|0xc2|0xc3|0xc4| ... |0xcf|
#define cursor_on 0x0e // +----+----+----+----+----+-----+----+
#define rotaciona_direita 0x1c

//Funcoes do LCD
void lcd_cmd(unsigned char dado);
void lcd_escreve(unsigned char dado);
void lcd_init(void);
void converte_LCD(void);

xSemaphoreHandle S0;
xSemaphoreHandle S1;
static void vTASK0(void);
static void vTASK1(void);
static void vTASK2(void);
static void vTASK3(void);
static void vTASK4(void);

void main(void) {
 TRISB=0b00000011;
 
lcd_init(); 

lcd_cmd(limpa_lcd);
lcd_cmd(linha1);
 
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

static void vTASK4(void){
 while(1) {
    if(xSemaphoreTake(S1,portMAX_DELAY) && xSemaphoreTake(S0,portMAX_DELAY)) {
        lcd_cmd(limpa_lcd);
        lcd_cmd(linha1);
        lcd_escreve('S');
        lcd_escreve('0');
        lcd_escreve(' ');
        lcd_escreve('S');
        lcd_escreve('1');
        lcd_escreve(':');
        lcd_escreve(' ');
        lcd_escreve('O');
        lcd_escreve('K');
    } else if(xSemaphoreTake(S0,portMAX_DELAY)) {
        lcd_cmd(limpa_lcd);
        lcd_cmd(linha1);
        lcd_escreve('S');
        lcd_escreve('0');
        lcd_escreve(' ');
        lcd_escreve('O');
        lcd_escreve('K');
        lcd_escreve(' ');
        lcd_escreve('S');
        lcd_escreve('1');
        lcd_escreve(' ');
        lcd_escreve('B');
        lcd_escreve('L');
    } else if(xSemaphoreTake(S1,portMAX_DELAY)) {
        lcd_cmd(limpa_lcd);
        lcd_cmd(linha1);
        lcd_escreve('S');
        lcd_escreve('0');
        lcd_escreve(' ');
        lcd_escreve('B');
        lcd_escreve('L');
        lcd_escreve(' ');
        lcd_escreve('S');
        lcd_escreve('1');
        lcd_escreve(' ');
        lcd_escreve('O');
        lcd_escreve('K');
    } else {
        lcd_cmd(limpa_lcd);
        lcd_cmd(linha1);
        lcd_escreve('S');
        lcd_escreve('0');
        lcd_escreve(' ');
        lcd_escreve('B');
        lcd_escreve('L');
        lcd_escreve(' ');
        lcd_escreve('S');
        lcd_escreve('1');
        lcd_escreve(' ');
        lcd_escreve('B');
        lcd_escreve('L');
    }
 }
} 

void lcd_cmd(unsigned char dado) {
    PORTD = dado; // Coloca dado na porta
    RS = 0; // Modo comando
    EN = 1; // Clock +---------+
    vTaskDelay(2/portTICK_RATE_MS); // | <-2ms-> |
    EN = 0; // | | <-2ms->
    vTaskDelay(2/portTICK_RATE_MS); // + +----------
}


//-------------------------------------------------------
// Funcao que escreve um caracter no LCD
//-------------------------------------------------------

void lcd_escreve(unsigned char dado) {
    PORTD = dado; // Coloca dado na porta
    RS = 1; // Modo escrita
    EN = 1; // Clock +----------+
    vTaskDelay(2/portTICK_RATE_MS); //
    EN = 0; //
    vTaskDelay(2/portTICK_RATE_MS); // + +-----------
}


//-------------------------------------------------------
// Funcao que inicializa display para 8 bits
//-------------------------------------------------------

void lcd_init(void) {
    lcd_cmd(0x38); // Display em 8 bit's
    lcd_cmd(0x38); // Display em 8 bit's (duas vezes)
    lcd_cmd(0x06); // Escreve da esquerda para direita
    lcd_cmd(cursor_off); // Cursor desligado
    lcd_cmd(limpa_lcd); // Limpa LCD
}