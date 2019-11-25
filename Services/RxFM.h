

/**
	* @brief  Configure le r�cepteur de la t�l�commande (TIM4 en PWM input et GPIOB en floating input sur les PIN 6 et 7).
  * @note   
	* @param  None
  * @retval None
  */
void Teleco_init(void) ; 

/**
	* @brief  R�cup�re la dur�e de l'impulsion envoy�e par la t�l�commande.
  * @note   
	* @param  None
  * @retval int value_cnt compris entre -20 et 20 (valeurs n�gatives � gauche et positives � droite). 
  */
int getLength(void); 

