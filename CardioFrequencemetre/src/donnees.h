/*
 * donnees.h
 *
 *  Created on: 13 nov. 2018
 *      Author: Marcus
 */

#ifndef DONNEES_H_
#define DONNEES_H_
typedef struct fichierProc fichierProc;
struct fichierProc{
	long int temps;
	int pouls;
	fichierProc *ptr;

};


void recupererDonnees(fichierProc*, int*);

#endif /* DONNEES_H_ */
