/*
 * donnees.h
 *
 *  Created on: 13 nov. 2018
 *      Author: Marcus
 */

#ifndef DONNEES_H_
#define DONNEES_H_
typedef struct fileProc fileProc;
struct fileProc{
	long int time;
	int pulse;
	fileProc *ptr;

};


void recupererDonnees(fileProc*, int*);

#endif /* DONNEES_H_ */
