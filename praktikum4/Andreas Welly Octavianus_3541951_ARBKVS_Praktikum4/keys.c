/*
 * keys.c
 *
 * Created: 09.11.2023 13:59:34
 *  Author: welly
 */ 
#include "keys.h"
volatile uint32_t systemClock=0;
void init_interrupt(){
	cli();
	PCICR = (1<<PCIE0);
	PCMSK0=(1<<PCINT1)|(1<<PCINT2);
	/*timer*/
	TCCR0A = (1<<WGM01); //set CTC(clear timer on compare match) bit
	TCCR0B = (1<<CS00)|(1<<CS01); //prescaler als 64
	OCR0A = 249;		//um 1ms zu erreichen braucht man 250 Ticks in 64 prescale
	TIMSK0 = (1<<OCIE0A);	//Set to use OCR0A as comparison
	sei();
}

void waitFor(uint32_t ms){
	uint32_t endTime = systemClock+ms;
	while(systemClock != endTime){} //to avoid early exit incase overflow
}
ISR(TIMER0_COMPA_vect){
	systemClock++;		//system clock +1 every ms
}

