/*
 * BCDSevSegment.c
 *
 * Created: 2/18/2019 12:49:14 PM
 *  Author: Yassin
 */ 
#include "../Includes/BCDSevSegment.h"

/************************************************************************/
/* Function: BCD Seven Segment Enable	                                */
/* @param: PinNum, take the pin to be enabled	                        */
/* Return: return void		                                            */
/* Description: config the pin to be enabled			                */
/************************************************************************/
void BCDSevSegment_Enable(uint8 PinNum)
{
	DIO_SetPinDirection(PinNum,OUT);
	DIO_WritePin(PinNum,HIGH);
}

/************************************************************************/
/* Function: BCD Seven Segment Disable	                                */
/* @param: PinNum take the pin to be configured                         */
/* Return: return void		                                            */
/* Description: config the pin to be disabled			                */
/************************************************************************/
void BCDSevSegment_Disable(uint8 PinNum)
{
	DIO_SetPinDirection(PinNum,OUT);
	DIO_WritePin(PinNum,LOW);
}

/************************************************************************/
/* Function: BCD Seven Segment Display number	                        */
/* @param: PinNum take the pin to be configured                         */
/* Return: return void		                                            */
/* Description: Display number on seven segment			                */
/************************************************************************/
void BCDSevSegment_DisplayNo(uint8 Num)
{
	DIO_WritePin(SEGMENT_A,(GET_BIT(Num,SEG_BIT0)>>SEG_BIT0)); /* Write status of bit0 on SEGMENT_A */
	DIO_WritePin(SEGMENT_B,(GET_BIT(Num,SEG_BIT1)>>SEG_BIT1)); /* Write status of bit1 on SEGMENT_B */
	DIO_WritePin(SEGMENT_C,(GET_BIT(Num,SEG_BIT2)>>SEG_BIT2)); /* Write status of bit2 on SEGMENT_C */
	DIO_WritePin(SEGMENT_D,(GET_BIT(Num,SEG_BIT3)>>SEG_BIT3)); /* Write status of bit3 on SEGMENT_D */
}


