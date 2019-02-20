/*
 * BCDSevSegment.h
 *
 * Created: 2/18/2019 12:49:36 PM
 *  Author: Yassin
 */ 


#ifndef BCDSEVSEGMENT_H_
#define BCDSEVSEGMENT_H_

#include "../Includes/BCDSevSegment_cfg.h"
#include "../Includes/types.h"
#include "../Includes/Dio.h"
#include "../Includes/BitwiseOperations.h"

/************************************************************************/
/* Function: BCD Seven Segment Enable	                                */
/* @param: PinNum, take the pin to be enabled	                        */
/* Return: return void		                                            */
/* Description: config the pin to be enabled			                */
/************************************************************************/
void BCDSevSegment_Enable(uint8 PinNum);

/************************************************************************/
/* Function: BCD Seven Segment Disable	                                */
/* @param: PinNum take the pin to be configured                         */
/* Return: return void		                                            */
/* Description: config the pin to be disabled			                */
/************************************************************************/
void BCDSevSegment_Disable(uint8 PinNum);

/************************************************************************/
/* Function: BCD Seven Segment Display number	                        */
/* @param: PinNum take the pin to be configured                         */
/* Return: return void		                                            */
/* Description: Display number on seven segment			                */
/************************************************************************/
void BCDSevSegment_DisplayNo(uint8 Num);

#endif /* BCDSEVSEGMENT_H_ */