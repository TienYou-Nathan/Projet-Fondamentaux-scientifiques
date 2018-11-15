/*
 * createMenu.c
 *
 *  Created on: 14 nov. 2018
 *      Author: legon
 */

#include <stdio.h>
#include <stdlib.h>

#include "paramsUtils.h"

int createMenu(choices *modes) {
	choices copy = *modes;
	int choice = 0;

	int i = 0;
	while (copy.next != NULL) {
		printf("%s\n", copy.description);
		copy = *copy.next;
		i++;
		printf("%i %s ", i, "-");
	}
	printf("%s\n", copy.description);

	do {
		printf("Enter a number: \n");
		fflush(stdout);
		char st[1024];
		fgets(st, sizeof(st), stdin);
		fflush(stdout);
		sscanf(st, "%d", &choice);
		if (!(choice > 0 && choice < i + 1))
			printf("You didn't type a number between 1 and %i!\n", i);
	} while (!(choice > 0 && choice < i + 1));
	choices temp = *modes;
	for (int i = 0; i < choice; i++) {
		temp = *temp.next;
	}
	printf("You choose %s\n", temp.description);

	return choice;
}
