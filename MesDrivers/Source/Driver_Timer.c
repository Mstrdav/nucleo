#include "Driver_Timer.h"

void MyTimer_Base_Init(TIM_TypeDef * Timer, unsigned short ARR, unsigned short PSC)
{
    Timer->ARR = ARR;
    Timer->PSC = PSC;
    Timer->EGR |= TIM_EGR_UG;
}
