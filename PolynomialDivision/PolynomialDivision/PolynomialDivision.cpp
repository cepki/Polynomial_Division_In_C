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

	/*maxDegreeOfDividend = _readMaxDegree(true);
	maxDegreeOdDivider = _readMaxDegree(false);*/

	maxDegreeOfDividend = 3;
	maxDegreeOdDivider = 1;


	dividend = (float *)malloc(sizeof(float) * (maxDegreeOfDividend + 1));
	divider = (float *)malloc(sizeof(float) * (maxDegreeOdDivider + 1));

	//maxDegreeOfDividend = _readPolynom(dividend, true, maxDegreeOfDividend);
	//maxDegreeOdDivider = _readPolynom(divider, false, maxDegreeOdDivider);

	//dividend[4] = 8;
	dividend[3] = 3;
	dividend[2] = -5;
	dividend[1] = 10;
	dividend[0] = -3;
	
	//divider[2] = 3;
	divider[1] = 3;
	divider[0] = 1;

	/*printf("Dividend\n");
	_printOutPolynomial(dividend, maxDegreeOfDividend);
	printf("Divider\n");
	_printOutPolynomial(divider, maxDegreeOdDivider);*/

	maxDegreeOfResult = maxDegreeOfDividend - maxDegreeOdDivider;
	result = (float *)malloc(sizeof(int) * (maxDegreeOfResult + 1));
	
	int broj = Divide(dividend, maxDegreeOfDividend, divider, maxDegreeOdDivider, result, maxDegreeOfResult);
	printf("%d\n", broj);
	_printfNewLine();
	_printfNewLine();
	_printfNewLine();
	_printfNewLine();

	PrintOutResoultPolynomial(dividend, divider, result, broj, maxDegreeOfDividend, maxDegreeOdDivider, maxDegreeOfResult);

}