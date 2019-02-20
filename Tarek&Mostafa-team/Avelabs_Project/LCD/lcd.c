/*
 * lcd.c
 *
 * Created: 2/19/2019 11:53:10 AM
 *  Author: AVE-LAP-016
 */ 
#include "../includes/lcd.h"
void LCD_init(void)
{
	// set pins directions 
	DIO_SetPinDirection(RS,OUTPUT);
	DIO_SetPinDirection(RW,OUTPUT);
	DIO_SetPinDirection(E ,OUTPUT);
	DIO_SetPinDirection(D4,OUTPUT);
	DIO_SetPinDirection(D5,OUTPUT);
	DIO_SetPinDirection(D6,OUTPUT);
	DIO_SetPinDirection(D7,OUTPUT);

  // for enable 4 bit mode
	 // send 0x33 command
	LCD_sendCommand(FOUR_BIT_MODE_CMD1);
	 // send 0x32 command
	LCD_sendCommand(FOUR_BIT_MODE_CMD2);
	 // send 0x28 command
	LCD_sendCommand(FOUR_BIT_MODE_CMD3);
    // Display ON cursor OFF
    LCD_sendCommand(DISPLAY_ON_CURSOR_OFF);
	// force courser to the beginning of first line
	LCD_sendCommand(RETURN_HOME);
	// Clear Screen
	LCD_clear();

}
void LCD_sendCommand (uint8 command)
{
    // RS = 0 to send command
	DIO_WritePin(RS,LOW) ;
	timer_delay(2);
	// RW = 0 for write
	DIO_WritePin(RW,LOW) ;
	timer_delay(2);
	
	
	// send command high nibble then low nibble
	//LCD_PORT = (LCD_PORT &  0x0F)  | ( command & 0xF0) ; // high nibble
	DIO_WritePin(D4,( ((command & 0xF0) & (1<<4)) >> 4));
	DIO_WritePin(D5,( ((command & 0xF0) & (1<<5)) >> 5));
	DIO_WritePin(D6,( ((command & 0xF0) & (1<<6)) >> 6));
	DIO_WritePin(D7,( ((command & 0xF0) & (1<<7)) >> 7));

	// E high low pulse
	DIO_WritePin(E,HIGH) ;
	timer_delay(LCD_COMMAND_DELAY);
	DIO_WritePin(E,LOW) ;
	timer_delay(LCD_COMMAND_DELAY);
	
	//LCD_PORT = (LCD_PORT &  0x0F)  | ((command & 0x0F)<<4) ; // low nibble
	DIO_WritePin(D4,( (((command & 0x0F)<<4) & (1<<4)) >> 4));
	DIO_WritePin(D5,( (((command & 0x0F)<<4) & (1<<5)) >> 5));
	DIO_WritePin(D6,( (((command & 0x0F)<<4) & (1<<6)) >> 6));
	DIO_WritePin(D7,( (((command & 0x0F)<<4) & (1<<7)) >> 7));
	// E high low pulse
	DIO_WritePin(E,HIGH) ;
	timer_delay(LCD_COMMAND_DELAY);
	DIO_WritePin(E,LOW) ;
	timer_delay(LCD_COMMAND_DELAY);

}
void LCD_displayChar (uint8 ch)
{	
	// RS HIGH to send data
	DIO_WritePin(RS,HIGH) ;
	timer_delay(LCD_COMMAND_DELAY);
	// RW LOW for write
	DIO_WritePin(RW,LOW) ;
	timer_delay(LCD_COMMAND_DELAY);
	
	// send data high nibble then low nibble
	//LCD_PORT = (LCD_PORT &  0x0F)  | ( ch & 0xF0) ; // high nibble
	DIO_WritePin(D4,( ((ch & 0xF0) & (1<<4)) >> 4));
	DIO_WritePin(D5,( ((ch & 0xF0) & (1<<5)) >> 5));
	DIO_WritePin(D6,( ((ch & 0xF0) & (1<<6)) >> 6));
	DIO_WritePin(D7,( ((ch & 0xF0) & (1<<7)) >> 7));
	// E high low pulse
	DIO_WritePin(E,HIGH) ;
	timer_delay(LCD_COMMAND_DELAY);
	DIO_WritePin(E,LOW) ;
	timer_delay(LCD_COMMAND_DELAY);
	
	//LCD_PORT = (LCD_PORT &  0x0F)  | ((ch & 0x0F)<<4) ; // low nibble
	DIO_WritePin(D4,( (((ch & 0x0F)<<4) & (1<<4)) >> 4));
	DIO_WritePin(D5,( (((ch & 0x0F)<<4) & (1<<5)) >> 5));
	DIO_WritePin(D6,( (((ch & 0x0F)<<4) & (1<<6)) >> 6));
	DIO_WritePin(D7,( (((ch & 0x0F)<<4) & (1<<7)) >> 7));
    // E high low pulse
    DIO_WritePin(E,HIGH) ;
    timer_delay(LCD_COMMAND_DELAY);
    DIO_WritePin(E,LOW) ;
    timer_delay(LCD_COMMAND_DELAY);
}
void LCD_displayString (sint8* str)
{
	while (*str != '\0')
	{
		LCD_displayChar(*str);
		str++ ;
	}
}
void LCD_displayStringRowColumn (sint8* str,uint8 row,uint8 col)
{
	LCD_gotoRowColumn ( row, col);
	LCD_displayString(str);
}
void LCD_clear (void)
{
	LCD_sendCommand(CLEAR_SCREEN);
}
void LCD_gotoRowColumn (uint8 row,uint8 col)
{
	if (row == LCD_FIRST_LINE)
	{
     LCD_sendCommand(FORCE_CURSOR_TO_THE_BEGINING_OF_FIRST_LINE+col);
	}
	else if (row == LCD_SECOND_LINE)
	{
	 LCD_sendCommand(FORCE_CURSOR_TO_THE_BEGINING_OF_SECOND_LINE+col);
	}
	  
}
void LCD_DisplayCustomChar (uint8 CustomCharacterLocation, uint8* CustomCharacter ){
	uint8 counter;
	if(CustomCharacterLocation < LCD_CGRAM_MAX_CHARCTERS)
	{
		LCD_sendCommand(LCD_CGRAM_ADDRESS + (CustomCharacterLocation*LCD_CGRAM_MAX_CHARCTERS));
		timer_delay(DELAY_2_MS);
		for(counter=INTIAL_VALUE;counter<LCD_CHARCATER_SIZE;counter++) {
			LCD_displayChar(CustomCharacter[counter]);
			timer_delay(DELAY_2_MS);
		}
	}
	
	LCD_sendCommand(FORCE_CURSOR_TO_THE_BEGINING_OF_FIRST_LINE);
}