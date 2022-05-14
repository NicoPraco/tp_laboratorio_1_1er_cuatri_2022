/*
 * arrayPassenger.h
 *
 *  Created on: 25 abr. 2022
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "menu.h"

#define NAME_LENGHT 51
#define SURNAME_LENGTH 51
#define FLIGHT_CODE_LENGHT 10

#define FLIGHT_STATUS_LENGHT 21
#define FLIGHT_STATUS_CANT 4

#define PASSENGER_TYPE_LENGHT 21
#define PASSENGER_TYPE_CANT 3

#define TRUE 1
#define FALSE 0

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
	int id;
	char name[NAME_LENGHT];
	char lastName[SURNAME_LENGTH];
	float price;
	char flightCode[FLIGHT_CODE_LENGHT];
	int typePassanger;
	int flightStatus;

	int isEmpty;

} Passenger;

typedef struct
{
	int id;
	char descripcion[FLIGHT_STATUS_LENGHT];

} FlightStatus;

typedef struct
{
	int id;
	char descripcion[PASSENGER_TYPE_LENGHT];

} PassengerType;

/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
 *
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
*
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);

/**
 * \brief Hardcode a couple of passengers to be able to use the rest of the programme's functions.
 *
 * \param list Passenger* Pointer to array of passenger
 * \param len int Array length
 * \param id
 *
 * \return
 */
int hardcodePassenger(Passenger* list, int len, int* id);

int hardcodeFlightStatus(FlightStatus* list, int len, int* id);

int hardcodePassengerType(PassengerType* list, int len, int* id);

/** \brief Find a Passenger by Id en returns the index position in array.
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param id int
*
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len, int id);

int findStatusById(FlightStatus* list, int len, int id);

int findPassengerTypeById(PassengerType* list, int len, int id);

/**
 * \brief
 *
 * \param list Passenger* Pointer to array of passenger
 * \param len int Array length
 * \param index
 *
 * \return
 */
int searchFree(Passenger* list, int len, int* index);

/**
 * \brief
 *
 * \param list Passenger* Pointer to array of passenger
 * \param len int Array length
 *
 * \return
 */
int arrayIsEmpty(Passenger* list, int len);

// =============================================================

// CARGA DE PASAJERO

/** \brief add in a existing list of passengers the values received as parameters in the first empty position
 *
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[], float price, char flightCode[], int typePassenger, int flightStatus);

/**
 * \brief
 *
 * \param list Passenger* Pointer to array of passenger
 * \param len int Array length
 * \param id
 *
 * \return
 */
int loadPassenger(Passenger* list, int len, int* id);

// BAJA DE PASAJERO

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param id int
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, FlightStatus* status, PassengerType* type, int len, int lenStatus, int lenType, int id);

// MODIFICAR PASAJERO

/**
 * \brief
 *
 * \param list Passenger* Pointer to array of passenger
 * \param len int Array length
 * \param id
 *
 * \return
 */
int modifyMenu(Passenger* list, FlightStatus* status, PassengerType* type, int len, int lenStatus, int lenType, int id);

/**
 * \brief
 *
 * \param list Passenger* Pointer to array of passenger
 * \param len int Array length
 * \param index
 *
 * \return
 */
int modifyPassenger(Passenger* list, int len, int index);

// ORDENAR PASAJEROS

int sortMenu(Passenger* list, int len, int* order);
/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param order int [1] indicate UP - [0] indicate DOWN
*
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order);

/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param order int [1] indicate UP - [0] indicate DOWN
*
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int len, int order);

// MOSTRAR PASAJEROS

/**
 * \brief
 *
 * \param list Passenger* Pointer to array of passenger
 * \param len int Array length
 *
 * \return
 */
int printMenu(Passenger* list, FlightStatus* status, PassengerType* type, int len, int lenStatus, int lenType);

/**
 * \brief
 *
 * \param anEmployee
 *
 * \return
 */
int printOnePassenger(Passenger* aPassenger, FlightStatus* status, PassengerType* type);

/** \brief print the content of passengers array
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
*
* \return int
*
*/
int printPassenger(Passenger* list, FlightStatus* status, PassengerType* type, int len, int lenStatus, int lenType);

// ============================================================================

int calculatePrices(Passenger* list, int len);

int AveragePassagePrices(Passenger* list, int len, float* accumulator, float* average);

int accumulatorOfPassagePrices(Passenger* list, int len, float* accumulator);

int PassengerCounter(Passenger* list, int len, int* counter);

int passengerExceedsAveragePrice(Passenger* list, int len, float average, int* counter);

int printAverageOfPasseges(int passengerCounter, float priceAverage, float priceAccumulator);

#endif /* ARRAYPASSENGER_H_ */
