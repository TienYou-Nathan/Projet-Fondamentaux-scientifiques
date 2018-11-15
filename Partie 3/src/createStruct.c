/*
 * createStruct.c
 *
 *  Created on: 14 nov. 2018
 *      Author: legon
 */

#include <stdio.h>
#include <stdlib.h>

#include "paramsUtils.h"

int createStruct(choices *stru, choices *next, char description[]) {
	stru->description = description;
	stru->next = next;
	return 0;
}
