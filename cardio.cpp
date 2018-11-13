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

int detectPulse(float pulses, float ms, float base,
		struct heartParams *settings) {
	delay(50);
	if (base - analogRead(ANALOGPORT) > 100) {
		beat(settings);
		settings->order++;
		pulses++;
	}

	if (pulses > 1) {
		settings->bpm = (pulses * 60) / ((millis() - ms) / 1000);
		if (pulses > 9) {
			return (pulses * 60) / ((millis() - ms) / 1000);
		}
	}
	return detectPulse(pulses, ms, analogRead(ANALOGPORT), settings);
}

int initPulse() {
	struct heartParams settings;
	settings.order = 0;
	settings.light = 4;
	settings.bpm = 120;
	settings.led = 0;
	return detectPulse(0, millis(), analogRead(ANALOGPORT), &settings);
}
