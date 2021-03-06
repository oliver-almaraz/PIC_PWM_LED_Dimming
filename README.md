# PIC_PWM_LED_Dimming
Dimm two LEDs with inverted phase using PWM pins of a PIC18F4525 MCU.
This function works in a similar way as `analogWrite()` in Arduino.

PIC18F4525 MCU has two ports capable of generating PWM output: CCP1 (pin 17) and CCP2 (pin 16) which can be used independently.
Here, I use them both at the same time in inverted phase mode to control the brightness of two LED's simultaneously in an infinite loop:
while the average voltage at CCP1 increments, the average voltage at CCP2 decrements and vice versa.

This code assumes that your timer settings are:
```
OSCCON = 0b01110100; // Internal oscillator (INTIO67) to 8MHz stable.
T0CON = 0X87; // TMR0 on, 16bit with max divide rate freq of 7812.5Hz
```

For the complete configuration I used, see header files.

## Bonus:
A function similar to `delay()` in arduino and a Makefile for [compiling from the command line without MPLAB X IDE](https://github.com/oliver-almaraz/PIC_display_binary_leds#compiling-with-mplab--xc8-using-only-the-command-line-interface).

All code is C.
