/*
 ============================================================================
 Name        : TP_1.c
 Author      : Praconovo, Nicolas Javier
 Version     :
 Copyright   : -
 Description : Trabajo Practico Nº 1
 ============================================================================
 */

/*
 * Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas para ofrecerlos a sus clientes.
 * Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
 * El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
 *
 * Para ello el programa iniciará y contará con un menú de opciones:
 *
 * 1. Ingresar Kilómetros: ( km=x)
 * 2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
 *
 * 		- Precio vuelo Aerolíneas:
 * 		- Precio vuelo Latam:
 *
 * 3. Calcular todos los costos:
 *
 * 		a) Tarjeta de débito (descuento 10%)
 * 		b) Tarjeta de crédito (interés 25%)
 * 		c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
 * 		d) Mostrar precio por km (precio unitario)
 * 		e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
 *
 * 4. Informar Resultados
 *
 * “Latam:
 *
 * 		a) Precio con tarjeta de débito: r
 * 		b) Precio con tarjeta de crédito: r
 * 		c) Precio pagando con bitcoin : r
 * 		d) Precio unitario: r
 *
 * Aerolíneas:
 *
 * 		a) Precio con tarjeta de débito: r
 * 		b) Precio con tarjeta de crédito: r
 * 		c) Precio pagando con bitcoin : r
 * 		d) Precio unitario: r
 *
 * La diferencia de precio es : r “
 *
 * 5. Carga forzada de datos
 * 6. Salir
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "input.h"
#include "funciones.h"
#include "menus.h"

int main(void)
{
	setbuf(stdout, NULL);

	int option;
	int optionsubMenu;

	//FLAGS
	int flagDistancia = 0;
	int flagAerolineas = 0;
	int flagLatam = 0;
	int flagCalculo = 0;

	float distancia = -1;

	float precioAerolineas = -1;
	float precioLatam = -1;

	//Resultados
	float resultadoDebitoAerolineas;
	float resultadoDebitoLatam;

	float resultadoCreditoAerolineas;
	float resultadoCreditoLatam;

	double resultadoBTC_Aerolineas;
	double resultadoBTC_Latam;

	float resultadoUnitarioAerolineas;
	float resultadoUnitarioLatam;

	float diferenciaPrecio;

	do
	{
		if(!menuDeOpcionesPrincipal(&option, distancia, precioAerolineas, precioLatam))
		{
			switch(option)
			{
				case 1:
					//Ingresar Kilometros
					if(!ingresarKilometros(&distancia))
					{
						printf("\nIngreso de distancia con exito!\n");

						flagDistancia = 1;
					}
					else
					{
						printf("\n\aError en la carga de la distancia.\n");
					}
					break;

				case 2:
					//Ingresar precio del vuelo
					//SUBMENU - 2 opciones
					if(!subMenuDeOpcionesVuelos(&optionsubMenu))
					{
						switch(optionsubMenu)
						{
							case 1:
								//Precio Vuelo Aerolineas
								if(!ingresarPrecioAerolineas(&precioAerolineas))
								{
									printf("\nIngreso del valor del vuelo con Aerolineas con exito.\n");

									flagAerolineas = 1;
								}
								else
								{
									printf("\n\aError en la carga del valor del vuelo con Aerolineas.\n");
								}
								break;

							case 2:
								//Precio Vuelo LATAM
								if(!ingresarPrecioLatam(&precioLatam))
								{
									printf("\nIngreso del valor del vuelo con LATAM con exito.\n");

									flagLatam = 1;
								}
								else
								{
									printf("\n\aError en el ingreso del valor del vuelo con LATAM.\n");
								}
								break;

							case 3:
								printf("\nSaliendo...\n\n");
								break;

							default:
								printf("\n\aError, se ha ingresado un valor invalido.\n");
								break;
						}
					}
					break;

				case 3:
					/*
					 * Calcular todos los costos
					 * Informar todas las operaciones realizadas.
					 *
					 * 		a) Tarjeta de débito (descuento 10%)
					 * 		b) Tarjeta de crédito (interés 25%)
					 * 		c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
					 * 		d) Mostrar precio por km (precio unitario)
					 * 		e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
					*/
					printf("\n3. Calculando los costos.\n");
					if(flagDistancia == 0 || flagAerolineas == 0 || flagLatam == 0)
					{
						printf("\n\aNo se puede realizar los calculos porque faltan datos por ingresar.\n");
						printf("\nPor favor, ingrese los datos faltantes.\n");

					}
					else
					{
						if(!calcularCostosTarjetaDebitoAerolineas(precioAerolineas, &resultadoDebitoAerolineas) &&
						   !calcularCostosTarjetaCreditoAerolineas(precioAerolineas, &resultadoCreditoAerolineas) &&
						   !calcularCostosBitcoinAerolineas(precioAerolineas, &resultadoBTC_Aerolineas) &&
						   !calcularPrecioPorKM_Aerolineas(precioAerolineas, distancia, &resultadoUnitarioAerolineas))
						{

							flagCalculo = 1;

							printf("\nSe ha calculado los costos del vuelo por Aerolineas con exito!\n\n");
							system("pause");

							if(!calcularCostosTarjetaDebitoLatam(precioLatam, &resultadoDebitoLatam) &&
							   !calcularCostosTarjetaCreditoLatam(precioLatam, &resultadoCreditoLatam) &&
							   !calcularCostosBitcoinLatam(precioLatam, &resultadoBTC_Latam) &&
							   !calcularPrecioPorKM_Latam(precioLatam, distancia, &resultadoUnitarioLatam) &&
							   !calcularDiferenciaDePrecio(precioAerolineas, precioLatam, &diferenciaPrecio))
							{
								printf("\nSe ha calculado los costos del vuelo por Latam con exito!\n\n");

								flagCalculo = 2;

								printf("\nSe calculo con exito los siguientes costos:\n");
								printf("\n1. Descuento por pago con tarjeta de debito del 10%% a ambas compañias.\n");
								printf("2. Interes por el pago con tarjeta de credito del 25%% a ambas compañias.\n");
								printf("3. Calcuclo del precio en Bitcoin (BTC) a ambas compañias.\n");
								printf("4. Precio por KM a ambas compañias.\n");
								printf("5. Diferencia de precio entre ambas compañias.\n");
							}
						}
						else
						{
							printf("\n\n\aSe ha producido un error al calcular los costos.\n");
						}

					}
					break;

				case 4:
					/*
					 * Informar Resultados
					 *
					 * “Latam:
					 *
					 * 		a) Precio con tarjeta de débito: r
					 * 		b) Precio con tarjeta de crédito: r
					 * 		c) Precio pagando con bitcoin : r
					 * 		d) Precio unitario: r
					 *
					 * Aerolíneas:
					 *
					 * 		a) Precio con tarjeta de débito: r
					 * 		b) Precio con tarjeta de crédito: r
					 * 		c) Precio pagando con bitcoin : r
					 * 		d) Precio unitario: r
					 *
					 * La diferencia de precio es : r “
					 */
					if(flagDistancia == 0 || flagAerolineas == 0 || flagLatam == 0 || flagCalculo == 0 || flagCalculo == 1)
					{
						printf("\n\aNo se puede mostrar porque faltan datos por ingresar o no se ha realizado los calculos.\n");
						printf("\nPor favor, ingrese los datos faltantes o realice los calculos.\n");

					}
					else
					{
						if(!mostrarResultados(resultadoDebitoAerolineas, resultadoCreditoAerolineas, resultadoBTC_Aerolineas,
											  resultadoUnitarioAerolineas, resultadoDebitoLatam, resultadoCreditoLatam,
											  resultadoBTC_Latam, resultadoUnitarioLatam, diferenciaPrecio, precioAerolineas,
											  precioLatam, distancia))
						{
							printf("\nResultados mostrados con exito.\n");
						}
						else
						{
							printf("\n\n\aError al mostrar los resultados.\n");
						}
					}

					break;

				case 5:
					// Carga forzosa de datos
					// Hardcodeo de los datos.
					if(!hardcodeosDeDatos(&distancia, &precioAerolineas, &precioLatam))
					{
						printf("\nDatos hardcodeados cargados con exito!\n\n");
						system("pause");

						if(!calcularCostosTarjetaDebitoAerolineas(precioAerolineas, &resultadoDebitoAerolineas) 		&&
						   !calcularCostosTarjetaCreditoAerolineas(precioAerolineas, &resultadoCreditoAerolineas) 		&&
						   !calcularCostosBitcoinAerolineas(precioAerolineas, &resultadoBTC_Aerolineas) 				&&
						   !calcularPrecioPorKM_Aerolineas(precioAerolineas, distancia, &resultadoUnitarioAerolineas) 	&&
						   !calcularCostosTarjetaDebitoLatam(precioLatam, &resultadoDebitoLatam)						&&
						   !calcularCostosTarjetaCreditoLatam(precioLatam, &resultadoCreditoLatam) 						&&
						   !calcularCostosBitcoinLatam(precioLatam, &resultadoBTC_Latam) 								&&
						   !calcularPrecioPorKM_Latam(precioLatam, distancia, &resultadoUnitarioLatam) 					&&
						   !calcularDiferenciaDePrecio(precioAerolineas, precioLatam, &diferenciaPrecio))
						{
							printf("\nCostos de los datos hardcodeados realizado con exito.\n\n");
							system("pause");

							if(!mostrarResultados(resultadoDebitoAerolineas, resultadoCreditoAerolineas, resultadoBTC_Aerolineas,
							   resultadoUnitarioAerolineas, resultadoDebitoLatam, resultadoCreditoLatam,
							   resultadoBTC_Latam, resultadoUnitarioLatam, diferenciaPrecio, precioAerolineas,
							   precioLatam, distancia))
							{
								printf("\nDatos Hardcodeados mostrados con exito!\n");
							}
							else
							{
								printf("\n\aError al mostrar los datos hardcodeados.\n");
							}
						}
						else
						{
							printf("\n\aError al intentar realizar los costos de los datos hardcodeados.\n");
						}

					}
					else
					{
						printf("\n\aError al realizar el hardcodeo de datos.\n");
					}
					break;

				case 6:
					printf("\nSaliendo del programa...\n");
					break;

				default:
					printf("\nError, se ha ingresado un valor invalido.\n");
			}

			printf("\n");
			system("pause");
			system("cls");

			//clearScreen();

		}
		else
		{
			printf("Error en la iniciazacion del menu de opciones.\n");
		}

	}while(option != 6);

	return EXIT_SUCCESS;
}
