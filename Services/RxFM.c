#include "RxFM.h"
#include "MyTimer.h"
#define PSC 999
#define ARR 719

void init(void){
	MyPWM_input_Conf(ARR,PSC) ; 
}

void getLength(void){
	int sens ; //1 = gauche et 0 = droite
	float power = 0; //1 max, 0,5 medium et 0 min
	int value_cnt = TIM3 -> CCR1;
	float tps = value_cnt * ((PSC+1)/72000000)*(ARR+1) ;
	if (tps < 0.00145 && tps > 0.001){
		sens = 1 ;
		power = tps* (1-(1.45/0.45)) +(1.45/0.45);
	}
	else if (tps > 0.00155 && tps < 0.002){
		sens = 0 ; 
		power =  (tps* (1/0.00045)) -(0.00155/0.00045);
	}
}


