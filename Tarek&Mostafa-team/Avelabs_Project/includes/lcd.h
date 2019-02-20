/*
 * lcd.h
 *
 * Created: 2/19/2019 11:51:56 AM
 *  Author: AVE-LAP-016
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "../includes/lcd_config.h"
#include "../includes/DIO.h"
#include "../includes/timer.h"
#define LCD_CGRAM_MAX_CHARCTERS 8U
#define LCD_CGRAM_ADDRESS 0x40U
#define LCD_CHARCATER_SIZE 8U
#define INTIAL_VALUE 0U
#define DELAY_2_MS 2U
void LCD_init(void);
void LCD_sendCommand (uint8 command);
void LCD_displayChar (uint8 ch);
void LCD_displayString (sint8* str);
void LCD_displayStringRowColumn (sint8* str,uint8 row,uint8 col);
void LCD_clear (void);
void LCD_gotoRowColumn (uint8 row,uint8 col);
void LCD_DisplayCustomChar (uint8 CustomCharacterLocation, uint8* CustomCharacter );


#endif /* LCD_H_ */