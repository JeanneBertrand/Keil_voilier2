#include "MyGPIO.h"
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_tim.h"


/**
	* @brief  Configure le GPIO B en floating input sur les pin 6 et 7
  * @note   
	* @param  None
  * @retval None
  */
void MyGPIO_PWMInputConf(void){

	RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN ; 

 LL_GPIO_InitTypeDef GPIO_InitStruct6;
	
 GPIO_InitStruct6.Pin = LL_GPIO_PIN_6;
 GPIO_InitStruct6.Mode = LL_GPIO_MODE_FLOATING;
 GPIO_InitStruct6.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
 GPIO_InitStruct6.Pull = LL_GPIO_OUTPUT_PUSHPULL;
 GPIO_InitStruct6.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
 
 LL_GPIO_Init(GPIOB, &GPIO_InitStruct6);
	
 LL_GPIO_InitTypeDef GPIO_InitStruct7;
	
 GPIO_InitStruct7.Pin = LL_GPIO_PIN_7;
 GPIO_InitStruct7.Mode = LL_GPIO_MODE_FLOATING;
 GPIO_InitStruct7.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
 GPIO_InitStruct7.Pull = LL_GPIO_OUTPUT_PUSHPULL;
 GPIO_InitStruct7.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
 
 LL_GPIO_Init(GPIOB, &GPIO_InitStruct7);
}



/**
	* @brief  Configure le GPIO A en push-pull sur la pin 1
  * @note   
	* @param  None
  * @retval None
  */
void MyGPIO_PWMOutputConf(void){
	
	
	RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN ; 
	
	LL_GPIO_InitTypeDef GPIOIn;
	GPIOIn.Pin=LL_GPIO_PIN_1;
	GPIOIn.Mode=LL_GPIO_MODE_ALTERNATE;
	GPIOIn.OutputType=LL_GPIO_OUTPUT_PUSHPULL;
	GPIOIn.Speed=LL_GPIO_SPEED_FREQ_MEDIUM;
	LL_GPIO_Init(GPIOA, &GPIOIn);
	
}


/**
	* @brief  Configure le GPIO A en general purpose output sur les pin 2
  * @note   
	* @param  None
  * @retval None
  */
void MyGPIO_SensConf(void){
		LL_GPIO_InitTypeDef GPIOIn;
	//Initialisation GPIO (Sens)
	GPIOIn.Pin=LL_GPIO_PIN_2;
	GPIOIn.Mode=LL_GPIO_MODE_OUTPUT;
	LL_GPIO_Init(GPIOA,&GPIOIn);


}

