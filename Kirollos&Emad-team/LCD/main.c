/*
 * GPIO.c
 *
 * Created: 2/13/2019 10:41:19 AM
 * Author : AVE-LAP-44
 */ 



    /* Replace with your application code */
 
#include "Commen\commen.h"
#include "Dio\DIO_prog.h"
#include "Timer\Timer.h"
#include "Sevenseg\BCDSevSegment.h"
#include "Keypad\Keypad.h"
#include "Lcd\lcd.h"
 
#define  BUTTON0       PINC4
#define  BUTTON1       PINB2
#define  QUEST_NUM       5
#define  QUEST_SIZE      17 
#define  CORRECT         1
#define  WRONG           0
#define  NUM_8           8
#define  NUM_1           1
#define NUM_13           13
#define NUM_15           15
#define NUM_16           16
#define NUM_5           5
#define ZERO             0
 int main(void)
 {
     timer_init();
     LCD_init();
	 LCD_smile_init();
	 LCD_like_init();
	 LCD_sad_init();
	 LCD_balona_init();
	 DIO_SetPinDirection(BUTTON0,LOW);
	 DIO_SetPinDirection(BUTTON1,LOW);
	 uint8 question_counter;
	 uint8 loop_counter ;
	 uint8 score=ZERO;
	 uint8 question[QUEST_NUM][QUEST_SIZE]={{"Shakiri num 23 ?"},{"16*.45+.7=7.9  ?"},{"1Dollar=17.25 LE"},{"Avelabs is NUM1?"},{"0X50=80D        ?"}};
	 uint8 yes_no_string[]={"Yes      NO"};
	 	 
	 uint8 String_size=sizeof(question[ZERO]);
	 
     uint8 answer[5]={CORRECT,CORRECT,WRONG,WRONG,CORRECT};
		 for(loop_counter=0;loop_counter<NUM_16;loop_counter++){
			 
			 LCD_balona_display();
		 }
		 LCD_displayStringRowColumn("Welcome",NUM_8,LCD_RAW1,LCD_COLUMN5);
		 timer_mdelay(TIME_1000MS);
		 LCD_clear();

		 
	 for (question_counter=ZERO;question_counter<NUM_5;question_counter++){
		 String_size=sizeof(question[ZERO]);
		 LCD_displayString(question[question_counter],String_size);
		 LCD_sendCommand(LCD_SECOND_LINE);
		 String_size=sizeof(yes_no_string);
		 LCD_displayString(yes_no_string,String_size);
		 while(CORRECT)
		 {
			 timer_mdelay(TIME_5MS);
			 if((DIO_ReadPin(BUTTON0))&&(~DIO_ReadPin(BUTTON1)))
			 {
				 LCD_clear();
				 if(answer[question_counter])
				 {	
					score++;
					for(loop_counter=ZERO;loop_counter<NUM_16;loop_counter++){
						/*LCD_gotoRowColumn(0,i);*/
						LCD_like_display();
					}					
					for(loop_counter=ZERO;loop_counter<NUM_5;loop_counter++)
					{
					LCD_displayStringRowColumn("correct",NUM_8,LCD_RAW1,LCD_COLUMN3);
					timer_mdelay(TIME_100MS);
					LCD_displayStringRowColumn("        ",NUM_8,LCD_RAW1,LCD_COLUMN3);
					timer_mdelay(TIME_100MS);
					}
	
					 timer_mdelay(TIME_500MS);
					 //timer_mdelay(5000);
					 LCD_clear();
					 break;
				 }
				 else
				 {
					 for(loop_counter=ZERO;loop_counter<NUM_16;loop_counter++){
                     /*LCD_gotoRowColumn(0,i);*/
					   LCD_sad_display();
					 }
					 for(loop_counter=ZERO;loop_counter<NUM_5;loop_counter++)
					 {
						 LCD_displayStringRowColumn("wrong!!",NUM_8, LCD_RAW1,LCD_COLUMN3);
						 timer_mdelay(TIME_100MS);
						 LCD_displayStringRowColumn("        ",NUM_8,LCD_RAW1,LCD_COLUMN3);
						 timer_mdelay(TIME_100MS);
					 }					 
					 LCD_clear();
					 
					 break;
				 }
				 
			 }
			 timer_mdelay(NUM_5);
			if(~(DIO_ReadPin(BUTTON0))&&(DIO_ReadPin(BUTTON1)))
			{
				 LCD_clear();

				 if(!answer[question_counter])
				 {   score++;
					 for(loop_counter=ZERO;loop_counter<NUM_16;loop_counter++){
						 /*LCD_gotoRowColumn(0,i);*/
						 LCD_like_display();
					 }
					 for(loop_counter=ZERO;loop_counter<NUM_5;loop_counter++)
					 {
					LCD_displayStringRowColumn("correct",NUM_8,LCD_RAW1,LCD_COLUMN3);
						 timer_mdelay(TIME_100MS);
						 LCD_displayStringRowColumn("        ",NUM_8,LCD_RAW1,LCD_COLUMN3);
						 timer_mdelay(TIME_100MS);
					 }
					 LCD_clear();
					 break;
				 }
				 else
				 {
					for(loop_counter=ZERO;loop_counter<NUM_16;loop_counter++){
						/*LCD_gotoRowColumn(0,i);*/
						LCD_sad_display();
					}
					for(loop_counter=ZERO;loop_counter<NUM_5;loop_counter++)
					{
						LCD_displayStringRowColumn("wrong!!",NUM_8,LCD_RAW1,LCD_COLUMN3);
						timer_mdelay(TIME_100MS);
						LCD_displayStringRowColumn("        ",NUM_8,LCD_RAW1,LCD_COLUMN3);
						timer_mdelay(TIME_100MS);
					}					 
					 LCD_clear();
					 break;
				 }
				 
			 }
			
			 
			 
			 
		 }

	 }
		 
	LCD_displayString("Your score =   ",NUM_15);
	LCD_gotoRowColumn(NUM_1,NUM_13);
	LCD_displayChar('0'+score);
	timer_mdelay(TIME_1000MS);
	LCD_clear();
	 for(loop_counter=ZERO;loop_counter<NUM_16;loop_counter++){
		 LCD_balona_display();
	 }
	 LCD_displayStringRowColumn("SHARAFT Ya Zo2 ",QUEST_SIZE,LCD_RAW1,LCD_COLUMN0);
	 timer_mdelay(TIME_1000MS);
	 LCD_clear();

			  
	 
	 return 0;
 }
/*  uint8 lcd_string[]="hi from here";
uint8 string_size=sizeof(lcd_string)/sizeof(lcd_string[0]);
while(1){
LCD_displayStringRowColumn(lcd_string,string_size,LCD_RAW0,LCD_COLUMN5);

timer_mdelay(TIME_1000MS);
LCD_clear();
timer_mdelay(TIME_1000MS);


}*/


	


