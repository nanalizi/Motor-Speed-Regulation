#ifndef __FILT_H
#define __FILT_H
#include "stm32f10x.h"

 #define N 40
extern float  value_buf[N];
	extern float  s;
float moveAverageFilter(void);


#endif 
