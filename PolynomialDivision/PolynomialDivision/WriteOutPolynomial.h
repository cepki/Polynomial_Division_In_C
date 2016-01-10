#pragma once
#include<stdio.h>
#include "PolynomialService.h"
void PrintOutPolynomial(float *polynomial, int maxDegreeOfPolynomial) //not appropriate for result
{
	for (int i = maxDegreeOfPolynomial; i >= 0 ; i--)
	{
		if (i == maxDegreeOfPolynomial)
		{
			printf("%gx^%d ", polynomial[i], i);
		}
		else if (i == 0)
		{
			if (polynomial[0] > 0)
			{
				printf(" + %g", polynomial[0]);
			}
			else if (polynomial[0] != 0)
			{
				printf(" - %g", -(polynomial[0]));
			}
		}
		else if (polynomial[i] > 0) 
		{
			printf(" + %gx^%d", polynomial[i], i);
		}
		else if (polynomial[i] != 0)
		{
			printf(" - %gx^%d", -(polynomial[i]), i);
		}
	}
	printf("\n");
}

void PrintOutResoultPolynomial(float* dividend, float* divider, float* result, int numberTillResoultIsDivided, int maxDegreeOfDividend, int maxDegreeOfDivider, int maxDegreeOfResult)
{
	int lastKnowsValue = FindOutWhatIsHighestDegreeThatCoefficientIsNotZero(dividend, maxDegreeOfDividend);
	
	for (int i = maxDegreeOfResult; i >= numberTillResoultIsDivided; i--)
	{
		if (i == maxDegreeOfResult)
		{
			printf("%gx^%d ", result[i], i);
		}
		else if (i == 0)
		{
			if (result[0] > 0)
			{
				printf(" + %g", result[0]);
			}
			else if (result[0] != 0)
			{
				printf(" - %g", -(result[0]));
			}
		}
		else if (result[i] >= 0)
		{
			printf(" + %gx^%d", result[i], i);
		}
		else if (result[i] != 0)
		{
			printf(" - %gx^%d", -(result[i]), i);
		}
	}


	printf(" + [ ");
	printf(" (");
	for (int i = lastKnowsValue; i >= 0; i--)
	{
		if (i == lastKnowsValue)
		{
			if (i == 0)
			{
				printf("%g ", dividend[i]);
			}
			else
			{
				printf("%gx^%d ", dividend[i], i);
			}
			
		}
		else if (i == 0)
		{
			if (dividend[0] > 0)
			{
				printf(" + %g", dividend[0]);
			}
			else if (dividend[0] != 0)
			{
				printf(" - %g", -(dividend[0]));
			}
		}
		else if (dividend[i] >= 0)
		{
			printf(" + %gx^%d", dividend[i], i);
		}
		else if (dividend[i] != 0)
		{
			printf(" - %gx^%d", -(dividend[i]), i);
		}
	}
	printf(") / ");

	printf("(");
	for (int i = maxDegreeOfDivider; i >= 0; i--)
	{
		if (i == maxDegreeOfDivider)
		{
			if (i == 0)
			{
				printf("%g ", divider[i]);
			}
			else
			{
				printf("%gx^%d ", divider[i], i);
			}
		}
		else if (i == 0)
		{
			if (divider[0] > 0)
			{
				printf(" + %g", divider[0]);
			}
			else if (divider[0] != 0)
			{
				printf(" - %g", -(divider[0]));
			}
		}
		else if (divider[i] >= 0)
		{
			printf(" + %gx^%d", divider[i], i);
		}
		else if (divider[i] != 0)
		{
			printf(" - %gx^%d", -(divider[i]), i);
		}
	}
	printf(")");
	printf(" ]");
	_printfNewLine();
}
