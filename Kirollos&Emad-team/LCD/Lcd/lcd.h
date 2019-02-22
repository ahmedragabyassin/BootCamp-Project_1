
#ifndef LCD_H
#define LCD_H

#include "..\Commen\commen.h"
#include "..\Dio\DIO_prog.h"
#include "..\Timer\Timer.h"
#include "lcd_config.h"

#define LCD_CLEAR       0X01
#define LCD_HOME        0X02
#define LCD_INCREMENT   0X14
#define	LCD_DISPLAY_ON  0X0F
#define LCD_FIRST_LINE  0X80
#define LCD_SECOND_LINE 0XC0
#define LCD_4BIT_MODE   0X28
#define LCD_8BIT_MODE   0X38
#define LCD_WAKEUP      0X30
#define LCD_CURSOR_OFF  0X0C


#define LCD_RAW0     0
#define LCD_RAW1     1

#define LCD_COLUMN0     0
#define LCD_COLUMN1     1
#define LCD_COLUMN2     2
#define LCD_COLUMN3     3
#define LCD_COLUMN4     4
#define LCD_COLUMN5     5
#define LCD_COLUMN6     6
#define LCD_COLUMN7     7
#define LCD_COLUMN8     8
#define LCD_COLUMN9     9
#define LCD_COLUMN10    10
#define LCD_COLUMN11    11
#define LCD_COLUMN12    12
#define LCD_COLUMN13    13
#define LCD_COLUMN14    14
#define LCD_COLUMN15    15





#define BIT0     0
#define BIT1     1
#define BIT2     2
#define BIT3     3
#define BIT4     4
#define BIT5     5
#define BIT6     6
#define BIT7     7

void LCD_init(void);
void LCD_sendCommand(uint8 command);
void LCD_displayChar(uint8 data);
void LCD_displayString(uint8 lcd_string[],uint8 string_size);
void LCD_displayStringRowColumn(uint8 lcd_string[],uint8 string_size,uint8  row, uint8 col);
void LCD_clear(void);
void LCD_gotoRowColumn(uint8 row ,uint8 column);
void LCD_smile_init(void);
void LCD_sad_init(void);
void LCD_sad_display(void);
void LCD_smile_display(void);
void LCD_like_init(void);
void LCD_like_display(void);
void LCD_balona_init(void);
void LCD_balona_display(void);


#endif