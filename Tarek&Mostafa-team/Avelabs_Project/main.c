/*
 * Avelabs_Project.c
 *
 * Created: 2/13/2019 10:53:23 AM
 * Author : AVE-LAP-016
 */ 

//#include <avr/io.h>
#define F_CPU 16000000u

#include "includes/types.h"
#include "includes/bitwiseOperations.h"
#include "includes/DIO.h"
#include "includes/timer.h"
#include "includes/sevenSeg.h"
#include "includes/keypad.h"
#include "includes/lcd.h"
#include "includes/yes_no_challenge.h"

int main(void)
{
	sint8 questions[5][17] = {"263+142+533=938","(368*5)+47=1888","1631/233*87=609","(952*2)/7=271","657*23*2=302220"};
	uint8 real_answers[5] = {YES,NO,YES,NO,NO};
	uint8 answers[5] ;

	timer_init();
	LCD_init();
	
	
    while (1) 
     {
	   startChallenge(questions, answers ,real_answers);
	   timer_delay(5000);
     }
	return 0 ;
}
ISR()
{
	
}
