/*
 * menu.c
 *
 *  Created on: 24 may. 2022
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "input.h"
#include "Passenger.h"


int optionsMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("Menu de Opciones Principal:\n\n");

		printf("1. Cargar los datos de los pasajeros desde el archivo 'data.csv' (modo texto).\n");
		printf("2. Cargar los datos de los pasajeros desde el archivo 'data.bin' (modo binario).\n");
		printf("3. Alta Pasajero.\n");
		printf("4. Modificar Pasajero.\n");
		printf("5. Baja Pasajero.\n");
		printf("6. Listar Pasajeros.\n");
		printf("7. Ordenar Pasajeros.\n");
		printf("8. Guardar los datos de los pasajeros en el archivo 'data.csv' (modo texto).\n");
		printf("9. Guardar los datos de los pasajeros en el archivo 'data.bin' (modo binario).\n");
		printf("10. Salir.\n");

		if(!getInt(input, "\nElija una opcion: ", "Error, solo numeros entre 1 y 10. Vuelva a intentarlo: ", 1, 10))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int modMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\nMenu de Modificacion de Pasajero:\n\n");

		printf("1. Modificar Nombre del Pasajero.\n");
		printf("2. Modificar Apellido del Pasajero.\n");
		printf("3. Modificar Precio del vuelo.\n");
		printf("4. Modificar Tipo de Pasajero.\n");
		printf("5. Modificar Codigo de Vuelo.\n");
		printf("6. Modificar Estado de Vuelo.\n");
		printf("7. Salir del Menu de Modificaciones.\n\n");

		if(!getInt(input, "Elija una opcion: ", "Error, solo numeros entre 1 y 7. Vuelva a intentarlo: ", 1, 7))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int sortMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\nMenu de Ordenamiento de Pasajero:\n\n");

		printf("1. Ordenar por ID.\n");
		printf("2. Ordenar por Nombre.\n");
		printf("3. Ordenar por Apellido.\n");
		printf("4. Ordenar por Precio.\n");
		printf("5. Ordenar por Tipo de Pasajero.\n");
		printf("6. Ordenar por Codigo de Vuelo .\n");
		printf("7. Ordenar por Estado de Vuelo.\n");

		if(!getInt(input, "Elija una opcion: ", "Error, solo numeros entre 1 y 7. Vuelva a intentarlo: ", 1, 7))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int sortOrderMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\nMenu de Orden de Ordenamiento:\n\n");

		printf("1. Orden Ascendente.\n");
		printf("2. Orden Descendente.\n");

		if(!getInt(input, "Elija una opcion: ", "Error, solo numeros entre 1 y 2. Vuelva a intentarlo: ", 1, 2))
		{
				toReturn = 0;
		}
	}

	return toReturn;
}

// ======================================================================================

int Passenger_choosePassengerType(char* passengerType)
{
	int toReturn = -1;

	int input;

	if(passengerType != NULL)
	{
		printf("\nElegir el tipo de pasajero:\n\n");

		printf("1. First Class.\n");
		printf("2. Executive Class.\n");
		printf("3. Economy Class.\n\n");

		if(!getInt(&input, "Elija una opcion: ", "Error, solo numeros del 1 al 3. Vuelva a intentarlo: ", 1, 3))
		{
			switch(input)
			{
				case 1:
					strncpy(passengerType, "Primera Clase", PASSENGER_TYPE_LEN);
					toReturn = 0;
					break;

				case 2:
					strncpy(passengerType, "Clase Ejecutiva", PASSENGER_TYPE_LEN);
					toReturn = 0;
					break;

				case 3:
					strncpy(passengerType, "Clase Economica", PASSENGER_TYPE_LEN);
					toReturn = 0;
					break;

				default:
					printf("\n\aError, ha ingresado un valor invalido.\n");
					break;
			}
		}
	}

	return toReturn;
}

int Passenger_choosePassengerFlightStatus(char* flightStatus)
{
	int toReturn = -1;

	int input;

	if(flightStatus != NULL)
	{
		printf("\nElegir el tipo de pasajero:\n\n");

		printf("1. En Horario.\n");
		printf("2. Demorado.\n");
		printf("3. Aterrizado.\n");
		printf("4. En Vuelo.\n\n");

		if(!getInt(&input, "Elija una opcion: ", "Error, solo numeros del 1 al 4. Vuelva a intentarlo: ", 1, 4))
		{
			switch(input)
			{
				case 1:
					strncpy(flightStatus, "En Horario", FLIGHT_STATUS_LEN);
					toReturn = 0;
					break;

				case 2:
					strncpy(flightStatus, "Demorado", FLIGHT_STATUS_LEN);
					toReturn = 0;
					break;

				case 3:
					strncpy(flightStatus, "Aterrizado", FLIGHT_STATUS_LEN);
					toReturn = 0;
					break;

				case 4:
					strncpy(flightStatus, "En Vuelo", FLIGHT_STATUS_LEN);
					toReturn = 0;
					break;

				default:
					printf("\n\aError, ha ingresado un valor invalido.\n");
					break;
			}
		}
	}

	return toReturn;
}




