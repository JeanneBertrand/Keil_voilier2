/* GIROUETTE.H

Ne pas oublier le include "girouette.h" au début du main.

Pour une mise en place rapide de la girouette,
appelez dans l'ordre les fonctions suivantes :

	initGirouette();
	enableGirouette();
	
Afin de récupérer l'angle pour le renvoyer au servomoteur,
procédez ainsi :
	
	int angle;
	angle = getAngle();
	
La valeur angle pourra être réutilisée dans le futur.

Combiner le angle = getAngle() de la girouette et le 
setSailAngle(angle) du servo dans une boucle infinie
est une bonne manière de procéder pour automatiser le 
processus.																					
																									*/

#ifndef GIROUETTE_H
#define GIROUETTE_H


#include "stm32f103xb.h"

//Angle d'initialisation du compteur au passage à l'index.
//Cette valeur a été trouvée expérimentalement en manipulant la girouette à la main.
static int INITIALANGLE = 0x0168-0x0040;

//Fonction d'initialisation de la girouette. 
//On y trouve la définition de la structure de l'encodeur, et l'activation du Timer 3.
void initGirouette(void);

//Fonction d'activation de la girouette.
//Elle contient uniquement la fonction EnableCounter pour le Timer 3.
void enableGirouette(void);

//Fonction de désactivation de la girouette.
//Une fois appelée, le compteur du Timer 3 sera désactivé.
void disableGirouette(void);

//Récupération de l'angle donné par la girouette.
//La fonction ajuste l'angle par rapport au décalage provoqué par la girouette.
//L'angle retourné prend des valeurs entre 0 et 360.
//On considère la valeur 0 degrés lorsque le vent est face au voilier.
int GetAngle(void);

//Initialise le compteur lorsque la girouette passe un certain point lors d'une première rotation.
void setIndex(void);

#endif
