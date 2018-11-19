#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "actions.h"

void InOrder(fileProc* file, int size)
{


	int i=0;
	while (i != size)
	{
		printf("%ld ; %d\n", file[i].time, file[i].pulse);
		fflush(stdout);
		i++;

	}

}

void Increasing(fileProc* file, int size, int data)
{
	printf("InOrder");
	fflush(stdout);
	int messy = TRUE;
	fileProc tmp;
	while (messy){
		messy = FALSE;
		if (data==1){
			for (int j = 0; j < size-1; j++)
			{
				if(file[j].pulse > file[j+1].pulse)
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
				if(file[j].time > file[j+1].time)
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

void Decreasing(fileProc* file, int size, int data)
{

	int messy = TRUE;
	fileProc tmp;
	while (messy){
		messy = FALSE;
		if (data==1){
			for (int j = 0; j < size-1; j++)
			{
				if(file[j].pulse < file[j+1].pulse)
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
				if(file[j].time < file[j+1].time)
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
void average(fileProc* file, int size)
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
	while (file[i].time < b && i<size)
	{
		while(file[i].time < a)
		{
			i++;
		}
		ave += file[i].pulse;
		nb++;
		i++;
	}
	double result= ave/nb;
	printf("%f \n ", result);
}


void MaxMin(fileProc *file, int size)
{
	int val=0;
	int indexMax=0;
	int indexMin=0;
	for (int i=0; i < size; i++)
	{
		if (file[i].pulse > val){
			val = file[i].pulse;
			indexMax=i;
		}

	}

	for (int i=0; i < size; i++)
	{
		if (file[i].pulse < val)
			val = file[i].pulse;
			indexMin=i;
	}
	printf("Le pouls max est : %d à %ld \nLe pouls min est  de %d à %ld\n", file[indexMax].pulse, file[indexMax].time, file[indexMin].pulse, file[indexMax].time);
	fflush(stdout);


}

void sortPrint(fileProc* file, int size)
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
		Increasing(file, size, b);
		//detecter les erreurs de frappe
		break;

	case 2:
		printf("Quelle donnee voulez vous trier?\n1: pouls\n2: temps\n");
		fflush(stdout);
		scanf("%d", &b);
		Decreasing(file, size, b);
		break;

	default:
		printf("error");
		break;
	}
}
void findTime(fileProc* file, int size){
	long int timeMax;
	long int timeMin;
	printf("Entrez le temps minimal: \n");
	fflush(stdout);
	scanf("%ld", &timeMin);
	printf("Entrez le temps maximal: \n");
	fflush(stdout);
	scanf("%ld", &timeMax);

	for (int i = 0; i< size; i++){
		if (file[i].time>=timeMin && file[i].time <= timeMax){
			printf("%ld ; %d \n", file[i].time, file[i].pulse);

		}
	}

}
