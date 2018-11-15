/*
 * cardio.h
 *
 *  Created on: 13 nov. 2018
 *      Author: legon
 */

#ifndef CARDIO_H_
#define CARDIO_H_

typedef struct {
	int pulses;
	int ms;
	int base;
	int checks;
	struct heartParams *settings;
	int way;
} state;

int detectPulse(float pulses, float ms, float base);
int initPulse();

#endif /* CARDIO_H_ */
