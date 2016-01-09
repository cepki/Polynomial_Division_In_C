#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "Services.h"
#include "WriteOutPolynomial.h"

int _readPolynom(float* polynom, bool isDividend, int maxDegreeOfPolynomial) //Dividend - the one who is being divided
{
	_printfNewLine();
	if (isDividend)
	{
		printf("*** DIVIDEND ***");
	}
	else
	{
		printf("*** DIVIDER ***");
	}
	_printfNewLine();

	for (int i = 0; i < maxDegreeOfPolynomial + 1; i++)
	{
		if (isDividend)
		{
			printf("Enter coefficient with x^%d of divident\n", i);
		}
		else
		{
			printf("Enter coefficient with x^%d of divider\n", i);
		}
		scanf(" %f", &polynom[i]);

	}

	return maxDegreeOfPolynomial;
}

int _readMaxDegree(bool isDividend)
{
	int maxDegreeOfPolynomial;
	if (isDividend)
	{
		printf("What is max degree of DIVIDEND?\n");
	}
	else
	{
		printf("What is max degree of DIVIDER?\n");
	}
	scanf(" %d", &maxDegreeOfPolynomial);
	_printfNewLine();
	return maxDegreeOfPolynomial;
}