/*
 * Lcd.c
 *
 * Created: 2/19/2019 12:23:46 PM
 *  Author: AVE-LAP-44
 */ 
#include "lcd.h"
#if(LCD_TYPE==LCD_4BIT_TYPE)

void LCD_init(){
	
	DIO_SetPinDirection(LCD_RS,HIGH);     /* Set LCD_RS OUTPUT */
	DIO_SetPinDirection(LCD_RW,HIGH);     /* Set LCD_RW OUTPUT */
	DIO_SetPinDirection(LCD_E,HIGH);      /* Set LCD_E OUTPUT */
	
	DIO_SetPinDirection(LCD_D4,HIGH);     /* Set LCD_D4 OUTPUT */
	DIO_SetPinDirection(LCD_D5,HIGH);     /* Set LCD_D5 OUTPUT */
    DIO_SetPinDirection(LCD_D6,HIGH);     /* Set LCD_D6 OUTPUT */
	DIO_SetPinDirection(LCD_D7,HIGH);     /* Set LCD_D7 OUTPUT */
	
	timer_mdelay(TIME_30MS);              /* Delay 30m second until the power steady */
	LCD_sendCommand(LCD_WAKEUP);          /* Send command to wake up #1 */
	timer_mdelay(TIME_10MS);              /* Must delay more than 5m second */
	LCD_sendCommand(LCD_WAKEUP);          /* Send command to wake up #2 */
	timer_mdelay(TIME_5MS);               /* Must delay more than 1m second */
	LCD_sendCommand(LCD_WAKEUP);          /* Send command to wake up #3 */
	timer_mdelay(TIME_5MS);               /* Must delay more than 1m second */
	LCD_sendCommand(LCD_HOME);            /* Send Home (0x02) command which initializes LCD 16x2 in 4-bit mode */
	LCD_sendCommand(LCD_4BIT_MODE);       /* Send 4BIT_MODE (0x28) command which configures LCD in 2-line, 4-bit mode and 5x8 dots */
    LCD_sendCommand(LCD_DISPLAY_ON);      /* SEND LCD_DISPLAY_ON(0X0F) display on,CURSOR_ON*/
	LCD_sendCommand(LCD_INCREMENT);       /* Send LCD_INCREMENT (0X14) to increment cursor */
	LCD_sendCommand(LCD_CLEAR);           /* Clear Screen */
	
	

}
void LCD_sendCommand(uint8 command){
	uint8 LCD_D4_value;                   
	uint8 LCD_D5_value;
	uint8 LCD_D6_value;
	uint8 LCD_D7_value;
	/* For 4_bit_Mode we have to divide the uint8 to 2 (4bits) and send the most 4bits then send the least 4bits
	 * for example :command = 0x52 which is 0b 0101 0010
	 * so we have to send 0b0101 (0x5) first then send 0b0010 (0x2)
	 * first  send   LCD_D7_value =0 ,LCD_D6_value=1 LCD_D5_value=0  LCD_D4_value=1
	 * second send   LCD_D7_value =0 ,LCD_D6_value=0 LCD_D5_value=1  LCD_D4_value=0
	 *  sequence : 1- Make E 0 RS O (Command) RW 0 (write) 
	              2- Get #1 LCD_D4:D7_value using Get_Bit
	              3- Write Data Pins with Values
				  4- Enable
				  5- delay
				  6- disable
				  7- Get #2 LCD_D4:D7_value using Get_Bit
				  8- Write Data Pins with Values
				  9- Enable
				  10-delay
				  11-disable*/
    DIO_WritePin(LCD_E,LOW);              /* Disable LCD*/
	DIO_WritePin(LCD_RS,LOW);             /* LCD_RS =0, Command*/
	DIO_WritePin(LCD_RW,LOW);             /* LCD_Rw =0, Write */
	
	
	LCD_D4_value=Get_Bit(command,BIT4);     /* 2 */
	LCD_D5_value=Get_Bit(command,BIT5);
	LCD_D6_value=Get_Bit(command,BIT6);
	LCD_D7_value=Get_Bit(command,BIT7);
	DIO_WritePin(LCD_D4,LCD_D4_value);     /* 3 */
	DIO_WritePin(LCD_D5,LCD_D5_value);
	DIO_WritePin(LCD_D6,LCD_D6_value);
	DIO_WritePin(LCD_D7,LCD_D7_value);

	DIO_WritePin(LCD_E,HIGH);              /* 4 */
	timer_mdelay(TIME_10MS);               /* 5 */
	DIO_WritePin(LCD_E,LOW);               /* 6 */
	LCD_D4_value=Get_Bit(command,BIT0);    /* 7 */
	LCD_D5_value=Get_Bit(command,BIT1);
	LCD_D6_value=Get_Bit(command,BIT2);
	LCD_D7_value=Get_Bit(command,BIT3);
	DIO_WritePin(LCD_D4,LCD_D4_value);     /* 8 */
	DIO_WritePin(LCD_D5,LCD_D5_value);
	DIO_WritePin(LCD_D6,LCD_D6_value);
	DIO_WritePin(LCD_D7,LCD_D7_value);
	DIO_WritePin(LCD_E,HIGH);              /* 9 */
	timer_mdelay(TIME_10MS);               /* 10 */
	DIO_WritePin(LCD_E,LOW);	           /* 11 */
}
void LCD_displayChar(uint8 data){
	uint8 LCD_D4_value;
	uint8 LCD_D5_value;
	uint8 LCD_D6_value;
	uint8 LCD_D7_value;
	/* For 4_bit_Mode we have to divide the uint8 to 2 (4bits) and send the most 4bits then send the least 4bits
	   for example :data = 0x52 which is 0b 0101 0010
	   so we have to send 0b0101 (0x5) first then send 0b0010 (0x2)
	   first  send   LCD_D7_value =0 ,LCD_D6_value=1 LCD_D5_value=0  LCD_D4_value=1
	   second send   LCD_D7_value =0 ,LCD_D6_value=0 LCD_D5_value=1  LCD_D4_value=0
	   sequence : 1- Make E 0 RS 1 (data) RW 0 (write) 
	              2- Get #1 LCD_D4:D7_value using Get_Bit
	              3- Write Data Pins with Values
				  4- Enable
				  5- delay
				  6- disable
				  7- Get #2 LCD_D4:D7_value using Get_Bit
				  8- Write Data Pins with Values
				  9- Enable
				  10-delay
				  11-disable*/
	DIO_WritePin(LCD_E,LOW);                 /* 1 */
	DIO_WritePin(LCD_RS,HIGH);
	DIO_WritePin(LCD_RW,LOW);
	LCD_D4_value=Get_Bit(data,BIT4);         /* 2 */
	LCD_D5_value=Get_Bit(data,BIT5);
	LCD_D6_value=Get_Bit(data,BIT6);
	LCD_D7_value=Get_Bit(data,BIT7);
	DIO_WritePin(LCD_D4,LCD_D4_value);       /* 3 */
	DIO_WritePin(LCD_D5,LCD_D5_value);
	DIO_WritePin(LCD_D6,LCD_D6_value);
	DIO_WritePin(LCD_D7,LCD_D7_value);

	DIO_WritePin(LCD_E,HIGH);                /* 4 */
	timer_mdelay(TIME_10MS);                 /* 5 */
	DIO_WritePin(LCD_E,LOW);                 /* 6 */
	LCD_D4_value=Get_Bit(data,BIT0);         /* 7 */
	LCD_D5_value=Get_Bit(data,BIT1);
	LCD_D6_value=Get_Bit(data,BIT2);
	LCD_D7_value=Get_Bit(data,BIT3);
	DIO_WritePin(LCD_D4,LCD_D4_value);       /* 8 */
	DIO_WritePin(LCD_D5,LCD_D5_value);
	DIO_WritePin(LCD_D6,LCD_D6_value);
	DIO_WritePin(LCD_D7,LCD_D7_value);
	DIO_WritePin(LCD_E,HIGH);                /* 9 */
	timer_mdelay(TIME_10MS);                 /* 10 */
	DIO_WritePin(LCD_E,LOW);                 /* 11 */
	
}
void LCD_displayString(uint8 lcd_string[],uint8 string_size){
	uint8 string_index =0;                         
	while(--string_size)                            /*  decrement size for every print*/
	{
		LCD_displayChar(lcd_string[string_index]);  /* print char with the specif index */   
		string_index++;
	};
	
		
}
void LCD_gotoRowColumn(uint8 row ,uint8 column){

	if (row==LCD_RAW0)
	{
	LCD_sendCommand(LCD_FIRST_LINE);        
	while(column--)
	  {
		LCD_sendCommand(LCD_INCREMENT);    /* Increment until reaching the specific column    */
	  }
	}
	else if (row==LCD_RAW1)
	{
		LCD_sendCommand(LCD_SECOND_LINE);
		while(column--)
		{
			LCD_sendCommand(LCD_INCREMENT);  /* Increment until reaching the specific column    */
		}
	}
	
	
}
void LCD_displayStringRowColumn(uint8 lcd_string[],uint8 string_size,uint8  row, uint8 col){
	LCD_gotoRowColumn(row,col);                    /* Go to  column */
	LCD_displayString(lcd_string,string_size);     
	
}
void LCD_clear(void){
	
	LCD_sendCommand(LCD_CLEAR);                    /* Send command clear */
	
}

void LCD_smile_init(void)
{
	LCD_sendCommand(0x40);
	LCD_displayChar(0x00);
	LCD_displayChar(0);
	LCD_displayChar(10);
	LCD_displayChar(0);
	LCD_displayChar(17);
	LCD_displayChar(14);
	LCD_displayChar(0);
	LCD_displayChar(0x00);
	timer_mdelay(5);
	LCD_sendCommand(0x80);

}
void LCD_smile_display(void){
		LCD_displayChar(0);
}

void LCD_sad_init(void){
	LCD_sendCommand(0x48);
	LCD_displayChar(0x00);
	LCD_displayChar(0);
	LCD_displayChar(10);
	LCD_displayChar(0);
	LCD_displayChar(14);
	LCD_displayChar(17);
	LCD_displayChar(0);
	LCD_displayChar(0x00);
	timer_mdelay(5);
	LCD_sendCommand(0x80);
}
LCD_sad_display(){
	LCD_displayChar(1);
}
void LCD_like_init(void){
	LCD_sendCommand(0x50);
	LCD_displayChar(0);
	LCD_displayChar(1);
	LCD_displayChar(3);
	LCD_displayChar(3);
	LCD_displayChar(15);
	LCD_displayChar(31);
	LCD_displayChar(31);
	LCD_displayChar(15);
	timer_mdelay(5);
	LCD_sendCommand(0x80);
}
void LCD_like_display(void){
	LCD_displayChar(2);
}
void LCD_balona_init(void){
	LCD_sendCommand(0x58);
	LCD_displayChar(14);
	LCD_displayChar(17);
	LCD_displayChar(17);
	LCD_displayChar(17);
	LCD_displayChar(14);
	LCD_displayChar(4);
	LCD_displayChar(4);
	LCD_displayChar(2);
	timer_mdelay(5);
	LCD_sendCommand(0x80);
}
void LCD_balona_display(void){
	LCD_displayChar(3);
}

#endif