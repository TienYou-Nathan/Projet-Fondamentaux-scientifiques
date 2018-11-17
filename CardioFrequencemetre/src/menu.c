/*
 * menu.c
 *
 *  Created on: 13 nov. 2018
 *      Author: Marcus
 */

#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "actions.h"

void printMenu(){
	int sizeArrayCsv=0;
		fileProc datas;
		fileProc *ArrayCsv;
		datas.pulse=0;
		datas.time=0;

		ArrayCsv=&datas;
		int response=0;
		printf("Bienvenue \nQue voulez-vous faire?\n \n");
		printf("1) Afficher les données dans l’ordre du fichier .csv\n");
		printf("2) Afficher les données en ordre croissant/décroissant\n");
		printf("3) Rechercher et afficher les données pour un temps particulier\n");
		printf("4) Afficher la moyenne de pouls dans une plage de temps donnée\n");
		printf("5) Afficher le nombre de lignes de données actuellement en mémoire\n");
		printf("6) Rechercher et afficher les max/min de pouls (avec le temps associé)\n");
		printf("0) Quitter\n");
		fflush(stdout);
		scanf("%d", &response);
		fflush(stdout);
		recupererDonnees(ArrayCsv, &sizeArrayCsv);

		switch(response){
		case 1:
			fflush(stdout);
			InOrder(ArrayCsv, sizeArrayCsv);
			break;
		case 2:
			sortPrint(ArrayCsv, sizeArrayCsv);
			break;
		case 3:
			findTime(ArrayCsv, sizeArrayCsv);
		break;
		case 4:
			average(ArrayCsv, sizeArrayCsv);
			break;
		case 5:
			printf("%d \n", sizeArrayCsv);
			fflush(stdout);
			break;
		case 6:
			MaxMin(ArrayCsv, sizeArrayCsv);
			break;

		default:
			printf("erreur");
			break;
		}


	printf("fin");
}







