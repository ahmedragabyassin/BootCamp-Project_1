/*
 * lcd_config.h
 *
 * Created: 2/19/2019 11:52:54 AM
 *  Author: AVE-LAP-016
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define RS PINA1
#define RW PINA2
#define E  PINA3
#define D4 PINA4
#define D5 PINA5
#define D6 PINA6
#define D7 PINA7
#define LCD_PORT PORTA
#define RETURN_HOME 0x02
#define DISPLAY_ON_CURSOR_OFF 0X0C
#define DISPLAY_ON_CURSOR_BLINKING 0X0E
#define FORCE_CURSOR_TO_THE_BEGINING_OF_FIRST_LINE 0x80
#define FORCE_CURSOR_TO_THE_BEGINING_OF_SECOND_LINE 0xC0
#define LCD_FIRST_LINE 1
#define LCD_SECOND_LINE 2


#define CLEAR_SCREEN 0x01
#define FOUR_BIT_MODE_CMD1 0x33
#define FOUR_BIT_MODE_CMD2 0x32
#define FOUR_BIT_MODE_CMD3 0x28
#define LCD_COMMAND_DELAY 2 // 2 milliseconds

#endif /* LCD_CONFIG_H_ */