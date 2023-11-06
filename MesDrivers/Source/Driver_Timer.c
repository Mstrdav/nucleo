#include "Driver_Timer.h"
//pointeur de fonction utilise pour importer code execute par handler
void (*ptr1) (void);
void (*ptr2) (void);
void (*ptr3) (void);
void (*ptr4) (void);


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

//enable interruption at the NVIC level
void MyTimer_ActiveIT(TIM_TypeDef *Timer, char Prio, void *Handler)
{
    if (Timer == TIM1)
    {
        NVIC_EnableIRQ(TIM1_UP_IRQn);
        NVIC_SetPriority(TIM1_UP_IRQn, Prio);
				//assignation du handler
				ptr1 = Handler;
			
    } else if (Timer == TIM2)
    {
        NVIC_EnableIRQ(TIM2_IRQn);
        NVIC_SetPriority(TIM2_IRQn, Prio);
							//assignation du handler
				ptr2 = Handler;
    } else if (Timer == TIM3)
    {
        NVIC_EnableIRQ(TIM3_IRQn);
        NVIC_SetPriority(TIM3_IRQn, Prio);
							//assignation du handler
				ptr3 = Handler;
    } else if (Timer == TIM4)
    {
        NVIC_EnableIRQ(TIM4_IRQn);
        NVIC_SetPriority(TIM4_IRQn, Prio);
							//assignation du handler
				ptr4 = Handler;
    } else {
        return;
    }
    Timer->DIER |= TIM_DIER_UIE; // Enable the interrupt at the timer level

		
}



//Timer handler
void TIM1_IRQHandler(void)
{
	//clear flag
	TIM1->SR &= ~TIM_SR_UIF;
	ptr1();
}


void TIM2_IRQHandler(void)
{
	
	//code to use if handler code inside this function
//SR is status register
	//uif is the flag raised when asking for an IT
	TIM2->SR &= ~TIM_SR_UIF; // Clear the interrupt flag
    // Toggle the LED
    //GPIOA->ODR ^= GPIO_ODR_ODR5;	
	//using the imported code from main
	ptr2();
}

void TIM3_IRQHandler(void)
{
	TIM3->SR &= ~TIM_SR_UIF;
	ptr3();
}

void TIM4_IRQHandler(void)
{
	TIM4->SR &= ~TIM_SR_UIF;
	ptr4();
}

void MyTimerPWM(TIM_TypeDef * Timer, char Channel){
	 if (Timer == TIM1)
    {
			
    } else if (Timer == TIM2)		
    {
			if (Channel == 1){
				//output ,ode				
				TIM2->CCMR1 &= ~TIM_CCMR1_CC1S;
				//reset OC1M
				TIM2->CCMR1 &= ~TIM_CCMR1_OC1M;
				//PWM mode
				TIM2->CCMR1 |= TIM_CCMR1_OC1M_2| TIM_CCMR1_OC1M_1;			
				TIM2->CCER |= TIM_CCER_CC1E;
				
				//set default value of CCR1 to 0
				TIM2->CCR1 = 0;
			}
			else if (Channel == 2){				
				TIM2->CCMR1 &= ~TIM_CCMR1_CC2S;
				TIM2->CCMR1 &= ~TIM_CCMR1_OC2M;
				TIM2->CCMR1 |= TIM_CCMR1_OC2M_2|TIM_CCMR1_OC2M_1;			
				TIM2->CCER |= TIM_CCER_CC2E;
				
				TIM2->CCR2 &= ~(0xf);
			}
			else if (Channel == 3){
				TIM2->CCMR2 &= ~TIM_CCMR2_CC3S;
				TIM2->CCMR2 &= ~TIM_CCMR2_OC3M;
				TIM2->CCMR2 |= TIM_CCMR2_OC3M_2|TIM_CCMR2_OC3M_1;		
				TIM2->CCER |= TIM_CCER_CC3E;
			}
			else if (Channel == 4){
				TIM2->CCMR2 &= ~TIM_CCMR2_CC4S;
				TIM2->CCMR2 &= ~TIM_CCMR2_OC4M;
				TIM2->CCMR2 |= TIM_CCMR2_OC4M_2|TIM_CCMR2_OC4M_1;		
				TIM2->CCER |= TIM_CCER_CC3E;
			}

    } else if (Timer == TIM3)
    {
			
    } else if (Timer == TIM4)
    {
			
    } else {
        return;
    }
	
}





