
#ifndef DIO_PROG_H
#define DIO_PROG_H
#include "..\Commen\commen.h"
extern void DIO_WritePin(uint8 PinNum,uint8 PinValue);
extern uint8 DIO_ReadPin(uint8 PinNum);
extern void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);
#endif
