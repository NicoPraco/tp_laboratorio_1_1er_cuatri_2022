/*
 * funciones.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Nicolas
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

// ===================================================

/**
 * \brief Permite al usuario ingresar la distancia del vuelo.
 *
 * \param distancia. Puntero a float. Donde se guardar el valor ingresado por el usuario.
 *
 * \return Retorna -1 si error o 0 si OK
 */
int ingresarKilometros(float* distancia);

/**
 * \brief Permite al usuario ingresar el valor del vuelo por Aerolineas.
 *
 * \param precioAerolinias. Puntero a float. Donde se guarda el valor ingresado por el usuario
 *
 * \return Retorna -1 si error o 0 si OK
 */
int ingresarPrecioAerolineas(float* precioAerolinias);

/**
 * \brief Permite al usuario ingresar el valor del vuelo por LATAM.
 *
 * \param precioLatam. Puntero a float. Donde se guarda el valor ingresado por el usuario
 *
 * \return Retorna -1 si error o 0 si OK
 */
int ingresarPrecioLatam(float* precioLatam);

// ===================================================

/**
 * \brief Realiza una carga forzada de datos.
 *
 * \param distancia. Puntero a float. Donde se guardaran los datos ingresados de manera forzada.
 * \param precioAerolineas. Puntero a float. Donde se guardaran los datos ingresados de manera forzada.
 * \param precioLatam. Puntero a float. Donde se guardaran los datos ingresados de manera forzada.
 *
 * \return Retorna -1 si error o 0 si OK
 */
int hardcodeosDeDatos(float* distancia, float* precioAerolineas, float* precioLatam);

// ===================================================

/**
 * \brief Calcula los costos del pago con tarjeta de debito, el cual tiene un 10% de descuento en los vuelos por Aerolineas.
 *
 * \param precioAerolineas. Float. Precio del vuelo por Aerolineas.
 * \param pResult. Puntero a Float. donde se guardara el resultado de la operacion.
 *
 * \return Retorna -1 si error o 0 si OK
 */
int calcularCostosTarjetaDebitoAerolineas(float precioAerolineas, float* pResult);

/**
 * \brief Calcula los costos del pago con tarjeta de debito, el cual tiene un 10% de descuento en los vuelos por LATAM.
 *
 * \param precioLatam Float. Float. Precio del vuelo por LATAM.
 * \param pResult Puntero a Float. donde se guardara el resultado de la operacion.
 *
 * \return Retorna -1 si error o 0 si OK
 */
int calcularCostosTarjetaDebitoLatam(float precioLatam, float* pResult);

/**
 * \brief Calcula los costos del pago con tarjeta de credito, el cual tiene un 25% de interes en los vuelos por Aerolineas.
 *
 * \param precioAerolineas Float. Precio del vuelo por Aerolineas.
 * \param pResult Puntero a Float. donde se guardara el resultado de la operacion.
 *
 * \return Retorna -1 si error o 0 si OK
 */
int calcularCostosTarjetaCreditoAerolineas(float precioAerolineas, float* pResult);

/**
 * \brief Calcula los costos del pago con tarjeta de credito, el cual tiene un 25% de interes en los vuelos por LATAM.
 *
 * \param precioLatam Float. Float. Precio del vuelo por LATAM.
 * \param pResult Puntero a Float. donde se guardara el resultado de la operacion.
 *
 * \return Retorna -1 si error o 0 si OK
 */
int calcularCostosTarjetaCreditoLatam(float precioLatam, float* pResult);

/**
 * \brief Calcula los costos del pago en Bitcoin del vuelo por Aerolineas.
 *
 * \param precioAerolineas Float. Precio del vuelo por Aerolineas.
 * \param pResult Puntero a Float. donde se guardara el resultado de la operacion.
 *
 * \return Retorna -1 si error o 0 si OK
 */
int calcularCostosBitcoinAerolineas(float precioAerolineas, double* pResult);

/**
 * \brief Calcula los costos del pago en Bitcoin del vuelo por LATAM.
 *
 * \param precioLatam Float. Precio del vuelo por LATAM.
 * \param pResult Puntero a Float. donde se guardara el resultado de la operacion.
 *
 * \return Retorna -1 si error o 0 si OK
 */
int calcularCostosBitcoinLatam(float precioLatam, double* pResult);

/**
 * \brief Calcula los costos del vuelo por Aerolineas por kilometro.
 *
 * \param precioAerolineas Float. Precio del vuelo por Aerolineas.
 * \param distancia Float. Distancia del vuelo
 * \param pResult Puntero a Float. donde se guardara el resultado de la operacion.
 *
 * \return Retorna -1 si error o 0 si OK
 */
int calcularPrecioPorKM_Aerolineas(float precioAerolineas, float distancia, float* pResult);

/**
 * \brief Calcula los costos del vuelo por LATAM por kilometro.
 *
 * \param precioLatam Float. Precio del vuelo por LATAM.
 * \param distancia Float. Distancia del vuelo
 * \param pResult Puntero a Float. donde se guardara el resultado de la operacion.
 *
 * \return Retorna -1 si error o 0 si OK
 */
int calcularPrecioPorKM_Latam(float precioLatam, float distancia, float* pResult);

/**
 * \brief Calcula la diferencia de precio entre le vuelo por Aerolineas y LATAM.
 *
 * \param precioAerolineas Float. Precio del vuelo por Aerolineas.
 * \param precioLatam Float. Precio del vuelo por LATAM.
 * \param pResult Puntero a Float. donde se guardara el resultado de la operacion.
 *
 * \return Retorna -1 si error o 0 si OK
 */
int calcularDiferenciaDePrecio(float precioAerolineas, float precioLatam, float* pResult);

// ===================================================

/**
 * \brief Funcion maestra que muestra todos los resultados.
 *
 * \param resultadoDebitoAerolineas Resultado obtenido por el descuento por el vuelo por Aerolineas.
 * \param resultadoCreditoAerolineas Resultado obtenido por el interes por el vuelo por Aerolineas.
 * \param resultadoBTC_Aerolineas Resultado obtenido por el pago en Bitcoin en el vuelo por Aerolineas.
 * \param resultadoPrecioUnitarioAerolineas Resultado obtenido por el precio por KM del vuelo por Aerolineas.
 *
 * \param resultadoDebitoLatam Resultado obtenido por el descuento por el vuelo por LATAM.
 * \param resultadoCreditoLatam Resultado obtenido por el interes por el vuelo por Aerolineas.
 * \param resultadoBTC_Latam Resultado obtenido por el pago en Bitcoin en el vuelo por LATAM.
 * \param resultadoPrecioUnitarioLatam Resultado obtenido por el precio por KM del vuelo por Aerolineas.
 *
 * \param diferenciaDePrecio Resultado obtenido por la diferencia de precio entre amas compañias.
 *
 * \param precioAerolineas Precio Base del vuelo por Aerolineas.
 * \param precioLatam Precio Base del vuelo por LATAM.
 * \param distancia Distancia del vuelo.
 *
 * \return Retorna -1 si error o 0 si OK
 */
int mostrarResultados(float resultadoDebitoAerolineas, 	float resultadoCreditoAerolineas,
					  float resultadoBTC_Aerolineas,   	float resultadoPrecioUnitarioAerolineas,
					  float resultadoDebitoLatam, 		float resultadoCreditoLatam,
					  float resultadoBTC_Latam, 		float resultadoPrecioUnitarioLatam,
					  float diferenciaDePrecio, 		float precioAerolineas,
					  float precioLatam, 				float distancia);

/**
 * \brief Muestra los resultados del vuelo por Aerolineas.
 *
 * \param precioAerolineas Precio Base del vuelo por Aerolineas.
 * \param resultDebitoAerolineas Resultado obtenido por el descuento por el vuelo por Aerolineas.
 * \param resultCreditoAerolineas Resultado obtenido por el interes por el vuelo por Aerolineas.
 * \param resultBTC_Aerolineas  Resultado obtenido por el pago en Bitcoin en el vuelo por Aerolineas.
 * \param resultUnitarioAerolineas Resultado obtenido por el precio por KM del vuelo por Aerolineas.
 *
 * \return Retorna -1 si error o 0 si OK
 */
int mostrarResultadosAerolineas(float precioAerolineas, float resultDebitoAerolineas, float resultCreditoAerolineas,
								float resultBTC_Aerolineas,   float resultUnitarioAerolineas);
/**
 * \brief Muestra los resultados del vuelo por LATAM.
 *
 * \param precioLatam Precio Base del vuelo por LATAM.
 * \param resultDebitoLatam Resultado obtenido por el descuento por el vuelo por LATAM.
 * \param resultCreditoLatam Resultado obtenido por el interes por el vuelo por Aerolineas.
 * \param resultBTC_Latam Resultado obtenido por el pago en Bitcoin en el vuelo por LATAM.
 * \param resultUnitarioLatam Resultado obtenido por el precio por KM del vuelo por Aerolineas.
 *
 * \return Retorna -1 si error o 0 si OK
 */
int mostrarResultadosLatam(float precioLatam, float resultDebitoLatam, 	  float resultCreditoLatam,
		  	  	  	  	   float resultBTC_Latam, 	  float resultUnitarioLatam);

#endif /* FUNCIONES_H_ */
