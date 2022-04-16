/*
 * funciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "input.h"
#include "funciones.h"
#include "calculadora.h"

// ===================================================

int ingresarKilometros(float* distancia)
{
	int toReturn = -1;

	if(distancia != NULL)
	{
		if(!getFloat(distancia, "\nIngrese la distancia del vuelo: ",
								"Error, solo numeros entre 1 y 25.000. Vuelva a intentarlo:", 1, 25000))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int ingresarPrecioAerolineas(float* precioAerolinias)
{
	int toReturn = -1;

	if(precioAerolinias != NULL)
	{
		if(!getFloat(precioAerolinias, "\nIngrese el precio del vuelo por Aerolineas: ",
									  "Error, solo numeros entre 1 y 300.000. Vuelve a intentarlo: ", 1, 300000))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int ingresarPrecioLatam(float* precioLatam)
{
	int toReturn = -1;

	if(precioLatam != NULL)
	{
		if(!getFloat(precioLatam, "\nIngrese el precio del vuelo por Latam: ",
									  "Error, solo numeros entre 1 y 300.000. Vuelve a intentarlo: ", 1, 300000))
		{
			toReturn = 0;
		}
	}
	return toReturn;
}

// ===================================================

int hardcodeosDeDatos(float* distancia, float* precioAerolineas, float* precioLatam)
{
	int toReturn = -1;

	if(distancia != NULL && precioAerolineas != NULL && precioLatam != NULL)
	{
		*distancia = 7090;
		*precioAerolineas = 162965;
		*precioLatam = 159339;

		toReturn = 0;
	}

	return toReturn;
}


// ===================================================

//DebitoAerolineas
int calcularCostosTarjetaDebitoAerolineas(float precioAerolineas, float* pResult)
{
	int toReturn = -1;

	float descuento;

	if(!isnan(precioAerolineas) && pResult != NULL)
	{
		if(!porcentaje(&descuento, precioAerolineas, 10, 100))
		{
			if(!resta(pResult, precioAerolineas, descuento))
			{
				toReturn = 0;
			}
		}
	}

	return toReturn;
}

//DebitoLatam
int calcularCostosTarjetaDebitoLatam(float precioLatam, float* pResult)
{
	int toReturn = -1;

	float descuento;

	if(!isnan(precioLatam) && pResult != NULL)
	{
		if(!porcentaje(&descuento, precioLatam, 10, 100))
		{
			if(!resta(pResult, precioLatam, descuento))
			{
				toReturn = 0;
			}
		}
	}

	return toReturn;
}

//CreditoAerolineas
int calcularCostosTarjetaCreditoAerolineas(float precioAerolineas, float* pResult)
{
	int toReturn = -1;

	float interes;

	if(!isnan(precioAerolineas) && pResult != NULL)
	{
		if(!porcentaje(&interes, precioAerolineas, 25, 100))
		{
			if(!suma(pResult, precioAerolineas, interes))
			{
				toReturn = 0;
			}
		}
	}

	return toReturn;
}

//CreditoLatam
int calcularCostosTarjetaCreditoLatam(float precioLatam, float* pResult)
{
	int toReturn = -1;

	float interes;

	if(!isnan(precioLatam) && pResult != NULL)
	{
		if(!porcentaje(&interes, precioLatam, 25, 100))
		{
			if(!suma(pResult, precioLatam, interes))
			{
				toReturn = 0;
			}
		}
	}

	return toReturn;
}

//BTC_Aerolineas
int calcularCostosBitcoinAerolineas(float precioAerolineas, double* pResult)
{
	int toReturn = -1;

	double precioBTC = 4606954.55;

	if(!isnan(precioAerolineas) && pResult != NULL)
	{
		if(!divisionDouble(pResult, precioAerolineas, precioBTC))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

//BTC_LATAM
int calcularCostosBitcoinLatam(float precioLatam, double* pResult)
{
	int toReturn = -1;

	double precioBTC = 4606954.55;

	if(!isnan(precioLatam) && pResult != NULL)
	{
		if(!divisionDouble(pResult, precioLatam, precioBTC))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

//Precio_KM_Aerolineas
int calcularPrecioPorKM_Aerolineas(float precioAerolineas, float distancia, float* pResult)
{
	int toReturn = -1;

	if(!isnan(precioAerolineas) && !isnan(distancia) && pResult != NULL)
	{
		if(!division(pResult, precioAerolineas, distancia))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

//Precio_KM_Latam
int calcularPrecioPorKM_Latam(float precioLatam, float distancia, float* pResult)
{
	int toReturn = -1;

	if(!isnan(precioLatam) && !isnan(distancia) && pResult != NULL)
	{
		if(!division(pResult, precioLatam, distancia))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

//DiferenciaDePrecio
int calcularDiferenciaDePrecio(float precioAerolineas, float precioLatam, float* pResult)
{
	int toReturn = -1;

	if(!isnan(precioAerolineas) && !isnan(precioLatam) && pResult != NULL)
	{
		if(!resta(pResult, precioLatam, precioAerolineas))
		{
			if(*pResult < 0)
			{
				*pResult = *pResult * -1;

				toReturn = 0;
			}
		}
	}

	return toReturn;
}

// ===================================================

int mostrarResultados(float resultadoDebitoAerolineas,      	float resultadoCreditoAerolineas,   	float resultadoBTC_Aerolineas,
					  float resultadoPrecioUnitarioAerolineas, 	float resultadoDebitoLatam, 			float resultadoCreditoLatam,
					  float resultadoBTC_Latam, 		    	float resultadoPrecioUnitarioLatam,		float diferenciaDePrecio,
					  float precioAerolineas, 					float precioLatam, 						float distancia)
{
	int toReturn = -1;

	printf("\nKMs ingresados: %.2f.\n\n", distancia);

	if(!isnan(resultadoDebitoAerolineas) && !isnan(resultadoCreditoAerolineas) && !isnan(resultadoBTC_Aerolineas)
	   &&
	   !isnan(resultadoPrecioUnitarioAerolineas) && !isnan(resultadoDebitoLatam) && !isnan(resultadoCreditoLatam)
	   &&
	   !isnan(resultadoBTC_Latam) && !isnan(resultadoPrecioUnitarioLatam) && !isnan(diferenciaDePrecio))
	{
		if(!mostrarResultadosAerolineas(precioAerolineas, resultadoDebitoAerolineas, resultadoCreditoAerolineas,
										resultadoBTC_Aerolineas, resultadoPrecioUnitarioAerolineas)
		   &&
		   !mostrarResultadosLatam(precioLatam, resultadoDebitoLatam, resultadoCreditoLatam, resultadoBTC_Latam, resultadoPrecioUnitarioLatam))
		{
			printf("\nDiferencia de Precio: $%.2f.\n", diferenciaDePrecio);

			toReturn = 0;
		}

	}

	return toReturn;
}

int mostrarResultadosAerolineas(float precioAerolineas, 	float resultDebitoAerolineas, float resultCreditoAerolineas,
								float resultBTC_Aerolineas, float resultUnitarioAerolineas)
{
	int toReturn = -1;

	if(!isnan(precioAerolineas) && !isnan(resultDebitoAerolineas) && !isnan(resultCreditoAerolineas) && !isnan(resultBTC_Aerolineas) &&
	   !isnan(resultUnitarioAerolineas))
	{
		printf("Aerolineas.\n\n");
		printf("Precio Base Aerolineas: $%.2f.\n", precioAerolineas);
		printf("A. Precio con pago con Tarjeta de Debito: $%.2f.\n", resultDebitoAerolineas);
		printf("B. Precio con pago con Tarjeta de Credito: $%.2f.\n", resultCreditoAerolineas);
		printf("C. Precio con pago con BITCOIN (BTC): $%.8f.\n", resultBTC_Aerolineas);
		printf("D. Precio unitario: $%.2f.\n", resultUnitarioAerolineas);

		toReturn = 0;
	}

	return toReturn;
}

int mostrarResultadosLatam(float precioLatam, 	  float resultDebitoLatam, float resultCreditoLatam,
						   float resultBTC_Latam, float resultUnitarioLatam)
{
	int toReturn = -1;

	if(!isnan(precioLatam) && !isnan(resultDebitoLatam) && !isnan(resultCreditoLatam) && !isnan(resultBTC_Latam) && !isnan(resultUnitarioLatam))
	{
		printf("\nLATAM.\n\n");
		printf("Precio Base LATAM: $%.2f.\n", precioLatam);
		printf("A. Precio con pago con Tarjeta de Debito: $%.2f.\n", resultDebitoLatam);
		printf("B. Precio con pago con Tarjeta de Credito: $%.2f.\n", resultCreditoLatam);
		printf("C. Precio con pago con BITCOIN (BTC): $%.8f.\n", resultBTC_Latam);
		printf("D. Precio unitario: $%.2f.\n", resultUnitarioLatam);

		toReturn = 0;
	}

	return toReturn;
}
