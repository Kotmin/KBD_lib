/*
 * my_keyboard_lib.c
 *
 * Created: 23.10.2022 20:54:37
 *  Author: ADMIN
 */ 

#include "my_keyboard_lib.h"


static volatile uint8_t key_code;


const uint8_t kolumny [] PROGMEM = {16,32,64,128 };

const uint8_t tab [] PROGMEM = {
								1,2,3,4,
								5,6,7,8,
								9,10,11,12,
								13,14,15,16,
								0};

void set_DDR(char port_name){
	switch(port_name){
		case 'A':
		DDRA = 0xF0;
		PORTA=0xFF;
		
		break;
		case 'B':
		DDRB = 0xF0;
		PORTB=0xFF;
		
		break;
		case 'C':
		DDRC = 0xF0;
		PORTC=0xFF;
		
		break;
		
		case 'D':
		DDRD = 0xF0;
		PORTD=0xFF;
		
		break;

	}
	

}

int8_t get_key(const char typ, const char port_name)
{	int port,dir;
	
	switch(port_name)
	{
		case 'A':
		port=PINA;
		dir=DDRA;
		break;
		
		case 'B':
		port=PINB;
		dir=DDRB;
		break;
		
		case 'C':
		port=PINC;
		dir=DDRC;
		break;
		
		case 'D':
		port=PIND;
		dir=DDRD;
		break;
	}
	
	if (typ=='M' || typ=='m')
		{
		int8_t temp = 0x0F & port;
				temp =  translate(temp);
				if(temp !=16)
					return temp;
		}
	/*
	if (typ=='M' || typ=='m'){
		int8_t temp = 0x0F & port;
		return translate(temp);
	}
	
	
	if (typ=='M' || typ=='m')
	{
		switch(pin):
		case 0x11101110:
			return 1;
		break;
		case 0x11101101:
		return 2;
		break;
		case 0x11101011;
		return 3;
		break;
		case 0x11100111:
		return 4;
		break;
	}
	*/
			static uint8_t licznik; //nr_kolumny tez inaczej
		for(int i=0;i<8;i++)
		{
		
		uint8_t pin =  PINA | 0xF0;
		
		
		if (pin < 255) //cos wcisniete
		{
			
			return  (translate(pin)+1 + 4*licznik); //mo¿e nawet berz tego translate()
				
			
		}

		

		_delay_ms(50);
		if(++licznik > 3) licznik =0;
		uint8_t out = pgm_read_byte ( &kolumny [ licznik ] );
		

		dir = out;	
		port = ~out;
		}
		 // to teoretycznie powinno nam rozwiazywac problem hipotetycznego zwarcia
		
		//dla malej 4x1
		//dir = (dir & 0xEF ) | out;
		//port = (port & 0xEF) | (~out & 0x10 );
		
		
		
	}


int8_t translate(int8_t key_code){
	
	switch(key_code)
	{
		case 0b00001110:
			return 0;
		case 0b00001101:
			return 1;
		case 0b00001011:
			return 2;
		case 0b00000111:
			return 3;
		default:
			return 16;
	}
	return 16;
	
}