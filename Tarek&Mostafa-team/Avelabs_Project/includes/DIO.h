/*
 * DIO.h
 *
 * Created: 2/13/2019 3:09:01 PM
 *  Author: AVE-LAP-016
 */ 


#ifndef MEMORY_MAPPED_REGISTERS_H_
#define MEMORY_MAPPED_REGISTERS_H_
#include "../includes/types.h"
#include "../includes/bitwiseOperations.h"
#include "../includes/DIO_Config.h"
#define INPUT 0
#define OUTPUT 1
#define OFF 0
#define ON 1
#define LOW 0 
#define HIGH 1

#define PINA *((volatile uint8*) (0x39)) 
#define PINB *((volatile uint8*) (0x36)) 
#define PINC *((volatile uint8*) (0x33))
#define PIND *((volatile uint8*) (0x30))

#define DDRA *((volatile uint8*) (0x3a)) 
#define DDRB *((volatile uint8*) (0x37))
#define DDRC *((volatile uint8*) (0x34))
#define DDRD *((volatile uint8*) (0x31)) 

#define PORTA *((volatile uint8*) (0x3b)) 
#define PORTB *((volatile uint8*) (0x38))
#define PORTC *((volatile uint8*) (0x35)) 
#define PORTD *((volatile uint8*) (0x32)) 



void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);




#endif /* MEMORY_MAPPED_REGISTERS_H_ */