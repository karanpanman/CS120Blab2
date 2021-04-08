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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	
	unsigned char tmpC; //Hold B
	unsigned char tmpA; //Hold A
	unsigned char tmpB;
	unsigned char tmpD;


    /* Insert your solution below */
    while (1) {

	//read input
	tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;

	tmpD = tmpA + tmpB + tmpC;
	PORTD = tmpD >> 2;

	if( tmpD > 140 ){
		PORTD = PORTD | 0x01;
	}
	else{
		PORTD = PORTD & 0xFE;
	}
	
	if( (tmpA - tmpC) > 80){
		PORTD = PORTD | 0x02;
	}
	else {
		PORTD = PORTD & 0x0D;
	}
	
    }

    return 0;
}
