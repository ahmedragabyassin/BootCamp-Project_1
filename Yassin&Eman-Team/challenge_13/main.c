/*
 * challenge_13.c
 *
 * Created: 2/18/2019 11:54:02 AM
 * Author : Yassin
 */ 

#include "Includes/BCDSevSegment.h"
#include "Includes/KeyPad.h"
#include "Includes/Lcd.h"
#include "Includes/CommonNumbers.h"
#include "Includes/Challenge.h"

int main(void)
{	
	
	/************************************************************************/
	/* Test challenge                                                       */
	/************************************************************************/
	#if ENABLE_CODE
	LCD_Init();
	#endif
	
	/************************************************************************/
	/* Test LCD goto row and column                                         */
	/************************************************************************/
	#if STOP_CODE
	LCD_Init();
	LCD_GotoRowColumn(LCD_ROW1,LCD_COL7);
	#endif
	
	
	/************************************************************************/
	/* test LCD driver                                                      */
	/************************************************************************/
	#if STOP_CODE
	LCD_Init();
	#endif
	
	#if STOP_CODE
	LCD_DisplayChar('Y');
	LCD_DisplayChar('A');
	LCD_DisplayChar('S');
	LCD_DisplayChar('S');
	LCD_DisplayChar('I');
	LCD_DisplayChar('N');
	#endif
	
	/************************************************************************/
	/* Test Seven Segment and Keypad Drivers                                */
	/************************************************************************/
	#if STOP_CODE
	DIO_SetPinDirection(SEGMENT_A,OUT);
	DIO_SetPinDirection(SEGMENT_B,OUT);
	DIO_SetPinDirection(SEGMENT_C,OUT);
	DIO_SetPinDirection(SEGMENT_D,OUT);
	KeyPad_Init();
	uint8 pressed_key = NUM_0;
	#endif
	
	
    while (NUM_1) 
    {
		
		/************************************************************************/
		/* Test Challenge                                                       */
		/************************************************************************/
		#if ENABLE_CODE
			Challenge(); 
		#endif
		
		/************************************************************************/
		/* Test Seven Segment and Keypad Drivers                                */
		/************************************************************************/
		#if STOP_CODE
		KeyPad_Init();
		BCDSevSegment_Enable(SEG1_EN);
		pressed_key = KeyPad_GetPressedKey();
		BCDSevSegment_DisplayNo(pressed_key);
		BCDSevSegment_Disable(SEG1_EN);
		/BCDSevSegment_Disable(SEG2_EN);
		BCDSevSegment_Disable(SEG3_EN);
		BCDSevSegment_Disable(SEG4_EN);
		_delay_us(FIVE_MS);
		BCDSevSegment_Enable(SEG2_EN);
		BCDSevSegment_DisplayNo(NUM_9);
		BCDSevSegment_Disable(SEG1_EN);
		BCDSevSegment_Disable(SEG2_EN);
		BCDSevSegment_Disable(SEG3_EN);
		BCDSevSegment_Disable(SEG4_EN);
		_delay_us(FIVE_MS);
		BCDSevSegment_Enable(SEG3_EN);
		BCDSevSegment_DisplayNo(NUM_9);
		BCDSevSegment_Disable(SEG1_EN);
		BCDSevSegment_Disable(SEG2_EN);
		BCDSevSegment_Disable(SEG3_EN);
		BCDSevSegment_Disable(SEG4_EN);
		_delay_us(FIVE_MS);
		BCDSevSegment_Enable(SEG4_EN);
		BCDSevSegment_DisplayNo(NUM_1);
		BCDSevSegment_Disable(SEG1_EN);
		BCDSevSegment_Disable(SEG2_EN);
		BCDSevSegment_Disable(SEG3_EN);
		BCDSevSegment_Disable(SEG4_EN);
		_delay_us(FIVE_MS); 
		#endif
		
    }
}

