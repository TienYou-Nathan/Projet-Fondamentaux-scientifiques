/*
 * fileUtils.h
 *
 *  Created on: 13 nov. 2018
 *      Author: legon
 */

#ifndef PARAMSUTILS_H_
#define PARAMSUTILS_H_

typedef struct choose {
	char *description;
	struct choose *next;
} choices;

FILE* getFile(char* file);
int createMenu(choices *modes);
int createStruct(choices *stru, choices *next, char description[]);


#endif /* PARAMSUTILS_H_ */
