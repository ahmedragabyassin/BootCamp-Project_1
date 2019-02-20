/*
 * Timer.h
 *
 * Created: 2/13/2019 8:58:43 PM
 *  Author: Ahmed Yassin
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "types.h"
#include "BitwiseOperations.h"

/************************************************************************/
/* Function: Timer Init                                                 */
/* @param: void			                                                */
/* return: void			                                                */
/* Description: initialize timer 		                                */
/************************************************************************/
void TimerInit(void);

/************************************************************************/
/* Function: Timer Init                                                 */
/* @param: n, numer of ms 			                                    */
/* return: void			                                                */
/* Description: delay for n ms			                                */
/************************************************************************/
void TimerDelay(uint32 n);




#endif /* TIMER_H_ */