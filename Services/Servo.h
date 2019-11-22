//driver for the rf receiver//
#ifndef SERVO_MOTEUR_H

#define SERVO_MOTEUR_H

/*

@brief : config TIMER1

@param : none

@return : none

*/

void initServo(void);

void enableServo(void);

void disableServo(void);

void setSailAngle (int angle) ;

#endif
