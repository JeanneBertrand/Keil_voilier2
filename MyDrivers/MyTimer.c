// TOUT A FAIRE !! //

/*
 indispensable pour pouvoir adresser les registres des p�riph�riques.
 Rem : OBLIGATION d'utiliser les d�finitions utiles contenues dans ce fichier (ex : TIM_CR1_CEN, RCC_APB1ENR_TIM2EN ...)
 pour une meilleure lisibilit� du code.

 Pour les masques, utiliser �galement les d�finitions propos�e
 Rappel : pour mettre � 1  , reg = reg | Mask (ou Mask est le repr�sente le ou les bits � positionner � 1)
				  pour mettre � 0  , reg = reg&~ Mask (ou Mask est le repr�sente le ou les bits � positionner � 0)
 
*/ 

#include "MyTimer.h"
#include "stm32f1xx_ll_bus.h" // Pour l'activation des horloges
#include "stm32f1xx_ll_tim.h" 


// variable pointeur de fonction permettant de m�moriser le callback � appeler depuis
// le handler d'IT
void (*Ptr_ItFct_TIM1)(void); 
void (*Ptr_ItFct_TIM2)(void); 
void (*Ptr_ItFct_TIM3)(void); 
void (*Ptr_ItFct_TIM4)(void); 




/**
	* @brief  Active l'horloge et r�gle l'ARR et le PSC du timer vis�
  * @note   Fonction � lancer avant toute autre. Le timer n'est pas encore lanc� (voir MyTimerStart)
	* @param  TIM_TypeDef Timer : indique le timer � utiliser par le chronom�tre, TIM1, TIM2, TIM3 ou TIM4
	* 				int Arr   : valeur � placer dans ARR
	*					int Psc   : valeur � placer dans PSC
  * @retval None
  */
void MyTimer_Conf(TIM_TypeDef * Timer,int Arr, int Psc)
{
	LL_TIM_InitTypeDef My_LL_Tim_Init_Struct;
	
	// Validation horloge locale
	if (Timer==TIM1) LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM1);
	else if (Timer==TIM2) LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2);
	else if (Timer==TIM3) LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);
	else  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM4);
	
	// chargement structure Arr, Psc, Up Count
	My_LL_Tim_Init_Struct.Autoreload=Arr;
	My_LL_Tim_Init_Struct.Prescaler=Psc;
	My_LL_Tim_Init_Struct.ClockDivision=LL_TIM_CLOCKDIVISION_DIV1;
	My_LL_Tim_Init_Struct.CounterMode=LL_TIM_COUNTERMODE_UP;
	My_LL_Tim_Init_Struct.RepetitionCounter=0;
	
	LL_TIM_Init(Timer,&My_LL_Tim_Init_Struct);
	

	// Blocage IT
	LL_TIM_DisableIT_UPDATE(Timer);
	
	
	// Blocage Timer
	LL_TIM_DisableCounter(Timer);
	

		
}


/**
	* @brief  Configure le Timer4 en PWM INPUT.
  * @note   
	* @param  valeurs de ARR et PSC donn�es par un DEFINE 
  * @retval None
  */
void MyPWM_input_Conf (int Arr, int Psc) {
	
	MyTimer_Conf (TIM4, Arr, Psc) ; 
	
	TIM4 -> CR1 |= TIM_CR1_CEN;
	
	TIM4 -> CCMR1 &=~ TIM_CCMR1_CC1S ;
	TIM4 -> CCMR1 |= 1<< TIM_CCMR1_CC1S_Pos ; 
	
	TIM4 -> CCER &=~ TIM_CCER_CC1P ; 

	TIM4 -> CCMR1 &=~ TIM_CCMR1_CC2S ; 
	TIM4 -> CCMR1 |= 2<< TIM_CCMR1_CC2S_Pos ; 
	
	TIM4 -> CCER |= TIM_CCER_CC2P ; 
	
	TIM4 -> SMCR &=~ TIM_SMCR_TS ; 
	TIM4 -> SMCR |= 5<<TIM_SMCR_TS_Pos ; 
	
	TIM4 -> SMCR &=~ TIM_SMCR_SMS ; 
	TIM4 -> SMCR |= 4<<TIM_SMCR_SMS_Pos ; 

	TIM4 -> CCER |= TIM_CCER_CC1E ;
	TIM4 -> CCER |= TIM_CCER_CC2E ; 	
	
}


/**
	* @brief  Configure le Timer2 en PWM OUTPUT.
  * @note   
	* @param  valeurs de ARR et PSC donn�es par un DEFINE 
  * @retval None
  */
void MyPWM_output_Conf (int Arr, int Psc)
{
	MyTimer_Conf(TIM2, Arr, Psc) ; 
	LL_TIM_OC_SetMode(TIM2,LL_TIM_CHANNEL_CH2,LL_TIM_OCMODE_PWM1);
	LL_TIM_CC_EnableChannel(TIM2,LL_TIM_CHANNEL_CH2);

}
/**
	* @brief  D�marre le timer consid�r�
 {
		LL_TIM_EnableCounter(Timer); 
}
*/
/**
	* @brief  Arr�t le timer consid�r�
  * @note   
	* @param  TIM_TypeDef Timer : indique le timer � utiliser par le chronom�tre, TIM1, TIM2, TIM3 ou TIM4
  * @retval None
  */
void MyTimer_Stop(TIM_TypeDef * Timer)
{
	LL_TIM_DisableCounter(Timer);
}


/**
	* @brief  Configure le Timer consid�r� en interruption sur d�bordement.
  * @note   A ce stade, les interruptions ne sont pas valid�s (voir  MyTimer_IT_Enable )
	* @param  TIM_TypeDef Timer : indique le timer � utiliser par le chronom�tre, TIM1, TIM2, TIM3 ou TIM4
	* 				void (*IT_function) (void) : nom (adresse) de la fonction � lancer sur interruption
	*         int Prio : priorit� associ�e � l'interruption
  * @retval None
  */
void MyTimer_IT_Conf(TIM_TypeDef * Timer, void (*IT_function) (void),int Prio)
{
	// affectation de la fonction
	if (Timer==TIM1) Ptr_ItFct_TIM1=IT_function;
	else if (Timer==TIM2)	Ptr_ItFct_TIM2=IT_function;
	else if (Timer==TIM3)	Ptr_ItFct_TIM3=IT_function;
	else  Ptr_ItFct_TIM4=IT_function;

	
	// Blocage IT (il faudra la d�bloquer voir fct suivante)
	LL_TIM_DisableIT_UPDATE(Timer);
	
	// validation du canal NVIC
	IRQn_Type TIM_irq;
	
	if (Timer==TIM1) TIM_irq=TIM1_UP_IRQn;
	else if (Timer==TIM2)	TIM_irq=TIM2_IRQn;
	else if (Timer==TIM3)	TIM_irq=TIM3_IRQn;
	else 	TIM_irq=TIM4_IRQn;
	
	NVIC_SetPriority(TIM_irq, Prio);
	NVIC_EnableIRQ(TIM_irq);

	
}


/**
	* @brief  Autorise les interruptions
  * @note   
	* @param  TIM_TypeDef Timer : indique le timer � utiliser par le chronom�tre, TIM1, TIM2, TIM3 ou TIM4
  * @retval None
  */
void MyTimer_IT_Enable(TIM_TypeDef * Timer)
{
		LL_TIM_EnableIT_UPDATE(Timer);
}


/**
	* @brief  Interdit les interruptions
  * @note   
	* @param  TIM_TypeDef Timer : indique le timer � utiliser par le chronom�tre, TIM1, TIM2, TIM3 ou TIM4
  * @retval None
  */
void MyTimer_IT_Disable(TIM_TypeDef * Timer)
{
			LL_TIM_DisableIT_UPDATE(Timer); 
}	


/*
============ LES INTERRUPTIONS =================================

*/

void TIM1_UP_IRQHandler(void)
{
	// rabaisser le flag d'IT
	LL_TIM_ClearFlag_UPDATE(TIM1);
	(*Ptr_ItFct_TIM1)();
}	

void TIM2_IRQHandler(void)
{
	// rabaisser le flag d'IT
	LL_TIM_ClearFlag_UPDATE(TIM2);
	(*Ptr_ItFct_TIM2)();
}	

void TIM3_IRQHandler(void)
{
	// rabaisser le flag d'IT
	LL_TIM_ClearFlag_UPDATE(TIM3);
	(*Ptr_ItFct_TIM3)();
}	

void TIM4_IRQHandler(void)
{
	// rabaisser le flag d'IT
	LL_TIM_ClearFlag_UPDATE(TIM4);
	(*Ptr_ItFct_TIM4)();
}	
