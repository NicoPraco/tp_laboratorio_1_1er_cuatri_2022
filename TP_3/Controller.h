/*
 * Controller.h
 *
 *  Created on: 23 may. 2022
 *      Author: Nicolas
 */


#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, int* id);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger, int* id);

int controller_addPassenger(LinkedList* pArrayListPassenger, int* id);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_listPassenger(LinkedList* pArrayListPassenger);

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

#endif /* CONTROLLER_H_ */
