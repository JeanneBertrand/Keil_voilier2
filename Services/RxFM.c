#include "RxFM.h"
#include "MyTimer.h"
#include "MyGPIO.h"
#define PSC 1799
#define ARR 0


void Teleco_init(void){
	MyPWM_input_Conf(ARR,PSC) ; 
	MyGPIO_PWMConf();
}

int getLength(void){
	
	int value_cnt = TIM4 -> CCR2;
	return value_cnt - 20 ;  // résolution = -20/+20 1 équivaut à -20 (gauche) et 40 à +20 (droite)
}


