# PIC_PWM_LED_Dimming
Dimm two LEDs with inverted phase using PWM pins of a PIC18F4525 MCU.
This function works in a similar way as `analogWrite()` in Arduino.

This code assumes that your timer settings are:
```
OSCCON = 0b01110100; // Internal oscillator (INTIO67) to 8MHz stable.
T0CON = 0X87; // TMR0 on, 16bit with max divide rate freq of 7812.5Hz
```

For the complete configuration I used, see header files.

Bonus: a function similar to delay()` in arduino.

All code is C.
