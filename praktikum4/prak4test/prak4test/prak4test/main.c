/*
 * prak4test.c
 *
 * Created: 03.12.2023 14:05:48
 * Author : welly
 */ 

#include "keys.h"
#include "sevenseg.h"

volatile uint32_t count = 0;
ISR(INT0_vect) { // SW1
	if (count == 0) {
		count = 99;
	}
	else {
		count--;
	}
}

ISR(INT1_vect) { // SW2
	if (count == 99) {
		count = 0;
	}
	else {
		count++;
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
	
	DDRD = 0b00000011; // PD2 & PD3 as input, PD0 & PD1 as output
	PORTD = (1<<PIND2)|(1<<PIND3); // Enable pull-up resistors for PD2&PD3
	DDRB = 0xff; //PB AS OUTPUT
}

int main(void)
{
    init();
    init_interrupt();
    while (1)
    {
	    int y = count%10; //xy
	    int x = count/10;	//xy
	    out(y);
	    out(x);
    }
}



