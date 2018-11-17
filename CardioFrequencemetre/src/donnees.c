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

void recupererDonnees(fileProc * fichierFinal, int *taille){
	char time[100] ;
	char pulse [3] ;
	int charFile;
	int i = 0;
	int j=0;
	int taille2=0;

	FILE*  file=NULL;
	if ((file = fopen ("Battements.csv", "r"))==NULL){
		printf("le fichier Battements.csv n'a pas ete trouve\n");
		fflush(stdout);
		exit(1);
	}else{

		while (!feof(file)){


			while((charFile=fgetc(file))!=';'&&charFile!=EOF){
				if (charFile != ';'){
					time[i]=charFile;
					i++;
				}else{
					time[i]='\0';
				}
			}
			i=0;
			while((charFile=fgetc(file))!='&'&&charFile!=EOF){
				if (charFile !='&'){
					pulse[i]=charFile;
					i++;
				}else{
					pulse[i]='\0';
				}
			}
			taille2++;
			i=0;
			fflush(stdout);
			fichierFinal[j].time=atoi(time);
			fichierFinal[j].pulse=atoi(pulse);
			*taille=taille2-1;
			memset (time, 0, sizeof (time));
			memset (pulse, 0, sizeof (pulse));
			j++;
		}
		fclose(file);
	}
}

