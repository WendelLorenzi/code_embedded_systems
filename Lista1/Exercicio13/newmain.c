/* include do FreeRTOS. */
#include "FreeRTOS/include/FreeRTOS.h"
#include "FreeRTOS/include/queue.h"
#include "FreeRTOS/include/task.h"

#include <stdio.h>
#include <stdlib.h>
#include <p18f4550.h>

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

/* configuração do uC */
//#pragma config FOSC = HS
//#pragma config CPUDIV = OSC1_PLL2
#pragma config WDT = OFF
#pragma config BOR = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF
#pragma config DEBUG = OFF
#pragma config MCLRE = OFF

void vTASK0(void);

///Declaracao de delay
void delay_ms(unsigned int a);
void delay(void);
//Funcoes do LCD
void lcd_cmd(unsigned char dado);
void lcd_escreve(unsigned char dado);
void lcd_init(void);
void converte_LCD(void);

void main(void) {
    TRISD = 0b00000000;
    TRISE = 0b00000000; // Configura port B como saida 0=output, 1=Input    
	TRISB = 0b00000000; 
    TRISC = 0b00000000;
    
    lcd_init(); 
    
    lcd_cmd(limpa_lcd);
    lcd_cmd(linha1);
    
    xTaskCreate(vTASK0, (const char * const) "T0", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);
    
    vTaskStartScheduler();
}

void vTASK0(void){
    while(1){
        lcd_cmd(limpa_lcd);
        lcd_cmd(linha1);
        lcd_escreve('S');    
        lcd_escreve('I');    
        lcd_escreve('S');    
        lcd_escreve('T');    
        lcd_escreve('E');    
        lcd_escreve('M');    
        lcd_escreve('A');    
        lcd_escreve('S');
        vTaskDelay(1000);
        lcd_cmd(limpa_lcd);
        lcd_cmd(linha1);
        lcd_escreve('E');    
        lcd_escreve('M');    
        lcd_escreve('B');    
        lcd_escreve('A');    
        lcd_escreve('R');    
        lcd_escreve('C');    
        lcd_escreve('A');    
        lcd_escreve('D');
        lcd_escreve('O');    
        lcd_escreve('S');
        vTaskDelay(1000);
        lcd_cmd(limpa_lcd);
        lcd_cmd(linha1);
        lcd_escreve('2');    
        lcd_escreve('0');    
        lcd_escreve('2');    
        lcd_escreve('3');    
        lcd_escreve(' ');    
        lcd_escreve('1');
        vTaskDelay(1000);
        
    }
}




//-------------------------------------------------------
// Funcao que executa comandos no LCD
//-------------------------------------------------------

void lcd_cmd(unsigned char dado) {
    PORTD = dado; // Coloca dado na porta
    RS = 0; // Modo comando
    EN = 1; // Clock +---------+
    delay_ms(2); // | <-2ms-> |
    EN = 0; // | | <-2ms->
    delay_ms(2); // + +----------
}


//-------------------------------------------------------
// Funcao que escreve um caracter no LCD
//-------------------------------------------------------

void lcd_escreve(unsigned char dado) {
    PORTD = dado; // Coloca dado na porta
    RS = 1; // Modo escrita
    EN = 1; // Clock +----------+
    delay_ms(2); //
    EN = 0; //
    delay_ms(2); // + +-----------
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

//-------------------------------------------------------
// Funcao Delay 1ms
//-------------------------------------------------------

void delay(void) {
    int a = 0;
    while (a < 164) {
        a++;
    }
}

//-------------------------------------------------------
// Funcao Delay em ms
//-------------------------------------------------------

void delay_ms(unsigned int a) {
    while (a != 0) {
        delay();
        a--;
    }
}
