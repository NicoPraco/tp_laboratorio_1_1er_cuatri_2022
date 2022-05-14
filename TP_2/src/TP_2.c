/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "arrayPassenger.h"
#include "menu.h"

#define MAX_PASSENGER 1000

int main(void)
{
	setbuf(stdout, NULL);

	Passenger arrayPassenger[MAX_PASSENGER];
	FlightStatus arrayStatus[FLIGHT_STATUS_CANT];
	PassengerType arrayPassengerType[PASSENGER_TYPE_CANT];

	int option;
	int auxID;

	int valueReturnRemove;
	int valueReturnMod;

	int id = 1;
	int idStatus = 1;
	int idPassengerType = 1;

	int flagHardcodeo = FALSE;

	if(!initPassengers(arrayPassenger, MAX_PASSENGER))
	{
		if(!hardcodeFlightStatus(arrayStatus, FLIGHT_STATUS_CANT, &idStatus) && !hardcodePassengerType(arrayPassengerType, PASSENGER_TYPE_CANT, &idPassengerType))
		{
			do
			{
				if(!PassengerOptionsMenu(&option))
				{
					switch(option)
					{
						case 1:
							if(!loadPassenger(arrayPassenger, MAX_PASSENGER, &id))
							{
								printf("\nSe ha cargado con exito un nuevo pasajero!\n");
							}
							else
							{
								printf("\nError al cargar un nuevo pasajero.\n");
							}
							break;

						case 2:
							if(!arrayIsEmpty(arrayPassenger, MAX_PASSENGER))
							{
								printPassenger(arrayPassenger, arrayStatus, arrayPassengerType, MAX_PASSENGER, FLIGHT_STATUS_CANT, PASSENGER_TYPE_CANT);

								if(!getInt(&auxID, "\nElija el pasajero a ser eliminado: ", "Error, solo numeros del 1 al 1000: ", 1, 1000))
								{
									valueReturnRemove = removePassenger(arrayPassenger, arrayStatus, arrayPassengerType, MAX_PASSENGER, FLIGHT_STATUS_CANT, PASSENGER_TYPE_CANT, auxID);

									switch(valueReturnRemove)
									{
										case -1:
											printf("\n\aError al borrar al pasajero.\n");
											break;

										case 0:
											printf("\nPasajero borrado con exito!\n");
											break;

										case 1:
											printf("\nEl usuario cancelo el borrado del pasajero\n");
											break;
									}
								}
							}
							else
							{
								printf("\n\aError, no hay pasajeros que borrar.\n");
							}
							break;

						case 3:
							if(!arrayIsEmpty(arrayPassenger, MAX_PASSENGER))
							{
								printPassenger(arrayPassenger, arrayStatus, arrayPassengerType, MAX_PASSENGER, FLIGHT_STATUS_CANT, PASSENGER_TYPE_CANT);

								if(!getInt(&auxID, "\nElija el pasajero a ser modificado: ", "Error, solo numeros del 1 al 1000: ", 1, 1000))
								{
									valueReturnMod = modifyMenu(arrayPassenger, arrayStatus, arrayPassengerType, MAX_PASSENGER, FLIGHT_STATUS_CANT, PASSENGER_TYPE_CANT, auxID);

									switch(valueReturnMod)
									{
										case -1:
											printf("\n\aError al modificar al pasajero.\n");
											break;

										case 0:
											printf("\nPasajero modificado con exito!\n");
											break;

										case 1:
											printf("\nEl usuario cancelo la modificacion del pasajero\n");
											break;
									}
								}
							}
							else
							{
								printf("\n\aError, no hay pasajeros que modificar.\n");
							}
							break;

						case 4:
							if(!arrayIsEmpty(arrayPassenger, MAX_PASSENGER))
							{
								if(!printMenu(arrayPassenger, arrayStatus, arrayPassengerType, MAX_PASSENGER, FLIGHT_STATUS_CANT, PASSENGER_TYPE_CANT))
								{
									printf("\nLista de pasajeros mostrada con exito\n");
								}
								else
								{
									printf("\n\aError al mostrar la lista de pasajeros.\n");
								}
							}
							else
							{
								printf("\n\aError, no hay pasajeros que mostrar.\n");
							}
							break;

						case 5:
							if(flagHardcodeo == FALSE)
							{
								if(!hardcodePassenger(arrayPassenger, MAX_PASSENGER, &id))
								{
									printf("\nHardcodeo de datos realizado con exito!\n");
								}
								else
								{
									printf("\n\aError, no se pudo realizar le hardcodeo de pasajeros.\n");
								}
							}
							else
							{
								printf("\n\aError, ya se ha ingresado los datos del hardcodeo.\n");
							}
							break;

						case 6:
							printf("\nSaliendo del menu de pasajeros...\n");
							break;

						default:
							printf("\n\a\aError, ha ingresado un valor invalido.\n");
							break;
					}
				}

				printf("\n");
				fflush(stdin);
				system("pause");
				system("cls");

			}while(option != 7);
		}
	}

	return EXIT_SUCCESS;
}
