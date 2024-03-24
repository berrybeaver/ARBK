/*
 * sevenseg.c
 *
 * Created: 03.12.2023 14:06:50
 *  Author: welly
 */ 
#include "sevenseg.h"

/*
  gfe dcba
0:100 0000 = 64
1:111 1001 = 121
2:010 0100 = 36
3:011 0000 = 48
4:001 1001 = 25
5:001 0010 = 18
6:000 0010 = 2
7:111 1000 = 120
8:000 0000 = 0
9:001 0000 = 16
*/

int numberb[10]={0, 57, 36, 48, 25, 18, 2, 56, 0, 32};
int numberd[10]={1, 1, 0, 0, 0, 0, 0, 1, 0, 0};
	

	
void out(int x){
	PORTB = numberb[x];
	PORTD = numberd[x];
	_delay_ms(20);
	//PORTB ^= (1<<PINB0);
	PORTD ^=(1<<PIND1);
}