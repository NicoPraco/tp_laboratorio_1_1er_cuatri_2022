/*
 * calculadora.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Nicolas
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "input.h"
#include "funciones.h"
#include "calculadora.h"

int suma(float* pResult, float num1, float num2)
{
	int toReturn = -1;

	if(pResult != NULL)
	{
		*pResult = num1 + num2;

		toReturn = 0;
	}

	return toReturn;
}

int resta(float* pResult, float num1, float num2)
{
	int toReturn = -1;

	if(pResult != NULL)
	{
		*pResult = num1 - num2;

		toReturn = 0;
	}

	return toReturn;
}

int multiplicacion(double* pResult, float num1, float num2)
{
	int toReturn = -1;

	if(pResult != NULL)
	{
		*pResult = (double)num1 * num2;

		toReturn = 0;
	}

	return toReturn;
}

int division(float* pResult, float num1, float num2)
{
	int toReturn = -1;

	if(pResult != NULL)
	{
		if(num2 == 0)
		{
			toReturn = 1;
		}
		else
		{
			*pResult = num1 / num2;

			toReturn = 0;
		}

	}

	return toReturn;
}

int divisionDouble(double* pResult, float num1, float num2)
{
	int toReturn = -1;

	if(pResult != NULL)
	{
		if(num2 == 0)
		{
			toReturn = 1;
		}
		else
		{
			*pResult = num1 / num2;

			toReturn = 0;
		}

	}

	return toReturn;
}

int porcentaje(float* pResult, float num, float multi, float div)
{
	int toReturn = -1;

	if(pResult != NULL)
	{
		*pResult = num * multi / div;

		toReturn = 0;
	}

	return toReturn;
}
