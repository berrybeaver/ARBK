/*
 * Andreas Welly Octavianus_3541951_ARBKVS_Praktikum4.c
 *
 * Created: 09.11.2023 13:46:39
 * Author : welly
 */ 

#include "keys.h"
#include "sevenseg.h"


volatile uint32_t count = 0;
ISR(PCINT0_vect){														//Interrupt Routine
	if(!(PINB & (1<<PINB1))){											//if SW1 pressed
		if(count == 0){
			count =99;
			}else{
			count--;;
		}
	}
	if(!(PINB & (1<<PINB2))){											//if SW2 pressed
		if(count == 99){
			count =0;
			}else{
			count++;
		}
	}
}

/*
	PB0 = a
	PB1 = b
	PB2 = c
	PB3 = d
	PB4 = e
	PB5 = f
	PD0 = g
	PD1 = A
 */

void init(){
	DDRD=0xff;															//PORTD as output
	PORTD=0x00;														
	
	DDRB = 0x01;														//PINB 0 as output and the rest are input
	PORTB = (1<<PINB1)|(1<<PINB2);										//set bit for both inputs
}
	
int main(void)
{
	init();
	init_interrupt();
    while (1) 
    {
		int y = count%10;
		int x = count/10; 
		out(y);
		out(x);
    }
}





