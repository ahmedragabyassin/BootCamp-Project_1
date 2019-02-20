
/*
 * One_Million.c
 *
 * Created: 2/20/2019 10:46:10 AM
 * Author : AVE-LAP-005
 */
#define F_CPU 16000000UL
#include "Types.h"
#include "DIO_Interface.h"
#include "Buttons.h"
#include "LCD.h"
#include "Utilites.h"
#include <util/delay.h>
/*Sad Matrix*/
uint8 Happy[]= {0x00,0x1B,0x1B,0x00,0x00,0x11,0x0E,0x00};
uint8 Sad[]= {0x00,0x1B,0x1B,0x00,0x00,0x0E,0x11,0x00};
/*Static APIS used in the app layer*/
static void Disp_Cgram(uint8* arr,uint8 loc);
static uint8 Button_Is_Pressed();

int main(void)
{
    uint8 flag1=NUM_ONE,flag2=NUM_ZERO,flag3=NUM_ZERO,flag4=NUM_ZERO,flag5=NUM_ZERO,flag6=NUM_ZERO,flag7=NUM_ZERO;
    uint8 i=NUM_ZERO,ret;
    uint8 counter=NUM_ZERO;
    LCD_init();
    /* we initialize button zero and one as input with pull up */
    Button_Init(BUTTON_ZERO);
    Button_Init(BUTTON_ONE);
    /* Display Greeting on the LCD */
    LCD_displayStringRowColumn(NUM_ONE,NUM_THREE,"Welcome To");
    LCD_displayStringRowColumn(NUM_TWO,NUM_TWO,"ONE MILLION ");
    _delay_ms(t_2000ms);
    LCD_clear();
    LCD_displayStringRowColumn(NUM_ONE,NUM_ZERO," 0 for yes ");
    LCD_displayStringRowColumn(NUM_TWO,NUM_ZERO," 1 for No ");
    _delay_ms(t_2000ms);
    LCD_clear();
    LCD_displayStringRowColumn(NUM_ONE,NUM_TWO," READY !!!! ");
    _delay_ms(t_2000ms);
    LCD_clear();


    while (1)
    {
        counter = 0;
        if (flag1==NUM_ONE)
        {
            LCD_clear();
            LCD_displayStringRowColumn(NUM_ONE,NUM_ZERO,"Did Egypt WON");
            LCD_displayStringRowColumn(NUM_TWO,NUM_ZERO,"CAN in 1986 ?");
            _delay_ms(t_2000ms);
            LCD_clear();
            LCD_displayStringRowColumn(NUM_ONE,NUM_TWO,"0.yes  1.No");
            ret = Button_Is_Pressed();
            if (ret==NUM_ONE)
            {
                LCD_clear();
                counter+=ret;
                LCD_gotoRowColumn(NUM_ONE,NUM_SEVEN);
                Disp_Cgram(Happy,NUM_ZERO);
            }
            else
            {
                LCD_clear();
                LCD_gotoRowColumn(NUM_ONE,NUM_SEVEN);
                Disp_Cgram(Sad,NUM_ZERO);
            }
            flag1=0;
            flag2=1;
        }

        if (flag2==1)
        {
            LCD_clear();
            LCD_displayStringRowColumn(NUM_ONE,NUM_ZERO,"Did Nadal Won US");
            LCD_displayStringRowColumn(NUM_TWO,NUM_ONE,"open in 2018?");
            _delay_ms(t_2000ms);
            LCD_clear();
            LCD_displayStringRowColumn(NUM_ONE,NUM_TWO,"0.yes  1.No");
            ret = Button_Is_Pressed();
            if (ret==NUM_ONE)
            {
	            LCD_clear();
				LCD_gotoRowColumn(NUM_ONE,NUM_SEVEN);
				Disp_Cgram(Sad,NUM_ZERO);

            }
            else
            {
	            LCD_clear();
			     counter+=NUM_ONE;
				 LCD_gotoRowColumn(NUM_ONE,NUM_SEVEN);
				 Disp_Cgram(Happy,NUM_ZERO);
            }
            flag2=0;
            flag3=1;
        }
        if (flag3==1)
         {
                  LCD_clear();
        LCD_displayStringRowColumn(NUM_ONE,NUM_ZERO,"Did Uruguay win");
        LCD_displayStringRowColumn(NUM_TWO,NUM_ZERO,"first world CUP?");
        _delay_ms(t_2000ms);
        LCD_clear();
        LCD_displayStringRowColumn(NUM_ONE,NUM_TWO,"0.yes  1.No");
        ret = Button_Is_Pressed();
        if (ret==NUM_ONE)
        {
            LCD_clear();
            counter+=ret;
            LCD_gotoRowColumn(NUM_ONE,NUM_SEVEN);
            Disp_Cgram(Happy,NUM_ZERO);
        }
        else
        {
            LCD_clear();
            LCD_gotoRowColumn(NUM_ONE,NUM_SEVEN);
            Disp_Cgram(Sad,NUM_ZERO);
        }
            flag3=0;
            flag4=1;
        }
        if (flag4==1)
        {
              LCD_clear();
               LCD_displayStringRowColumn(NUM_ONE,NUM_ZERO,"Is Kabul Capital");
               LCD_displayStringRowColumn(NUM_TWO,NUM_ONE,"OF Afghanistan ?");
               _delay_ms(t_2000ms);
               LCD_clear();
               LCD_displayStringRowColumn(NUM_ONE,NUM_TWO,"0.yes  1.No");
               ret = Button_Is_Pressed();
               if (ret==NUM_ONE)
               {
                   LCD_clear();
                   counter+=ret;
                   LCD_gotoRowColumn(NUM_ONE,NUM_SEVEN);
                   Disp_Cgram(Happy,NUM_ZERO);
               }
               else
               {
                   LCD_clear();
                   LCD_gotoRowColumn(NUM_ONE,NUM_SEVEN);
                   Disp_Cgram(Sad,NUM_ZERO);
               }
             flag4=0;
             flag5=1;
         }
         if (flag5==1)
         {
               LCD_clear();
         LCD_displayStringRowColumn(NUM_ONE,NUM_ZERO,"Does Ramy goes to");
         LCD_displayStringRowColumn(NUM_TWO,NUM_ZERO,"life GYM?");
         _delay_ms(t_2000ms);
         LCD_clear();
         LCD_displayStringRowColumn(NUM_ONE,NUM_TWO,"0.yes  1.No");
         ret = Button_Is_Pressed();
         if (ret==NUM_ONE)
         {
            LCD_clear();
					  counter+=NUM_ONE;
					  LCD_gotoRowColumn(NUM_ONE,NUM_SEVEN);
					  Disp_Cgram(Happy,NUM_ZERO);


         }
         else
         {
            LCD_clear();
			LCD_gotoRowColumn(NUM_ONE,NUM_SEVEN);
			Disp_Cgram(Sad,NUM_ZERO);

         }
            flag5=0;
            flag6=1;
        }
        if (flag6==1)
        {
            LCD_clear();
            LCD_displayStringRowColumn(NUM_ONE,NUM_ZERO,"your score is:");
            LCD_gotoRowColumn(NUM_TWO,NUM_SEVEN);
            LCD_displayChar(counter+48);
            _delay_ms(t_2000ms);
            LCD_clear();
            LCD_displayStringRowColumn(NUM_ONE,NUM_ZERO,"Do you want to");
            LCD_displayStringRowColumn(NUM_TWO,NUM_TWO,"Play again");
            _delay_ms(t_3000ms);
            LCD_clear();
            LCD_displayStringRowColumn(NUM_ONE,NUM_ZERO,"0.yes  1.No");
            ret=Button_Is_Pressed();
            if (ret==NUM_ONE)
            {
                flag1=NUM_ONE;
                flag6=NUM_ZERO;
            }
            else
            {
                flag7=NUM_ONE;
                flag6=NUM_ZERO;

            }
        }
        if (flag7==NUM_ONE)
        {
            LCD_clear();
            LCD_displayStringRowColumn(NUM_ONE,NUM_FOUR,"Thank YOU");
        }



    }
}

static void Disp_Cgram(uint8* arr,uint8 loc)
{

    uint8 i=NUM_ZERO;
    if(loc<NUM_EIGHT)
    {
        LCD_sendCommand(0x40+loc*NUM_EIGHT);
        for (i=NUM_ZERO; i<NUM_EIGHT; i++)
        {
            LCD_displayChar(arr[i]);
        }
        LCD_sendCommand(0X80);
        LCD_clear();
        LCD_displayChar(NUM_ZERO+loc);
        _delay_ms(t_3000ms);
    }
}

static uint8 Button_Is_Pressed()
{
    uint8 flag = 1;
    uint8 counter;
    while (flag)
    {
        if (DIO_ReadPin(BUTTON_ZERO))
        {
            counter  = 1;
            break;
        }
        else if (DIO_ReadPin(BUTTON_ONE))
        {
            counter = 0;
            break;
        }
        else
        {
            /*Nothing to do*/
        }
    }
    return counter;

}
