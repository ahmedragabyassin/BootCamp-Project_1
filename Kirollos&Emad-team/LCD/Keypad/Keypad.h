#ifndef KEYPAD_H
#define KEYPAD_H

#include "..\Commen\commen.h"
#include "..\Timer\Timer.h"
#include "..\Dio\DIO_prog.h"
#include "Keypad_cfg.h"
void Keypad_init(void);
uint8 Keypad_getPressedKey(void);


#endif

