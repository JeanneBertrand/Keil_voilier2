#include "MyTimer.h"
#include "MyGPIO.h"
#include "MoteurPlateau.h"
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_tim.h"

#define PSC 3599 // (1/20kHz) = (1/72MHz) * (PSC+1)
#define ARR 0

/**
	* @brief  Configure le Moteur.
  * @note   
	* @param  None
  * @retval None
  */
void Init_Moteur(void){

	MyPWM_output_Conf(ARR,PSC);
	MyGPIO_PWMOutputConf();
	MyGPIO_SensConf();
	
}


/**
	* @brief  Set les paramètres de sens (droite ou gauche) et de puissance du moteur .
  * @note   
	* @param  int angle compris entre -20 et 20
  * @retval None
  */
void SetParam(int angle){
	if (angle>0) {
		LL_GPIO_SetOutputPin(GPIOA,LL_GPIO_PIN_2);
	} else {
		LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_2);
		angle= - angle; 
	}
	int power = angle*4;
	LL_TIM_OC_SetCompareCH2(TIM2,power); 
}
