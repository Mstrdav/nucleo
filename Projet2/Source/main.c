#include "stm32f10x.h"
#include "Driver_GPIO.h"

int main (void) {
	/*// enable the clocks of GPIO A and C
	// RCC->APB2ENR |= (0x01 << 2) | (0x01 << 4);
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN;

	// set the mode of GPIO A pin 5 as output
	// to do this, we need to clear the bits first
	GPIOA->CRL &= ~(0xF << 5*4);
	// then set the bits to 0x02 (output mode, max speed 2 MHz)
	GPIOA->CRL |= 0x02 << 5*4;

	// set the mode of GPIO C pin 13 as output
	// to do this, we need to clear the bits first
	GPIOC->CRH &= ~(0xF << (13%8)*4);
	// then set the bits to 0x02 (output mode, max speed 2 MHz)
	GPIOC->CRH |= 0x04 << (13%8)*4;*/
	
    MyGPIO_Init(GPIOA, 5, Out_Ppull);
    MyGPIO_Init(GPIOC, 13, In_Floating);

	while (1) {
		// if the button is pressed, turn on the LED
		// if ((GPIOC->IDR & GPIO_IDR_IDR13) == GPIO_IDR_IDR13) {
		// 	GPIOA->ODR &= ~GPIO_ODR_ODR5; // turn of the LED
		// } else {
		// 	GPIOA->ODR |= GPIO_ODR_ODR5; // turn on the LED
		// }
        if (MyGPIO_Read(GPIOC, 13) == GPIO_IDR_IDR13) {
            MyGPIO_Reset(GPIOA, 5);
        } else {
            MyGPIO_Set(GPIOA, 5);
        }
	}
}