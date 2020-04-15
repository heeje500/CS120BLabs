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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;

	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00; 
    /* Insert your solution below */
	
    while (1) {
	unsigned char totalweight;
	unsigned char lighterweight;
	unsigned char heavierweight;
	
	totalweight = tmpA + tmpB + tmpC; 
	tmpD = totalweight;
		
	tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC; //reads all 8 bits


	if (tmpA > tmpC) { 
		lighterweight = tmpC;
		heavierweight = tmpA; 
}
	else {
		lighterweight = tmpA;
		heavierweight = tmpC;
	}

	if (totalweight > 0x8C) {
		tmpD = tmpD | 0x01; // sets PD0 to 1

}	else {
		tmpD = tmpD & ~(0x01);
	}
	
	if ((heavierweight - lighterweight) > 0x50) {
		tmpD =tmpD | 0x02;
		PORTD = tmpD;
}
	else {
		tmpD = tmpD & ~(0x02);
	}
	PORTD = tmpD;
}

return 1;
}
