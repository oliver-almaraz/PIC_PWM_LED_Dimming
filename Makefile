CC = xc8-cc # Compiler must be in yout path. Otherwise, add an absolute path to it
FLAGS = -mcpu=18f4525 -O2 #-O<n> sets the optimization level

all: main.p1 configBits.p1 delay.p1
	$(CC) $(FLAGS) main.p1 configBits.p1 delay.p1 -o PIC_PWM_LED_Dimming.hex
main.p1: main.c configBits.h delay.h
	$(CC) $(FLAGS) -c main.c
configBits.p1: configBits.c
	$(CC) $(FLAGS) -c configBits.c
delay.p1: delay.c
	$(CC) $(FLAGS) -c delay.c -c
clean:
	rm *.lst *.rlf *.cmf *.d *.elf *.hxl *.o *.p1 *.s *.sdb *.sym
