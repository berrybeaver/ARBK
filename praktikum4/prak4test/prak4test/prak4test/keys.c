/*
 * keys.c
 *
 * Created: 03.12.2023 14:06:14
 *  Author: welly
 */ 
#include "keys.h"

void init_interrupt(){
	cli();							//clear interrupt flag
	EICRA = (1<<ISC11)|(1<<ISC01);	//set the control on INT0 & INT1 to falling edge->generate interrupt
	EIMSK = (1<<INT0)|(1<<INT1);	//enable external interrupt from INT0&INT1
	sei();							//set global interrupt flag
}
