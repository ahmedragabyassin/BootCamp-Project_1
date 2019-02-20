/*
 * Buttons.c
 *
 * Created: 2/20/2019 10:51:39 AM
 *  Author: AVE-LAP-005
 */ 
#include "Types.h"
#include "Buttons_confg.h"
#include "DIO_Interface.h"
#include "Buttons.h"

/* this function intializes button to be input  */
void Button_Init(uint8 Pin_Num){
	DIO_SetPinDirection(Pin_Num,INPUT_WITHOUT_PULL);
	
	
}