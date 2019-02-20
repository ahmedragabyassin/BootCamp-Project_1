/*
 * DIO_Program.c
 *
 * Created: 2/13/2019 2:45:35 PM
 *  Author: AVE-LAP-005
 */ 
#include "Types.h"
#include "DIO_Registers.h"
#include "DIO_Interface.h"
#include "BitwiseOperations.h"

static void Apply(GPIO* Gpio,uint8 Copy_u8Value,uint8 PinNum);
static uint8 Apply_Read(GPIO* Gpio,uint8 PinNum);
static void Apply_Dir(GPIO* Gpio,uint8 PinNum,uint8 PinDirection);
/***********************LCD_init()***************************
*Parameters:
*			i/P:
*			O/P:
*           I/O:
*Return:
*Description:
*************************************************************/
void DIO_WritePin(uint8 PinNum,uint8 PinValue){
	GPIO* Local_Copy_Address=0;
	if ((PinNum<=pin7) && (PinNum>=pin0))
	{
		Local_Copy_Address=GPIOA_DIO;
	}
	else if ((PinNum<=pin15) && (PinNum>=pin8))
	{
		Local_Copy_Address=GPIOB_DIO;
	}
	else if ((PinNum<=pin23) && (PinNum>=pin16))
	{
		Local_Copy_Address=GPIOC_DIO;
	}else if ((PinNum<=pin31) && (PinNum>=pin24))
	{
		Local_Copy_Address=GPIOD_DIO;
	}
	
	Apply(Local_Copy_Address,PinValue,PinNum);
	
	
}
/***********************LCD_init()***************************
*Parameters:
*			i/P:
*			O/P:
*           I/O:
*Return:
*Description:
*************************************************************/

static void Apply(GPIO* Gpio,uint8 Copy_u8Value,uint8 PinNum){
	uint8 Local_Copyu8_Actuall_Pin=0;
	if ((PinNum<=pin7) && (PinNum>=pin0))
	{
		Local_Copyu8_Actuall_Pin=PinNum;
	}
	else if ((PinNum<=pin15) && (PinNum>=pin8))
	{
		Local_Copyu8_Actuall_Pin=PinNum-8;
	}
	else if ((PinNum<=pin23) && (PinNum>=pin16))
	{
		Local_Copyu8_Actuall_Pin=PinNum-16;
	}else if ((PinNum<=pin31) && (PinNum>=pin24))
	{
		Local_Copyu8_Actuall_Pin=PinNum-24;
	}
	switch (Copy_u8Value)
	{
		case High:Set_Bit((Gpio->PORT),Local_Copyu8_Actuall_Pin); break;
		case LOW:Clear_Bit((Gpio->PORT),Local_Copyu8_Actuall_Pin); break;
	}
	
}
/***********************LCD_init()***************************
*Parameters:
*			i/P:
*			O/P:
*           I/O:
*Return:
*Description:
*************************************************************/
uint8 DIO_ReadPin(uint8 PinNum){
	GPIO* Local_Copy_Address=0;
	if ((PinNum<=pin7) && (PinNum>=pin0))
	{
		Local_Copy_Address=GPIOA_DIO;
	}
	else if ((PinNum<=pin15) && (PinNum>=pin8))
	{
		Local_Copy_Address=GPIOB_DIO;
	}
	else if ((PinNum<=pin23) && (PinNum>=pin16))
	{
		Local_Copy_Address=GPIOC_DIO;
	}else if ((PinNum<=pin31) && (PinNum>=pin24))
	{
		Local_Copy_Address=GPIOD_DIO;
	}
	
	return Apply_Read(Local_Copy_Address,PinNum);	
	
	
}
/***********************LCD_init()***************************
*Parameters:
*			i/P:
*			O/P:
*           I/O:
*Return:
*Description:
*************************************************************/
static uint8 Apply_Read(GPIO* Gpio,uint8 PinNum){
	uint8 Local_Copyu8_Actuall_Pin=0;
	if ((PinNum<=pin7) && (PinNum>=pin0))
	{
		Local_Copyu8_Actuall_Pin=PinNum;
	}
	else if ((PinNum<=pin15) && (PinNum>=pin8))
	{
		Local_Copyu8_Actuall_Pin=PinNum-8;
	}
	else if ((PinNum<=pin23) && (PinNum>=pin16))
	{
		Local_Copyu8_Actuall_Pin=PinNum-16;
	}else if ((PinNum<=pin31) && (PinNum>=pin24))
	{
		Local_Copyu8_Actuall_Pin=PinNum-24;
	}
	
	return Get_Bit(Gpio->PIN,Local_Copyu8_Actuall_Pin);
	
	
}
/***********************LCD_init()***************************
*Parameters:
*			i/P:
*			O/P:
*           I/O:
*Return:
*Description:
*************************************************************/
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection){
	GPIO* Local_Copy_Address=0;
	if ((PinNum<=pin7) && (PinNum>=pin0))
	{
		Local_Copy_Address=GPIOA_DIO;
	}
	else if ((PinNum<=pin15) && (PinNum>=pin8))
	{
		Local_Copy_Address=GPIOB_DIO;
	}
	else if ((PinNum<=pin23) && (PinNum>=pin16))
	{
		Local_Copy_Address=GPIOC_DIO;
	}else if ((PinNum<=pin31) && (PinNum>=pin24))
	{
		Local_Copy_Address=GPIOD_DIO;
	}
	
	Apply_Dir(Local_Copy_Address,PinNum,PinDirection);
	
}

/***********************LCD_init()***************************
*Parameters:
*			i/P:
*			O/P:
*           I/O:
*Return:
*Description:
*************************************************************/
static void Apply_Dir(GPIO* Gpio,uint8 PinNum,uint8 PinDirection){
	
	uint8 Local_Copyu8_Actuall_Pin=0;
	if ((PinNum<=pin7) && (PinNum>=pin0))
	{
		Local_Copyu8_Actuall_Pin=PinNum;
	}
	else if ((PinNum<=pin15) && (PinNum>=pin8))
	{
		Local_Copyu8_Actuall_Pin=PinNum-8;
	}
	else if ((PinNum<=pin23) && (PinNum>=pin16))
	{
		Local_Copyu8_Actuall_Pin=PinNum-16;
	}else if ((PinNum<=pin31) && (PinNum>=pin24))
	{
		Local_Copyu8_Actuall_Pin=PinNum-24;
	}
	switch(PinDirection){
		case Input_PUll_UP:Clear_Bit(Gpio->DDR,Local_Copyu8_Actuall_Pin);Set_Bit(Gpio->PORT,Local_Copyu8_Actuall_Pin); break;
		case INPUT_WITHOUT_PULL:Clear_Bit(Gpio->DDR,Local_Copyu8_Actuall_Pin);Clear_Bit(Gpio->PORT,Local_Copyu8_Actuall_Pin); break;
		case OUTPUT:Set_Bit(Gpio->DDR,Local_Copyu8_Actuall_Pin);break;
		
		
	}
	
}