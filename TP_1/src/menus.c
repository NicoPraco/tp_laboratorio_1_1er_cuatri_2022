/*
 * menus.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "input.h"
#include "funciones.h"

int menuDeOpcionesPrincipal(int* input, float KM, float precioAerolineas, float precioLatam)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("Menu de Opciones Principal\n\n");
		printf("1. Ingresar kilometros (KM = %.2f).\n", KM);
		printf("2. Ingresar precio del vuelo (Aerolineas = %g - LATAM = %.2f).\n", precioAerolineas, precioLatam);
		printf("3. Calcular todos los costos.\n");
		printf("4. Informar resultados.\n");
		printf("5. Carga forzada de datos.\n");
		printf("6. Salir.\n\n");

		if(!getInt(input, "Elija una opcion: ", "Error, opcion invalida. Vuelva a intentarlo: ", 1, 6))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int subMenuDeOpcionesVuelos(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("Submenu de opciones sobre el precio del vuelo\n\n");
		printf("1. Precio del vuelo por Aerolineas.\n");
		printf("2. Precio del vuelo por LATAM.\n");
		printf("3. Salir.\n\n");

		if(!getInt(input, "Elija una opcion: ", "Error, elija una opcion valida. Vuelva a intentarlo: ", 1, 3))
		{
			toReturn = 0;
		}

	}

	return toReturn;
}
