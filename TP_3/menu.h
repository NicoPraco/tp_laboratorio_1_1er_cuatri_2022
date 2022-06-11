/*
 * menu.h
 *
 *  Created on: 24 may. 2022
 *      Author: Nicolas
 */

#ifndef MENU_H_
#define MENU_H_

#include "LinkedList.h"

// ======================================================================================

int optionsMenu(int* input);

int modMenu(int* input);

int sortMenu(int * input);

int sortOrderMenu(int* input);

// ======================================================================================

int Passenger_choosePassengerType(char* passengerType);

int Passenger_choosePassengerFlightStatus(char* flightStatus);

#endif /* MENU_H_ */
