#include <xc.h>
#include "configBits.h"

void setup(){
	// Set all port bits to LOW by default
	PORTA = 0b00000000;
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;
	PORTE = 0;

	// Set all 8 bits of PORTX as output (1-0xFF) or input (0);
	TRISA = 0b00000000;
	TRISB = 0;
	TRISC = 0;
	TRISD = 0;
	TRISE = 0;

	// Turn off ADC
	ADCON0 = 0b00000000;

	// Bits 0-4 of ADCON1 define which bits will be
	// analog (0) or digital (1) (see table)
	// Set all digital.
	ADCON1 = 0b00001111;
	
	OSCTUNE = 0; // Do not care about temp changes
	OSCCON = 0b01110100; // Set internal oscillator (INTIO67) to 8MHz stable.
	T0CON = 0X87; // Set TMR0 on, 16bit with max divide rate freq of 7812.5Hz: one tick takes 128 microsecs.
}
