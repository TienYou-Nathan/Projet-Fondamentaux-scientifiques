#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#define TRUE 1;
#define FALSE 0;
#ifndef ACTIONS
#define ACTIONS
void InOrder(fichierProc*, int);
void Increasing(fichierProc*, int ,int);
void Decreasing(fichierProc*, int ,int);
void average(fichierProc*, int);
void affichTrie(fichierProc*, int);
void rechercheTemps(fichierProc*, int);
void MaxMin(fichierProc*, int);
#endif
