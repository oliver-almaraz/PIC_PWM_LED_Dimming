#include <xc.h>
#include "delay.h"

void delay_msecs(int msecs){
	// For the milliseconds passed as argument
	for (int i=0; i < msecs; i++){
		TMR0 = 0;
		// Do nothing for aprox one msec. assuming:
		// OSCCON = 0b01110100; 
		// T0CON = 0x87;
		while (TMR0 < 7);
	}
}

