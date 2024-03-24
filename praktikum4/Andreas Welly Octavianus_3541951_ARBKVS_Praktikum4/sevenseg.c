/*
 * sevenseg.c
 *
 * Created: 09.11.2023 13:58:54
 *  Author: welly
 */ 
#include "sevenseg.h"
#include "keys.h"

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

	
int number[10] ={ 64, 121, 36, 48, 25, 18, 2, 120, 0, 16};
	
void out(int x){
	PORTD = number[x];
	//_delay_ms(10);
	waitFor(10);
	PORTB ^= (1<<PINB0);
}