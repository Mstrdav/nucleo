#include "Driver_Timer.h"
#include "Driver_GPIO.h"



//function used as an IT handler for TIM2
void main_TIM2_IRQHandler(void)
		{
		//SR is status register
	//uif is th flag
	TIM2->SR &= ~TIM_SR_UIF; // Clear the interrupt flag
    // Toggle the LED
    GPIOA->ODR ^= GPIO_ODR_ODR5;
		}	
		
		
		
int main (void){


	MyGPIO_Init(GPIOA, 5, Out_Ppull);
	MyTimer_Base_Init(TIM2,10000-1,3600-1);
	MyTimer_ActiveIT(TIM2, 3, main_TIM2_IRQHandler);
	while(1);
	


}
