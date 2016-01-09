#pragma once
#include<stdio.h>
#include "PolynomialService.h"
void _printOutPolynomial(float *polynomial, int maxDegree) //just for dividend and divider
{
	for (int i = maxDegree; i >= 0 ; i--)
	{
		printf("%gx^%d", polynomial[i], i);
		if (i != 0)
		{
			printf(" + ");
		}
	}
	printf("\n");
}

void PrintOutResoultPolynomial(float* dividend, float* divider, float* result, int numberTillResoultIsDivided, int maxDegreeOfDividend, int maxDegreeOfDivider, int maxDegreeOfResult)
{
	int lastKnowsValue = FindOutWhatIsHighestDegreeThatCoefficientIsNotZero(dividend, maxDegreeOfDividend);
	
	for (int i = maxDegreeOfResult; i >= numberTillResoultIsDivided; i--)
	{
		printf("%gx^%d +", result[i], i);
	}

	printf("(");
	for (int i = lastKnowsValue; i >= 0; i--)
	{
		printf("%gx^%d +", dividend[i], i);
	}
	printf(") /");

	printf("(");
	for (int i = maxDegreeOfDivider; i >= 0; i--)
	{
		printf("%gx^%d +", divider[i], i);
	}
	printf(")");
	_printfNewLine();
	printf("KRAJ");
}
