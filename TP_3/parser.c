#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "parser.h"
#include "Passenger.h"

/*
 *
 * typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int isEmpty;

} Passenger;
 */

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger, int* id)
{
	int toReturn = -1;

	int auxID;

	char idStr[BUFFER_LEN];
	char auxNombre[BUFFER_LEN];
	char auxApellido[BUFFER_LEN];
	char auxPrecio[BUFFER_LEN];
	char auxTipoPasajero[BUFFER_LEN];
	char auxCodigoVuelo[BUFFER_LEN];
	char auxEstadoVuelo[BUFFER_LEN];

	Passenger* this;

	if(pFile != NULL && pArrayListPassenger != NULL && id != NULL)
	{
		while(!feof(pFile))
		{
			if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", idStr, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo) == 7)
			{
				this = Passenger_newParametrosAsText(idStr, auxNombre, auxApellido, auxPrecio, auxTipoPasajero, auxCodigoVuelo, auxEstadoVuelo);

				if(this != NULL)
				{
					auxID = atoi(idStr);

					if(auxID > *id)
					{
						*id = auxID;
					}

					ll_add(pArrayListPassenger, this);
				}
			}
		}

		toReturn = 0;
	}


    return toReturn;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger, int* id)
{
	int toReturn = -1;

	int auxID;

	Passenger* this;

	if(pFile != NULL && pArrayListPassenger != NULL && id != NULL)
	{
		while(!feof(pFile))
		{
			this = Passenger_new();

			if(this != NULL && fread(this, sizeof(Passenger), 1, pFile) == 1)
			{
				if(!Passenger_getId(this, &auxID) && auxID > *id)
				{
					*id = auxID;
				}

				ll_add(pArrayListPassenger, this);
			}
		}

		toReturn = 0;
	}

    return toReturn;
}
