//#include "Servo.h"
#include "stm32f1xx_ll_bus.h"
#include "stm32f1xx_ll_tim.h"


void initServo (void) {
//start the clock of TIM1
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM1);

//struct use to config TIM1
	LL_TIM_InitTypeDef TIM1InitStruct;

/*set at 20ms*/
	TIM1InitStruct.Autoreload = 999; 
	TIM1InitStruct.Prescaler= 1439;

/*************/
//init the other files
	TIM1InitStruct.ClockDivision=LL_TIM_CLOCKDIVISION_DIV1;
	TIM1InitStruct.CounterMode=LL_TIM_COUNTERMODE_UP;
	TIM1InitStruct.RepetitionCounter=0;

//Initialisation de la structure (remplissage automatique des valeurs pas importantes)
	LL_TIM_Init(TIM1,&TIM1InitStruct);

//Utilisation d'une structure pour configurer le TIM1 en PWM
	LL_TIM_OC_InitTypeDef PWMInitStruct;

//Initialisation de la structure du PWM
	LL_TIM_OC_StructInit(&PWMInitStruct);

//set the values of the fields of the PWM structure
	PWMInitStruct.OCMode = LL_TIM_OCMODE_PWM1;

//1ms (value : 50) for the minimum angle and 2ms (value : 100) for the max angle
//set at 2 ms by default (sail in straight position)
	PWMInitStruct.CompareValue = 100;

//enable the compare mode
	PWMInitStruct.OCState = LL_TIM_OCSTATE_ENABLE;
	PWMInitStruct.OCNState = LL_TIM_OCSTATE_ENABLE;

//start TIM1 output mode
	TIM1 -> BDTR |= 0x1 << 15;

//bind the PWM struct with the timer and the channel
	LL_TIM_OC_Init(TIM1, LL_TIM_CHANNEL_CH1, &PWMInitStruct);
}

void enableServo(void){
		LL_TIM_EnableCounter(TIM3);
}

void disableServo(void){
		LL_TIM_DisableCounter(TIM3);
}

void setSailAngle (int angle) { 
	float coefDirect = (-5./6.);
	float	origin = 100.;
	float compareValue = coefDirect * (float) angle + origin;
	LL_TIM_OC_SetCompareCH1(TIM1,(int) compareValue);
}
