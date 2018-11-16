#include <Arduino.h>
#include <string.h>
#include "cardio.h"


void setup() {
	for (int i = 2; i < 12; i++) {
		pinMode(i, OUTPUT);
	}
	pinMode(A0, INPUT);
	Serial.begin(9600);

}

void loop() {

	Serial.print(String(String(millis()) + ";" + String(initPulse()) + "\n"));

	delay(1);
}
