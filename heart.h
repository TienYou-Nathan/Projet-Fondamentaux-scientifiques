/*
 * heart.h
 *
 *  Created on: 13 nov. 2018
 *      Author: legon
 */

#ifndef HEART_H_
#define HEART_H_

struct heartParams {
	int bpm;
	int light;
	int order;
	int led;
};

void beat(struct heartParams *settings);

#endif /* HEART_H_ */
