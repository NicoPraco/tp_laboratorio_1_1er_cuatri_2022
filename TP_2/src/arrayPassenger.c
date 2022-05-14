/*
 * arrayPassenger.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Nicolas
 */

#include "arrayPassenger.h"

int initPassengers(Passenger* list, int len)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}

		toReturn = 0;
	}

	return toReturn;
}

int hardcodePassenger(Passenger* list, int len, int* id)
{
    int toReturn = -1;

    int i;
    int cant;
    int index;

    int flag = FALSE;

    Passenger auxPassengers[] =
    {
    		{0, "Martin", 		"Fernandez", 	45000, "AR1000", 3, 1, FALSE},
			{0, "Jorge", 		"Menendez", 	50000, "AR1000", 3, 1, FALSE},
			{0, "Julio", 		"Lopez", 		60000, "AR1100", 2, 2, FALSE},
			{0, "Valentina", 	"Alvarez", 		60000, "AR1200", 2, 1, FALSE},
			{0, "Martin", 		"Lopez", 		80000, "AR1300", 1, 3, FALSE},
			{0, "Miguel", 		"DiLuca", 		85000, "AR1400", 1, 4, FALSE}
    };

    if(list != NULL && len > 0 && id != NULL)
    {
    	cant = sizeof(auxPassengers) / sizeof(Passenger);

    	if(cant <= len)
    	{
			for(i = 0; i < cant; i++)
			{
				if(!searchFree(list, len, &index))
				{
					list[index] = auxPassengers[i];
					list[index].id = *id;

					(*id)++;

					flag = TRUE;
				}
			}
			if(flag)
			{
				toReturn = 0;
			}
    	}
    }

    return toReturn;
}

int hardcodeFlightStatus(FlightStatus* list, int len, int* id)
{
	int toReturn = -1;

	int i;
	int cant;

	FlightStatus auxStatus[] =
		{
				{0, "ACTIVO"},
				{0, "DEMORADO"},
				{0, "POSTERGADO"},
				{0, "CANCELADO"}
		};

	if(list != NULL && len > 0)
	{
		cant = sizeof(auxStatus) / sizeof(FlightStatus);

		if(cant <= len)
		{
			for(i = 0; i < cant; i++)
			{
				list[i] = auxStatus[i];
				list[i].id = *id;

				(*id)++;
			}

			toReturn = 0;
		}
	}

	return toReturn;
}

int hardcodePassengerType(PassengerType* list, int len, int* id)
{
	int toReturn = -1;

	int i;
	int cant;

	PassengerType auxPassengerType[] =
		{
				{0, "PRIMERA CLASE"},
				{0, "CLASE EJECUTIVA"},
				{0, "CLASE ECONOMICA"},

		};

	if(list != NULL && len > 0)
	{
		cant = sizeof(auxPassengerType) / sizeof(PassengerType);

		if(cant <= len)
		{
			for(i = 0; i < cant; i++)
			{
				list[i] = auxPassengerType[i];
				list[i].id = *id;

				(*id)++;
			}

			toReturn = 0;
		}
	}

	return toReturn;
}

int searchFree(Passenger* list, int len, int* index)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0 && index != NULL)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				*index = i;
				toReturn = 0;
				break;
			}
		}
	}

	return toReturn;
}

int findPassengerById(Passenger* list, int len, int id)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0 && id > 0 && id < len)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				toReturn = i;
				break;
			}
		}
	}

	return toReturn;
}

int findStatusById(FlightStatus* list, int len, int id)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].id == id)
			{
				toReturn = i;
				break;
			}
		}
	}

	return toReturn;
}

int findPassengerTypeById(PassengerType* list, int len, int id)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].id == id)
			{
				toReturn = i;
				break;
			}
		}
	}

	return toReturn;
}

int arrayIsEmpty(Passenger* list, int len)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				toReturn = 0;
				break;
			}
		}
	}

	return toReturn;
}

// =============================================================

// CARGA DE PASAJERO

int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, char flightCode[], int typePassenger, int flightStatus)
{
	int toReturn = -1;

	int index;

	if(list != NULL && len > 0 && id > -1)
	{
		if(!searchFree(list, len, &index) && index > -1)
		{
			list[index].id = id;

			strncpy(list[index].name, name, NAME_LENGHT);
			strncpy(list[index].lastName, lastName, SURNAME_LENGTH);

			list[index].price = price;

			strncpy(list[index].flightCode, flightCode, FLIGHT_CODE_LENGHT);

			list[index].typePassanger = typePassenger;
			list[index].flightStatus = flightStatus;

			list[index].isEmpty = FALSE;

			toReturn = 0;
		}
	}

	return toReturn;
}

int loadPassenger(Passenger* list, int len, int* id)
{
	int toReturn = -1;

	Passenger auxPassenger;

	if(list != NULL && len > 0 && id != NULL)
	{
		if(!getString(auxPassenger.name, "\nIngrese el nombre del pasajero: ", "Error, vuelva a intentarlo: ", 3, NAME_LENGHT) &&
		   !getString(auxPassenger.lastName, "\nIngrese el apellido del pasajero: ", "Error, vuelva a  intentarlo: ", 3, SURNAME_LENGTH) &&
		   !getFloat(&auxPassenger.price, "\nIngrese el precio del vuelo entre 10000 y 300000: ", "Error, vuelva a intenrarlo: ", 10000, 300000) &&
		   !getString(auxPassenger.flightCode, "\nIngrese el codigo de vuelo: ", "Error, vuelva a intentarlo: ", 1, 10) &&
		   !loadPassengerClassMenu(&auxPassenger.typePassanger) &&
		   !loadPassengerFlightStatusMenu(&auxPassenger.flightStatus) &&
		   !addPassenger(list, len, *id, auxPassenger.name, auxPassenger.lastName,
				   	   	 auxPassenger.price, auxPassenger.flightCode ,auxPassenger.typePassanger, auxPassenger.flightStatus))
		{
			(*id)++;
			toReturn = 0;
		}
	}

	return toReturn;
}

// BAJA DE PASAJERO

int removePassenger(Passenger* list, FlightStatus* status, PassengerType* type, int len, int lenStatus, int lenType, int id)
{
	int toReturn = -1;

	int index;
	int indexStatus;
	int indexType;
	int answer;

	if(list != NULL && len > 0 && id > -1)
	{
		index = findPassengerById(list, len, id);
		indexStatus = findStatusById(status, lenStatus, list[index].flightStatus);
		indexType = findPassengerTypeById(type, lenType, list[index].typePassanger);

		if(index > -1)
		{
			printf("\n\n");
			fflush(stdin);
			system("pause");
			system("cls");

			printf("\tBAJA DE PASAJERO\n\n");
			printf("ID \tNOMBRE \t\tAPELLIDO \tPRECIO \t\tCODIGO DE VUELO \tTIPO DE PASAJEROS \tESTADO DEL VUELO\n\n");
			printOnePassenger(&list[index], &status[indexStatus], &type[indexType]);

			printf("\n\n0. = NO");
			printf("\n1. = SI\n");

			if(!getInt(&answer, "\nEsta seguro de eliminar al pasajero: ", "Error, solo 0 o 1: ", 0, 1))
			{
				switch(answer)
				{
					case 0:
						toReturn = 1;
						break;

					case 1:
						list[index].isEmpty = TRUE;

						toReturn = 0;
						break;

					default:
						printf("\n\aError, ha ingresado un valor invalido\n");
						break;
				}
			}
		}
	}

	return toReturn;
}

// MODIFICAR PASAJERO

int modifyMenu(Passenger* list, FlightStatus* status, PassengerType* type, int len, int lenStatus, int lenType, int id)
{
	int toReturn = -1;

	int index;
	int indexStatus;
	int indexType;
	int answer;

	if(list != NULL && len > 0 && id > -1)
	{
		index = findPassengerById(list, len, id);
		indexStatus = findStatusById(status, lenStatus, list[index].flightStatus);
		indexType = findPassengerTypeById(type, lenType, list[index].typePassanger);

		if(index > -1)
		{
			printf("\n\n");
			fflush(stdin);
			system("pause");
			system("cls");

			printf("\tMODIFICACION DE PASAJERO\n\n");
			printf("ID \tNOMBRE \t\tAPELLIDO \tPRECIO \t\tCODIGO DE VUELO \tTIPO DE PASAJEROS \tESTADO DEL VUELO\n\n");
			printOnePassenger(&list[index], &status[indexStatus], &type[indexType]);

			printf("\n\n0. = NO");
			printf("\n1. = SI\n");

			if(!getInt(&answer, "\nEsta seguro de modificar al pasajero: ", "Error, solo 0 o 1: ", 0, 1))
			{
				switch(answer)
				{
					case 0:
						toReturn = 1;
						break;

					case 1:
						if(!modifyPassenger(list, len, index))
						{
							toReturn = 0;
						}
				}
			}
		}
	}

	return toReturn;
}

int modifyPassenger(Passenger* list, int len, int index)
{
	int toReturn = -1;

	int option;

	int flag = FALSE;

	Passenger auxPassenger;

	if(list != NULL && len > 0 && index > -1)
	{
		do
		{
			if(!PassengerModMenu(&option))
			{
				switch(option)
				{
					case 1:
						if(!getString(auxPassenger.name, "\nIngrese el nuevo nombre del pasajero: ", "Error, vuelva a intentarlo: ", 3, NAME_LENGHT))
						{
							strncpy(list[index].name, auxPassenger.name, NAME_LENGHT);

							flag = TRUE;
						}
						break;

					case 2:
						if(!getString(auxPassenger.lastName, "\nIngrese el nuevo apellido del pasajero: ", "Error, vuelva a intentarlo: ", 3, SURNAME_LENGTH))
						{
							strncpy(list[index].lastName, auxPassenger.lastName, SURNAME_LENGTH);

							flag = TRUE;
						}
						break;

					case 3:
						if(!getFloat(&auxPassenger.price, "\nIngrese el nuevo precio del pasaje: ", "Error, vuelva a intentarlo: ", 10000, 300000))
						{
							list[index].price = auxPassenger.price;

							flag = TRUE;
						}
						break;

					case 4:
						if(!getString(auxPassenger.flightCode, "\nIngrese el nuevo codigo de vuelo: ", "Error, vuelva a intentarlo: ", 1, 10))
						{
							strncpy(list[index].flightCode, auxPassenger.flightCode, FLIGHT_CODE_LENGHT);

							flag = TRUE;
						}
						break;

					case 5:
						if(!loadPassengerClassMenu(&auxPassenger.typePassanger))
						{
							list[index].typePassanger = auxPassenger.typePassanger;

							flag = TRUE;

						}
						break;

					case 6:
						printf("\nSaliendo...\n\n");
						break;

					default:
						printf("\n\aError, ha ingresado un valor invalido.\n");
						break;
				}

				printf("\n\n");
				fflush(stdin);
				system("pause");
				system("cls");
			}

		}while(option != 6);

		if(flag)
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

// ORDENAR PASAJEROS

int sortMenu(Passenger* list, int len, int* order)
{
	int toReturn = -1;

	int option;

	if(list != NULL && len > 0)
	{
		do
		{
			PassengerSortMenu(&option);

			switch (option) {
				case 1:
					*order = 1;
					break;

				case 2:
					*order = 0;
					break;

				default:
					printf("\n\aError, ha ingresado un valor invalido.\n");
					break;
			}

		}while(option != 1 && option != 2);

		toReturn = 0;
	}

	return toReturn;
}

int sortPassengers(Passenger* list, int len, int order)
{
	int toReturn = -1;

	int i;
	int auxLen;
	int flagSwap;
	int auxCmp;

	Passenger auxPassenger;

	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		auxLen = len;

		do
		{
			flagSwap = FALSE;

			for(i = 0; i < auxLen - 1; i++)
			{
				if(list[i].isEmpty == FALSE && list[i + 1].isEmpty == FALSE)
				{
					auxCmp = strncmp(list[i].lastName, list[i + 1].lastName, SURNAME_LENGTH);

					if( ((auxCmp > 0 || (auxCmp == 0 && list[i].typePassanger > list[i + 1].typePassanger)) && order == 1) ||
						((auxCmp < 0 || (auxCmp == 0 && list[i].typePassanger < list[i + 1].typePassanger)) && order == 0 ) )
					{
						auxPassenger = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxPassenger;

						flagSwap = TRUE;
					}
				}
			}
			auxLen--;

		}while(flagSwap);

		toReturn = 0;
	}

	return toReturn;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	int toReturn = -1;

	int i;
	int auxLen;
	int flagSwap;
	int auxCmp;

	Passenger auxPassenger;

	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		auxLen = len;

		do
		{
			flagSwap = FALSE;

			for(i = 0; i < auxLen - 1; i++)
			{
				if(list[i].isEmpty == FALSE && list[i + 1].isEmpty == FALSE)
				{
					auxCmp = strncmp(list[i].flightCode, list[i + 1].flightCode, FLIGHT_CODE_LENGHT);

					if( ((auxCmp > 0 || (auxCmp == 0 && list[i].flightStatus > list[i + 1].flightStatus)) && order == 1) ||
						((auxCmp < 0 || (auxCmp == 0 && list[i].flightStatus < list[i + 1].flightStatus)) && order == 0 ) )
					{
						auxPassenger = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxPassenger;

						flagSwap = TRUE;
					}
				}
			}
			auxLen--;

		}while(flagSwap);

		toReturn = 0;
	}

	return toReturn;
}

// MOSTRAR PASAJEROS

int printMenu(Passenger* list, FlightStatus* status, PassengerType* type, int len, int lenStatus, int lenType)
{
	int toReturn = -1;

	int option;
	int order;

	int flag = FALSE;

	if(list != NULL && len > 0)
	{
		do
		{
			printf("\n\n");
			fflush(stdin);
			system("pause");
			system("cls");

			PassengerPrintMenu(&option);

			switch(option)
			{
				case 1:
					if(!sortMenu(list, len, &order) && !sortPassengers(list, len, order))
					{
						printf("\nOrdenamiento Realizado con exito!\n\n");

						if(!printPassenger(list, status, type, len, lenStatus, lenType))
						{
							printf("\nLista de pasajeros mostrada con exito!\n");

							flag = TRUE;
						}
						else
						{
							printf("\nError al mostrar la lista de pasajeros.\n");
						}
					}
					else
					{
						printf("\nError al realizar el ordenamiento.\n");
					}
					break;

				case 2:
					if(!calculatePrices(list, len))
					{
						printf("\nReporte de precios mostrado con exito.\n");

						flag = TRUE;
					}
					else
					{
						printf("\nError al mostrar el reporte de precios.\n");
					}
					break;

				case 3:
					if(!sortMenu(list, len, &order) && !sortPassengersByCode(list, len, order))
					{
						printf("\nOrdenamiento Realizado con exito!\n\n");

						if(!printPassenger(list, status, type, len, lenStatus, lenType))
						{
							printf("\nLista de pasajeros mostrada con exito!\n");

							flag = TRUE;
						}
						else
						{
							printf("\nError al mostrar la lista de pasajeros.\n");
						}
					}
					else
					{
						printf("\nError al realizar el ordenamiento.\n");
					}
					break;

				case 4:
					printf("\nSaliendo...\n");
					break;

				default:
					printf("\n\aError, ha ingresado un valor invalido.\n");
					break;

			}
		}while(option != 4);

		if(flag)
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int printOnePassenger(Passenger* aPassenger, FlightStatus* status, PassengerType* type)
{
	int toReturn = -1;

	if(aPassenger != NULL && status != NULL)
	{
		//ID 	NAME 	SURNAME 	PRICE 		FLYCODE 	PASSANGER_TYPE		STATUS_FLIGHT
		printf("%d %12s %16s %16.2f %17s %28s %20s\n", aPassenger->id, aPassenger->name, aPassenger->lastName, aPassenger->price,
													   aPassenger->flightCode, type->descripcion, status->descripcion);

		toReturn = 0;
	}

	return toReturn;
}

int printPassenger(Passenger* list, FlightStatus* status, PassengerType* type, int len, int lenStatus, int lenType)
{
	int toReturn = -1;

	int i;
	int indexStatus;
	int indexType;

	if(list != NULL && len > 0)
	{
		printf("\n\n");
		fflush(stdin);
		system("pause");

		printf("\t\tLISTA DE PASAJEROS\n\n");
		printf("ID \tNOMBRE \t\tAPELLIDO \tPRECIO \t\tCODIGO DE VUELO \tTIPO DE PASAJEROS \tESTADO DEL VUELO\n\n");

		for(i = 0; i < len; i++)
		{
			indexStatus = findStatusById(status, lenStatus, list[i].flightStatus);
			indexType = findPassengerTypeById(type, lenType, list[i].typePassanger);

			if(list[i].isEmpty == FALSE && printOnePassenger(&list[i], &status[indexStatus], &type[indexType]))
			{
				break;
			}
		}

		if(i == len)
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

// ============================================================================

int calculatePrices(Passenger* list, int len)
{
	int toReturn = -1;

	int passengerCounter;

	float priceAccumulator;
	float priceAverage;

	if(list != NULL && len > 0)
	{
		if(!AveragePassagePrices(list, len, &priceAccumulator, &priceAverage) && !passengerExceedsAveragePrice(list, len, priceAverage, &passengerCounter))
		{
			printAverageOfPasseges(passengerCounter, priceAverage, priceAccumulator);

			toReturn = 0;
		}

	}

	return toReturn;
}

int AveragePassagePrices(Passenger* list, int len, float* accumulator, float* average)
{
	int toReturn = -1;

	int counter;

	if(list != NULL && len > 0 && average != NULL)
	{
		if(!accumulatorOfPassagePrices(list, len, accumulator) &&
		   !PassengerCounter(list, len, &counter) && counter > 0)
		{
			*average = *accumulator / counter;

			toReturn = 0;
		}
	}

	return toReturn;
}

int accumulatorOfPassagePrices(Passenger* list, int len, float* accumulator)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0 && accumulator != NULL)
	{
		*accumulator = 0;

		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				*accumulator = *accumulator + list[i].price;
			}
		}

		toReturn = 0;
	}

	return toReturn;
}

int PassengerCounter(Passenger* list, int len, int* counter)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0 && counter != NULL)
	{
		*counter = 0;

		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				(*counter)++;
			}
		}

		toReturn = 0;
	}

	return toReturn;
}

int passengerExceedsAveragePrice(Passenger* list, int len, float average, int* counter)
{
	int toReturn = -1;

	int i;


	if(list != NULL && len > 0 && counter != NULL)
	{
		*counter = 0;

		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].price > average)
			{
				(*counter)++;
			}
		}

		toReturn = 0;
	}

	return toReturn;
}

int printAverageOfPasseges(int passengerCounter, float priceAverage, float priceAccumulator)
{
	int toReturn = -1;

	if(passengerCounter > 0 && priceAverage > 0 && priceAccumulator > 0)
	{
		printf("\tREPORTE DE PRECIOS\n\n");

		printf("Suma total de precios: %g. \n", priceAccumulator);
		printf("Promedio de precios: %g. \n", priceAverage);
		printf("Cantidad de pasajeros que superar el promedio: %d.\n\n", passengerCounter);

		toReturn = 0;
	}

	return toReturn;
}
