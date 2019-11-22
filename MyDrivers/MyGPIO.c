#include "MyGPIO.h"
#include "stm32f1xx_ll_gpio.h"

void MyGPIO_PWMConf(void){

	RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN ; 

 LL_GPIO_InitTypeDef GPIO_InitStruct6;
	
 GPIO_InitStruct6.Pin = LL_GPIO_PIN_6;
 GPIO_InitStruct6.Mode = LL_GPIO_MODE_FLOATING;
 GPIO_InitStruct6.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
 GPIO_InitStruct6.Pull = LL_GPIO_OUTPUT_PUSHPULL;
 GPIO_InitStruct6.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
 
 LL_GPIO_Init(GPIOB, &GPIO_InitStruct6);
	
 LL_GPIO_InitTypeDef GPIO_InitStruct7;
	
 GPIO_InitStruct7.Pin = LL_GPIO_PIN_7;
 GPIO_InitStruct7.Mode = LL_GPIO_MODE_FLOATING;
 GPIO_InitStruct7.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
 GPIO_InitStruct7.Pull = LL_GPIO_OUTPUT_PUSHPULL;
 GPIO_InitStruct7.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
 
 LL_GPIO_Init(GPIOB, &GPIO_InitStruct7);
}
