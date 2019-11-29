#include "MyTimer.h"
#include "MyGPIO.h"
#include "MoteurPlateau.h"
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_tim.h"

#define PSC 3 // (1/20kHz) = (1/72MHz) * (PSC+1) * (ARR+1) --> en vrai notre fréquence est à 18kHz
#define ARR 999
 int power ; 
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
	* @param  int valeur_teleco compris entre -20 et 20
  * @retval None
  */
void SetParam(int valeur_teleco){
	
	if (valeur_teleco>0) {
		LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_2); //droite
	} else {
		LL_GPIO_SetOutputPin(GPIOA,LL_GPIO_PIN_2); //gauche
		valeur_teleco= - valeur_teleco; 
	}
	power = valeur_teleco*60;
	if (power>1000) {power=1000;} 
	LL_TIM_OC_SetCompareCH2(TIM2,power); 
}
