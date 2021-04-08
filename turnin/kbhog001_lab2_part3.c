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
	
	unsigned char tmpC; //Hold B
	unsigned char tmpA; //Hold A
	unsigned char tmpB;
	unsigned char tmpD;
	unsigned char cntavail = 0x00;

    /* Insert your solution below */
    while (1) {
	cntavail = 0x00;
	//read input
	tmpA = PINA & 0x01;
	tmpB = PINA & 0x02;
	tmpC = PINA & 0x04;
	tmpD = PINA & 0x08;

	if (tmpA != 0x01){
		cntavail = cntavail + 1;
	}
	if (tmpB != 0x02){
		cntavail = cntavail + 1;
	}
	if (tmpC != 0x04){
		cntavail = cntavail + 1;
	} 
	if (tmpD != 0x08){
		cntavail = cntavail + 1;
	}
	
	PORTC = cntavail;
	
	if(cntavail == 0){
        PORTC = PORTC | 0x80;
        }
    }

    return 0;
}
