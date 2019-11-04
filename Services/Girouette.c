#include "stm32f103xb.h" 
#include <stm32f1xx_ll_gpio.h>

#include "Girouette.h"

void init_girouette(void)
{
	TIM3->SMCR |= (TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1); //lecture sur TI1 et TI2 en même temps
	//TIM3->CCER = TIM_CCER_CC1P TIM_CCER_CC2P; //polarity
	TIM3->CR1 |= TIM_CR1_CEN;
	
	
	//simulation
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	//PA6 et PA7
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_6, LL_GPIO_MODE_FLOATING);
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_7, LL_GPIO_MODE_FLOATING);
}


int GetAngle(void)
{
	return 0;
}
