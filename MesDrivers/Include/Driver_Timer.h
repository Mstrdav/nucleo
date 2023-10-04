#ifndef MYTIMER_H
#define MYTIMER_H
#include "stm32f10x.h"

void MyTimer_Base_Init(TIM_TypeDef * Timer, unsigned short ARR, unsigned short PSC);

#define MyTimer_Base_Start(Timer) (...)
#define MyTimer_Base_Stop(Timer) (...)

#endif
