/* SERVO.H

Ne pas oublier le include "Servo.h" au début du main.

Pour une mise en place rapide du servomoteur,
appelez dans l'ordre les fonctions suivantes :

	initServo();
	enableServo();
	
Afin d'envoyer l'angle récupéré de la girouette
pour l'envoyer au servomoteur, procédez ainsi :
	
	setSailAngle(angle);
	
Combiner le angle = getAngle() de la girouette et le 
setSailAngle(angle) du servo dans une boucle infinie
est une bonne manière de procéder pour automatiser le 
processus.																					
																									*/
																									
#ifndef SERVO_H

#define SERVO_H

//Fonction d'initialisation du servomoteur. 
//On y trouve la définition de la structure du GPIO, du Timer 1 et du BDTR pour le MOE.
void initServo(void);

//Fonction d'activation du servomoteur.
//Elle contient uniquement la fonction EnableCounter pour le Timer 1.
void enableServo(void);

//Fonction de désactivation du servomoteur.
//Une fois appelée, le compteur du Timer 1 sera désactivé.
void disableServo(void);

//Envoi d'une valeur (comprise entre 50 = min et 100 = max) au servomoteur.
void setSailAngle (int angle) ;

#endif
