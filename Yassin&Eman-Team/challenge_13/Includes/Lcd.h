/*
 * Lcd.h
 *
 * Created: 2/19/2019 11:46:34 AM
 *  Author: Yassin
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "BitwiseOperations.h"
#include "Dio.h"
#include "types.h"
#include "lcd_cfg.h"
#include "CommonDelays.h"
#include "CommonNumbers.h"
#include "CommonDefinations.h"
#include "ChallengeCommonDef.h"
#ifndef F_CPU
#define F_CPU 16000000UL
#include <util/delay.h>
#endif


/************************************************************************/
/* Function: LCD Init											        */
/* @param: void													        */
/* return: void													        */
/* Description: function Initialize LCD		                            */
/************************************************************************/
void LCD_Init(void);

/************************************************************************/
/* Function: LCD Send Command                                           */
/* @param: command, command to be sent to LCD                           */
/* return: void													        */
/* Description: function take hexa command                              */
/************************************************************************/
void LCD_SendCommand(uint8 Command);

/************************************************************************/
/* Function: LCD Display character                                      */
/* @param: data, character to be displayed on LCD                       */
/* return: void		 											        */
/* Description: function display charcter on LCD                        */
/************************************************************************/
void LCD_DisplayChar(uint8 Data);

/************************************************************************/
/* Function: LCD Display String						                    */
/* @param: Str[], array of strings					                    */
/* return: void		 											        */
/* Description: function display String on LCD	                        */
/************************************************************************/
void LCD_DisplayString(const uint8 Str[]);

/************************************************************************/
/* Function: LCD go to row column                                       */
/* @param: Row, row to write on				                            */
/* @param: Col, col to shift cursor to		                            */
/* @param: str[], array of strings to be printed    	                */
/* return: void													        */
/* Description: function to set cursor to certain row and column        */
/*			    and display string on LCD		                        */
/************************************************************************/
void LCD_DisplayStringRowColumn(uint8 Row, uint8 Col, const uint8 Str[]);

/************************************************************************/
/* Function: LCD Clear			                                        */
/* @param: void													        */
/* return: void													        */
/* Description: function clears LCD				                        */
/************************************************************************/
void LCD_Clear(void);

/************************************************************************/
/* Function: LCD go to row column                                       */
/* @param: Row, row to write on				                            */
/* @param: Col, col to shift cursor to		                            */
/* return: void													        */
/* Description: function to set cursor to certain row and column        */
/************************************************************************/
void LCD_GotoRowColumn(uint8 Row, uint8 Col);

/************************************************************************/
/* Function: LCD Generate character                                     */
/* @param: arr[], array of hexa to the certain shape                    */
/* @param: add_location, location to goto CGRAM		                    */
/* @param: char_add, address to save the character	                    */
/* return: void,									                    */
/* Description: Generate certain character in CGRAM                     */
/************************************************************************/
void LCD_GenerateCharacter(uint8 arr[], uint8 add_Location, uint8 char_add, uint8 ROw, uint8 Col);


#endif /* LCD_H_ */