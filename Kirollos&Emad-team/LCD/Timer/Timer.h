
#ifndef TIMER_DELAY
#define TIMER_DELAY


#include "..\Commen\commen.h"

#define TIME_1MS        1
#define TIME_2MS        2
#define TIME_5MS        5
#define TIME_10MS       10
#define TIME_15MS       15
#define TIME_20MS       20
#define TIME_25MS       25
#define TIME_30MS       30
#define TIME_40MS       40
#define TIME_50MS       50
#define TIME_60MS       60
#define TIME_70MS       70
#define TIME_80MS       80
#define TIME_90MS       90
#define TIME_100MS      100
#define TIME_200MS      200
#define TIME_300MS      300
#define TIME_400MS      400
#define TIME_500MS      500
#define TIME_1000MS     1000



 void timer_mdelay(uint32 n);
 void timer_udelay(uint32 n);
 void timer_mdelay_interrupt(uint32 n);
 void timer_init();
#endif
