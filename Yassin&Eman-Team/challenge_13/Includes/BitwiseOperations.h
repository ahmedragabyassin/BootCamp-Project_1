/*
 * BitwiseOperations.h
 *
 * Created: 2/13/2019 11:18:07 AM
 *  Author: Yassin
 */ 


#ifndef BITWISEOPERATIONS_H_
#define BITWISEOPERATIONS_H_
#include "types.h"
#include "CommonNumbers.h"

/************************************************************************/
/* Bitwise Operations                                                   */
/************************************************************************/
/************************************************************************/
/* SET BIT                                                              */
/************************************************************************/
#define SET_BIT(REG,BIT)   		((REG) = REG|(NUM_1<<BIT))
/************************************************************************/
/* CLEAR BIT                                                            */
/************************************************************************/
#define CLEAR_BIT(REG,BIT) 		((REG) = REG &~(NUM_1<<BIT))
/************************************************************************/
/* RETURN BIT STATUS                                                    */
/************************************************************************/
#define GET_BIT(REG,BIT)		((REG)&((NUM_1<<BIT)))
/************************************************************************/
/* TOGGLE BIT                                                           */
/************************************************************************/
#define TOGGLE_BIT(REG,BIT)		((REG)=((REG)^(NUM_1<<BIT))

#endif /* BITWISEOPERATIONS_H_ */