/* GIROUETTE.H

Ne pas oublier le include "girouette.h" au d�but du main.

Pour une mise en place rapide de la girouette,
appelez dans l'ordre les fonctions suivantes :

	initGirouette();
	enableGirouette();
	
Afin de r�cup�rer l'angle pour le renvoyer au servomoteur,
proc�dez ainsi :
	
	int angle;
	angle = getAngle();
	
La valeur angle pourra �tre r�utilis�e dans le futur.

Combiner le angle = getAngle() de la girouette et le 
setSailAngle(angle) du servo dans une boucle infinie
est une bonne mani�re de proc�der pour automatiser le 
processus.																					
																									*/

#ifndef GIROUETTE_H
#define GIROUETTE_H


#include "stm32f103xb.h"

//Angle d'initialisation du compteur au passage � l'index.
//Cette valeur a �t� trouv�e exp�rimentalement en manipulant la girouette � la main.
static int INITIALANGLE = 0x0168-0x0040;

//Fonction d'initialisation de la girouette. 
//On y trouve la d�finition de la structure de l'encodeur, et l'activation du Timer 3.
void initGirouette(void);

//Fonction d'activation de la girouette.
//Elle contient uniquement la fonction EnableCounter pour le Timer 3.
void enableGirouette(void);

//Fonction de d�sactivation de la girouette.
//Une fois appel�e, le compteur du Timer 3 sera d�sactiv�.
void disableGirouette(void);

//R�cup�ration de l'angle donn� par la girouette.
//La fonction ajuste l'angle par rapport au d�calage provoqu� par la girouette.
//L'angle retourn� prend des valeurs entre 0 et 360.
//On consid�re la valeur 0 degr�s lorsque le vent est face au voilier.
int GetAngle(void);

//Initialise le compteur lorsque la girouette passe un certain point lors d'une premi�re rotation.
void setIndex(void);

#endif
