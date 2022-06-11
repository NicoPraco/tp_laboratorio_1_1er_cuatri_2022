/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Controller.h"
#include "Passenger.h"
#include "menu.h"
#include "input.h"

//#include <conio.h>

Passenger* Passenger_new()
{
	Passenger* this;

	this = (Passenger*) malloc(sizeof(Passenger));

	return this;
}

Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, char* tipoPasajero, char* codigoVuelo, char* estadoVuelo)
{
	Passenger* this = NULL;

	if(nombre != NULL && apellido != NULL && tipoPasajero != NULL && codigoVuelo != NULL && estadoVuelo != NULL)
	{
		this = Passenger_new();

		if(this != NULL)
		{
			if(Passenger_setId(this, id) || Passenger_setNombre(this, nombre) || Passenger_setApellido(this, apellido) || Passenger_setPrecio(this, precio) ||
			   Passenger_setTipoPasajero(this, tipoPasajero) || Passenger_setCodigoVuelo(this, codigoVuelo) || Passenger_setEstadoVuelo(this, estadoVuelo))
			{
				Passenger_delete(this);

				this = NULL;
			}
		}
	}

	return this;
}

Passenger* Passenger_newParametrosAsText(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr)
{
	Passenger* this = NULL;

	if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL && estadoVueloStr != NULL)
	{
		this = Passenger_new();

		if(this != NULL)
		{
			if(Passenger_setIdTxt(this, idStr) || Passenger_setNombre(this, nombreStr) || Passenger_setApellido(this, apellidoStr) || Passenger_setPrecioTxt(this, precioStr) ||
			   Passenger_setTipoPasajero(this, tipoPasajeroStr) || Passenger_setCodigoVuelo(this, codigoVueloStr) || Passenger_setEstadoVuelo(this, estadoVueloStr))
			{
				Passenger_delete(this);
				this = NULL;
			}
		}
	}

	return this;
}

int Passenger_delete(Passenger* this)
{
	int toReturn = -1;

	if(this != NULL)
	{
		free(this);

		toReturn = 0;
	}

	return toReturn;
}

// =======================================================================================================================================================

//Geters y Seters de ID
int Passenger_setId(Passenger* this, int id)
{
	int toReturn = -1;

	if(this != NULL && !isnan(id))
	{
		if(id > 0)
		{
			this->id = id;

			toReturn = 0;
		}
	}

	return toReturn;
}

int Passenger_getId(Passenger* this, int* id)
{
	int toReturn = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;

		toReturn = 0;
	}

	return toReturn;
}

int Passenger_setIdTxt(Passenger* this, char* idStr)
{
	int toReturn = -1;

	int auxID;

	if(this != NULL && idStr != NULL && isNumInt(idStr, BUFFER_LEN) == 1)
	{
		auxID = atoi(idStr);

		if(auxID > 0)
		{
			this->id = auxID;

			toReturn = 0;
		}
	}

	return toReturn;
}

int Passenger_getIdTxt(Passenger* this, char* idStr)
{
	int toReturn = -1;

	if(this != NULL && idStr != NULL)
	{
		snprintf(idStr, BUFFER_LEN, "%d", this->id);

		toReturn = 0;
	}

	return toReturn;
}

//Geters y Seters de Nombre
int Passenger_setNombre(Passenger* this, char* nombre)
{
	int toReturn = -1;

	if(this != NULL && nombre != NULL && isStringAlphabetical(nombre, NAME_LEN))
	{
		strncpy(this->nombre, nombre, NAME_LEN);

		toReturn = 0;
	}

	return toReturn;
}

int Passenger_getNombre(Passenger* this, char* nombre)
{
	int toReturn = -1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, NAME_LEN);

		toReturn = 0;
	}

	return toReturn;
}

//Geters y Seters de Apellido
int Passenger_setApellido(Passenger* this, char* apellido)
{
	int toReturn = -1;

	if(this != NULL && apellido != NULL && isStringAlphabetical(apellido, SURNAME_LEN))
	{
		strncpy(this->apellido, apellido, SURNAME_LEN);

		toReturn = 0;
	}

	return toReturn;
}
int Passenger_getApellido(Passenger* this, char* apellido)
{
	int toReturn = -1;

	if(this != NULL && apellido != NULL)
	{
		strncpy(apellido, this->apellido, SURNAME_LEN);

		toReturn = 0;
	}

	return toReturn;
}

//Geters y Seters de Precio
int Passenger_setPrecio(Passenger* this, float precio)
{
	int toReturn = -1;

	if(this != NULL && !isnan(precio) && precio > 0)
	{
		this->precio = precio;

		toReturn = 0;
	}

	return toReturn;
}
int Passenger_getPrecio(Passenger* this, float* precio)
{
	int toReturn = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;

		toReturn = 0;
	}

	return toReturn;
}

int Passenger_setPrecioTxt(Passenger* this, char* precioStr)
{
	int toReturn = -1;

	int auxPrecio;

	if(this != NULL && precioStr != NULL && isNumFloat(precioStr, BUFFER_LEN) == 1)
	{
		auxPrecio = atof(precioStr);

		if(auxPrecio > 0)
		{
			this->precio = auxPrecio;

			toReturn = 0;
		}
	}

	return toReturn;
}
int Passenger_getPrecioTxt(Passenger* this, char* precioStr)
{
	int toReturn = -1;

	if(this != NULL && precioStr != NULL)
	{
		snprintf(precioStr, BUFFER_LEN, "%.2f", this->precio);

		toReturn = 0;
	}

	return toReturn;
}

//Geters y Seters de Tipo de Pasajero
int Passenger_setTipoPasajero(Passenger* this, char* TipoPasajero)
{
	int toReturn = -1;

	if(this != NULL && TipoPasajero != NULL)
	{
		strncpy(this->tipoPasajero, TipoPasajero, PASSENGER_TYPE_LEN);

		toReturn = 0;
	}

	return toReturn;
}
int Passenger_getTipoPasajero(Passenger* this, char* TipoPasajero)
{
	int toReturn = -1;

	if(this != NULL && TipoPasajero != NULL)
	{
		strncpy(TipoPasajero, this->tipoPasajero, PASSENGER_TYPE_LEN);

		toReturn = 0;
	}

	return toReturn;
}

//Geters y Seters de Codigo de Vuelo
int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int toReturn = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(this->codigoVuelo, codigoVuelo, FLIGHT_CODE_LEN);

		toReturn = 0;
	}

	return toReturn;
}

int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int toReturn = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(codigoVuelo, this->codigoVuelo, FLIGHT_CODE_LEN);

		toReturn = 0;
	}

	return toReturn;
}

//Geters y Seters de Estado de Vuelo
int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	int toReturn = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strncpy(this->estadoVuelo, estadoVuelo, FLIGHT_STATUS_LEN);

		toReturn = 0;
	}

	return toReturn;
}

int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	int toReturn = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strncpy(estadoVuelo, this->estadoVuelo, FLIGHT_STATUS_LEN);

		toReturn = 0;
	}

	return toReturn;
}

// =======================================================================================================================================================

int findPassengerByID(LinkedList* pArrayListPassenger, int ID, int* index)
{
	int toReturn = -1;

	int i;
	int len;
	int auxID;

	Passenger* this;

	if(pArrayListPassenger != NULL && index != NULL)
	{
		len = ll_len(pArrayListPassenger);

		if(len > 0)
		{
			for(i = 0; i < len; i++)
			{
				this = (Passenger*) ll_get(pArrayListPassenger, i);

				if(this != NULL && !Passenger_getId(this, &auxID))
				{
					if(auxID == ID)
					{
						*index = i;

						toReturn = 0;
						break;
					}
				}
			}
		}
	}

	return toReturn;
}

int Passenger_compareById(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	int auxId1;
	int auxId2;

	Passenger* pPassenger1;
	Passenger* pPassenger2;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pPassenger1 = (Passenger*) pElement1;
		pPassenger2 = (Passenger*) pElement2;

		if(!Passenger_getId(pPassenger1, &auxId1) && !Passenger_getId(pPassenger2, &auxId2))
		{
			if(auxId1 > auxId2)
			{
				// El Primer ID es MAYOR al Segundo ID.
				toReturn = 1;
			}
			else if(auxId1 == auxId2)
			{
				// Los IDs son iguales.
				toReturn = 0;
			}
			else
			{
				// El Primer ID es menor al Segundo ID.
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

int Passenger_compareByName(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	char auxName1[NAME_LEN];
	char auxName2[NAME_LEN];

	int auxCmp;

	Passenger* pPassenger1;
	Passenger* pPassenger2;

	if(pElement1 != NULL && pElement2)
	{
		pPassenger1 = (Passenger*) pElement1;
		pPassenger2 = (Passenger*) pElement2;

		if(!Passenger_getNombre(pPassenger1, auxName1) && !Passenger_getNombre(pPassenger2, auxName2))
		{
			auxCmp = strncmp(auxName1, auxName2, NAME_LEN);

			if(auxCmp > 0)
			{
				// El Primer Nombre es MAYOR al Segundo Nombre.
				toReturn = 1;
			}
			else if(auxCmp == 0)
			{
				// Los nombres son iguales.
				toReturn = 0;
			}
			else
			{
				// El Primer Nombre es MENOR al Segundo Nombre.
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

int Passenger_compareBySurname(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	char auxSurname1[SURNAME_LEN];
	char auxSurname2[SURNAME_LEN];

	int auxCmp;

	Passenger* pPassenger1;
	Passenger* pPassenger2;

	if(pElement1 != NULL && pElement2)
	{
		pPassenger1 = (Passenger*) pElement1;
		pPassenger2 = (Passenger*) pElement2;

		if(!Passenger_getApellido(pPassenger1, auxSurname1) && !Passenger_getApellido(pPassenger2, auxSurname2))
		{
			auxCmp = strncmp(auxSurname1, auxSurname2, SURNAME_LEN);

			if(auxCmp > 0)
			{
				// El Primer Apellido es MAYOR al Segundo Apellido.
				toReturn = 1;
			}
			else if(auxCmp == 0)
			{
				// Los Apellidos son iguales.
				toReturn = 0;
			}
			else
			{
				// El Primer Apellido es MENOR al Segundo Apellido.
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

int Passenger_compareByPrice(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	float auxPrice1;
	float auxPrice2;

	Passenger* pPassenger1;
	Passenger* pPassenger2;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pPassenger1 = (Passenger*) pElement1;
		pPassenger2 = (Passenger*) pElement2;

		if(!Passenger_getPrecio(pPassenger1, &auxPrice1) && !Passenger_getPrecio(pPassenger2, &auxPrice2))
		{
			if(auxPrice1 > auxPrice2)
			{
				// El Primer Precio es Mayor que el Segundo Precio.
				toReturn = -1;
			}
			else if(auxPrice1 == auxPrice2)
			{
				// Los Precios son iguales.
				toReturn = 0;
			}
			else
			{
				// El Primer Precio es Menor que el Segundo Precio.
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

int Passenger_compareByPassengerType(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	char auxPassengerType1[PASSENGER_TYPE_LEN];
	char auxPassengerType2[PASSENGER_TYPE_LEN];

	int auxCmp;

	Passenger* pPassenger1;
	Passenger* pPassenger2;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pPassenger1 = (Passenger*) pElement1;
		pPassenger2 = (Passenger*) pElement2;

		if(!Passenger_getTipoPasajero(pPassenger1, auxPassengerType1) && !Passenger_getTipoPasajero(pPassenger2, auxPassengerType2))
		{
			auxCmp = strncmp(auxPassengerType1, auxPassengerType2, PASSENGER_TYPE_LEN);

			if(auxCmp > 0)
			{
				// El tipo de pasajero 1 es MAYOR al tipo de pasajero 2.
				toReturn = 1;
			}
			else if(auxCmp == 0)
			{
				// Los tipos de pasajeros son iguales.
				toReturn = 0;
			}
			else
			{
				// El tipo de pasajero 1 es MENOR al tipo de pasajero 2.
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

int Passenger_compareByFlightCode(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	char auxFlightCode1[FLIGHT_CODE_LEN];
	char auxFlightCode2[FLIGHT_CODE_LEN];

	int auxCmp;

	Passenger* pPassenger1;
	Passenger* pPassenger2;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pPassenger1 = (Passenger*) pElement1;
		pPassenger2 = (Passenger*) pElement2;

		if(!Passenger_getCodigoVuelo(pPassenger1, auxFlightCode1) && !Passenger_getCodigoVuelo(pPassenger2, auxFlightCode2))
		{
			auxCmp = strncmp(auxFlightCode1, auxFlightCode2, FLIGHT_CODE_LEN);

			if(auxCmp > 0)
			{
				// El primer codigo de vuelo es MAYOR al Segundo.
				toReturn = 1;
			}
			else if(auxCmp == 0)
			{
				// Los codigos de vuelo son iguales.
				toReturn = 0;
			}
			else
			{
				// El primer codigo de vuelo es MENOR al segundo.
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

int Passenger_compareByFlightStatus(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	char auxFlightStatus1[FLIGHT_STATUS_LEN];
	char auxFlightStatus2[FLIGHT_STATUS_LEN];

	int auxCmp;

	Passenger* pPassenger1;
	Passenger* pPassenger2;

	if(pElement1 != NULL && pElement2)
	{
		pPassenger1 = (Passenger*) pElement1;
		pPassenger2 = (Passenger*) pElement2;

		if(!Passenger_getEstadoVuelo(pPassenger1, auxFlightStatus1) && !Passenger_getEstadoVuelo(pPassenger2, auxFlightStatus2))
		{
			auxCmp = strncmp(auxFlightStatus1, auxFlightStatus2, FLIGHT_STATUS_LEN);

			if(auxCmp > 0)
			{
				// El estado de vuelo 1 es MAYOR al segundo.
				toReturn = 1;
			}
			else if(auxCmp == 0)
			{
				// Los estados de vuelo son iguales.
				toReturn = 0;
			}
			else
			{
				// El estado de vuelo 1 es MENOR al segundo.
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

// =======================================================================================================================================================

int Passenger_showModMenu(LinkedList* pArrayListPassenger, Passenger* this)
{
	int toReturn = -1;

	char auxNombre[NAME_LEN];
	char auxApellido[SURNAME_LEN];
	float auxPrecio;
	char auxTipoPasajero[PASSENGER_TYPE_LEN];
	char auxCodigoVuelo[FLIGHT_CODE_LEN];
	char auxEstadoVuelo[FLIGHT_STATUS_LEN];

	int option;

	int flag = 0;

	if(pArrayListPassenger != NULL && this != NULL)
	{
		do
		{
			if(!modMenu(&option))
			{
				switch (option)
				{
					case 1:
						// MODIFICAR NOMBRE
						if(!getString(auxNombre, "\nIngrese el nuevo nombre: ", "Error, vuelva a intentarlo: ", 3, NAME_LEN)
							&&
						   !Passenger_setNombre(this, auxNombre))
						{
							flag = 1;
						}
						break;

					case 2:
						// MODIFICAR APELLIDO
						if(!getString(auxApellido, "\nIngrese el nuevo apellido: ", "Error, vuelva a intentarlo: ", 3, SURNAME_LEN)
							&&
						   !Passenger_setApellido(this, auxApellido))
						{
							flag = 1;
						}
						break;

					case 3:
						// MODIFICAR PRECIO
						if(!getFloat(&auxPrecio, "\nIngrese el nuevo precio: ", "Error, vuelva a intentarlo: ", 1000, 1000000)
							&&
						   !Passenger_setPrecio(this, auxPrecio))

						{
							flag = 1;
						}
						break;

					case 4:
						// MODIFICAR TIPO PASAJERO
						if(!Passenger_choosePassengerType(auxTipoPasajero)
							&&
						   !Passenger_setTipoPasajero(this, auxTipoPasajero))
						{
							flag = 1;
						}
						break;

					case 5:
						// MODIFICAR CODIGO DE VUELO
						if(!getString(auxCodigoVuelo, "\nIngrese el nuevo codigo de vuelo: ", "Error, vuelva a intentarlo: ", 1, FLIGHT_CODE_LEN)
							&&
						   !Passenger_setCodigoVuelo(this, auxCodigoVuelo))
						{
							flag = 1;
						}
						break;

					case 6:
						// MODIFICAR ESTADO DE VUELO
						if(!Passenger_choosePassengerFlightStatus(auxEstadoVuelo)
							&&
						   !Passenger_setEstadoVuelo(this, auxEstadoVuelo))
						{
							flag = 1;
						}
						break;

					case 7:
						printf("\nSaliendo del menu de modificaciones...\n");
						break;

					default:
						printf("\nError, ha ingresado un valor invalido.\n");
						break;
				}
			}
			else
			{
				printf("\nError al mostrar el menu de modificaciones.\n");
			}

		}while(option != 7);

		if(flag == 1)
		{
			//SE REALIZO UNA MODIFICACION CON EXITO
			toReturn = 0;
		}
	}

	return toReturn;
}

int Passenger_showSortMenu(LinkedList* pArrayListPassenger)
{
	int toReturn = -1;

	int option;
	int orderOption;

	int order;

	int (*pFunc)(void*, void*);

	if(pArrayListPassenger != NULL)
	{
		do
		{
			if(!sortMenu(&option))
			{
				switch(option)
				{
					case 1:
						// COMPARAR POR ID
						pFunc = Passenger_compareById;
						break;

					case 2:
						// COMPARAR POR NOMBRE
						pFunc = Passenger_compareByName;
						break;

					case 3:
						// COMPARAR POR APELLIDO
						pFunc = Passenger_compareBySurname;
						break;

					case 4:
						// COMPARAR POR PRECIO
						pFunc = Passenger_compareByPrice;
						break;

					case 5:
						// COMPARAR POR TIPO PASAJERO
						pFunc = Passenger_compareByPassengerType;
						break;

					case 6:
						// COMPARAR POR CODIGO DE VUELO
						pFunc = Passenger_compareByFlightCode;
						break;

					case 7:
						// COMPARAR POR ESTADO DE VUELO
						pFunc = Passenger_compareByFlightStatus;
						break;

					default:
						printf("\nError, ha ingresado un valor invalido.\n");
						break;

				}
			}

		}while(option < 1 || option > 7);

		do
		{
			if(!sortOrderMenu(&orderOption))
			{
				switch(orderOption)
				{
					case 1:
						order = 1;
						break;

					case 2:
						order = 0;
						break;

					default:
						printf("\nError, ha ingresado un valor invalido.\n");
						break;
				}
			}

		}while(orderOption != 1 && orderOption != 2);

		ll_sort(pArrayListPassenger, pFunc, order);

		toReturn = 0;
	}

	return toReturn;
}

// =======================================================================================================================================================

int Passenger_add(LinkedList* pArrayListPassenger, int* ID)
{
	int toReturn = -1;

	char auxNombre[NAME_LEN];
	char auxApellido[SURNAME_LEN];
	float auxPrecio;
	char auxTipoPasajero[PASSENGER_TYPE_LEN];
	char auxCodigoVuelo[FLIGHT_CODE_LEN];
	char auxEstadoVuelo[FLIGHT_STATUS_LEN];

	Passenger* this;

	if(pArrayListPassenger != NULL && ID != NULL)
	{
		printf("\n");

		if(!getString(auxNombre, "Ingrese el nombre del pasajero: ", "Error, vuelva a intentarlo: ", 3, NAME_LEN) 			&&
		   !getString(auxApellido, "Ingrese el apellido del pasajero: ", "Error, vuelva a intentarlo: ", 3, SURNAME_LEN) 	&&
		   !getFloat(&auxPrecio, "Ingrese el precio del pasaje: ", "Error, vuelva a intentarlo: ", 1000, 1000000) 			&&
		   !Passenger_choosePassengerType(auxTipoPasajero) 																	&&
		   !getString(auxCodigoVuelo, "Ingrese el codigo de vuelo: ", "Error, vuelva a intenarlo: ", 1, FLIGHT_CODE_LEN) 	&&
		   !Passenger_choosePassengerFlightStatus(auxEstadoVuelo))
		{
			this = Passenger_newParametros(*ID + 1, auxNombre, auxApellido, auxPrecio, auxTipoPasajero, auxCodigoVuelo, auxEstadoVuelo);

			if(this != NULL)
			{
				(*ID)++;

				ll_add(pArrayListPassenger, this);

				toReturn = 0;
			}
		}
	}

	return toReturn;
}

int Passenger_edit(LinkedList* pArrayListPassenger)
{
	int toReturn = -1;

	int auxID;
	int answer;
	int index;

	Passenger* this;

	if(pArrayListPassenger != NULL)
	{
		if(!controller_listPassenger(pArrayListPassenger))
		{
			if(!getInt(&auxID, "\nIngrese la ID del empleado a modificar entre 1 y 2000: ", "Error, vuelva a intentarlo: ", 1, 2000))
			{
				if(!findPassengerByID(pArrayListPassenger, auxID, &index))
				{
					this = (Passenger*) ll_get(pArrayListPassenger, index);

					if(this != NULL)
					{
						printf("%s %12s %14s %11s %18s %16s %16s\n\n","ID", "Nombre", "Apellido", "Precio", "Tipo de Pasajero", "Codigo de Vuelo", "Estado de Vuelo");
						Passenger_print(this);

						printf("\n\n 0 = NO.\n");
						printf(" 1 = SI.\n");

						if(!getInt(&answer, "\nEsta seguro de modificar al pasajero?: ", "Error, solo 0 o 1: ", 0, 1))
						{
							if(!Passenger_showModMenu(pArrayListPassenger, this))
							{
								toReturn = 0;
							}
						}
					}
				}
			}
		}
	}

	return toReturn;
}

int Passenger_remove(LinkedList* pArrayListPassenger)
{
	int toReturn = -1;

	int answer;
	int index;
	int auxId;

	Passenger* this;

	if(pArrayListPassenger != NULL)
	{
		if(!controller_listPassenger(pArrayListPassenger))
		{
			if(!getInt(&auxId, "\nIngrese la ID del pasajero a eliminar: ", "Error, solo numeros del 1 al 2000. Vuelva a intentarlo: ", 1, 2000))
			{
				if(!findPassengerByID(pArrayListPassenger, auxId, &index))
				{
					this = (Passenger*) ll_get(pArrayListPassenger, index);

					if(this != NULL)
					{
						printf("%s %12s %14s %11s %18s %16s %16s\n\n","ID", "Nombre", "Apellido", "Precio", "Tipo de Pasajero", "Codigo de Vuelo", "Estado de Vuelo");
						Passenger_print(this);

						printf("\n0 = NO.\n");
						printf("1 = SI.\n\n");

						if(!getInt(&answer, "\nEsta seguro de eliminar a este pasajero?: ", "Error, solo 0 o 1. Vuelva a intentarlo: ", 0, 1))
						{
							Passenger_delete(this);
							ll_remove(pArrayListPassenger, index);

							toReturn = 0;
						}
					}
				}
			}
		}
	}

	return toReturn;
}

int Passenger_sort(LinkedList* pArrayListPassenger)
{
	int toReturn = -1;

	//REVISAR

	return toReturn;
}
int Passenger_clear(LinkedList* pArrayListPassenger)
{
	int toReturn = -1;

	int i;
	int len;

	Passenger* this;

	if(pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);

		if(len > 0)
		{
			for(i = 0; i < len; i++)
			{
				this = (Passenger*) ll_get(pArrayListPassenger, i);

				if(this != NULL)
				{
					Passenger_delete(this);
				}
				else
				{
					break;
				}
			}

			if(i == len)
			{
				toReturn = 0;
			}
		}
	}

	return toReturn;
}

int Passenger_print(Passenger* this)
{
	int toReturn = -1;

	int auxID;
	char auxNombre[NAME_LEN];
	char auxApellido[SURNAME_LEN];
	float auxPrecio;
	char auxTipoPasajero[PASSENGER_TYPE_LEN];
	char auxCodigoVuelo[FLIGHT_CODE_LEN];
	char auxEstadoVuelo[FLIGHT_STATUS_LEN];

	if(this != NULL)
	{
		if(!Passenger_getId(this, &auxID) && !Passenger_getNombre(this, auxNombre) && !Passenger_getApellido(this, auxApellido) &&
		   !Passenger_getPrecio(this, &auxPrecio) && !Passenger_getTipoPasajero(this, auxTipoPasajero) &&
		   !Passenger_getCodigoVuelo(this, auxCodigoVuelo) && !Passenger_getEstadoVuelo(this, auxEstadoVuelo))
		{
			printf("%d %12s %14s %13.2f %16s %15s %15s \n", auxID, auxNombre, auxApellido, auxPrecio, auxTipoPasajero, auxCodigoVuelo, auxEstadoVuelo);

			toReturn = 0;
		}
	}

	return toReturn;
}

int Passenger_list(LinkedList* pArrayListPassenger)
{
	int toReturn = -1;

	int i;
	int len;

	Passenger* this;

	if(pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);

		if(len > 0)
		{
			printf("\n");
			printf("Lista de Pasajeros: \n\n");
			//"ID", "Nombre", "Apellido", "Precio", "Tipo de Pasajero", "Codigo de Vuelo", "Estado de Vuelo"
			printf("%s %12s %14s %11s %18s %16s %16s\n\n","ID", "Nombre", "Apellido", "Precio", "Tipo de Pasajero", "Codigo de Vuelo", "Estado de Vuelo");

			for(i = 0; i < len; i++)
			{
				this = (Passenger*) ll_get(pArrayListPassenger, i);

				if(Passenger_print(this))
				{
					break;
				}
			}

			if(i == len)
			{
				toReturn = 0;
			}

		}
	}

	return toReturn;
}

// =======================================================================================================================================================
