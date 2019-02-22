#ifndef  SEGMENT_7_H
#define  SEGMENT_7_H

#include "..\Commen\commen.h"
#include "..\Dio\DIO_prog.h"
#include "BCDSevSegment_cfg.h"
#include "..\Timer\Timer.h"



void BCDSevegments_enable(uint8 num);
void BCDSevegments_disable(void);

void BCDSevegments_displayNo(uint32 num);


#endif