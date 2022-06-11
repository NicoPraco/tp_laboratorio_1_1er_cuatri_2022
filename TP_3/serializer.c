/*
 * serializer.c
 *
 *  Created on: 30 may. 2022
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>

#include "serializer.h"
#include "Passenger.h"

int serializer_PassengerToText(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int toReturn = -1;

	int i;
	int cant;

	/*
	 * int auxID;
	char auxNombre[NAME_LEN];
	char auxApellido[SURNAME_LEN];
	float auxPrecio;
	char auxTipoPasajero[PASSENGER_TYPE_LEN];
	char auxCodigoVuelo[FLIGHT_CODE_LEN];
	char auxEstadoVuelo[FLIGHT_STATUS_LEN];
	 */

	char auxID[BUFFER_LEN];
	char auxNombre[NAME_LEN];
	char auxApellido[SURNAME_LEN];
	char auxPrecio[BUFFER_LEN];
	char auxTipoPasajero[BUFFER_LEN];
	char auxCodigoVuelo[FLIGHT_CODE_LEN];
	char auxEstadoVuelo[FLIGHT_STATUS_LEN];

	Passenger* this;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		cant = ll_len(pArrayListPassenger);

		fprintf(pFile, "id,name,lastName,flyCode,typePassenger,flightStatus\n");

		for(i = 0; i < cant; i++)
		{
			this = (Passenger*) ll_get(pArrayListPassenger, i);

			if(this != NULL && !Passenger_getIdTxt(this, auxID) 	&& !Passenger_getNombre(this, auxNombre) 			&&
			  !Passenger_getApellido(this, auxApellido) 			&& !Passenger_getPrecioTxt(this, auxPrecio) 		&&
			  !Passenger_getTipoPasajero(this, auxTipoPasajero) 	&& !Passenger_getCodigoVuelo(this, auxCodigoVuelo) && !Passenger_getEstadoVuelo(this, auxEstadoVuelo))
			{
				fprintf(pFile, "%s,%s,%s,%s,%s,%s,%s\n", auxID, auxNombre, auxApellido, auxPrecio, auxTipoPasajero, auxCodigoVuelo, auxEstadoVuelo);
			}
			else
			{
				break;
			}
		}
		if(i == cant)
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int serializer_PassengerToBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int toReturn = -1;

	int i;
	int cant;

	Passenger* this;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		cant = ll_len(pArrayListPassenger);

		if(cant > 0)
		{
			for(i = 0; i < cant; i++)
			{
				this = (Passenger*) ll_get(pArrayListPassenger, i);

				if(this == NULL || fwrite(this, sizeof(Passenger), 1, pFile) != 1)
				{
					break;
				}
			}

			if(i == cant)
			{
				toReturn = 0;
			}
		}
	}

	return toReturn;
}
