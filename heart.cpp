/*
 * coeur.c
 *
 *  Created on: 13 nov. 2018
 *      Author: legon
 */
#include <Arduino.h>
#include "heart.h"

void boucle(struct heartParams *settings) {
	for (int i = 2; i <= 11; i = i + settings->light) {
		digitalWrite(i, HIGH);
	}
	delay(50);
	for (int i = 2; i <= 11; i = i + settings->light) {
		digitalWrite(i, LOW);
	}

}

void beat(struct heartParams *settings) {
	if (settings->light == 4) {
		digitalWrite((settings->order % 10) + 2, HIGH);
		delay(50);
		digitalWrite((settings->order % 10) + 2, LOW);

	} else if (settings->light == 5) {
		digitalWrite((settings->led % 10) + 2, HIGH);
		delay(50);
		digitalWrite((settings->led % 10) + 2, LOW);

	} else {
		boucle(settings);
	}
}
