#include "Recepteur.h"
#include "MyTimer.h"
#include "MyGPIO.h"
#define PSC 1799
#define ARR 65535

/**
	* @brief  Configure le r�cepteur de la t�l�commande (TIM4 en PWM input et GPIOB en floating input sur les PIN 6 et 7).
  * @note   
	* @param  None
  * @retval None
  */
void Init_Teleco(void){
	MyPWM_input_Conf(ARR,PSC) ; 
	MyGPIO_PWMInputConf();
}

/**
	* @brief  R�cup�re la dur�e de l'impulsion envoy�e par la t�l�commande.
  * @note   
	* @param  None
  * @retval int value_cnt compris entre -20 et 20 (valeurs n�gatives � gauche et positives � droite). 
  */
int getTelecoCount(void){
	
	int value_cnt = TIM4 -> CCR2;
	return (value_cnt -59) ;  // r�solution = -20/+20 1 �quivaut � -20 (gauche) et 40 � +20 (droite)
}


