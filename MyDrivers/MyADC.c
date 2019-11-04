#include "MyADC.h" 
#include "stm32f1xx_ll_adc.h" 


void MyADC_Conf (ADC_TypeDef * ADC) {
	 RCC -> APB2ENR |= RCC_APB2ENR_ADC1EN ; 
		LL_ADC_InitTypeDef ADC_init;

		ADC_init.DataAlignment = LL_ADC_DATA_ALIGN_RIGHT;
		ADC_init.SequencersScanMode = LL_ADC_SEQ_SCAN_DISABLE;	

		LL_ADC_Init(ADC ,&ADC_init );
}
