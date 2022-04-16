/*
 * calculadora.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Nicolas
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

/**
* \brief Funcion que realiza la operacion de la suma
* \param pResult Puntero. Sera donde se guarde el resultado obtenido.
* \param num1. Flotante. Primer operando.
* \param num2. Flotante. Segundo operando.
*
* \return Devuelve -1 si error, 0 si OK.
*
*/
int suma(float* pResult, float num1, float num2);

/**
* \brief Funcion que realiza la operacion de la resta
* \param pResult Puntero. Sera donde se guarde el resultado obtenido.
* \param num1. Flotante. Primer operando.
* \param num2. Flotante. Segundo operando.
*
* \return Devuelve -1 si error, 0 si OK.
*
*/
int resta(float* pResult, float num1, float num2);

/**
* \brief Funcion que realiza la operacion de la multiplicacion.
* \param pResult Puntero. Sera donde se guarde el resultado obtenido.
* \param num1. Flotante. Primer operando.
* \param num2. Flotante. Segundo operando.
*
* \return Devuelve -1 si error, 0 si OK.
*
*/
int multiplicacion(double* pResult, float num1, float num2);

/**
* \brief Funcion que realiza la operacion de la division.
* \param pResult Puntero. Sera donde se guarde el resultado obtenido.
* \param num1. Flotante. Primer operando.
* \param num2. Flotante. Segundo operando.
*
* \return Devuelve -1 si error, 0 si OK, 1 si segundo operando es igual a 0.
*
*/
int division(float* pResult, float num1, float num2);

/**
* \brief Funcion que realiza la operacion de la division pero con retorno en double.
* \param pResult Puntero. Sera donde se guarde el resultado obtenido.
* \param num1. Flotante. Primer operando.
* \param num2. Flotante. Segundo operando.
*
* \return Devuelve -1 si error, 0 si OK, 1 si segundo operando es igual a 0.
*
*/
int divisionDouble(double* pResult, float num1, float num2);

/**
 * \brief Funcion que realiza el calculo de un porcentaje.
 *
 * \param pResult Puntero a float. Donde se guardara el resultado obtneido.
 * \param num numero al que se le va a sacar el porcentaje.
 * \param multi valor del porcentaje.
 * \param div valor por el que se divide el porcentaje.
 *
 * \return Devuelve -1 si error, 0 si OK.
 */
int porcentaje(float* pResult, float num, float multi, float div);

#endif /* CALCULADORA_H_ */
