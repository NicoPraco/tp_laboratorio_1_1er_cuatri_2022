/*
 * menus.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Nicolas
 */

#ifndef MENUS_H_
#define MENUS_H_

/**
 * \brief Funcion que muestra el menu de opciones principal del programa.
 *
 * \param input Entero. Numero con el cual se elije la opcion del menu.
 * \param KM Float. Numero que muestra en el menu principal la distancia del vuelo. Por defecto aparece como -1.
 * \param precioAerolineas Numero que muestra en el menu principal el precio del vuelo por Aerolineas. Por defecto aparece como -1.
 * \param precioLatam Numero que muestra en el menu principal el precio del vuelo por LATAM. Por defecto aparece como -1.
 *
 * \return Retorna -1 si Error o 0 si OK
 */
int menuDeOpcionesPrincipal(int* input, float KM, float precioAerolineas, float precioLatam);

/**
 * \brief Submenu de Opciones para ingresar los precios de los vuelos.
 *
 * \param input Numero con el que se elije la opcion del menu.
 *
 * \return Retorna -1 si Error o 0 si OK
 */
int subMenuDeOpcionesVuelos(int* input);

#endif /* MENUS_H_ */
