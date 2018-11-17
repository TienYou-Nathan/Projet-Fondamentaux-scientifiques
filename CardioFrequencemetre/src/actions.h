#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#define TRUE 1;
#define FALSE 0;
#ifndef ACTIONS
#define ACTIONS
void InOrder(fileProc*, int);
void Increasing(fileProc*, int ,int);
void Decreasing(fileProc*, int ,int);
void average(fileProc*, int);
void sortPrint(fileProc*, int);
void findTime(fileProc*, int);
void MaxMin(fileProc*, int);
#endif
