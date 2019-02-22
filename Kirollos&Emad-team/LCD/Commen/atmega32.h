/*
 * atmega32.h
 *
 * Created: 2/20/2019 5:32:27 PM
 *  Author: AVE-LAP-44
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_
/* GPIO */
#define PORTA_START   0
#define PORTA_END     7  

#define PORTB_START   8
#define PORTB_END     15

#define PORTC_START   16
#define PORTC_END     23

#define PORTD_START   24
#define PORTD_END     31

#define PORTA (*((volatile ptr8)0x3B)) // address of portA (output)
#define DDRA  (*((volatile ptr8)0x3A))//address of ddrA (direction)
#define PINA  (*((volatile ptr8)0x39))//address of pinA	(input)

#define PORTB (*((volatile ptr8)0x38))// address of portB
#define DDRB  (*((volatile ptr8)0x37))//address of ddrB
#define PINB  (*((volatile ptr8)0x36))//address of pinB

#define PORTC (*((volatile ptr8)0x35))// address of portC
#define DDRC  (*((volatile ptr8)0x34))//address of ddrC
#define PINC  (*((volatile ptr8)0x33))//address of pinC

#define PORTD (*((volatile ptr8)0x32))// address of portD
#define DDRD  (*((volatile ptr8)0x31))//address of ddrD
#define PIND  (*((volatile ptr8)0x30))//address of pinD

/* Timer0*/
#define TCCR0 (*((volatile ptr8) 0x53))
#define OCR0  (*((volatile ptr8) 0x5C))
#define TIFR  (*((volatile ptr8)  0x58))
#define TCNT0 (*((volatile ptr8)  0x52))

#endif /* ATMEGA32_H_ */