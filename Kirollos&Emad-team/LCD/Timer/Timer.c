#include "Timer.h"
#include <stdint.h>
#include <avr\interrupt.h>
 
 uint32 counter=0;
void timer_mdelay(uint32 n){
	uint32 i=0;
	TCCR0=0;
	OCR0=250;
	TCCR0=0b10001011;
	TCNT0=0;
	for(;i<n;i++){
		while(!Get_Bit(TIFR,BIT1)){}
			Set_Bit(TIFR,BIT1);
			
}
	}
	void timer_mdelay_interrupt(uint32 n){
		uint32 i=0;
		TCCR0=0;
		OCR0=250;
		counter=n;
		Set_Bit(TIMSK,BIT1);
		sei();
		
		TCNT0=0;
		TCCR0=0b10001011;
		while(counter){};
		
		
		
		
			
		
	}
void timer_udelay(uint32 n){
	TCCR0=0;
	OCR0=16;
	uint32 i=0;
	TCCR0=0b10001001;
	TCNT0=0;
	
	for(;i<n;i++){
		while(!Get_Bit(TIFR,BIT1)){}
			Set_Bit(TIFR,BIT1);
}
	}
void timer_init(){
	
	OCR0=250;
	TCCR0=0b10001011;
	
	
	
	
	
}
ISR(TIMER0_COMP_vect){
	
	counter--;

	
	
}