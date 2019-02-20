/*
 * yes_no_challenge.c
 *
 * Created: 2/20/2019 10:45:09 AM
 *  Author: AVE-LAP-016
 */ 
#include "../includes/yes_no_challenge.h"

/* This external function is responsible for initialization of the YES-NO buttons
   of the challenge. it is used inside the start challenge function*/
static void challenge_init(void);
/* This function is responsible for printing of the welcome screen
   of the challenge and wait until you are ready */
static void welcomeScreen(void);
/* This external function is responsible for displaying a custom screen
   when your answer is a correct Answer.
   it is used inside the start challenge function. */
static void LCD_DisplayrightAnswer(void);

/* This external function is responsible for displaying a custom screen
   when your answer is a wrong Answer.it is used inside the start challenge function */
static void LCD_DisplayWrongAnswer(void);

/* This external function is responsible for displaying 
   your final total score . it is used inside the start challenge function
   INPUTS : questions
   array contains your answers
   array contains the correct answers to compare */
static void displayScore(uint8 answers[NO_OF_QUESTIONS],uint8 realAnswers[NO_OF_QUESTIONS]);



static void challenge_init(void)
{
	DIO_SetPinDirection(BUTTON_0,INPUT);
	DIO_SetPinDirection(BUTTON_1,INPUT);
}
static void welcomeScreen(void)
{
	for (uint8 flash_string = 0 ; flash_string < WELCOME_SCREEN_DELAY ; flash_string++)
	{
		LCD_gotoRowColumn(LCD_FIRST_LINE,5);
		LCD_displayString("Welcome");
		timer_delay(100);
		LCD_gotoRowColumn(LCD_SECOND_LINE,0);
		LCD_displayString("To New Challenge");
		timer_delay(100);
		LCD_clear();
	}
	
	LCD_gotoRowColumn(LCD_FIRST_LINE,0);
	LCD_displayString("If you are ready ");
	LCD_gotoRowColumn(LCD_SECOND_LINE,1);
	LCD_displayString("Press button 1 to start ");
	while(DIO_ReadPin(BUTTON_1) == OFF) ;
	LCD_clear();
	
}
extern void startChallenge(sint8 questions[NO_OF_QUESTIONS][SIZE_OF_QUESTION],uint8 answers[NO_OF_QUESTIONS],uint8 realAnswers[NO_OF_QUESTIONS])
{
	challenge_init();
	welcomeScreen();
	uint8 not_answered = YES ;
	for (uint8 i = 0 ; i < NO_OF_QUESTIONS ; i++)
	{
		LCD_displayStringRowColumn(questions[i],LCD_FIRST_LINE,0);
		LCD_displayStringRowColumn("B0-YES",LCD_SECOND_LINE,0);
		LCD_displayStringRowColumn("B1-NO",LCD_SECOND_LINE,10);
		not_answered = 1 ;
		while (not_answered)
		{
			if (DIO_ReadPin(BUTTON_0))
			{
				while(DIO_ReadPin(BUTTON_0));
				answers[i] = YES ;
				if ( answers[i] == realAnswers[i])
				{
					LCD_clear();
					LCD_DisplayrightAnswer();
					timer_delay(ANSWER_STATUS_DELAY);
					not_answered = NO ;
				}
				else
				{
					LCD_clear();
					LCD_DisplayWrongAnswer();
					timer_delay(ANSWER_STATUS_DELAY);
					not_answered = NO ;
				}
				
			}
			else if (DIO_ReadPin(BUTTON_1))
			{
				while(DIO_ReadPin(BUTTON_1));
				answers[i] = NO ;
				if ( answers[i] == realAnswers[i])
				{
					LCD_clear();
					LCD_DisplayrightAnswer();
					timer_delay(ANSWER_STATUS_DELAY);
					not_answered = NO ;
				}
				else
				{
					LCD_clear();
					LCD_DisplayWrongAnswer();
					timer_delay(ANSWER_STATUS_DELAY);
					not_answered = NO ;
				}
			}
		}
		
		LCD_clear();
	}
	displayScore(answers,realAnswers);
}

static void displayScore(uint8 answers[NO_OF_QUESTIONS],uint8 realAnswers[NO_OF_QUESTIONS])
{
	uint8 counter = 0 ;
	uint8 score = 0 ;
	while (counter < NO_OF_QUESTIONS)
	{
		if (answers[counter] == realAnswers[counter])
		{
			score++ ;
		}
		counter++ ;
		
	}
	LCD_clear();
	LCD_displayString("YOUR SCORE IS ");
	LCD_displayChar(score+48);
}
static void LCD_DisplayrightAnswer(void){
	
	sint8 *Right_first_string ="Bravo :)";
	sint8 *Right_Second_string ="You Did It";
	
	uint8 SmileCharacter1[CHARACTER_SIZE] = {0, 1, 2, 4, 8, 16, 16, 16};
	uint8 SmileCharacter2[CHARACTER_SIZE] = {31, 0, 6, 6, 0, 0, 0, 0};
	uint8 SmileCharacter3[CHARACTER_SIZE] = {31, 0, 12, 12, 0, 0, 0, 0};
	uint8 SmileCharacter4[CHARACTER_SIZE] = {0, 16, 8, 4, 2, 1, 1, 1};
	uint8 SmileCharacter5[CHARACTER_SIZE] = {16, 16, 16, 8, 4, 2, 1, 0};
	uint8 SmileCharacter6[CHARACTER_SIZE] = {0, 0, 16, 16, 8, 7, 0, 31};
	uint8 SmileCharacter7[CHARACTER_SIZE] = {0, 0, 1, 1, 2, 28, 0, 31};
	uint8 SmileCharacter8[CHARACTER_SIZE] = {1, 1, 1, 2, 4, 8, 16, 0};
	
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_ONE,SmileCharacter1);
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_TWO,SmileCharacter2);
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_THREE,SmileCharacter3);
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_FOUR,SmileCharacter4);
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_FIVE,SmileCharacter5);
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_SIX,SmileCharacter6);
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_SEVEN,SmileCharacter7);
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_EIGHT,SmileCharacter8);
	
	
	LCD_displayChar(CUSTOM_CHARACTER_ONE);
	timer_delay(DELAY_2_MS);
	LCD_displayChar(CUSTOM_CHARACTER_TWO);
	timer_delay(DELAY_2_MS);
	LCD_displayChar(CUSTOM_CHARACTER_THREE);
	timer_delay(DELAY_2_MS);
	LCD_displayChar(CUSTOM_CHARACTER_FOUR);
	timer_delay(DELAY_2_MS);
	
	LCD_displayStringRowColumn (Right_first_string,LINE_ONE, DigitEight);
	
	LCD_gotoRowColumn(LINE_TWO,DigitOne);
	
	LCD_displayChar(CUSTOM_CHARACTER_FIVE);
	timer_delay(DELAY_2_MS);
	LCD_displayChar(CUSTOM_CHARACTER_SIX);
	timer_delay(DELAY_2_MS);
	LCD_displayChar(CUSTOM_CHARACTER_SEVEN);
	timer_delay(DELAY_2_MS);
	LCD_displayChar(CUSTOM_CHARACTER_EIGHT);
	timer_delay(DELAY_2_MS);
	
	
	LCD_displayStringRowColumn (Right_Second_string,LINE_TWO, DigitSeven);
	
}

static void LCD_DisplayWrongAnswer(void){
	sint8* wrong_first_string="Sorry :(";
	sint8* wrong_Second_string="Try Again!";
	
	uint8 SmileCharacter1[CHARACTER_SIZE] = {0, 1, 2, 4, 8, 16, 16, 16};
	uint8 SmileCharacter2[CHARACTER_SIZE] = {31, 0, 6, 6, 0, 0, 0, 0};
	uint8 SmileCharacter3[CHARACTER_SIZE] = {31, 0, 12, 12, 0, 0, 0, 0};
	uint8 SmileCharacter4[CHARACTER_SIZE] = {0, 16, 8, 4, 2, 1, 1, 1};
	uint8 SmileCharacter5[CHARACTER_SIZE] = {16, 16, 16, 8, 4, 2, 1, 0};
	uint8 SmileCharacter6[CHARACTER_SIZE] = {0, 7, 8, 16, 16, 0, 0, 31};
	uint8 SmileCharacter7[CHARACTER_SIZE] = {0, 28, 2, 1, 1, 0, 0, 31};
	uint8 SmileCharacter8[CHARACTER_SIZE] = {1, 1, 1, 2, 4, 8, 16, 0};
	
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_ONE,SmileCharacter1);
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_TWO,SmileCharacter2);
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_THREE,SmileCharacter3);
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_FOUR,SmileCharacter4);
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_FIVE,SmileCharacter5);
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_SIX,SmileCharacter6);
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_SEVEN,SmileCharacter7);
	LCD_DisplayCustomChar(CUSTOM_CHARACTER_EIGHT,SmileCharacter8);
	
	
	LCD_displayChar(CUSTOM_CHARACTER_ONE);
	timer_delay(DELAY_2_MS);
	LCD_displayChar(CUSTOM_CHARACTER_TWO);
	timer_delay(DELAY_2_MS);
	LCD_displayChar(CUSTOM_CHARACTER_THREE);
	timer_delay(DELAY_2_MS);
	LCD_displayChar(CUSTOM_CHARACTER_FOUR);
	timer_delay(DELAY_2_MS);
	
	LCD_displayStringRowColumn (wrong_first_string,LINE_ONE, DigitEight);
	
	LCD_gotoRowColumn(LINE_TWO,DigitOne);
	
	LCD_displayChar(CUSTOM_CHARACTER_FIVE);
	timer_delay(DELAY_2_MS);
	LCD_displayChar(CUSTOM_CHARACTER_SIX);
	timer_delay(DELAY_2_MS);
	LCD_displayChar(CUSTOM_CHARACTER_SEVEN);
	timer_delay(DELAY_2_MS);
	LCD_displayChar(CUSTOM_CHARACTER_EIGHT);
	timer_delay(DELAY_2_MS);
	
	LCD_displayStringRowColumn (wrong_Second_string,LINE_TWO, DigitSeven);
	
}