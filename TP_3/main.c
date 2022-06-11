#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menu.h"
#include "input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

	LinkedList* listaPasajeros = ll_newLinkedList();

	int id = 1;
    int option;

    int flagExit = 0;
    int flagSave = 0;

    if(listaPasajeros != NULL)
    {
    	do
    	{
    		if(!optionsMenu(&option))
    		{
    			switch(option)
    			{
    				case 1:
    					// CARGAR DATOS DE DATA.CSV COMO TEXTO
    					if(ll_isEmpty(listaPasajeros))
    					{
    						if(!controller_loadFromText("data.csv", listaPasajeros, &id))
    						{
    							printf("\nEl archivo 'data.csv' ha sido cargado con exito.\n");

    						}
    						else
    						{
    							printf("\nError en la carga del archivo 'data.csv'.\n");
    						}
    					}
    					else
    					{
    						printf("La lista ya ha sido cargada.\n");
    					}
    					break;

    				case 2:
    					// CARGA DATOS DE DATA.BIN COMO BINARIO
    					if(ll_isEmpty(listaPasajeros))
    					{
    						if(!controller_loadFromBinary("data.bin", listaPasajeros, &id))
    						{
    							printf("\nEl archivo 'data.bin' ha sido cargado con exito.\n");

    						}
    						else
    						{
    							printf("\nError en la carga del archivo 'data.bin'.\n");
    						}
    					}
    					else
    					{
    						printf("\nLa lista ya ha sido cargada.\n");
    					}
    					break;

    				case 3:
    					//ALTA PASAJERO
    					if(!ll_isEmpty(listaPasajeros))
    					{
    						if(!controller_addPassenger(listaPasajeros, &id))
    						{
    							printf("\nPasajero cargado con exito.\n");
    						}
    						else
    						{
    							printf("\nError en el alta de un pasajero.\n");
    						}
    					}
    					else
    					{
    						printf("Error, la lista no se ha cargado.\n");
    					}
    					break;

    				case 4:
    					// MODIFICAR PASAJERO
    					if(!ll_isEmpty(listaPasajeros))
    					{
    						if(!controller_editPassenger(listaPasajeros))
    						{
    							printf("\nPasajero modificado con exito.\n");
    						}
    						else
    						{
    							printf("\nError en la modificacion del pasajero.\n");
    						}
    					}
    					else
    					{
    						printf("Error, la lista no se ha cargado.\n");
    					}
    					break;

    				case 5:
    					// BAJA PASAJERO
    					if(!ll_isEmpty(listaPasajeros))
    					{
    						if(!controller_removePassenger(listaPasajeros))
    						{
    							printf("\nPasajero eliminado con exito.\n");
    						}
    						else
    						{
    							printf("\nError en la baja del pasajero.\n");
    						}
    					}
    					else
    					{
    						printf("\nError, la lista no se ha cargado.\n");
    					}
    					break;

    				case 6:
    					// LISTAR PASAJEROS
    					if(!ll_isEmpty(listaPasajeros))
    					{
    						if(!controller_listPassenger(listaPasajeros))
    						{
    							printf("\nListado de Pasajeros mostrada con exito.\n");
    						}
    						else
    						{
    							printf("\nError en la muestra de la lista de pasajeros.\n");
    						}
    					}
    					else
    					{
    						printf("\nError, la lista no se ha cargado.\n");
    					}
    					break;

    				case 7:
    					// ORDENAR PASAJEROS
    					if(!ll_isEmpty(listaPasajeros))
    					{
    						if(!controller_sortPassenger(listaPasajeros))
    						{
    							printf("\nOrdenamiento de pasajeros realizado con exito.\n");
    						}
    						else
    						{
    							printf("\nError al ordenar la lista de pasajeros.\n");
    						}
    					}
    					else
    					{
    						printf("\nError, la lista no ha sido cargada.\n");
    					}
    					break;

    				case 8:
    					// GUARDAR DATOS EN DATA.CSV COMO TEXTO
    					if(!ll_isEmpty(listaPasajeros))
    					{
    						if(!controller_saveAsText("data.csv", listaPasajeros))
    						{
    							printf("\nLos datos han sido guardado en 'data.csv' como texto con exito.\n");

    							flagSave = 1;
    						}
    						else
    						{
    							printf("\nHa ocurrido un error al guardar los datos como texto en el archivo 'data.csv'.\n");
    						}
    					}
    					else
    					{
    						printf("\nError, la lista no ha sido cargada.\n");
    					}
    					break;

    				case 9:
    					//GUARDAR LOS DATOS EN DATA.BIN COMO BINARIO
    					if(!ll_isEmpty(listaPasajeros))
    					{
    						if(!controller_saveAsBinary("data.bin", listaPasajeros))
    						{
    							printf("\nLos datos han sido guardados en el archivo 'data.bin' como binario con exito.\n");

    							flagSave = 1;
    						}
    						else
    						{
    							printf("\nHa ocurrido un error al guardar los datos como binario en el archivo 'data.bin'.\n");
    						}
    					}
    					else
    					{
    						printf("Error, la lista no ha sido cargada.\n");
    					}
    					break;

    				case 10:
    					// SALIR
    					if(flagSave )
    					{
    						printf("\nSaliendo del menu de opciones...\n");

    						flagExit = 1;
    					}
    					else
    					{
    						printf("\nPor favor guarde la lista antes de salir\n");
    					}

    					break;

    				default:
    					printf("\nError, ha ingresado un valor invalido.\n");
    					break;
    			}
    		}

    		printf("\n");

    		system("pause");
    		system("cls");

    	}while(option != 10 || !flagExit );

    }
    else
    {
    	printf("Ha ocurrido un error al crear la LinkedList.\n");
    }

    return 0;
}
