/*
 * Challenge.h
 *
 * Created: 2/20/2019 2:03:46 PM
 *  Author: Yassin
 */ 


#ifndef CHALLENGE_H_
#define CHALLENGE_H_
#include "ChallengeCommonDef.h"
#include "Lcd.h"
#include "Dio.h"
#include "types.h"
#include "CommonDefinations.h"
#include "CommonNumbers.h"

#ifndef F_CPU
#include <util/delay.h>
#define F_CPU 16000000UL
#endif




/************************************************************************/
/* Function: Challenge                                                  */
/* @param: Void			                                                */
/* return: void			                                                */
/* Description: function display questions on LCD and handle the case   */
/*				and score of the player then display it on LCD          */
/************************************************************************/
void Challenge(void);
/************************************************************************/
/* Function: Display LEDs                                               */
/* @param: void			                                                */
/* return: void										                    */
/* Description: Display LEDs in a sequence                              */
/************************************************************************/
void Display_Leds(void);



#endif /* CHALLENGE_H_ */