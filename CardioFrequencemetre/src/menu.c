/*
 * menu.c
 *
 *  Created on: 13 nov. 2018
 *      Author: Marcus
 */

#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
void afficherMenu(){
	int sizeTabFichier=0;
	fichierProc donnees;
	fichierProc *premiereDonnee;
	donnees.pouls=0;
	donnees.temps=0;
	donnees.ptr=NULL;
	premiereDonnee=&donnees;
	int reponse=0;
	printf("Bienvenue \nQue voulez-vous faire?\n \n");
	printf("1) Afficher les donn�es dans l�ordre du fichier .csv\n");
	printf("2) Afficher les donn�es en ordre croissant/d�croissant\n");
	printf("3) Rechercher et afficher les donn�es pour un temps particulier\n");
	printf("4) Afficher la moyenne de pouls dans une plage de temps donn�e\n");
	printf("5) Afficher le nombre de lignes de donn�es actuellement en m�moire\n");
	printf("6) Rechercher et afficher les max/min de pouls (avec le temps associ�)\n");
	printf("0) Quitter\n");
	fflush(stdout);
	//scanf("%d", reponse);
	recupererDonnees(premiereDonnee, &sizeTabFichier);
	/*switch(reponse){
	case 1:
		affichNormal();
		break;
	case 2:
		affichOrdonne();
		break;
	case 3:
		rechercheTemps();
		break;
	case 4:
		affMoyPouls();
		break;
	case 5:
		affNbLignes();
		break;
	case 6:
		affMaxMin();
	}*/




}
