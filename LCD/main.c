/*
 * LCD.c
 *
 * Created: 25/10/2017 08:39:54
 * Author : mauricio.donatti
 * E-mail: mauricio.donatti@lnls.br
 */ 

/*
LCD Pinout

1	-----------------	VSS/GND		
2	-----------------	VDD
3	-----------------	V0
4	-----------------	RS
5	-----------------	RW	
6	-----------------	E
7	-----------------	DB0
8	-----------------	DB1
9	-----------------	DB2	
10	-----------------	DB3
11	-----------------	DB4
12	-----------------	DB5
13	-----------------	DB6
14	-----------------	DB7
15	-----------------	K
16	-----------------	A-RED
17	-----------------	A-GREEN
18	-----------------	A-BLUE

*/

#define F_CPU 16000000UL	//definição da frequência de clock

#include <avr/io.h>
#include <util/delay.h>


#define D4	eS_PORTD4		//arduino pin 4
#define D5	eS_PORTD5		//arduino pin 5
#define D6	eS_PORTD6		//arduino pin 6
#define D7	eS_PORTD7		//arduino pin 7
#define RS	eS_PORTB0		//arduino pin 8
#define EN	eS_PORTB1		//arduino pin 9
#define BR	eS_PORTB2		//arduino pin 10
#define BG	eS_PORTB3		//arduino pin 11	 
#define BB	eS_PORTB4		//arduino pin 12

#include "lcd.h" //Can be download from the bottom of this article

int i;

void Backlight_off()
{
	pinChange(BR,0);
	pinChange(BG,0);
	pinChange(BB,0);
}

void Backlight_red()
{
	pinChange(BR,1);
}

void Backlight_green()
{
	pinChange(BG,1);
}

void Backlight_blue()
{
	pinChange(BB,1);	
}

int main(void)
{
	DDRD = 0xF0;
	DDRB = 0xFF;
	Backlight_off();

	Lcd4_Init();
	Backlight_red();
	_delay_ms(1000);
	Backlight_green();
	_delay_ms(1000);
	Backlight_blue();
	_delay_ms(1000);
	
	while(1)
	{
		Lcd4_Set_Cursor(1,1);
		Lcd4_Write_String("electroSome LCD Hello World");
		for(i=0;i<15;i++)
		{
			_delay_ms(500);
			Lcd4_Shift_Left();
		}
		for(i=0;i<15;i++)
		{
			_delay_ms(500);
			Lcd4_Shift_Right();
		}
		Lcd4_Clear();
		Lcd4_Set_Cursor(2,1);
		Lcd4_Write_Char('e');
		Lcd4_Write_Char('S');
		_delay_ms(2000);
	}
}
