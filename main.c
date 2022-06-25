#include <xc.h>

// Header file for definitions and a general
// setup function
#include "configBits.h"
#include "delay.h"

int main(){

SETUP:
	// General setup. Included in configBits.c
	setup();

	// CCP1 and CCP2 pin are bits 2-3 of PORTB in 18F4525.
	// You can set them as 1 or 0, but you must set them.
	TRISC = 0b00000000;

	T2CON  = 0X06; // Timer2 ON with preset value of 16
	PR2 = 249; // Frequency of 500MHz

	// Put CCP module into PWM mode
	// CCP1 (pin 17 of 18F4525) and CCP2 (pin 16) will
	// have inverted phase since bit 1 of CCP1CON
	// is set to 1. Set that bit to 0 for having
	// the same phase in both.
	CCP1CON = 0b00001110;
	CCP2CON = 0b00001100;

	// The value in CCPR1L controls the duty cycle of
	// the PWM output. A higher value tranlates to a
	// higher average voltage. In plactiice, you must
	// find the higher and lower values that will serve
	// your means. You may follow the equations on the
	// docs but we perceive brightness in a non-linear
	// way, and different LEDs react differently.
	// For my LED in series with a 330Ohm resistor
	// I found the next aprox. values to controll the
	// brightness (variation above 200 is not perceived)
	//	CCPR1L = 62; // 25%
	//	CCPR1L = 125; // 50%
	//	CCPR1L = 187; // 75%
	//	CCPR1L = 219; // 100%
	
	// Start at 0
	// Both registers will have the same value but CCP1
	// is set for inverted phase: as voltage in CCP1
	// increments, the voltage in CCP2 decrements.
	CCPR1L = CCPR2L = 0;

LOOP:
	while (1){

		// Increase brightness gradually in CCP1
		while (CCPR1L != 254){ // 255 is max value for 8bit registers CCRXL
			CCPR2L = CCPR1L += 2;
			delay_msecs(50); // Defined in delay.h
		}
		// Decrease grightness gradually in CCP1
		while (CCPR1L != 0){
			CCPR2L = CCPR1L -= 2;
			delay_msecs(50);
		}

	}

}
