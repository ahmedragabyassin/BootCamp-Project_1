#include "Keypad.h"
uint8 keymap[3][3]={{1,2,3},{4,5,6},{7,8,9}};

void Keypad_init(void){
	
	DIO_SetPinDirection(KEYPAD_COL1,LOW);
	DIO_SetPinDirection(KEYPAD_COL2,LOW);
	DIO_SetPinDirection(KEYPAD_COL3,LOW);
	DIO_WritePin(KEYPAD_COL1,HIGH);
	DIO_WritePin(KEYPAD_COL2,HIGH);
	DIO_WritePin(KEYPAD_COL3,HIGH);

	DIO_SetPinDirection(KEYPAD_RAW1,HIGH);
	DIO_SetPinDirection(KEYPAD_RAW2,HIGH);
	DIO_SetPinDirection(KEYPAD_RAW3,HIGH);
	
	
	
}
uint8 Keypad_getPressedKey(void){
	uint8 key=-1;
	uint8 raw;
	uint8 col;
	DIO_WritePin(KEYPAD_RAW1,0);
	DIO_WritePin(KEYPAD_RAW2,0);
	DIO_WritePin(KEYPAD_RAW3,0);
	
	if((PINC&0xE0) ==0xE0){
		key=0;
		return key;
		}
while(1){	
	DIO_WritePin(KEYPAD_RAW1,0);
	DIO_WritePin(KEYPAD_RAW2,1);
	DIO_WritePin(KEYPAD_RAW3,1);
	if((PINC&0xE0) !=0xE0){
		col=PINC&0xE0;
		raw=0;
		break;
		
	}
	DIO_WritePin(KEYPAD_RAW1,1);
	DIO_WritePin(KEYPAD_RAW2,0);
	DIO_WritePin(KEYPAD_RAW3,1);
	if((PINC&0xE0) !=0xE0){
		col=PINC&0xE0;
		raw=1;
		break;
	}
	DIO_WritePin(KEYPAD_RAW1,1);
	DIO_WritePin(KEYPAD_RAW2,1);
	DIO_WritePin(KEYPAD_RAW3,0);
	if((PINC&0xE0) !=0xE0){
		col=PINC&0xE0;
		raw=2;
		break;
	}
			
	
}
switch (col){
	case 0xc0: return keymap[raw][0];
	case 0xA0: return keymap[raw][1];
	case 0x60: return keymap[raw][2];
	case 0xE0: return 0;
	
}
}