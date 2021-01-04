
#define F_CPU 8000000UL
#define FRE 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "hunget_adc.h"
#include "hunget_lcd.h"
#include "hunget_uart.h"
#include "thu_vien_rieng.h"

unsigned char push_button = 0;

int main(void)
{
	
	/*//Phan 3.3: DOC TRANG THAI LOGIC DAU VAO SO
	INIT();
	PB_2_LED();
	*/
	
	
	
	/* //Phan 3.4: DO DIEN AP TUONG TU VA HIEN THI LEN MAN HINH LCD
	
	ADC_2_LCD_new();
	
	*/
	

	
	//Phan3.5: GIAO TIEP VOI MAY TINH BANG CHUAN UART
	char first_line[] = "Hello Baby";
	//char second_line[] = "Vien Dien tu Vien Thong";
	LCD_Init();		//Initialize LCD
	LCD_String(first_line); // Write string on 1st line of LCD
    //LCD_String_xy(1,0, second_line);
	_delay_ms(1000);
	
	UART_init(9600);
	
	while(1)
	{
		UART_SendString(first_line);
		UART_SendString("\n"); //newline
		//UART_SendString(second_line);
		//UART_SendString("\n"); //newline
		LCD_Command(0x18);	// shift entire display left
				//0x1C la dich phai
				//0x18 la dic trai
		_delay_ms(1000);
	}

	return 0;
} 