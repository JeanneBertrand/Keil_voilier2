

/**
	* @brief  Configure le récepteur de la télécommande (TIM4 en PWM input et GPIOB en floating input sur les PIN 6 et 7).
  * @note   
	* @param  None
  * @retval None
  */
void Teleco_init(void) ; 

/**
	* @brief  Récupère la durée de l'impulsion envoyée par la télécommande.
  * @note   
	* @param  None
  * @retval int value_cnt compris entre -20 et 20 (valeurs négatives à gauche et positives à droite). 
  */
int getLength(void); 

