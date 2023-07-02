/* include do FreeRTOS. */
#include "FreeRTOS/include/FreeRTOS.h"
#include "FreeRTOS/include/queue.h"
#include "FreeRTOS/include/task.h"
#include "FreeRTOS/include/semphr.h"

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
#pragma config FOSC = HS
#pragma config CPUDIV = OSC1_PLL2
#pragma config WDT = OFF
#pragma config BOR = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF
#pragma config DEBUG = OFF
#pragma config MCLRE = OFF

void vTASK1(void);
void vTASK2(void);
xSemaphoreHandle S1;

///Declaracao de delay
void delay_ms(unsigned int a);
void delay(void);
//Funcoes do LCD
void lcd_cmd(unsigned char dado);
void lcd_escreve(unsigned char dado);
void lcd_init(void);
void init_adc(void);

void converte_LCD(void);

char contador=0;
int valorAD = 0;

void main(void) {
    TRISD = 0b00000000;
    TRISE = 0b00000000; // Configura port B como saida 0=output, 1=Input    
	TRISB = 0b00000000; 
    TRISC = 0b00000000;
    PORTA = 0b00000100;
    
    lcd_init(); 
    init_adc();
    
    lcd_cmd(limpa_lcd);
    lcd_cmd(linha1);

    vSemaphoreCreateBinary(S1);
    
    xTaskCreate(vTASK1, (const char * const) "5segundos", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);
    xTaskCreate(vTASK2, (const char * const) "ColetaAD", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);
    
    vTaskStartScheduler();
}

void vTASK1(void){
    while(1){
        PORTBbits.RB0=!PORTBbits.RB0;
        vTaskDelay(5000);
        xSemaphoreGive(S1);
    }
}

void vTASK2(void){
    unsigned int milhar = 0;
    unsigned int centena = 0;
    unsigned int dezena = 0;
    unsigned int unidade = 0;
    
    while(1){
        xSemaphoreTake(S1,portMAX_DELAY);
        
        lcd_cmd(limpa_lcd);
        lcd_cmd(linha1);
    
        ADCON0bits.GO=1;
        while(ADCON0bits.DONE);
        valorAD = ADRESH;
        valorAD = (valorAD << 8);
        valorAD = valorAD | ADRESL;
        valorAD = ((valorAD*10)/2.048);
        
        milhar = valorAD / 1000;
        centena = (valorAD - milhar * 1000) / 100;
        dezena = (valorAD - milhar * 1000 - centena * 100) / 10;
        unidade = valorAD - milhar * 1000 - centena * 100 - dezena * 10;

        lcd_escreve(milhar + 0x30); //Soma 0x30 para converter para ascii
        lcd_escreve(centena + 0x30);
        lcd_escreve(dezena + 0x30);
        lcd_escreve('.');
        lcd_escreve(unidade + 0x30);
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


void init_adc(void){
    ADCON0 = 0b00001000;
    ADCON1 = 0b00001100;
    ADCON2 = 0b10001000;
    ADCON0bits.ADON = 1;
}