#ifndef MYGPIO_H
#define MYGPIO_H
#include "stm32f10x.h"

typedef struct
{
	GPIO_TypeDef*GPIO;
	char GPIO_Pin;
	char GPIO_Conf;
} MyGPIO_Struct_TypeDef;

//need to write ODR register to choose PullUp or PullDown
//Set bit corresponding to GPIO Pin on ODR register to 1 for PullUp, 0 for PullDown
//method setting ODR bit not yet written
#define In_Floating 0x1
#define In_PullDown 0x2
#define In_PullUp 0x2
#define In_Analog 0x0
#define Out_Ppull 0x8
#define Out_OD 0x9
#define AltOut_Ppull 0xA
#define AltOut_OD 0xB


void MyGPIO_Init( MyGPIO_Struct_TypeDef * GPIOStructPtr);
int MyGPIO_Read(GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Set(GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_Pin);

//enable the clocks of GPIO A
void MyGPIO_Activate_Clock_A(){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
}
//enable the clocks of GPIO C
void MyGPIO_Activate_Clock_C(){
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
}

#endif
	
