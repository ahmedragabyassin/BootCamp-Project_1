/*
 * Lcd.c
 *
 * Created: 2/19/2019 11:47:14 AM
 *  Author: Yassin
 */ 
#include "../Includes/Lcd.h"

/************************************************************************/
/* Function: LCD Init											        */
/* @param: void													        */
/* return: void													        */
/* Description: function Initialize LCD		                            */
/************************************************************************/
void LCD_Init(void)
{
	/* Config Control Pins and set thir direction*/
	DIO_SetPinDirection(PIN1,OUT);
	DIO_SetPinDirection(PIN2,OUT);
	DIO_SetPinDirection(PIN3,OUT);
	/*config data pins direction */
	DIO_SetPinDirection(PIN4,OUT);
	DIO_SetPinDirection(PIN5,OUT);
	DIO_SetPinDirection(PIN6,OUT);
	DIO_SetPinDirection(PIN7,OUT);
	
	
	/* Initialize LCD in Four bits Mode and two lines */
	LCD_SendCommand(LCD_FOUR_BIT_TWO_LINE_MODE);
	LCD_SendCommand(LCD_FOUR_BIT_DATA_MODE);
	/* Clear LCD and set cursor at the beginning */
	LCD_SendCommand(LCD_CURSOR_OFF);
	LCD_SendCommand(LCD_CLEAR);
}

/************************************************************************/
/* Function: LCD Send Command                                           */
/* @param: command, command to be sent to LCD                           */
/* return: void													        */
/* Description: function take hexa command                              */
/************************************************************************/
void LCD_SendCommand(uint8 Command)
{
	/*Config Control Reg*/
	DIO_WritePin(LCD_RS,LOW); /* RS set to low to send command*/
	DIO_WritePin(LCD_RW,LOW); /* RW set to write */
	_delay_ms(ONE_MS);
	DIO_WritePin(LCD_E,HIGH); /* Set EN pin to high */
	_delay_ms(ONE_MS);
	/* Send Command Most significant bit first */
	DIO_WritePin(LCD_D4,(GET_BIT(Command,LCD_BIT4)>>LCD_BIT4));
	DIO_WritePin(LCD_D5,(GET_BIT(Command,LCD_BIT5)>>LCD_BIT5));
	DIO_WritePin(LCD_D6,(GET_BIT(Command,LCD_BIT6)>>LCD_BIT6));
	DIO_WritePin(LCD_D7,(GET_BIT(Command,LCD_BIT7)>>LCD_BIT7));
	_delay_ms(ONE_MS);
	DIO_WritePin(LCD_E,LOW); /* latch data by writing low on EN pin */
	_delay_ms(ONE_MS);
	DIO_WritePin(LCD_E,HIGH);/* set EN pin */ 
	_delay_ms(ONE_MS);
	/*Send Least Significant bit */
	DIO_WritePin(LCD_D4,(GET_BIT(Command,LCD_BIT0)>>LCD_BIT0));
	DIO_WritePin(LCD_D5,(GET_BIT(Command,LCD_BIT1)>>LCD_BIT1));
	DIO_WritePin(LCD_D6,(GET_BIT(Command,LCD_BIT2)>>LCD_BIT2));
	DIO_WritePin(LCD_D7,(GET_BIT(Command,LCD_BIT3)>>LCD_BIT3));
	_delay_ms(ONE_MS);
	DIO_WritePin(LCD_E,LOW);
	_delay_ms(ONE_MS);
	
}

/************************************************************************/
/* Function: LCD Display character                                      */
/* @param: data, character to be displayed on LCD                       */
/* return: void		 											        */
/* Description: function display character on LCD                       */
void LCD_DisplayChar(uint8 Data)
{
		/*Config Control Reg*/
		DIO_WritePin(LCD_RS,HIGH); /* RS = 1 for Data */
		DIO_WritePin(LCD_RW,LOW);
		_delay_ms(ONE_MS);
		DIO_WritePin(LCD_E,HIGH);
		_delay_ms(ONE_MS);
		/* Send Data Most significant bit first */
		DIO_WritePin(LCD_D4,(GET_BIT(Data,LCD_BIT4)>>LCD_BIT4));
		DIO_WritePin(LCD_D5,(GET_BIT(Data,LCD_BIT5)>>LCD_BIT5));
		DIO_WritePin(LCD_D6,(GET_BIT(Data,LCD_BIT6)>>LCD_BIT6));
		DIO_WritePin(LCD_D7,(GET_BIT(Data,LCD_BIT7)>>LCD_BIT7));
		_delay_ms(ONE_MS);
		DIO_WritePin(LCD_E,LOW);
		_delay_ms(ONE_MS);
		DIO_WritePin(LCD_E,HIGH);
		_delay_ms(ONE_MS);
		/*Send Least Significant bit */
		DIO_WritePin(LCD_D4,(GET_BIT(Data,LCD_BIT0)>>LCD_BIT0));
		DIO_WritePin(LCD_D5,(GET_BIT(Data,LCD_BIT1)>>LCD_BIT1));
		DIO_WritePin(LCD_D6,(GET_BIT(Data,LCD_BIT2)>>LCD_BIT2));
		DIO_WritePin(LCD_D7,(GET_BIT(Data,LCD_BIT3)>>LCD_BIT3));
		_delay_ms(ONE_MS);
		DIO_WritePin(LCD_E,LOW);
		_delay_ms(ONE_MS);
}


/************************************************************************/
/* Function: LCD go to row column                                       */
/* @param: Row, row to write on				                            */
/* @param: Col, col to shift cursor to		                            */
/* return: void													        */
/* Description: function to set cursor to certain row and column        */
/************************************************************************/
void LCD_GotoRowColumn(uint8 Row, uint8 Col)
{
	if (Row == LCD_ROW1) /* goto row 1 */
	{
		LCD_SendCommand(LCD_CURSOR_LINE_ONE);
		for (uint8 i = NUM_0 ; i<Col; i++)
		{
			LCD_SendCommand(LCD_SHIFT_CURSOR_RIGHT);
		}
	} 
	else if(Row == LCD_ROW2)
	{
		LCD_SendCommand(LCD_CURSOR_LINE_TWO);
		for (uint8 i = NUM_0; i<Col; i++)
		{
			LCD_SendCommand(LCD_SHIFT_CURSOR_RIGHT);
		}
	}
	else
	{
		LCD_SendCommand(LCD_CURSOR_LINE_ONE);
		for (uint8 i = NUM_0; i<Col; i++)
		{
			LCD_SendCommand(LCD_SHIFT_CURSOR_RIGHT);
		}
	}
}

/************************************************************************/
/* Function: LCD go to row column                                       */
/* @param: Row, row to write on				                            */
/* @param: Col, col to shift cursor to		                            */
/* @param: str[], array of strings to be printed    	                */
/* return: void													        */
/* Description: function to set cursor to certain row and column        */
/*			    and display string on LCD		                        */
/************************************************************************/
void LCD_DisplayStringRowColumn(uint8 Row, uint8 Col, const uint8 Str[])
{
	LCD_GotoRowColumn(Row,Col);
	LCD_DisplayString(Str);
}


/************************************************************************/
/* Function: LCD Clear			                                        */
/* @param: void													        */
/* return: void													        */
/* Description: function clears LCD				                        */
/************************************************************************/
void LCD_Clear(void)
{
	LCD_SendCommand(LCD_CLEAR);
}

/************************************************************************/
/* Function: LCD Display String						                    */
/* @param: Str[], array of strings					                    */
/* return: void		 											        */
/* Description: function display String on LCD	                        */
/************************************************************************/
void LCD_DisplayString(const uint8 Str[])
{
	uint8 i = NUM_0;
	while(Str[i] != NULL_CHAR)
	{
		LCD_DisplayChar(Str[i]);
		i++;
	}
}






/************************************************************************/
/* Function: LCD Generate character                                     */
/* @param: arr[], array of hexa to the certain shape                    */
/* @param: add_location, location to goto CGRAM		                    */
/* @param: char_add, address to save the character	                    */
/* return: void,									                    */
/* Description: Generate certain character in CGRAM                     */
/************************************************************************/
void LCD_GenerateCharacter(uint8 arr[], uint8 add_Location, uint8 char_add, uint8 ROw, uint8 Col)
{
	LCD_SendCommand(add_Location);
	for (uint8 i=NUM_0; i<NUM_8; i++)
	{
		LCD_DisplayChar(arr[i]);
		_delay_ms(TEN_MS);
	}
	LCD_SendCommand(0x80);
	LCD_GotoRowColumn(ROw, Col);
	LCD_DisplayChar(char_add);
}


