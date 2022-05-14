/*
 * menu.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Nicolas
 */

#include "menu.h"
#include "input.h"

int PassengerOptionsMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\n\tMENU DE PASAJEROS:\n\n");

		printf("1. Alta Pasajero.\n");
		printf("2. Baja Pasajero.\n");
		printf("3. Modificar Pasajero.\n");
		printf("4. Informar Pasajeros.\n");
		printf("5. Hardcodear Pasajeros.\n");
		printf("6. Salir.\n\n");

		if(!getInt(input, "Elija una opcion: ", "\nError, vuelva a intentarlo:", 1, 6))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int PassengerModMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\n\tMENU DE MODIFICACION:\n\n");

		printf("1. Modificar Nombre.\n");
		printf("2. Modificar Apellido.\n");
		printf("3. Modificar Precio.\n");
		printf("4. Modificar Codigo del Vuelo.\n");
		printf("5. Modificar Tipo de Pasajero.\n");
		printf("6. Salir.\n\n");

		if(!getInt(input, "Elija una opcion: ", "Error, vuelva a intenarlo:", 1, 6))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int PassengerSortMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\n\tMENU DE SELECCION DE ORDEN:\n\n");

		printf("1. Orden Ascendente.\n");
		printf("2. Order Descendente.\n\n");

		if(!getInt(input, "Elija una opcion: ", "Error, vuelva a intentarlo: ", 1, 2))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int PassengerPrintMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\n\tMENU DE INFORMES\n\n");

		printf("1. Mostrar Lista Ordenada de Pasajeros por Apellido y Tipo de Pasajero.\n");
		printf("2. Mostrar Promedio de precio de los Pasajes.\n");
		printf("3. Mostrar Lista Ordenada de Pasajeros por Codigo de Vuelo y estado 'ACTIVO'.\n");
		printf("4. Salir.\n\n");

		if(!getInt(input, "Elija una opcion: ", "Error, vuelva a intentarlo: ", 1, 4))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int loadPassengerClassMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\nLas clases disponibles son:");
		printf("\n\n1. Primera Clase.");
		printf("\n2. Clase Ejecutiva.");
		printf("\n3. Clase Economica.\n");

		if(!getInt(input, "\nIngrese la clase del pasajero del 1 al 3: ", "Error, vuelva a intentarlo: ", 1, 3))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int loadPassengerFlightStatusMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\nLos estados de vuelo posibles son:");
		printf("\n\n1. Activo.");
		printf("\n2. Demorado.");
		printf("\n3. Postergado.");
		printf("\n4. Cancelado.\n");

		if(!getInt(input, "\nIngrese el estado del vuelo: ", "Error, vuelva a intentarlo: ", 1, 5))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}
