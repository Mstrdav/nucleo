#ifndef MYTIMER_H
#define MYTIMER_H
#include "stm32f10x.h"

void MyTimer_Base_Init(TIM_TypeDef * Timer, unsigned short ARR, unsigned short PSC);

#define MyTimer_Base_Start(Timer) (Timer->CR1 |= TIM_CR1_CEN)
#define MyTimer_Base_Stop(Timer) (Timer->CR1 &= ~TIM_CR1_CEN)

void MyTimer_ActiveIT(TIM_TypeDef * Timer, char Prio, void *Handler);
void MyTimerPWM(TIM_TypeDef * Timer, char Channel);

#endif
