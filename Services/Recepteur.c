#include "Recepteur.h"
#include "MyTimer.h"
#include "MyGPIO.h"
#define PSC 1799
#define ARR 65535

/**
	* @brief  Configure le récepteur de la télécommande (TIM4 en PWM input et GPIOB en floating input sur les PIN 6 et 7).
  * @note   
	* @param  None
  * @retval None
  */
void Init_Teleco(void){
	MyPWM_input_Conf(ARR,PSC) ; 
	MyGPIO_PWMInputConf();
}

/**
	* @brief  Récupère la durée de l'impulsion envoyée par la télécommande.
  * @note   
	* @param  None
  * @retval int value_cnt compris entre -20 et 20 (valeurs négatives à gauche et positives à droite). 
  */
int getTelecoCount(void){
	
	int value_cnt = TIM4 -> CCR2;
	return (value_cnt -59) ;  // résolution = -20/+20 1 équivaut à -20 (gauche) et 40 à +20 (droite)
}


