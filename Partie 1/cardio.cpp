/*
 * cardio.cpp
 *
 *  Created on: 13 nov. 2018
 *      Author: legon
 */
#include <Arduino.h>
#include "cardio.h"
#include "heart.h"

#define ANALOGPORT 0

int detectPulse(state *settings, struct heartParams *params) {
	Serial.print(analogRead(ANALOGPORT));
	Serial.print("\n");
	delay(1);
	if (analogRead(ANALOGPORT) > 100 && settings->way == 0) {
		settings->way = 1;
		beat(params);
		params->order++;
		settings->pulses++;
	} else if (analogRead(ANALOGPORT) < 100 && settings->way == 1) {
		settings->way = 0;
	}

	if (settings->pulses > 1) {
		params->bpm = (settings->pulses * 60)
				/ ((millis() - settings->ms) / 1000);
		if (settings->pulses > 10) {
			return (settings->pulses * 60) / ((millis() - settings->ms) / 1000);
		}
	}
	return detectPulse(settings, params);
}

int initPulse() {
	struct heartParams params;
	params.order = 0;
	params.bpm = 120;
	state settings = { 0, millis(), analogRead(ANALOGPORT), 0, &params, 0 };
	return detectPulse(&settings, &params);
}
