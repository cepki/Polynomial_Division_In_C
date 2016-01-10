#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Testing.h"
#include "ReadingPolynoms.h"
#include "WriteOutPolynomial.h"
#include "DivideAlgoritham.h"

int main()
{
	float *dividend = NULL;
	int maxDegreeOfDividend = 0;
	float *divider = NULL;
	int maxDegreeOdDivider = 0;
	float *result = NULL;
	int maxDegreeOfResult;

	maxDegreeOfDividend = _readMaxDegree(true);
	maxDegreeOdDivider = _readMaxDegree(false);


	dividend = (float *)malloc(sizeof(float) * (maxDegreeOfDividend + 1));
	divider = (float *)malloc(sizeof(float) * (maxDegreeOdDivider + 1));

	maxDegreeOfDividend = _readPolynom(dividend, true, maxDegreeOfDividend);
	maxDegreeOdDivider = _readPolynom(divider, false, maxDegreeOdDivider);

	system("cls");

	printf("Dividend\n");
	PrintOutPolynomial(dividend, maxDegreeOfDividend);
	printf("Divider\n");
	PrintOutPolynomial(divider, maxDegreeOdDivider);

	maxDegreeOfResult = maxDegreeOfDividend - maxDegreeOdDivider;
	result = (float *)malloc(sizeof(int) * (maxDegreeOfResult + 1));
	
	int broj = Divide(dividend, maxDegreeOfDividend, divider, maxDegreeOdDivider, result, maxDegreeOfResult);

	printf("Result\n");
	PrintOutResoultPolynomial(dividend, divider, result, broj, maxDegreeOfDividend, maxDegreeOdDivider, maxDegreeOfResult);

}