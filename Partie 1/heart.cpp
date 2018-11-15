/*
 * coeur.c
 *
 *  Created on: 13 nov. 2018
 *      Author: legon
 */
#include <Arduino.h>
#include "heart.h"
#include "params.h"

void boucle(struct heartParams *settings) {
	for (int i = 2; i <= 11; i = i + LIGHT) {
		digitalWrite(i, HIGH);
	}
	delay(50);
	for (int i = 2; i <= 11; i = i + LIGHT) {
		digitalWrite(i, LOW);
	}

}

void beat(struct heartParams *settings) {
	if (LIGHT == 4) {
		digitalWrite((settings->order % 10) + 2, HIGH);
		delay(50);
		digitalWrite((settings->order % 10) + 2, LOW);

	} else if (LIGHT == 5) {
		digitalWrite((LED % 10) + 2, HIGH);
		delay(50);
		digitalWrite((LED % 10) + 2, LOW);

	} else {
		boucle(settings);
	}
}
