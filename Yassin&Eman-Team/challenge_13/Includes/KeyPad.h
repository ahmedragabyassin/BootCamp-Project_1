/*
 * KeyPad.h
 *
 * Created: 2/18/2019 2:58:25 PM
 *  Author: Yassin
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "KeyPad_cfg.h"
#include "Dio.h"
#include "BitwiseOperations.h"
#include "types.h"
#include "CommonNumbers.h"
#include "CommonDefinations.h"
#include "CommonDelays.h"




/************************************************************************/
/* Function: KeyPad Init                                                */
/* @param: void			                                                */
/* return: void			                                                */
/* Description: Initialize  keypad pins directions                      */
/************************************************************************/
void KeyPad_Init(void);

/************************************************************************/
/* Function: KeyPad Get Pressed Key                                     */
/* @param: void					                                        */
/* @return: return number detected                                      */
/* Description: Detect pressed key and return its value                 */
/************************************************************************/
uint8 KeyPad_GetPressedKey(void);

#endif /* KEYPAD_H_ */