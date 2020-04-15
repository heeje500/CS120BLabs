/*	Author: hlee272
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tmpA = 0x00;
	unsigned char cntavail = 0x00;
	unsigned char i;
	unsigned char tmpB = 0x00; 
    /* Insert your solution below */
	
    while (1) {
	cntavail = 0x00;
	tmpA = PINA & 0x0F; //reads all four bits

	for (i = 0; i < 4; i++) {
		if((tmpA & (0x01 << i)) !=0 ) {
			cntavail++;
	}
	tmpB = 4 - cntavail;
	}
	if (PINA == 0x0F) {
		tmpB = 0x8F;
	}
	PORTC = tmpB;
}

return 1;
}
