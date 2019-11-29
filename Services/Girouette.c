#include "stm32f103xb.h" 
#include <stm32f1xx_ll_gpio.h>
#include "..\LLDrivers\inc\stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_bus.h"

#include "Girouette.h"

int flag = 1; //1: l'interruption de l'index

void initGirouette(void)
{

	//Activation du TIM3
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);
	
	//Initialisation de la structure de l'encodeur pour la girouette
	LL_TIM_ENCODER_InitTypeDef structEncoder;
	
	//Définition des valeurs de base pour la structure
	structEncoder.EncoderMode = LL_TIM_ENCODERMODE_X4_TI12 ;
	structEncoder.IC1Polarity = LL_TIM_IC_POLARITY_RISING;
	structEncoder.IC1ActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI;
	structEncoder.IC1Prescaler = LL_TIM_ICPSC_DIV1;
	structEncoder.IC1Filter = 0;
	structEncoder.IC2Polarity = LL_TIM_IC_POLARITY_RISING;
	structEncoder.IC2ActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI;
	structEncoder.IC2Prescaler = LL_TIM_ICPSC_DIV1;
	structEncoder.IC2Filter = 0;

	LL_TIM_ENCODER_Init(TIM3,&structEncoder);
	LL_TIM_SetPrescaler(TIM3,3);
	LL_TIM_SetAutoReload(TIM3, 360);	
	
	//Simulation
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	//Config de PA6 et PA7 pour la simulation
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_6, LL_GPIO_MODE_FLOATING);
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_7, LL_GPIO_MODE_FLOATING);
	
	//index
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_5, LL_GPIO_MODE_FLOATING);
	
	//LL_GPIO_GetPinPull
}

/*void IT_girouette(void){
	
}*/

void enableGirouette(void){
	
	LL_TIM_EnableCounter(TIM3);
}

void diableGirouette(void){
	LL_TIM_DisableCounter(TIM3);
}

int GetAngle(void)
{
	return LL_TIM_GetCounter(TIM3);
}

void setIndex(void){
	while (!LL_GPIO_IsInputPinSet (GPIOA, LL_GPIO_PIN_5)){
		LL_TIM_SetCounter(TIM3,INITIALANGLE);
	}
}