/*
 * Matrix_kbd_lib.c
 *
 * Created: 23.10.2022 20:53:07
 * Author : ADMIN
 */ 

#include <avr/io.h>



#include "my_keyboard_lib.h"

int main(void)
{
    /* Replace with your application code */
	
	
	DDRA =0xF0;
	PORTA = 0x0F;
	
	//set_DDR('A');
	//Ledy
	DDRB =0xFF;
	PORTB =0xFF;
	// ja wiem ze te literki chwilowo nic nie zmieniaja
    while (1) 
    {
		PORTB = get_key('D', 'A');
    }
}

