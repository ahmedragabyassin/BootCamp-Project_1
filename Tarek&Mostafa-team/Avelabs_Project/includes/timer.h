/*
 * timer.h
 *
 * Created: 2/14/2019 9:29:02 AM
 *  Author: AVE-LAP-016
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "types.h"
#include "bitwiseOperations.h"

#define TCCR0 *((volatile uint8*) (0x53))
#define TCNT0 *((volatile uint8*) (0x52))
#define OCR0  *((volatile uint8*) (0x5C))
#define TIFR  *((volatile uint8*) (0x58))
#define OCF0 1
#define CS0 0
#define CS1 1
#define CS2 2
#define WGM1 3
#define WGM0 0
#define ONE_SECOND 1000 // 1000 milliseconds
void timer_init(void);

void timer_delay(uint32 n);


#endif /* TIMER_H_ */