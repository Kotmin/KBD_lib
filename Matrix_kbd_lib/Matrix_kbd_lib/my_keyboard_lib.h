/*
 * my_keyboard_lib.h
 *
 * Created: 23.10.2022 20:53:49
 *  Author: ADMIN
 */ 


#ifndef MY_KEYBOARD_LIB_H_
#define MY_KEYBOARD_LIB_H_

#define F_CPU 1600000UL

#include <avr/io.h>
#include <avr/pgmspace.h>

#include <util/delay.h>






int8_t get_key(const char typ, const char port_name);
void set_DDR(char port_name);

int8_t translate(int8_t key_code);


#endif /* MY_KEYBOARD_LIB_H_ */