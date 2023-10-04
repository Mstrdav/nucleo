#include "Driver_Timer.h"

int main (void){
	MyTimer_Base_Init(TIM2,1000-1,3600-1);
	
	while(1);
}
