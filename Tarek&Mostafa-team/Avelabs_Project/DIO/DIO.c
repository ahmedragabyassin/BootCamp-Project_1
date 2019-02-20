/*
 * memory_mapped_registers.c
 *
 * Created: 2/13/2019 3:19:57 PM
 *  Author: AVE-LAP-016
 */ 
#include "../includes/DIO.h"

void DIO_WritePin(uint8 PinNum,uint8 PinValue){
	if(PinValue == 0)
	{
		if( (PinNum >= 0) && (PinNum <= 7)){
			Clear_Bit(PORTA,(PinNum%8));
		}
		else if( (PinNum >= 8) && (PinNum <= 15)){
			Clear_Bit(PORTB,(PinNum%8));
		}
		else if( (PinNum >= 16) && (PinNum <= 23)){
			Clear_Bit(PORTC,(PinNum%8));
		}
		else if( (PinNum >=24) && (PinNum <= 31)) {
			Clear_Bit(PORTD,(PinNum%8));
		}
	}
	if(PinValue == 1)
	{
		if( (PinNum >= 0) && (PinNum <= 7)){
			Set_Bit(PORTA,(PinNum%8));
		}
		else if( (PinNum >= 8) && (PinNum <= 15)){
			Set_Bit(PORTB,(PinNum%8));
		}
		else if( (PinNum >= 16) && (PinNum <= 23)){
			Set_Bit(PORTC,(PinNum%8));
		}
		else if( (PinNum >=24) && (PinNum <= 31)) {
			Set_Bit(PORTD,(PinNum%8));
		}
	}
}
uint8 DIO_ReadPin(uint8 PinNum){
	uint8 bit_status = 0 ;
	if( (PinNum >= 0) && (PinNum <= 7)){
	      bit_status = Get_Bit(PINA,(PinNum%8));
	}
	else if( (PinNum >= 8) && (PinNum <= 15)){
		bit_status = Get_Bit(PINB,(PinNum%8));
	}
	else if( (PinNum >= 16) && (PinNum <= 23) ){
		bit_status = Get_Bit(PINC,(PinNum%8));
	}
	else if( (PinNum >=24) && (PinNum <= 31)) {
		bit_status = Get_Bit(PIND,(PinNum%8));
	}
	else
	bit_status = 0 ;
	
	return bit_status ;
	
}
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection){
	if(PinDirection == 0)
	{
		if( (PinNum >= 0) && (PinNum <= 7)){
			Clear_Bit(DDRA,(PinNum%8));
		}
		else if( (PinNum >= 8) && (PinNum <= 15)){
			Clear_Bit(DDRB,(PinNum%8));
		}
		else if( (PinNum >= 16) && (PinNum <= 23)){
			Clear_Bit(DDRC,(PinNum%8));
		}
		else if( (PinNum >=24) && (PinNum <= 31)) {
			Clear_Bit(DDRD,(PinNum%8));
		}
	}
	if(PinDirection == 1)
	{
		if( (PinNum >= 0) && (PinNum <= 7)){
			Set_Bit(DDRA,(PinNum%8));
		}
		else if( (PinNum >= 8) && (PinNum <= 15)){
			Set_Bit(DDRB,(PinNum%8));
		}
		else if( (PinNum >= 16) && (PinNum <= 23)){
			Set_Bit(DDRC,(PinNum%8));
		}
		else if( (PinNum >=24) && (PinNum <= 31)) {
			Set_Bit(DDRD,(PinNum%8));
		}
	}
}