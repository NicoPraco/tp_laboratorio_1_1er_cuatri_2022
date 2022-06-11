/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#define BUFFER_LEN 100

#define NAME_LEN 51
#define SURNAME_LEN 51
#define FLIGHT_CODE_LEN 21
#define PASSENGER_TYPE_LEN 31
#define FLIGHT_STATUS_LEN 21

typedef struct
{
	int id;
	char nombre[NAME_LEN];
	char apellido[SURNAME_LEN];
	float precio;
	char tipoPasajero[PASSENGER_TYPE_LEN];
	char codigoVuelo[FLIGHT_CODE_LEN];
	char estadoVuelo[FLIGHT_STATUS_LEN];

} Passenger;

// =======================================================================================================================================================

Passenger* Passenger_new();
Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, char* tipoPasajero, char* codigoVuelo, char* estadoVuelo);
Passenger* Passenger_newParametrosAsText(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr);
int Passenger_delete(Passenger* this);

// =======================================================================================================================================================

//Geters y Seters de ID
int Passenger_setId(Passenger* this, int id);
int Passenger_getId(Passenger* this, int* id);

int Passenger_setIdTxt(Passenger* this, char* idStr);
int Passenger_getIdTxt(Passenger* this, char* idStr);

//Geters y Seters de Nombre
int Passenger_setNombre(Passenger* this, char* nombre);
int Passenger_getNombre(Passenger* this, char* nombre);

//Geters y Seters de Apellido
int Passenger_setApellido(Passenger* this, char* apellido);
int Passenger_getApellido(Passenger* this, char* apellido);

//Geters y Seters de Precio
int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this, float* precio);

int Passenger_setPrecioTxt(Passenger* this, char* precioStr);
int Passenger_getPrecioTxt(Passenger* this, char* precioStr);

//Geters y Seters de Tipo de Pasajero
int Passenger_setTipoPasajero(Passenger* this, char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this, char* tipoPasajero);

//Geters y Seters de Codigo de Vuelo
int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);

//Geters y Seters de Estado de Vuelo
int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo);

// =======================================================================================================================================================

int findPassengerByID(LinkedList* pArrayListPassenger, int ID, int* index);

int Passenger_compareById(void* pElement1, void* pElement2);
int Passenger_compareByName(void* pElement1, void* pElement2);
int Passenger_compareBySurname(void* pElement1, void* pElement2);
int Passenger_compareByPrice(void* pElement1, void* pElement2);
int Passenger_compareByPassengerType(void* pElement1, void* pElement2);
int Passenger_compareByFlightCode(void* pElement1, void* pElement2);
int Passenger_compareByFlightStatus(void* pElement1, void* pElement2);

// =======================================================================================================================================================

int Passenger_showModMenu(LinkedList* pArrayListPassenger, Passenger* this);
int Passenger_showSortMenu(LinkedList* pArrayListPassenger);

// =======================================================================================================================================================

int Passenger_add(LinkedList* pArrayListPassenger, int* ID);
int Passenger_edit(LinkedList* pArrayListPassenger);
int Passenger_remove(LinkedList* pArrayListPassenger);
int Passenger_sort(LinkedList* pArrayListPassenger);
int Passenger_clear(LinkedList* pArrayListPassenger);
int Passenger_print(Passenger* this);
int Passenger_list(LinkedList* pArrayListPassenger);

// =======================================================================================================================================================

// =======================================================================================================================================================

#endif /* PASSENGER_H_ */
