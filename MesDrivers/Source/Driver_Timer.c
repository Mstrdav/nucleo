#include "Driver_Timer.h"

void MyTimer_Base_Init(TIM_TypeDef *Timer, unsigned short ARR, unsigned short PSC)
{
    // Enable the clock for the timer
    if (Timer == TIM1)
    {
        // RCC->APB1ENR |= RCC_APB1ENR_;
    } else if (Timer == TIM2)
    {
        RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    } else if (Timer == TIM3)
    {
        RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    } else if (Timer == TIM4)
    {
        RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
    } else {
        return;
    }

    Timer->ARR = ARR;
    Timer->PSC = PSC;
    MyTimer_Base_Start(Timer);
}

void MyTimer_ActiveIT(TIM_TypeDef *Timer, char Prio)
{
    if (Timer == TIM1)
    {
        NVIC_EnableIRQ(TIM1_UP_IRQn);
        NVIC_SetPriority(TIM1_UP_IRQn, Prio);
    } else if (Timer == TIM2)
    {
        NVIC_EnableIRQ(TIM2_IRQn);
        NVIC_SetPriority(TIM2_IRQn, Prio);
    } else if (Timer == TIM3)
    {
        NVIC_EnableIRQ(TIM3_IRQn);
        NVIC_SetPriority(TIM3_IRQn, Prio);
    } else if (Timer == TIM4)
    {
        NVIC_EnableIRQ(TIM4_IRQn);
        NVIC_SetPriority(TIM4_IRQn, Prio);
    } else {
        return;
    }
    Timer->DIER |= TIM_DIER_UIE; // Enable the interrupt
}

void TIM2_IRQHandler(void)
{
    TIM2->SR &= ~TIM_SR_UIF; // Clear the interrupt flag
    // Toggle the LED
    GPIOA->ODR ^= GPIO_ODR_ODR5;
}
