#include "Driver_Timer.h"

void MyTimer_Base_Init(TIM_TypeDef * Timer, unsigned short ARR, unsigned short PSC)
{
    // Enable the clock for the timer
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    Timer->ARR = ARR;
    Timer->PSC = PSC;
    Timer->EGR |= TIM_EGR_UG;
}
