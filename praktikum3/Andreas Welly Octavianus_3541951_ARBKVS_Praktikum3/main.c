/*
 * Andreas Welly Octavianus_3541951_ARBKVS_Praktikum3.c
 *
 * Created: 06.11.2023 14:09:01
 * Author : welly
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "avr/interrupt.h"

volatile uint32_t systemClock = 0;

void init(){
	DDRD = 0x03;		// output setzen
	PORTD = 0x00;
}
void init_timer(){
	TCCR0A = (1<<WGM01); //set CTC(clear timer on compare match) bit
	TCCR0B = (1<<CS00)|(1<<CS01); //prescaler als 64
	OCR0A = 250;		//um 1ms zu erreichen braucht man 250 Ticks in 64 prescale
	TIMSK0 = (1<<OCIE0A);	//Set to use OCR0A as comparison
	sei();
}

void waitFor(uint32_t ms){
	uint32_t endTime = systemClock+ms;
	while(systemClock != endTime){} //to avoid early exit incase overflow
}

void waitUntil(uint32_t ms){
	while(systemClock <= ms){}
}

int main(void)
{
	init();
	init_timer();
	PORTD = (1<<PORTD1);
	waitUntil(2000);
	PORTD ^= (1<<PORTD1);
	while(1){
		waitFor(500);
		PORTD ^= (1<<PORTD0);
	}
}

ISR(TIMER0_COMPA_vect){
	systemClock++;		//systemclock +1 every ms
}



