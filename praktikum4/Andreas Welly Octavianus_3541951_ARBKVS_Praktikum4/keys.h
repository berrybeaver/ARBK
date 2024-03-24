/*
 * keys.h
 *
 * Created: 09.11.2023 13:59:45
 *  Author: welly
 */ 
#include "avr/interrupt.h"
#include <avr/io.h>

#ifndef KEYS_H
#define KEYS_H
	void init_interrupt();	
	void waitFor(uint32_t ms);
#endif
