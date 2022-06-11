/*
 * Controller.c
 *
 *  Created on: 23 may. 2022
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "parser.h"
#include "serializer.h"
#include "Passenger.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, int* id)
{
	int toReturn = -1;

	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL && id != NULL)
	{
		pFile = fopen(path, "r");

		if(pFile != NULL)
		{
			if(!parser_PassengerFromText(pFile, pArrayListPassenger, id))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}
	}

    return toReturn;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger, int* id)
{
	int toReturn = -1;

	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL && id != NULL)
	{
		pFile = fopen(path, "rb");

		if(pFile != NULL)
		{
			if(!parser_PassengerFromBinary(pFile, pArrayListPassenger, id))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}
	}

    return toReturn;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* id)
{
	int toReturn = -1;

	if(pArrayListPassenger != NULL && id != NULL)
	{
		if(!Passenger_add(pArrayListPassenger, id))
		{
			toReturn = 0;
		}
	}

    return toReturn;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int toReturn = -1;

	if(pArrayListPassenger != NULL)
	{
		if(!Passenger_edit(pArrayListPassenger))
		{
			toReturn = 0;
		}
	}

    return toReturn;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int toReturn = -1;

	if(pArrayListPassenger != NULL)
	{
		if(!Passenger_remove(pArrayListPassenger))
		{
			toReturn = 0;
		}
	}

    return toReturn;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int toReturn = -1;

	if(pArrayListPassenger != NULL)
	{
		if(!Passenger_showSortMenu(pArrayListPassenger))
		{
			toReturn = 0;
		}
	}

    return toReturn;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_listPassenger(LinkedList* pArrayListPassenger)
{
	int toReturn = -1;

	if(pArrayListPassenger != NULL)
	{
		if(!Passenger_list(pArrayListPassenger))
		{
			toReturn = 0;
		}
	}

    return toReturn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int toReturn = -1;

	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "w");

		if(pFile != NULL)
		{
			if(!serializer_PassengerToText(pFile, pArrayListPassenger))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}
	}

    return toReturn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int toReturn = -1;

	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "wb");

		if(pFile != NULL)
		{
			if(!serializer_PassengerToBinary(pFile, pArrayListPassenger))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}
	}

    return toReturn;
}

