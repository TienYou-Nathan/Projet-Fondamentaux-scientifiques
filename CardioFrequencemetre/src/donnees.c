/*
 * donnees.c
 *
 *  Created on: 13 nov. 2018
 *      Author: Marcus
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donnees.h"

int recupererDonnees(fichierProc * fichierFinal, int *taille){
	char temps[100] ;
	char pouls [3] ;
	int charFich;
	int i = 0;
	int j=0;
	int taille2=0;

	FILE*  fichier=NULL;
	if ((fichier = fopen ("Battements.csv", "r"))==NULL){
		printf("le fichier Battements.csv n'a pas ete trouve\n");
		fflush(stdout);
		exit(1);
	}else{

		while (!feof(fichier)){


			while((charFich=fgetc(fichier))!=';'&&charFich!=EOF){
				if (charFich != ';'){
					temps[i]=charFich;
					i++;
				}else{
					temps[i]='\0';
				}
			}
			i=0;
			while((charFich=fgetc(fichier))!='&'&&charFich!=EOF){
				if (charFich !='&'){
					pouls[i]=charFich;
					i++;
				}else{
					pouls[i]='\0';
				}
			}
			taille2++;
			i=0;
			fflush(stdout);
			fichierFinal[j].temps=atoi(temps);
			fichierFinal[j].pouls=atoi(pouls);
			*taille=taille2-1;
			printf("test  %d %ld %d %d\n",*taille, fichierFinal[j].temps, fichierFinal[j].pouls, feof(fichier));
			printf("ok");
			fflush(stdout);
			memset (temps, 0, sizeof (temps));
			memset (pouls, 0, sizeof (pouls));
			j++;
		}
		fclose(fichier);
		return 0;
	}
}

