/*
 * get.c
 *
 *  Created on: 13 nov. 2018
 *      Author: legon
 */
#include <stdio.h>
#include <stdlib.h>

FILE* getFile(char* file) {
	FILE *f = fopen(file, "w");
	if (f == NULL) {
		printf("Error opening file!\n");
		exit(1);
	}
	return f;
}

