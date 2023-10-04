#include "Driver_Timer.h"
#include "Driver_GPIO.h"

int main (void){
	MyGPIO_Init(GPIOA, 5, Out_Ppull);
	MyTimer_Base_Init(TIM2,10000-1,3600-1);
	MyTimer_ActiveIT(TIM2, 3);
	while(1);
}
