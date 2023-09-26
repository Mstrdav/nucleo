#include "Driver_GPIO.h"

void MyGPIO_Init(GPIO_TypeDef *GPIO, char GPIO_Pin, char GPIO_Conf)
{
    // enable the clock oof the concerned GPIO
    if (GPIO == GPIOA)
    {
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    }
    else if (GPIO == GPIOB)
    {
        RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    }
    else if (GPIO == GPIOC)
    {
        RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    }
    else if (GPIO == GPIOD)
    {
        RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
    }
    else if (GPIO == GPIOE)
    {
        RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;
    }

    // set the mode of the GPIO pin
    if (GPIO_Pin < 8)
    {
        GPIO->CRL &= ~(0xF << GPIO_Pin * 4);
        GPIO->CRL |= GPIO_Conf << GPIO_Pin * 4;
    }
    else
    {
        GPIO->CRH &= ~(0xF << (GPIO_Pin % 8) * 4);
        GPIO->CRH |= GPIO_Conf << (GPIO_Pin % 8) * 4;
    }
}

int MyGPIO_Read(GPIO_TypeDef *GPIO, char GPIO_Pin)
{
    // read the value of the GPIO pin
    return (GPIO->IDR & (0x01 << GPIO_Pin));
}

void MyGPIO_Set(GPIO_TypeDef *GPIO, char GPIO_Pin)
{
    // set the GPIO pin
    if (GPIO_Pin < 8)
    {
        GPIO->ODR |= (0x01 << GPIO_Pin);
    }
    else
    {
        GPIO->ODR |= (0x01 << (GPIO_Pin % 8));
    }
}

void MyGPIO_Reset(GPIO_TypeDef *GPIO, char GPIO_Pin)
{
    // reset the GPIO pin
    if (GPIO_Pin < 8)
    {
        // clear the bit
        GPIO->ODR &= ~(0x01 << GPIO_Pin);
    }
    else
    {
        // clear the bit
        GPIO->ODR &= ~(0x01 << (GPIO_Pin % 8));
    }
}

void MyGPIO_Toggle(GPIO_TypeDef *GPIO, char GPIO_Pin)
{
    // toggle the GPIO pin
    if (GPIO_Pin < 8)
    {
        // toggle the bit
        GPIO->ODR ^= (0x01 << GPIO_Pin);
    }
    else
    {
        // toggle the bit
        GPIO->ODR ^= (0x01 << (GPIO_Pin % 8));
    }
}
