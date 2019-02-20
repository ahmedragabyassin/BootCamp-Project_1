/*
 * MemMapReg.h
 *
 * Created: 2/19/2019 5:09:40 PM
 *  Author: Yassin
 */ 


#ifndef MEMMAPREG_H_
#define MEMMAPREG_H_
#include "types.h"

/************************************************************************/
/* Mapping PORTS Registers                                              */
/************************************************************************/
#define PORTA			(*(volatile uint8 *)(0x3B))
#define PORTB			(*(volatile uint8 *)(0x38))
#define PORTC			(*(volatile uint8 *)(0x35))
#define PORTD			(*(volatile uint8 *)(0x32))


/************************************************************************/
/* Mapping Direction Registers                                          */
/************************************************************************/
#define DDRA			(*(volatile uint8 *)(0x3A))
#define DDRB			(*(volatile uint8 *)(0x37))
#define DDRC			(*(volatile uint8 *)(0x34))
#define DDRD			(*(volatile uint8 *)(0x31))

/************************************************************************/
/* Mapping PIN Registers                                                */
/************************************************************************/
#define PINA			(*(volatile uint8 *)(0x39))
#define PINB			(*(volatile uint8 *)(0x36))
#define PINC			(*(volatile uint8 *)(0x33))
#define PIND			(*(volatile uint8 *)(0x30))



#endif /* MEMMAPREG_H_ */