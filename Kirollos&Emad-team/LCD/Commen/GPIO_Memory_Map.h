#ifndef GPIO_MAP_H
#define GPIO_MAP_H

#define PORTA (*((volatile ptr8)0x3B)) // address of portA (output)
#define DDRA  (*((volatile ptr8)0x3A))//address of ddrA (direction)
#define PINA  (*((volatile ptr8)0x39))//address of pinA	(input)

#define PINA0  0
#define PINA1  1
#define PINA2  2
#define PINA3  3
#define PINA4  4
#define PINA5  5
#define PINA6  6
#define PINA7  7

#define PORTB (*((volatile ptr8)0x38))// address of portB
#define DDRB  (*((volatile ptr8)0x37))//address of ddrB
#define PINB  (*((volatile ptr8)0x36))//address of pinB


#define PINB0  8
#define PINB1  9
#define PINB2  10
#define PINB3  11
#define PINB4  12
#define PINB5  13
#define PINB6  14
#define PINB7  15

#define PORTC (*((volatile ptr8)0x35))// address of portC
#define DDRC  (*((volatile ptr8)0x34))//address of ddrC
#define PINC  (*((volatile ptr8)0x33))//address of pinC

#define PINC0  16
#define PINC1  17
#define PINC2  18
#define PINC3  19
#define PINC4  20
#define PINC5  21
#define PINC6  22
#define PINC7  23

#define PORTD (*((volatile ptr8)0x32))// address of portD
#define DDRD  (*((volatile ptr8)0x31))//address of ddrD
#define PIND  (*((volatile ptr8)0x30))//address of pinD

#define PIND0  24
#define PIND1  25
#define PIND2  26
#define PIND3  27
#define PIND4  28
#define PIND5  29
#define PIND6  30
#define PIND7  31

#define TCCR0 (*((volatile ptr8) 0x53))
#define OCR0  (*((volatile ptr8) 0x5C))
#define TIFR  (*((volatile ptr8)  0x58))
#define TCNT0 (*((volatile ptr8)  0x52))



#endif
