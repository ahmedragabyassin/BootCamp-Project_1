/*
 * KeyPad.c
 *
 * Created: 2/18/2019 2:57:50 PM
 *  Author: Yassin
 */ 

#include "../Includes/KeyPad.h"

/************************************************************************/
/* Function: KeyPad Init                                                */
/* @param: void						    	                            */
/* return: void								                            */
/* Description: Init keypad pins directions                             */
/************************************************************************/
void KeyPad_Init(void)
{
	/************************************************************************/
	/* Set Columns Direction                                                */
	/************************************************************************/
	DIO_SetPinDirection(COL1,OUT);
	DIO_SetPinDirection(COL2,OUT);
	DIO_SetPinDirection(COL3,OUT);
	/************************************************************************/
	/* SET Rows Direction                                                   */
	/************************************************************************/
	DIO_SetPinDirection(ROW1,IN);
	DIO_SetPinDirection(ROW2,IN);
	DIO_SetPinDirection(ROW3,IN);
	/************************************************************************/
	/* Write initial value on columns                                       */
	/************************************************************************/
	DIO_WritePin(COL1,HIGH);
	DIO_WritePin(COL2,HIGH);
	DIO_WritePin(COL3,HIGH);
	/************************************************************************/
	/* Activate Pull-up resistor on Rows                                    */
	/************************************************************************/
	DIO_WritePin(ROW1,HIGH);
	DIO_WritePin(ROW2,HIGH);
	DIO_WritePin(ROW3,HIGH);
}



/************************************************************************/
/* Function: KeyPad Get Pressed Key                                     */
/* @param: Void							                                */
/* @return: return number detected                                      */
/* Description: Detect pressed key and return its value                 */
/************************************************************************/
uint8 KeyPad_GetPressedKey(void)
{
	while(NUM_1){
		for (uint8 i = NUM_0; i < COL_NUM; i++)
		{
			KeyPad_Init();
			DIO_WritePin((COL1 + i), LOW); /* write low on one column each loop  */
			for (uint8 j = NUM_0; j < ROW_NUM; j++)
			{
				if (!(DIO_ReadPin((ROW1 + j)))) /*detect if key pressed */
				{
					uint8 result = ((j * COL_NUM) + i + NUM_1); /* equation to get the pressed number according to the maping of keypad */
					return result;
				}
			}
		}
	}
	return NUM_0; /* if no key pressed return 0 */
}


