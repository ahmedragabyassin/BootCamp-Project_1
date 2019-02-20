/*
 * challenge.c
 *
 * Created: 2/20/2019 2:04:27 PM
 *  Author: Yassin
 */ 
#include "../Includes/Challenge.h"



/************************************************************************/
/* Function: Challenge                                                  */
/* @param: Void			                                                */
/* return: void			                                                */
/* Description: function display questions on LCD and handle the case   */
/*				and score of the player then display it on LCD          */
/************************************************************************/
void Challenge(void)
{
	/************************************************************************/
	/* Array of hexa to draw pattern on LCD                                 */
	/************************************************************************/
	uint8 Happy[NUM_8]	= {0x00,0x0A,0x00,0x00,0x11,0x1F,0x0E,0x00};
	uint8 Sad[NUM_8]	= {0x00,0x0A,0x00,0x00,0x0E,0x1F,0x11,0x00};
	
	/************************************************************************/
	/* hold addresses of CGRAM and DDRAM of drawn patterns                  */
	/************************************************************************/
	uint8 add_char_happy  = HAPPY_CHAR_ADDRESS;
	uint8 add_char_sad	  = SAD_CHAR_ADDRESS;
	uint8 ADD_CGRAM_happy = HAPPY_CGRAM_ADDRESS;
	uint8 ADD_CGRAM_sad	  = SAD_CGRAM_ADDRESS;
	
	/************************************************************************/
	/* Config pins of buttons, Buzzer and LEDs                           */
	/************************************************************************/
	DIO_SetPinDirection(NO_BUTTON,IN);
	DIO_SetPinDirection(YES_BUTTON,IN);
	DIO_SetPinDirection(BUZZER_PIN,OUT);
	DIO_WritePin(NO_BUTTON,HIGH);
	DIO_WritePin(YES_BUTTON,HIGH);
	DIO_SetPinDirection(LED0,OUT);
	DIO_SetPinDirection(LED1,OUT);
	DIO_SetPinDirection(LED2,OUT);
	DIO_SetPinDirection(LED3,OUT);
	
	/************************************************************************/
	/* hold score of correct questions                                      */
	/************************************************************************/
	uint8 score = NUM_0;
	
	/************************************************************************/
	/* array of strings to questions to be displayed on LCD                 */
	/************************************************************************/
	uint8 Welcome[NUM_16]		= "Welcome";
	uint8 Start_ch[NUM_16]		= "Start challenge";
	uint8 question1[NUM_16]		= "Ghana capital is";
	uint8 question1_a[NUM_16]	= "addis ababa?";
	uint8 question2[NUM_16]		= "5 + 8 * 9 = ";
	uint8 question2_a[NUM_16]	= " 77 ";
	uint8 question3[NUM_16]		= "Salah is Fa5r";
	uint8 question3_a[NUM_16]	= " El arab ?";
	uint8 question4[NUM_16]		= "friends Rachel";
	uint8 question4_a[NUM_16]	= "sister is:Janice";
	uint8 question5[NUM_16]		= "Amr Diab age ";
	uint8 question5_a[NUM_16]	= " is 57 ?";
	uint8 Score[NUM_16]			= "Your Score:";
	uint8 Genuis[NUM_16]		= "YA GENUIS ";
	uint8 WEll_done[NUM_16]		= "WELL DONE";
	uint8 Looser[NUM_16]		= "YA LOOSER";
	uint8 Play_again[NUM_16]	= "Wanna Play again";
	uint8 Next[NUM_16]			= "press 0 no 1";
	uint8 Thanks[NUM_16]		= "Thanks";
	
	/************************************************************************/
	/* Welcome message before challenge start                               */
	/************************************************************************/
	LCD_GotoRowColumn(LCD_ROW1,LCD_COL5);
	LCD_DisplayString(Welcome);
	_delay_ms(ONE_1000_MS);
	LCD_Clear();
	LCD_DisplayString(Start_ch);
	_delay_ms(ONE_1000_MS);
	LCD_Clear();
	/************************************************************************/
	/* LOOP for five questions                                              */
	/************************************************************************/
	for (uint8 i = NUM_0; i < NUM_5; i++)
	{
		switch(i){
			case NUM_0:
			LCD_DisplayString(question1);
			LCD_DisplayStringRowColumn(LCD_ROW2,LCD_COL1,question1_a);
			while(!DIO_ReadPin(NO_BUTTON) && !DIO_ReadPin(YES_BUTTON));
			if (DIO_ReadPin(NO_BUTTON))
			{
				LCD_Clear();
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL7);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL7);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL6);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL6);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL8);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL8);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL9);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL9);
				_delay_ms(ONE_1000_MS);
				_delay_ms(ONE_1000_MS);
				score++;
			}
			else if(DIO_ReadPin(YES_BUTTON))
			{
				LCD_Clear();
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL7);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL7);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL6);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL6);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL8);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL8);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL9);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL9);
				DIO_WritePin(BUZZER_PIN,HIGH);
				_delay_ms(HUNDRED_MS);
				DIO_WritePin(BUZZER_PIN,LOW);
				_delay_ms(HUNDRED_MS);
				DIO_WritePin(BUZZER_PIN,HIGH);
				_delay_ms(HUNDRED_MS);
				DIO_WritePin(BUZZER_PIN,LOW);
				_delay_ms(ONE_1000_MS);
				DIO_WritePin(BUZZER_PIN,HIGH);
				_delay_ms(HUNDRED_MS);
				DIO_WritePin(BUZZER_PIN,LOW);
				_delay_ms(HUNDRED_MS);
				DIO_WritePin(BUZZER_PIN,HIGH);
				_delay_ms(HUNDRED_MS);
				DIO_WritePin(BUZZER_PIN,LOW);
				_delay_ms(ONE_1000_MS);
				
			}
			LCD_Clear();
			break;
			case NUM_1:
			LCD_DisplayString(question2);
			LCD_DisplayStringRowColumn(LCD_ROW2,LCD_COL1,question2_a);
			while(!DIO_ReadPin(NO_BUTTON) && !DIO_ReadPin(YES_BUTTON));
			if (DIO_ReadPin(YES_BUTTON))
			{
				LCD_Clear();
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL7);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL7);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL6);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL6);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL8);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL8);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL9);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL9);
				_delay_ms(ONE_1000_MS);
				score++;
			}
			else if(DIO_ReadPin(NO_BUTTON))
			{
				LCD_Clear();
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL7);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL7);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL6);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL6);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL8);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL8);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL9);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL9);
				DIO_WritePin(BUZZER_PIN,HIGH);
				_delay_ms(ONE_1000_MS);
				_delay_ms(ONE_1000_MS);
				DIO_WritePin(BUZZER_PIN,LOW);
			}
			LCD_Clear();
			break;
			case NUM_2:
			LCD_DisplayString(question3);
			LCD_DisplayStringRowColumn(LCD_ROW2,LCD_COL1,question3_a);
			while(!DIO_ReadPin(NO_BUTTON) && !DIO_ReadPin(YES_BUTTON));
			if (DIO_ReadPin(YES_BUTTON))
			{
				LCD_Clear();
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL7);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL7);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL6);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL6);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL8);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL8);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL9);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL9);
				_delay_ms(ONE_1000_MS);
				_delay_ms(ONE_1000_MS);
				score++;
			}
			else if(DIO_ReadPin(NO_BUTTON))
			{
				LCD_Clear();
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL7);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL7);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL6);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL6);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL8);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL8);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL9);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL9);
				DIO_WritePin(BUZZER_PIN,HIGH);
				_delay_ms(ONE_1000_MS);
				_delay_ms(ONE_1000_MS);
				DIO_WritePin(BUZZER_PIN,LOW);
			}
			LCD_Clear();
			break;
			case NUM_3:
			LCD_DisplayString(question4);
			LCD_DisplayStringRowColumn(LCD_ROW2,LCD_COL1,question4_a);
			while(!DIO_ReadPin(NO_BUTTON) && !DIO_ReadPin(YES_BUTTON));
			if (DIO_ReadPin(NO_BUTTON))
			{
				LCD_Clear();
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL7);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL7);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL6);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL6);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL8);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL8);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL9);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL9);
				_delay_ms(ONE_1000_MS);
				_delay_ms(ONE_1000_MS);
				score++;
			}
			else if(DIO_ReadPin(YES_BUTTON))
			{
				LCD_Clear();
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL7);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL7);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL6);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL6);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL8);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL8);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL9);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL9);
				DIO_WritePin(BUZZER_PIN,HIGH);
				_delay_ms(ONE_1000_MS);
				_delay_ms(ONE_1000_MS);
				DIO_WritePin(BUZZER_PIN,LOW);
			}
			LCD_Clear();
			break;
			
			case NUM_4:
			LCD_DisplayString(question5);
			LCD_DisplayStringRowColumn(LCD_ROW2,LCD_COL1,question5_a);
			while(!DIO_ReadPin(NO_BUTTON) && !DIO_ReadPin(YES_BUTTON));
			_delay_ms(TEN_MS);
			if (DIO_ReadPin(YES_BUTTON))
			{
				LCD_Clear();
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL7);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL7);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL6);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL6);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL8);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL8);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW1,LCD_COL9);
				LCD_GenerateCharacter(Happy, ADD_CGRAM_happy,add_char_happy,LCD_ROW2,LCD_COL9);
				_delay_ms(ONE_1000_MS);
				_delay_ms(ONE_1000_MS);
				score++;
			}
			else if(DIO_ReadPin(NO_BUTTON))
			{
				LCD_Clear();
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL7);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL7);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL6);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL6);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL8);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL8);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW1,LCD_COL9);
				LCD_GenerateCharacter(Sad, ADD_CGRAM_sad,add_char_sad,LCD_ROW2,LCD_COL9);
				DIO_WritePin(BUZZER_PIN,HIGH);
				_delay_ms(ONE_1000_MS);
				_delay_ms(ONE_1000_MS);
				DIO_WritePin(BUZZER_PIN,LOW);
			}
			LCD_Clear();
			break;
		}
	}
	
	switch(score){
		case NUM_1:
			LCD_DisplayString(Score);
			LCD_GotoRowColumn(LCD_ROW1, LCD_COL13);
			LCD_DisplayChar(CHAR_1);
			LCD_GotoRowColumn(LCD_ROW2, LCD_COL7);
			LCD_DisplayString(Looser);
			DIO_WritePin(BUZZER_PIN,HIGH);
			_delay_ms(ONE_1000_MS);
			_delay_ms(ONE_1000_MS);
			DIO_WritePin(BUZZER_PIN,LOW);
			LCD_Clear();
			break;
		case NUM_2:
			LCD_DisplayString(Score);
			LCD_GotoRowColumn(LCD_ROW1, LCD_COL13);
			LCD_DisplayChar(CHAR_2);
			LCD_GotoRowColumn(LCD_ROW2, LCD_COL7);
			LCD_DisplayString(Looser);
			DIO_WritePin(BUZZER_PIN,HIGH);
			_delay_ms(ONE_1000_MS);
			_delay_ms(ONE_1000_MS);
			DIO_WritePin(BUZZER_PIN,LOW);
			LCD_Clear();
			break;
		case NUM_3:
			LCD_DisplayString(Score);
			LCD_GotoRowColumn(LCD_ROW2, LCD_COL9);
			LCD_DisplayChar(CHAR_3);
			DIO_WritePin(LED0,HIGH);
			_delay_ms(HUNDRED_MS);
			DIO_WritePin(LED0,LOW);
			DIO_WritePin(LED0,HIGH);
			_delay_ms(HUNDRED_MS);
			DIO_WritePin(LED0,LOW);
			DIO_WritePin(LED0,HIGH);
			_delay_ms(ONE_1000_MS);
			DIO_WritePin(LED0,LOW);
			DIO_WritePin(LED0,HIGH);
			_delay_ms(HUNDRED_MS);
			DIO_WritePin(LED0,LOW);
			_delay_ms(ONE_1000_MS);
			LCD_Clear();
			break;
		case NUM_4:
			LCD_DisplayString(Score);
			LCD_GotoRowColumn(LCD_ROW1, LCD_COL13);
			LCD_DisplayChar(CHAR_4);
			LCD_GotoRowColumn(LCD_ROW2, LCD_COL6);
			LCD_DisplayString(WEll_done);
			DIO_WritePin(LED0,HIGH);
			_delay_ms(TEN_MS);
			DIO_WritePin(LED0,LOW);
			DIO_WritePin(LED1,HIGH);
			_delay_ms(TEN_MS);
			DIO_WritePin(LED1,LOW);
			DIO_WritePin(LED2,HIGH);
			_delay_ms(TEN_MS);
			DIO_WritePin(LED2,LOW);
			DIO_WritePin(LED0,HIGH);
			_delay_ms(TEN_MS);
			DIO_WritePin(LED0,LOW);
			_delay_ms(ONE_1000_MS);
			DIO_WritePin(LED1,HIGH);
			_delay_ms(TEN_MS);
			DIO_WritePin(LED1,LOW);
			DIO_WritePin(LED2,HIGH);
			_delay_ms(TEN_MS);
			DIO_WritePin(LED2,LOW);
			DIO_WritePin(LED0,HIGH);
			_delay_ms(TEN_MS);
			DIO_WritePin(LED0,LOW);
			DIO_WritePin(LED1,HIGH);
			_delay_ms(TEN_MS);
			DIO_WritePin(LED1,LOW);
			_delay_ms(ONE_1000_MS);
			LCD_Clear();
			break;
		case NUM_5:
			LCD_DisplayString(Score);
			LCD_GotoRowColumn(LCD_ROW1, LCD_COL13);
			LCD_DisplayChar(CHAR_5);
			LCD_GotoRowColumn(LCD_ROW2, LCD_COL6);
			LCD_DisplayString(Genuis);
			Display_Leds();
			_delay_ms(ONE_1000_MS);
			LCD_Clear();
			break;
		default:
			LCD_DisplayString(Score);
			LCD_GotoRowColumn(LCD_ROW1, LCD_COL13);
			LCD_DisplayChar(CHAR_2);
			LCD_GotoRowColumn(LCD_ROW2, LCD_COL7);
			LCD_DisplayString(Looser);
			DIO_WritePin(BUZZER_PIN,HIGH);
			_delay_ms(ONE_1000_MS);
			_delay_ms(ONE_1000_MS);
			DIO_WritePin(BUZZER_PIN,LOW);
			LCD_Clear();
			break;
	}
	LCD_DisplayString(Play_again);
	LCD_GotoRowColumn(LCD_ROW2, LCD_COL1);
	LCD_DisplayString(Next);
	while(!DIO_ReadPin(YES_BUTTON) && !DIO_ReadPin(YES_BUTTON));
	if (DIO_ReadPin(NO_BUTTON))
	{
		LCD_Clear(); 
		LCD_DisplayString(Thanks);
	} 
	else if(DIO_ReadPin(YES_BUTTON))
	{
		LCD_Clear();
	}
	LCD_Clear();
}

/************************************************************************/
/* Function: Display LEDs                                               */
/* @param: void			                                                */
/* return: void										                    */
/* Description: Display LEDs in a sequence                              */
/************************************************************************/
void Display_Leds(void)
{
	for(uint8 i = NUM_0; i < NUM_5; i++)
	{
		DIO_WritePin(LED0,HIGH);
		DIO_WritePin(LED1,HIGH);
		DIO_WritePin(LED2,HIGH);
		DIO_WritePin(LED3,HIGH);
		_delay_ms(ONE_1000_MS);
		DIO_WritePin(LED0,LOW);
		DIO_WritePin(LED1,LOW);
		DIO_WritePin(LED2,LOW);
		DIO_WritePin(LED3,LOW);
		_delay_ms(HUNDRED_MS);
	}
}
