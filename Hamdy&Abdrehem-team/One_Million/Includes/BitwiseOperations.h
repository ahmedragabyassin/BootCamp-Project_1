/*
 * BitwiseOperations.h
 *
 * Created: 2/13/2019 11:15:18 AM
 *  Author: Ahmed Abdlrehem
 */ 


#ifndef BITWISEOPERATIONS_H_
#define BITWISEOPERATIONS_H_
/* Set bit in any Register  */
#define Set_Bit(Register,Bit)      Register|=(1<<Bit)
/* Clear bit in any Register  */
#define Clear_Bit(Register,Bit)    Register&= ~(1<<Bit)
/* Get bit in any Register  */
#define Get_Bit(Register,Bit)  (((uint8)Register&(1<<Bit))>>Bit)
/* Toggle bit in any Register  */
#define Toggle_Bit(Register,Bit)   Register^=(1<<Bit)




#endif /* BITWISEOPERATIONS_H_ */