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
		
		void testPWM(void)
		{
			//frequence timer set a 100kHz
		MyTimer_Base_Init(TIM2,20-1,36-1);
	  MyTimer_ActiveIT(TIM2, 3, main_TIM2_IRQHandler);
  	MyTimerModeToPWM(TIM2, 1);
	  MyTimerSetPWMCycle(TIM2,1,20);
		}
		
		
		
int main (void){


	//MyGPIO_Init(GPIOA, 5, Out_Ppull);

	testPWM();
	while(1);
	


}
