#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "actions.h"

void InOrder(fichierProc* file, int size)
{


	int i=0;
	while (i != size)
	{
		printf("%ld ; %d\n", file[i].temps, file[i].pouls);
		fflush(stdout);
		i++;

	}

}

void Increasing(fichierProc* file, int size, int data)
{
	printf("InOrder");
	fflush(stdout);
	int messy = TRUE;
	fichierProc tmp;
	while (messy){
		messy = FALSE;
		if (data==1){
			for (int j = 0; j < size-1; j++)
			{
				if(file[j].pouls > file[j+1].pouls)
				{
					tmp = file[j+1];
					file[j+1] = file[j];
					file[j] = tmp;
					messy = TRUE;


				}
			}
		}else{
			for (int j = 0; j < size-1; j++)
			{
				if(file[j].temps > file[j+1].temps)
				{
					tmp = file[j+1];
					file[j+1]= file[j];
					file[j] = tmp;
					messy = TRUE;
				}
			}
		}
	}
	InOrder(file, size);
}

void Decreasing(fichierProc* file, int size, int data)
{

	int messy = TRUE;
	fichierProc tmp;
	while (messy){
		messy = FALSE;
		if (data==1){
			for (int j = 0; j < size-1; j++)
			{
				if(file[j].pouls < file[j+1].pouls)
				{
					tmp = file[j+1];
					file[j+1] = file[j];
					file[j] = tmp;
					messy = TRUE;

				}
			}
		}else{
			for (int j = 0; j < size-1; j++)
			{
				if(file[j].temps < file[j+1].temps)
				{
					tmp = file[j+1];
					file[j+1]= file[j];
					file[j] = tmp;
					messy = TRUE;
				}
			}
		}
	}
	InOrder(file, size);
}
void average(fichierProc* file, int size)
{
	int a;
	int b;
	int i;
	double ave=0;
	double nb=0;
	printf("A partir de quel temps voulez vous commencer la moyenne des pouls?");
	fflush(stdout);
	scanf("%d", &a);
	printf("Jusqu'a  quel temps voulez vous faire la moyenne des pouls?");
	fflush(stdout);
	scanf("%d", &b);
	while (file[i].temps < b&&i<size)
	{
		while(file[i].temps < a)
		{
			i++;
		}
		ave += file[i].pouls;
		nb++;
		i++;
	}
	double resultat= ave/nb;
	printf("%f \n ", resultat);
}


void MaxMin(fichierProc *file, int size)
{
	int val=0;
	int indiceMax=0;
	int indiceMin=0;
	for (int i=0; i < size; i++)
	{
		if (file[i].pouls > val){
			val = file[i].pouls;
			indiceMax=i;
		}

	}

	for (int i=0; i < size; i++)
	{
		if (file[i].pouls < val)
			val = file[i].pouls;
			indiceMin=i;
	}
	printf("Le pouls max est : %d \nLe pouls min est  de %d \n", file[indiceMax].pouls, file[indiceMin].pouls);
	fflush(stdout);


}

void affichTrie(fichierProc* fichier, int size)
{
	int a=0;
	int b=0;
	printf ("Dans quel ordre voulez-vous afficher vos donnees ? \n1)Ordre croissant \n2)Ordre decroissant");
	fflush(stdout);
	scanf("%d", &a);
	//selectionner a
	switch (a)
	{
	case 1:
		printf("Quelle donnee voulez vous trier?\n1: pouls\n2: temps\n");
		fflush(stdout);
		scanf("%d", &b);
		Increasing(fichier, size, b);
		//detecter les erreurs de frappe
		break;

	case 2:
		printf("Quelle donnee voulez vous trier?\n1: pouls\n2: temps\n");
		fflush(stdout);
		scanf("%d", &b);
		Decreasing(fichier, size, b);
		break;

	default:
		printf("error");
		break;
	}
}
void rechercheTemps(fichierProc* file, int size){
	long int tempsMax;
	long int tempsMin;
	printf("Entrez le temps minimal: \n");
	fflush(stdout);
	scanf("%ld", &tempsMin);
	printf("Entrez le temps maximal: \n");
	fflush(stdout);
	scanf("%ld", &tempsMax);

	for (int i = 0; i< size; i++){
		if (file[i].temps>=tempsMin && file[i].temps <= tempsMax){
			printf("%ld ; %d \n", file[i].temps, file[i].pouls);

		}
	}

}
