/*
 * serializer.h
 *
 *  Created on: 30 may. 2022
 *      Author: Nicolas
 */

#ifndef SERIALIZER_H_
#define SERIALIZER_H_

#include "LinkedList.h"

#define BUFFER_LEN 100

/** \brief Serializa los datos de los empleados al archivo data.csv (modo texto)
 *
 * \param pFile FILE* Puntero al Archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int serializer_PassengerToText(FILE* pFile, LinkedList* pArrayListPassenger);


/** \brief Serializa los datos de los empleados al archivo data2.csv (modo binario)
 *
 * \param pFile FILE* Puntero al Archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int serializer_PassengerToBinary(FILE* pFile, LinkedList* pArrayListPassenger);

#endif /* SERIALIZER_H_ */
