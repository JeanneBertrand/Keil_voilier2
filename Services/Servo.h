/* SERVO.H

Ne pas oublier le include "Servo.h" au d�but du main.

Pour une mise en place rapide du servomoteur,
appelez dans l'ordre les fonctions suivantes :

	initServo();
	enableServo();
	
Afin d'envoyer l'angle r�cup�r� de la girouette
pour l'envoyer au servomoteur, proc�dez ainsi :
	
	setSailAngle(angle);
	
Combiner le angle = getAngle() de la girouette et le 
setSailAngle(angle) du servo dans une boucle infinie
est une bonne mani�re de proc�der pour automatiser le 
processus.																					
																									*/
																									
#ifndef SERVO_H

#define SERVO_H

//Fonction d'initialisation du servomoteur. 
//On y trouve la d�finition de la structure du GPIO, du Timer 1 et du BDTR pour le MOE.
void initServo(void);

//Fonction d'activation du servomoteur.
//Elle contient uniquement la fonction EnableCounter pour le Timer 1.
void enableServo(void);

//Fonction de d�sactivation du servomoteur.
//Une fois appel�e, le compteur du Timer 1 sera d�sactiv�.
void disableServo(void);

//Envoi d'une valeur (comprise entre 50 = min et 100 = max) au servomoteur.
void setSailAngle (int angle) ;

#endif
