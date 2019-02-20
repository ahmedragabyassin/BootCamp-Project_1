/*
 * Dio.h
 *
 * Created: 2/13/2019 2:06:29 PM
 *  Author: Yassin
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "CommonDefinations.h"
#include "CommonDelays.h"
#include "CommonNumbers.h"
#include "types.h"
#include "Dio_cfg.h"

/************************************************************************/
/* Definition to direction of pins                                      */
/************************************************************************/
#define IN				NUM_0
#define OUT				NUM_1

/************************************************************************/
/* Definition to status of pin                                          */
/************************************************************************/
#define HIGH			NUM_1
#define LOW				NUM_0			


/************************************************************************/
/* Function: DIO Write Pin	                                            */
/* @param: PinNum take the pin to be configured                         */
/* @param: PinValue take the Value to write on the PinNum               */
/* Return: return void		                                            */
/* Description: config the pin to be high or low		                */
/************************************************************************/
void DIO_WritePin(uint8 PinNum, uint8 PinValue);

/************************************************************************/
/* Function: DIO Read Pin	                                            */
/* @param: PinNum take the pin we need to return its value              */
/* Return: return status of the pin		                                */
/* Description: return pin status			      		                */
/************************************************************************/
uint8 DIO_ReadPin(uint8 PinNum);

/************************************************************************/
/* Function: DIO Set Pin Direction	                                    */
/* @param: PinNum take the pin to be configured                         */
/* @param: PinValue take the Value to write on the PinNum               */
/* Return: return void		                                            */
/* Description: config the pin to be input or output	                */
/************************************************************************/
void DIO_SetPinDirection(uint8 PinNum, uint8 PinValue);


#endif /* DIO_H_ */