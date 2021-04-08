/*	Author: kbhog001
 *  Partner(s) Name: 
 *	Lab Section:21
 *	Assignment: Lab #2  Exercise #Prelab
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
	
	unsigned char tmpC = 0x00; //Hold B
	unsigned char tmpA = 0x00; //Hold A
	unsigned char cntavail = 0x00;

    /* Insert your solution below */
    while (1) {
	//read input
	tmpA = PINA & 0x0F;
	
	unsigned int i;
	unsigned char temp = 0x00;

	for (i = 0; i < 4; i++){
		temp = 0x01 & tmpA;
		if ( temp == 0x00 ){
			cntavail = cntavail + 0x01;
		}
		tmpA = tmpA >> 1;
	}
	cntavail = cntavail & 0x0F;
	
	
	
	PORTC = cntavail;
    }

    return 0;
}
