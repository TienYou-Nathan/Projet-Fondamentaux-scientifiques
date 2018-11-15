#include <Arduino.h>
#include <string.h>
#include "cardio.h"
#include "heart.h"

void setup() {
	for (int i = 2; i < 12; i++) {
		pinMode(i, OUTPUT);
	}
	pinMode(A0, INPUT);
	Serial.begin(9600);
	struct heartParams settings;
	settings.order = 0;
	settings.bpm = 120;

}

void loop() {
	//Serial.print(initPulse());
	Serial.print(String(String(millis()) + ";" + String(initPulse()) + "\n"));
	//Serial.print(analogRead(0));
	//Serial.print("\n");
	delay(1);
}
