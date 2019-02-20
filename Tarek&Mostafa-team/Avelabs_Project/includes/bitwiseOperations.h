/*
 * bitwiseOperations.h
 *
 * Created: 2/13/2019 11:37:54 AM
 *  Author: AVE-LAP-016
 */ 


#ifndef BITWISEOPERATIONS_H_
#define BITWISEOPERATIONS_H_
#include "types.h"

#define Set_Bit(Register,Bit)    ( Register |= (uint8)(1<<Bit) )
#define Clear_Bit(Register,Bit)  (Register &= ~(uint8)(1<<Bit))
#define Get_Bit(Register,Bit)    ( (uint8)(Register & (uint8)(1<<Bit)) >> Bit )
#define Toggle_Bit(Register,Bit) (Register ^= (uint8)(1<<Bit))


#endif /* BITWISEOPERATIONS_H_ */