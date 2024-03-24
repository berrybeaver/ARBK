/*
 * Andreas Welly Octavianus_3541951_ARBKVS_Praktikum2.c
 *
 * Created: 30.10.2023 20:40:45
 * Author : welly
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "avr/interrupt.h"
volatile int on = 0;
//volatile int off = 0;
volatile int blink = 0;

void init(){
	DDRD=0x00;					//DDRD als Input, PORTD als input PD2 zu SW1 und PD3 zu SW2
	PORTD=0xff;
	
	DDRB=0xff;					//DDRB als output, PORTB als output PB0 zu D0 und PB1 zu D9
	PORTB=0x00;
}
void init_timer(){
	cli();							//clear interrupt flag
	EICRA = (1<<ISC11)|(1<<ISC01);	//set the control on INT0 & INT1 to falling edge->generate interrupt
	EIMSK = (1<<INT0)|(1<<INT1);	//enable external interrupt from INT0&INT1
	sei();							//set global interrupt flag
}
ISR(INT0_vect){					//ISR for pd2
	if(PINB & (1<<PINB0)){			//if D0 ON -> blink
		blink ^=1;
	}else{					//if D0 OFF -> ON
		PORTB = (1<<PORTB0);
	}
	on = PORTB0;
}
ISR(INT1_vect){				//ISR for pd3
	if(PINB & (1<<PINB1)){		//if D9 ON -> blink
		blink ^=1;
	}else{					//if D9 OFF->ON
		PORTB = (1<<PORTB1);
	}
	on = PORTB1;
}
int main(void)
{
	init();
	init_timer();
	
	while (1)
	{	
		if(blink==1){
			PORTB ^= 1<<on;
		}else{
			PORTB = 1<<on;
		}
		_delay_ms(200);
	}
}