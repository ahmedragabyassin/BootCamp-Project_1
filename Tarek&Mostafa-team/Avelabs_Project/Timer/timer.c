/*
 * timer.c
 *
 * Created: 2/14/2019 9:28:36 AM
 *  Author: AVE-LAP-016
 */ 
#include "../includes/timer.h"

void timer_init(void)
{
	TCNT0 = 0 ;
	OCR0 = 249 ;
	TIFR = (1<<OCF0) ;
	TCCR0 = (1<<CS0)|(1<<CS1)|(1<<WGM1) ;
	
}

void timer_delay(uint32 n)
{
	TCNT0 = 0 ;
	for (uint16 i = 0 ; i < n ; i++)
	{
	  // count one millisecond
      while(Get_Bit(TIFR,OCF0) == 0 );
      // clear the OC flag to be ready for another millisecond
      TIFR = (1<<OCF0) ;
	}
	
		
}