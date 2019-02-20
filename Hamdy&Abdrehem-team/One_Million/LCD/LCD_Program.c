/*
 * LCD_Program.c
 *
 * Created: 2/19/2019 11:13:35 AM
 *  Author: AVE-LAP-005
 */ 
#define F_CPU 16000000UL
#include "Types.h"
#include "BitwiseOperations.h"
#include "LCD.h"
#include "LCD_Config.h"
#include "DIO_Interface.h"
#include <util/delay.h>

/***********************LCD_init()***************************
*Parameters: 
*			i/P:
*			O/P:
*           I/O:
*Return: 
*Description:                                                       
*************************************************************/

void LCD_init(){
	#ifdef FOUR_BIT_MODE
	/* portA output */
	DIO_SetPinDirection(LCD_RS,OUTPUT);
	DIO_SetPinDirection(LCD_EN,OUTPUT);
	DIO_SetPinDirection(LCD_RW,OUTPUT);
	DIO_SetPinDirection(LCD_D4,OUTPUT);
	DIO_SetPinDirection(LCD_D5,OUTPUT);
	DIO_SetPinDirection(LCD_D6,OUTPUT);
	DIO_SetPinDirection(LCD_D7,OUTPUT);
	DIO_WritePin(LCD_EN,LOW);	
	_delay_ms(t_15ms);	
	
	LCD_sendCommand(LCD_INIT_PHASE_ONE);
	
	LCD_sendCommand(LCD_INIT_PHASE_TWO);
	/* set function to be 4 bit mode */
	LCD_sendCommand(LCD_INIT_PHASE_THREE);
	/* shift right and i/d=0 */
	LCD_sendCommand(LCD_DISPLAY_OPTIONS);
	/* clear LCD */
	LCD_sendCommand(LCD_CLEAR);
	/* increment cursor */
	LCD_sendCommand(LCD_INCREMENT_CURSOR);
	_delay_ms(t_1ms);
	#elif EIGHT_BIT_MODE
	#endif
}
/***********************LCD_init()***************************
*Parameters:
*			i/P:
*			O/P:
*           I/O:
*Return:
*Description:
*************************************************************/
void LCD_sendCommand(uint8 command){
	#ifdef FOUR_BIT_MODE
	/* 1- Register select choose send command mode Rs=0 */
	DIO_WritePin(LCD_RS,LOW);
	/* 2- choose write rw =0 */
	DIO_WritePin(LCD_RW,LOW);
	/* send High nibble */
	DIO_WritePin(LCD_D4,((LCD_CMD_BIT_FOUR & command)>>LCD_SHIFT_FOUR));
	DIO_WritePin(LCD_D5,((LCD_CMD_BIT_FIVE & command)>>LCD_SHIFT_FIVE));
	DIO_WritePin(LCD_D6,((LCD_CMD_BIT_SIX & command)>>LCD_SHIFT_SIX));
	DIO_WritePin(LCD_D7,((LCD_CMD_BIT_SEVEN & command)>>LCD_SHIFT_SEVEN));
	/* Latch Enable */
	DIO_WritePin(LCD_EN,High);
	_delay_ms(t_1ms);
	DIO_WritePin(LCD_EN,LOW);
	_delay_ms(t_1ms);
	/* Send Low Nibble */
   DIO_WritePin(LCD_D4,((LCD_CMD_BIT_ZERO & command)>>LCD_SHIFT_ZERO));
   DIO_WritePin(LCD_D5,((LCD_CMD_BIT_ONE & command)>>LCD_SHIFT_ONE));
   DIO_WritePin(LCD_D6,((LCD_CMD_BIT_TWO & command)>>LCD_SHIFT_TWO));
   DIO_WritePin(LCD_D7,((LCD_CMD_BIT_THREE & command)>>LCD_SHIFT_THREE));
   	/* Latch Enable */
   	DIO_WritePin(LCD_EN,High);
   	_delay_ms(t_1ms);
   	DIO_WritePin(LCD_EN,LOW);
   	_delay_ms(t_1ms);
	#elif EIGHT_BIT_MODE
	#endif
}
/***********************LCD_init()***************************
*Parameters:
*			i/P:
*			O/P:
*           I/O:
*Return:
*Description:
*************************************************************/
void LCD_displayChar(uint8 Char){
	#ifdef FOUR_BIT_MODE
	/* 1- Register select choose send Data mode Rs=1 */
	DIO_WritePin(LCD_RS,High);
	/* 2- choose write rw =0 */
	DIO_WritePin(LCD_RW,LOW);
	/* send High nibble */
	DIO_WritePin(LCD_D4,((LCD_DATA_BIT_FOUR & Char)>>LCD_SHIFT_FOUR));
	DIO_WritePin(LCD_D5,((LCD_DATA_BIT_FIVE & Char)>>LCD_SHIFT_FIVE));
	DIO_WritePin(LCD_D6,((LCD_DATA_BIT_SIX  & Char)>>LCD_SHIFT_SIX));
	DIO_WritePin(LCD_D7,((LCD_DATA_BIT_SEVEN & Char)>>LCD_SHIFT_SEVEN));
	/* Latch Enable */
	DIO_WritePin(LCD_EN,High);
	_delay_ms(t_1ms);
	DIO_WritePin(LCD_EN,LOW);
	_delay_ms(t_1ms);
	/* Send Low Nibble */
	DIO_WritePin(LCD_D4,((LCD_DATA_BIT_ZERO & Char)>>LCD_SHIFT_ZERO));
	DIO_WritePin(LCD_D5,((LCD_DATA_BIT_ONE  &  Char)>>LCD_SHIFT_ONE));
	DIO_WritePin(LCD_D6,((LCD_DATA_BIT_TWO  &  Char)>>LCD_SHIFT_TWO));
	DIO_WritePin(LCD_D7,((LCD_DATA_BIT_THREE & Char)>>LCD_SHIFT_THREE));
	/* Latch Enable */
	DIO_WritePin(LCD_EN,High);
	_delay_ms(t_1ms);
	DIO_WritePin(LCD_EN,LOW);
	_delay_ms(t_1ms);
	#elif EIGHT_BIT_MODE
	#endif
}
/***********************LCD_init()***************************
*Parameters:
*			i/P:
*			O/P:
*           I/O:
*Return:
*Description:
*************************************************************/
void LCD_displayString(uint8* data){
		uint32 i=0;
		/* Loop till the Finding the Null Pointer */
		while (data[i] != '\0')
		{
			LCD_displayChar(data[i]);
			i++;
		}
}
/***********************LCD_init()***************************
*Parameters:
*			i/P:
*			O/P:
*           I/O:
*Return:
*Description:
*************************************************************/
void LCD_gotoRowColumn(uint8 row,uint8 col){
	/* Choose Between the two rows then add the coulomn to define the index in the lcd 2*16 */
	switch(row){
		case ROW_ONE:LCD_sendCommand(LCD_START_LINE_ONE+col); break;
		case ROW_TWO:LCD_sendCommand(LCD_START_LINE_TWO+col); break;
	
	}
}
/***********************LCD_init()***************************
*Parameters:
*			i/P:
*			O/P:
*           I/O:
*Return:
*Description:
*************************************************************/
void LCD_clear(){
	/* Send Command To Clear The LCD */
	LCD_sendCommand(LCD_CLEAR);
	
}
/***********************LCD_init()***************************
*Parameters:
*			i/P:
*			O/P:
*           I/O:
*Return:
*Description:
*************************************************************/
void LCD_displayStringRowColumn(uint8 row,uint8 col,uint8* data){
	/* Call The two functions write string and goto  */
	LCD_gotoRowColumn(row,col);
	LCD_displayString(data);
}