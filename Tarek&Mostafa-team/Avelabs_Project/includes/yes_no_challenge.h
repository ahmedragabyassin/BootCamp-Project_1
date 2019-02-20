/*
 * yes_no_challenge.h
 *
 * Created: 2/20/2019 10:45:26 AM
 *  Author: AVE-LAP-016
 */ 


#ifndef YES_NO_CHALLENGE_H_
#define YES_NO_CHALLENGE_H_

#include "../includes/lcd.h"
#include "../includes/DIO.h"
#include "../includes/timer.h"

#define YES (uint8)1
#define NO (uint8)0
#define WELCOME_SCREEN_DELAY 5 // 5 * 200 milliseconds
#define YES_BUTTON BUTTON_0
#define NO_BUTTON BUTTON_1
#define QUESTION_DEAD_LINE 100
#define ANSWER_STATUS_DELAY 2000 // 2000 MS
enum{
	DigitOne = 0,
	DigitTwo = 1,
	DigitThree = 2,
	DigitFour = 3,
	DigitFive = 4,
	DigitSix = 5,
	DigitSeven = 6,
	DigitEight = 7,
	DigitNine = 8,
	DigitTen = 9,
	DigitEleven = 10,
	DigitTwelve = 11,
	DigitThirteen = 12,
	DigitFourteen = 13,
	DigitFiveteen = 14,
	DigitSixteen = 15,
};

#define  CUSTOM_CHARACTER_ONE	0x00U
#define  CUSTOM_CHARACTER_TWO	0x01U
#define  CUSTOM_CHARACTER_THREE 0x02U
#define  CUSTOM_CHARACTER_FOUR	0x03U
#define  CUSTOM_CHARACTER_FIVE	0x04U
#define  CUSTOM_CHARACTER_SIX	0x05U
#define  CUSTOM_CHARACTER_SEVEN 0x06U
#define  CUSTOM_CHARACTER_EIGHT 0x07U

#define CHARACTER_SIZE 8U
#define DELAY_2_MS		2U

#define LINE_ONE 1U
#define LINE_TWO 2U

#define FIRST_WRITE_STRING_SIZE 8U
#define SECOND_WRITE_STRING_SIZE 10U

#define FIRST_WRONG_STRING_SIZE 8U
#define SECOND_WRONG_STRING_SIZE 11U

#define NO_OF_QUESTIONS 5
#define SIZE_OF_QUESTION 17


/* This external function is responsible for start the challenge.
   it is used inside the start challenge function
   INPUTS : questions 
            array to collect your answers
			array contains the correct answers to compare */
extern void startChallenge(sint8 questions[NO_OF_QUESTIONS][SIZE_OF_QUESTION],uint8 answers[NO_OF_QUESTIONS],uint8 realAnswers[NO_OF_QUESTIONS]);



#endif /* YES_NO_CHALLENGE_H_ */