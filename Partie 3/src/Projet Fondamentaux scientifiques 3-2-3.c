/*
 ============================================================================
 Name        : Projet.c
 Author      : jambon
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "paramsUtils.h"

int main(void) {

	choices init, one, two, three, four, five;
	createStruct(&init, &one, "CHOOSE A MODE");
	createStruct(&one, &two, "All LEDS at once");
	createStruct(&two, &three, "Half the LEDS");
	createStruct(&three, &four, "Third of the LEDS");
	createStruct(&four, &five, "Caterpillar mode");
	createStruct(&five, NULL, "Only one LED");

	FILE *f = getFile("params.h");

	fprintf(f, "%s",
			"/*\n * params.h\n *\n *      Author: legon\n */\n#ifndef PARAMS_H_\n#define PARAMS_H_\n\n");
	int mode = createMenu(&init);
	fprintf(f, "#define LIGHT %i\n", mode);
	//fprintf(f, "%s", "#define LIGHT %i\n");
	if (mode == 5) {
		choices init, one, two, three, four, five, six, seven, eight, nine, ten;
		createStruct(&init, &one, "CHOOSE A LED");
		createStruct(&one, &two, "1 - First LED");
		createStruct(&two, &three, "2 - Second LED");
		createStruct(&three, &four, "3 - Third LED");
		createStruct(&four, &five, "4 - Fourth LED");
		createStruct(&five, &six, "5 - Fifth LED");
		createStruct(&six, &seven, "6 - Sixth LED");
		createStruct(&seven, &eight, "7 - Seventh LED");
		createStruct(&eight, &nine, "8 - Eighth LED");
		createStruct(&nine, &ten, "9 - Ninth LED");
		createStruct(&ten, NULL, "10 - Tenth LED");
		int led = createMenu(&init);
		fprintf(f, "#define LED %i\n",
				led);
	} else {
		fprintf(f, "#define LED 1\n");
	}
	fprintf(f,
			"\n#endif /* PARAMS_H_ */");
	fclose(f);
	return EXIT_SUCCESS;
}
