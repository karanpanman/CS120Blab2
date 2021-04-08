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
	DDRB = 0xFF; PORTB = 0x00;
	
	unsigned char tmpB = 0x00; //Hold B
	unsigned char tmpA = 0x00; //Hold A

    /* Insert your solution below */
    while (1) {
	//read input
	tmpA = PINA & 0x03;
	
	if (tmpA == 0x00){
		tmpB = 0x00; //sets tmpB to bbbbbb01
	}
	else if (tmpA == 0x01){
		tmpB = 0x01; //sets tmpB to bbbbbb10
	}
	else if (tmpA == 0x02){
		tmpB = 0x00;
	}
	else if (tmpA == 0x03){
		tmpB = 0x00;
	}
	
	PORTB = tmpB;
    }

    return 0;
}
