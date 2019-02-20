/*
 * LCD.c
 *
 * Created: TWO_MS/19/TWO_MS019 11:14:59 AM
 *  Author: AVE-LAP-064
 */ 

#include "LCD.h"


 /*  LCD initialization
  *  PARAM : void
  *  input : void
  *  output: void
  *  i/o   : void 
  *  used to initialize LCD with 4bit mode,clear screen,enable cursor
  *                              */
void LCD_init(void)
{   /* Setting Direction of LCD PORT */
	DIO_SetPinDirection(LCD_RS,HIGH); 
	DIO_SetPinDirection(LCD_RW,HIGH);
	DIO_SetPinDirection(LCD_E,HIGH);
	DIO_SetPinDirection(D4,HIGH);
	DIO_SetPinDirection(D5,HIGH);
	DIO_SetPinDirection(D6,HIGH);
	DIO_SetPinDirection(D7,HIGH);
	DIO_WritePin(LCD_E,LOW);
	/*Clear Enable */
	Clear_bit(LCD_PRT,LCD_E); 
	Delay(TWO_MS); 
	/* Enable 4bit mode */
	LCD_sendCommand(CMND_4BIT_MODE); 
	LCD_sendCommand(CMND_4BIT);
	/* Enable two lines in 4 bit mode*/
	LCD_sendCommand(CMND_TWO_LINES);
	/*Display on and cursor on */
	LCD_sendCommand(DISPLAY_ON);
	/* Clean LCD */
	LCD_sendCommand(CLEAR_SCREEN);
	/* shift cursor right */
	LCD_sendCommand(SHIFT_CURSOR);
	_delay_ms(TWO_MS);
}
 /*  LCD send commands
  *  PARAM : Command
  *  input : CMND
  *  output: void
  *  i/o   : void 
  *  used to initialize LCD with 4bit mode,clear screen,enable cursor
  *                              */
void LCD_sendCommand(uint8 CMND)
{   /* MASK PORT and send high nibble */
	 DIO_WritePin(D4,Get_bit(CMND,D4));
	 DIO_WritePin(D5,Get_bit(CMND,D5));
	 DIO_WritePin(D6,Get_bit(CMND,D6));
	 DIO_WritePin(D7,Get_bit(CMND,D7));
	 Delay(TWO_MS);
	/* Choose Command and Write option */
	Clear_bit(LCD_PRT,LCD_RS);
	Clear_bit(LCD_PRT,LCD_RW);
	/* Enable falling edge to latch information */
	Set_bit(LCD_PRT,LCD_E);
	_delay_ms(TWO_MS);
	Clear_bit(LCD_PRT,LCD_E);
	Delay(TWO_MS);
	/* Mask PORT and send low nibble */
	DIO_WritePin(D4,Get_bit(CMND,D0));
	DIO_WritePin(D5,Get_bit(CMND,D1));
	DIO_WritePin(D6,Get_bit(CMND,D2));
	DIO_WritePin(D7,Get_bit(CMND,D3));
	/* Choose Command and Write option */
	Set_bit(LCD_PRT,LCD_E);
	Delay(TWO_MS);
	Clear_bit(LCD_PRT,LCD_E);
	Delay(TWO_MS);

}
 /*  LCD  DisplayChar 
  *  PARAM : Data
  *  input : data
  *  output: void
  *  i/o   : void 
  *  used to display character on LCD 
  *                              */
void LCD_displayChar(uint8 data)
{       /* MASK PORT and send high nibble */
	     DIO_WritePin(D4,Get_bit(data,D4));
	     DIO_WritePin(D5,Get_bit(data,D5));
	     DIO_WritePin(D6,Get_bit(data,D6));
	     DIO_WritePin(D7,Get_bit(data,D7));
		/* Choose Data register and Write option */
		Set_bit(LCD_PRT,LCD_RS);
		Clear_bit(LCD_PRT,LCD_RW);
		/* Enable falling edge to latch information */
		Set_bit(LCD_PRT,LCD_E);
		Delay(TWO_MS);
		Clear_bit(LCD_PRT,LCD_E);
		Delay(TWO_MS);
		/* Mask PORT and send low nibble */
		DIO_WritePin(D4,Get_bit(data,D0));
		DIO_WritePin(D5,Get_bit(data,D1));
		DIO_WritePin(D6,Get_bit(data,D2));
		DIO_WritePin(D7,Get_bit(data,D3));
		/* Choose Command and Write option */
		Set_bit(LCD_PRT,LCD_E);
		Delay(TWO_MS);
		Clear_bit(LCD_PRT,LCD_E);;
		Delay(TWO_MS);
}
 /*  LCD display string
  *  PARAM : string
  *  input : *ptr
  *  output: void
  *  i/o   : void 
  * used to display string on LCD
  *                              */
void LCD_displayString(uint8 *ptr)
{  /* send each character alone from string */
	uint8 i=LOW;
	#ifdef FOUR_BIT
			while(ptr[i]!= 0)
				{	
					LCD_displayChar(ptr[i]);
					i++;
				}
	#else
			while(ptr[i]!= 0)
			{
				LCD_displayChar_Eight_bit(ptr[i]);
				i++;
			}
	
	#endif
}
 /*  LCD go to rowCol
  *  PARAM : row,col
  *  input : row,col
  *  output: void
  *  i/o   : void 
  *  used to go to certain location in lcd
  *                              */
void LCD_gotoRowColumn(uint8 row,uint8 col)
{   /* choose row and col to begin with */
	
	uint8 arr_pos[]={ROW_ONE,COL_ONE};
	LCD_sendCommand((arr_pos[row]+col));
	
}
 /*  LCD clear
  *  PARAM : void
  *  input : void
  *  output: void
  *  i/o   : void 
  *  Clearing LCD Screen
  *                              */
void LCD_clear(void)
{  /* Clear command */
	#ifdef FOUR_BIT
	    LCD_sendCommand(CLEAR_SCREEN);
	#else
	    LCD_sendCommand_Eight_bit(CLEAR_SCREEN);
	#endif
	
	
	Delay(ONE_MS);
}
 /*  LCD DisplayStringRowCol
  *  PARAM : Command
  *  input : CMND
  *  output: void
  *  i/o   : void 
  *  used to initialize LCD with 4bit mode,clear screen,enable cursor
  *                              */
void LCD_displayStringRowColumn(uint8 *ptr,uint8 row,uint8 col)
{   LCD_gotoRowColumn(row,col);
	Delay(TEN_MS);
	uint8 i=LOW;
	#ifdef FOUR_BIT
	while(ptr[i]!= 0)
	{
		LCD_displayChar(ptr[i]);
		i++;
	}
	#else
	while(ptr[i]!= 0)
	{
		LCD_displayChar_Eight_bit(ptr[i]);
		i++;
	}
	
	#endif
}



/*-------------------------------------------------------EIGHT_BIT_MODE--------------------------------------------------------------*/
 /*  LCD initialization
  *  PARAM : void
  *  input : void
  *  output: void
  *  i/o   : void 
  *  used to initialize LCD with 8bit mode,clear screen,enable cursor
  *                              */
void LCD_init_Eight_bit(void)
{
		DIO_SetPinDirection(LCD_RS,HIGH);
		DIO_SetPinDirection(LCD_RW,HIGH);
		DIO_SetPinDirection(LCD_E,HIGH);
		DIO_SetPinDirection(D0,HIGH);
		DIO_SetPinDirection(D1,HIGH);
		DIO_SetPinDirection(D2,HIGH);
		DIO_SetPinDirection(D3,HIGH);
		DIO_SetPinDirection(D4,HIGH);
		DIO_SetPinDirection(D5,HIGH);
		DIO_SetPinDirection(D6,HIGH);
		DIO_SetPinDirection(D7,HIGH);
		DIO_WritePin(LCD_E,LOW);
		/*Clear Enable */
		Clear_bit(LCD_PRT,LCD_E);
		Delay(TWO_MS);
		/* Enable 8bit mode */
		LCD_sendCommand(CMND_8BIT_MODE); 
		/*Display on and cursor on */
		LCD_sendCommand(DISPLAY_ON);
		/* Clean LCD */
		LCD_sendCommand(CLEAR_SCREEN);
		/* shift cursor right */
		LCD_sendCommand(SHIFT_CURSOR);
		_delay_ms(TWO_MS);
}

 /*  LCD send commands
  *  PARAM : Command
  *  input : CMND
  *  output: void
  *  i/o   : void 
  *  used to initialize LCD with 8bit mode,clear screen,enable cursor
  *                              */
void LCD_sendCommand_Eight_bit(uint8 CMND)
{ 
	   	DIO_WritePin(D0,Get_bit(CMND,D0));
	   	DIO_WritePin(D1,Get_bit(CMND,D1));
	   	DIO_WritePin(D2,Get_bit(CMND,D2));
	   	DIO_WritePin(D3,Get_bit(CMND,D3));
	    DIO_WritePin(D4,Get_bit(CMND,D4));
	    DIO_WritePin(D5,Get_bit(CMND,D5));
	    DIO_WritePin(D6,Get_bit(CMND,D6));
	    DIO_WritePin(D7,Get_bit(CMND,D7));
		/* Choose Data register and Write option */
		Clear_bit(LCD_PRT,LCD_RS);
		Clear_bit(LCD_PRT,LCD_RW);
		/* Enable falling edge to latch information */
		Set_bit(LCD_PRT,LCD_E);
		_delay_ms(TWO_MS);
		Clear_bit(LCD_PRT,LCD_E);
		Delay(TWO_MS);
}

 /*  LCD  DisplayChar 
  *  PARAM : Data
  *  input : data
  *  output: void
  *  i/o   : void 
  *  used to display character on LCD 
  *                              */
void LCD_displayChar_Eight_bit(uint8 data)
{
		   	DIO_WritePin(D0,Get_bit(data,D0));
		   	DIO_WritePin(D1,Get_bit(data,D1));
		   	DIO_WritePin(D2,Get_bit(data,D2));
		   	DIO_WritePin(D3,Get_bit(data,D3));
		   	DIO_WritePin(D4,Get_bit(data,D4));
		   	DIO_WritePin(D5,Get_bit(data,D5));
		   	DIO_WritePin(D6,Get_bit(data,D6));
		   	DIO_WritePin(D7,Get_bit(data,D7));
			/* Choose Data register and Write option */
		   	Set_bit(LCD_PRT,LCD_RS);
		   	Clear_bit(LCD_PRT,LCD_RW);
		   	/* Enable falling edge to latch information */
		   	Set_bit(LCD_PRT,LCD_E);
		   	_delay_ms(TWO_MS);
		   	Clear_bit(LCD_PRT,LCD_E);
		   	Delay(TWO_MS);
} 


void emoji_sad_init(void)
{    
	 
	/* Drawing Sad emoji in LCD*/
		LCD_sendCommand(FIRST_CHAR_LOC);
		LCD_displayChar(D0);
		LCD_displayChar(D8);
		LCD_displayChar(D0);
		LCD_displayChar(D0);
		LCD_displayChar(D3);
		LCD_displayChar(D4);
		LCD_displayChar(D8);
		LCD_displayChar(D0);
		_delay_ms(FIVE_MS);
		LCD_sendCommand(SECOND_CHAR_LOC);
		LCD_displayChar(D0);
		LCD_displayChar(D2);
		LCD_displayChar(D0);
		LCD_displayChar(D0);
		LCD_displayChar(D24);
		LCD_displayChar(D4);
		LCD_displayChar(D2);
		LCD_displayChar(D0);
		
	
	
		_delay_ms(10);
}

void emoji_happy_init(void)
{    /* Drawing happy emoji in LCD */
		Delay(TWO_MS);
		LCD_sendCommand(FIRST_CHAR_LOC);
		LCD_displayChar(D0);
		LCD_displayChar(D4);
		LCD_displayChar(D0);
		LCD_displayChar(D0);
		LCD_displayChar(D8);
		LCD_displayChar(D4);
		LCD_displayChar(D3);
		LCD_displayChar(D0);
		_delay_ms(FIVE_MS);
		LCD_sendCommand(SECOND_CHAR_LOC);
		LCD_displayChar(D0);
		LCD_displayChar(D4);
		LCD_displayChar(D0);
		LCD_displayChar(D0);
		LCD_displayChar(D2);
		LCD_displayChar(D4);
		LCD_displayChar(D24);
		LCD_displayChar(D0);
		
}

void LCD_General_Question(void)
{   uint8 count_right = LOW;    /* init counter for right answers with zero */ 
	uint8 count_wronge = LOW;   /* init counter for wrong answers with zero */
	/* first Question */
	LCD_displayStringRowColumn("7asn mzakr 8051",LOW,LOW);  /* 1st line in LCD */
	LCD_displayStringRowColumn("men mazidi?",HIGH,LOW);    /* 2nd line in LCD */
	Delay(TWO_THOUSAND_MS);
	while(!(DIO_ReadPin(BUTTON0)) && !(DIO_ReadPin(BUTTON1)) );  /* pulling two buttons until one pressed */
	if(!(DIO_ReadPin(BUTTON0))) { /* if answer is wrong show sad emoji */
                                LCD_sendCommand(CLEAR_SCREEN);
								emoji_sad_init();
								LCD_sendCommand(FIRST_LINE);
								LCD_displayChar(LOW);
								LCD_displayChar(HIGH);
								Delay(THREE_THOUSAND_MS);
								count_wronge++;  /* increment counter of wrong answers */
						}
  else {  LCD_sendCommand(CLEAR_SCREEN);  /*if answer is right show happy emoji */
		  emoji_happy_init();
	      LCD_sendCommand(FIRST_LINE);
	      LCD_displayChar(LOW);
	      LCD_displayChar(HIGH);
	      Delay(THREE_THOUSAND_MS);
		  count_right++;  /*increment counter of right answers */
	   }
/* second Question */
   LCD_sendCommand(CLEAR_SCREEN);
   Delay(ONE_THOUSAND_MS);
   	LCD_displayStringRowColumn("HONGKONG is",LOW,LOW);           /* 1st line in LCD */
   	LCD_displayStringRowColumn("Capital of China?",HIGH,LOW);   /* 2nd line in LCD */  /*beijing*/
   	Delay(TWO_THOUSAND_MS);
   	while(!(DIO_ReadPin(BUTTON0)) && !(DIO_ReadPin(BUTTON1)) ); /* pulling two buttons until one pressed */
   	if(!(DIO_ReadPin(BUTTON0))) { /* if answer is wrong show sad emoji */
	   	LCD_sendCommand(CLEAR_SCREEN);
	   	emoji_sad_init();
	   	LCD_sendCommand(FIRST_LINE);
	   	LCD_displayChar(LOW); /*display first char created  */
	   	LCD_displayChar(HIGH); /*display second char created */
	   	Delay(THREE_THOUSAND_MS);
	   	count_wronge++;  /* increment counter of wrong answers */
   	}
   	else {  LCD_sendCommand(CLEAR_SCREEN);   /*if answer is right show happy emoji */
	   	emoji_happy_init();
	   	LCD_sendCommand(FIRST_LINE);
	   	LCD_displayChar(LOW);      /*display first char created  */
	   	LCD_displayChar(HIGH);     /*display second char created */
	   	Delay(THREE_THOUSAND_MS); 
	   	count_right++;                     /* increment counter of right answers */
   	}
/* Third Question */
   LCD_sendCommand(CLEAR_SCREEN);  
   Delay(ONE_THOUSAND_MS);
   LCD_displayStringRowColumn("Currency of",LOW,LOW);       /* 1st line in LCD */
   LCD_displayStringRowColumn("Chile is Rubee?",HIGH,LOW);  /* Peso */  /*2nd line in LCD */
   Delay(TWO_THOUSAND_MS);
   while(!(DIO_ReadPin(BUTTON0)) && !(DIO_ReadPin(BUTTON1)) );   /* pulling two buttons until one pressed */
   if(!(DIO_ReadPin(BUTTON0))) {                                 /* if answer is wrong show sad emoji */
	   LCD_sendCommand(CLEAR_SCREEN);                            /*if answer is right show happy emoji */
	   emoji_sad_init();
	   LCD_sendCommand(FIRST_LINE); 
	   LCD_displayChar(LOW);                                     /*display first char created  */
	   LCD_displayChar(HIGH);                                    /*display second char created */
	   Delay(THREE_THOUSAND_MS);
	   count_wronge++;                                           /* increment counter of wrong answers */
   }
   else {  LCD_sendCommand(CLEAR_SCREEN);                        /*if answer is right show happy emoji */
	   emoji_happy_init();
	   LCD_sendCommand(FIRST_LINE);
	   LCD_displayChar(LOW);                                     /*display first char created  */
	   LCD_displayChar(HIGH);									 /*display second char created */
	   Delay(THREE_THOUSAND_MS);
	   count_right++;										     /* increment counter of right answers */
   }
  /* fourth Question */
  LCD_sendCommand(CLEAR_SCREEN);
  Delay(ONE_THOUSAND_MS);  
  LCD_displayStringRowColumn("CapitalOf Chile",LOW,LOW);       /* 1st line in LCD */        
  LCD_displayStringRowColumn("is Maipu ?",HIGH,LOW);  /*santiago */ /* 2nd line in LCD */
  Delay(TWO_THOUSAND_MS);
  while(!(DIO_ReadPin(BUTTON0)) && !(DIO_ReadPin(BUTTON1)) );    /* pulling two buttons until one pressed */
  if(!(DIO_ReadPin(BUTTON0))) {                                  /* if answer is wrong show sad emoji */
	  LCD_sendCommand(CLEAR_SCREEN);                    
	  emoji_sad_init();
	  LCD_sendCommand(FIRST_LINE);
	  LCD_displayChar(LOW);                                      /*display first char created  */
	  LCD_displayChar(HIGH);                                     /*display second char created */
	  Delay(THREE_THOUSAND_MS);
	  count_wronge++;											 /* increment counter of wrong answers */
  } 
  else {  LCD_sendCommand(CLEAR_SCREEN);                          /*if answer is right show happy emoji */
	  emoji_happy_init(); 
	  LCD_sendCommand(FIRST_LINE);
	  LCD_displayChar(LOW);										 /*display first char created  */
	  LCD_displayChar(HIGH);									 /*display second char created */
	  Delay(THREE_THOUSAND_MS);  
	  count_right++;                                             /* increment counter of right answers */
  } 
	/* fifth Question */
	  LCD_sendCommand(CLEAR_SCREEN);
	  Delay(ONE_THOUSAND_MS);
	  LCD_displayStringRowColumn("end of worldwar",LOW,LOW);           /* 1st line in LCD */   
	  LCD_displayStringRowColumn("two is 1944 ?",HIGH,LOW);  /*1945 */ /* 2nd line in LCD */   
	  Delay(TWO_THOUSAND_MS);
	  while(!(DIO_ReadPin(BUTTON0)) && !(DIO_ReadPin(BUTTON1)) );  /* pulling two buttons until one pressed */
	  if(!(DIO_ReadPin(BUTTON0))) {                                /* if answer is wrong show sad emoji */
		  LCD_sendCommand(CLEAR_SCREEN);
		  emoji_sad_init();
		  LCD_sendCommand(FIRST_LINE);
		  LCD_displayChar(LOW);                                    /*display first char created  */
		  LCD_displayChar(HIGH);								   /*display second char created */
		  Delay(THREE_THOUSAND_MS);
		  count_wronge++;										   /* increment counter of wrong answers */
	  }
	  else {  LCD_sendCommand(CLEAR_SCREEN);					/*if answer is right show happy emoji */
		  emoji_happy_init();
		  LCD_sendCommand(FIRST_LINE);
		  LCD_displayChar(LOW);									/*display first char created  */
		  LCD_displayChar(HIGH);								/*display second char created */
		  Delay(THREE_THOUSAND_MS);
		  count_right++;										/* increment counter of right answers */
	  }
	  
	 /*Display Result */
	 LCD_sendCommand(CLEAR_SCREEN);
	 Delay(ONE_THOUSAND_MS);
	 LCD_displayStringRowColumn("Final Result" , LOW , LOW);
	 Delay(ONE_THOUSAND_MS);
	 LCD_sendCommand(CLEAR_SCREEN);
	 LCD_displayStringRowColumn("Right = ",LOW,LOW);
	 LCD_displayChar(count_right + ZERO_ASCII  );                 /* show the result */
	 Delay(TWO_MS);
	  LCD_displayStringRowColumn("Wrong = ",HIGH,LOW);
	 LCD_displayChar(count_wronge+ ZERO_ASCII  );                
	 
}

void Init_game(void)
{   uint16 i =LOW; 
		
 
	LCD_displayStringRowColumn("welcome to Game",LOW,LOW); /* first row in LCD */
	Delay(TWO_MS);
	LCD_displayStringRowColumn("Let's Start ^_^",HIGH,LOW); /* second row */

	for(i=0; i<5;i++)                                
	 {Delay(HALF_MS);
	 LCD_sendCommand(Shift_Right);                   /* shift Right */
	 Delay(HALF_MS);
	 LCD_sendCommand(Shift_left);                   /* shift left  */
	}
	LCD_sendCommand(CLEAR_SCREEN); /* Clear display */
	LCD_displayStringRowColumn("0: yes",LOW,LOW);  /* begin from first row */
	LCD_displayStringRowColumn("1: No",HIGH,LOW);   /* begin from second row */
    Delay(TWO_THOUSAND_MS);	 
	
	LCD_sendCommand(CLEAR_SCREEN); /* Clear display */
	LCD_General_Question();
}


void Button_init(void)
{
	DIO_SetPinDirection(BUTTON0,LOW); /* Button 0 as output */
	DIO_SetPinDirection(BUTTON1,LOW); /* Button 1 as output */
	DIO_WritePin(BUTTON0,LOW);
	DIO_WritePin(BUTTON1,LOW);
	
}
