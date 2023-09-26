#ifndef MYGPIO_H
#define MYGPIO_H
#include "stm32f10x.h"


// need to write ODR register to choose PullUp or PullDown
// Set bit corresponding to GPIO Pin on ODR register to 1 for PullUp, 0 for PullDown
// method setting ODR bit not yet written

// CNF:MODE
#define In_Floating 0x04 // 0100
#define In_PullDown 0x08 // 1000
#define In_PullUp 0x08	 // 1000
#define In_Analog 0x00	 // 0000
// output in 2MHz max (mode 10)
#define Out_Ppull 0x02	  // 0010
#define Out_OD 0x06		  // 0110
#define AltOut_Ppull 0x0A // 1010
#define AltOut_OD 0x0E	  // 1110

// Provided code

// typedef struct
// {
// 	GPIO_TypeDef *GPIO;
// 	char GPIO_Pin;
// 	char GPIO_Conf;
// } MyGPIO_Struct_TypeDef;

// void MyGPIO_Init(MyGPIO_Struct_TypeDef *GPIOStructPtr);
// int MyGPIO_Read(GPIO_TypeDef *GPIO, char GPIO_Pin);
// void MyGPIO_Set(GPIO_TypeDef *GPIO, char GPIO_Pin);
// void MyGPIO_Reset(GPIO_TypeDef *GPIO, char GPIO_Pin);
// void MyGPIO_Toggle(GPIO_TypeDef *GPIO, char GPIO_Pin);

// same thing but the structure does not exist, we pass the three arguments

void MyGPIO_Init(GPIO_TypeDef *GPIO, char GPIO_Pin, char GPIO_Conf);
int MyGPIO_Read(GPIO_TypeDef *GPIO, char GPIO_Pin); // 0 or not 0 (??!)
void MyGPIO_Set(GPIO_TypeDef *GPIO, char GPIO_Pin);
void MyGPIO_Reset(GPIO_TypeDef *GPIO, char GPIO_Pin);
void MyGPIO_Toggle(GPIO_TypeDef *GPIO, char GPIO_Pin);

#endif