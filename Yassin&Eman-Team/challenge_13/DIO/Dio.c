/*
 * Dio.c
 *
 * Created: 2/13/2019 2:34:51 PM
 *  Author: Yassin
 */ 
#include "../Includes/Dio.h"
#include "../Includes/types.h"
#include "../Includes/BitwiseOperations.h"
#include "../Includes/MemMapReg.h"

/************************************************************************/
/* Function: DIO Write Pin	                                            */
/* @param: PinNum take the pin to be configured                         */
/* @param: PinValue take the Value to write on the PinNum               */
/* Return: return void		                                            */
/* Description: config the pin to be high or low		                */
/************************************************************************/
void DIO_WritePin(uint8 PinNum, uint8 PinValue)
{
	if((PinNum >= NUM_0) && (PinNum < NUM_8))/*check if Pins in PORTA*/
	{
		if (PinValue == NUM_1) /* Check Pin Value if high to set bit or low to clear bit */
		{
			SET_BIT(PORTA,PinNum);
		}
		else
		{
			CLEAR_BIT(PORTA,PinNum);
		}
	}
	else if ((PinNum >= NUM_8) && (PinNum < NUM_16)) /*check if Pins in PORTB*/
	{
		if (PinValue == NUM_1) /* Check Pin Value if high to set bit or low to clear bit */
		{
			SET_BIT(PORTB,(PinNum - NUM_8));
		}
		else
		{
			CLEAR_BIT(PORTB,(PinNum - NUM_8));
		}
	}
	else if((PinNum >= NUM_16) && (PinNum < NUM_24)) /*check if Pins in PORTC*/
	{
		if(PinValue == NUM_1) /* Check Pin Value if high to set bit or low to clear bit */
		{
			SET_BIT(PORTC,(PinNum-NUM_16));
		}
		else
		{
			CLEAR_BIT(PORTC,(PinNum-NUM_16));
		}
	}
	else if((PinNum >= NUM_24) && (PinNum < NUM_32)) /*check if Pins in PORTD*/
	{
		if (PinValue == NUM_1) /* Check Pin Value if high to set bit or low to clear bit */
		{
			SET_BIT(PORTD,(PinNum-NUM_24));
		}
		else
		{
			CLEAR_BIT(PORTD,(PinNum-NUM_24));
		}
	}
}

/************************************************************************/
/* Function: DIO Read Pin	                                            */
/* @param: PinNum take the pin we need to return its value              */
/* Return: return status of the pin		                                */
/* Description: return pin status			      		                */
/************************************************************************/
uint8 DIO_ReadPin(uint8 PinNum)
{
		if((PinNum >= NUM_0) && (PinNum < NUM_8)) /*check if Pins in PORTA*/
		{
			return GET_BIT(PINA,PinNum); /* Return Bit status*/
		}
		else if((PinNum >= NUM_8) && (PinNum < NUM_16)) /*check if Pins in PORTB*/
		{
			return GET_BIT(PINB,(PinNum-NUM_8));
		}
		else if((PinNum >= NUM_16) && (PinNum < NUM_24)) /*check if Pins in PORTC*/
		{
			return GET_BIT(PINC,(PinNum-NUM_16));
		}
		else if((PinNum >= NUM_24) && (PinNum < NUM_32)) /*check if Pins in PORTD*/
		{
			return GET_BIT(PIND,(PinNum-NUM_24));
		}
	return NUM_0;
}


/************************************************************************/
/* Function: DIO Set Pin Direction	                                    */
/* @param: PinNum take the pin to be configured                         */
/* @param: PinValue take the Value to write on the PinNum               */
/* Return: return void		                                            */
/* Description: config the pin to be input or output	                */
/************************************************************************/
void DIO_SetPinDirection(uint8 PinNum, uint8 PinValue)
{
	if((PinNum >= NUM_0) && (PinNum <NUM_8)) /*check if Pins in PORTA*/
	{
		if (PinValue == NUM_1) /* Check Pin Value if OUT to set bit or IN to clear bit */
		{
			SET_BIT(DDRA,(PinNum));
		}
		else
		{
			CLEAR_BIT(DDRA,(PinNum));
		}
	}
	else if ((PinNum >= NUM_8) && (PinNum < NUM_16)) /*check if Pins in PORTB*/
	{
		if (PinValue == NUM_1)
		{
			SET_BIT(DDRB,(PinNum - NUM_8));
		}
		else
		{
			CLEAR_BIT(DDRB,(PinNum - NUM_8));
		}
	}
	else if ((PinNum >= NUM_16) && (PinNum < NUM_24)) /*check if Pins in PORTC*/
	{
		if (PinValue == NUM_1)
		{
			SET_BIT(DDRC,(PinNum - NUM_16));
		}
		else
		{
			CLEAR_BIT(DDRC,(PinNum - NUM_16));
		}
	}
	else if ((PinNum >= NUM_24) && (PinNum < NUM_32)) /*check if Pins in PORTD*/
	{
		if (PinValue == NUM_1)
		{
			SET_BIT(DDRD,(PinNum - NUM_24));
		}
		else
		{
			CLEAR_BIT(DDRD,(PinNum - NUM_24));
		}
	}
}

