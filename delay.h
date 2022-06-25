#ifndef DELAY_H
#define DELAY_H

// Do nothing for the milliseconds passed as argument
// This function assumes that you set:
// OSCCON = 0b01110100; // Internal oscillator (INTIO67) to 8MHz stable.
// T0CON = 0X87; // TMR0 on, 16bit with max divide rate freq of 7812.5Hz: one tick takes 128 microsecs.
void delay_msecs(int msecs);

#endif
