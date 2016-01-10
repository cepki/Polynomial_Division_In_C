#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Services.h"
#include "MultipyPolynomials.h"
#include "WriteOutPolynomial.h"
#include "SubductPolynoms.h"
#include "PolynomialService.h"

int Divide(float *dividend, int maxDegreeOfDividend, float *divider, int maxDegreeOfDivider, float *result, int maxDegreeOfResult)
{
	int lastKnownMaxDegreeOfDividend = maxDegreeOfDividend;
	maxDegreeOfResult = lastKnownMaxDegreeOfDividend - maxDegreeOfDivider;

	float *tempPolynomial = (float *)malloc(sizeof(float) * (maxDegreeOfDividend + 1));

	for (int i = maxDegreeOfResult; i >= 0; i--)
	{
		result[i] = dividend[lastKnownMaxDegreeOfDividend] / divider[maxDegreeOfDivider];
		//printf("%g\n", result[i]);

		_multipyPolynomials(tempPolynomial, maxDegreeOfDividend + 1, divider, maxDegreeOfDivider, i, result[i]);
		SubductPolynoms(dividend, tempPolynomial, maxDegreeOfDividend);
		lastKnownMaxDegreeOfDividend = FindOutWhatIsHighestDegreeThatCoefficientIsNotZero(dividend, maxDegreeOfDividend);

		if ((lastKnownMaxDegreeOfDividend < maxDegreeOfDivider) || (lastKnownMaxDegreeOfDividend == maxDegreeOfDivider && dividend[lastKnownMaxDegreeOfDividend] < divider[lastKnownMaxDegreeOfDividend]))
		{
			return i;
			//break;
		}
	}

	/*_printfNewLine();

	_printOutPolynomial(result, maxDegreeOfResult);
	_printOutPolynomial(dividend, maxDegreeOfDividend);

	return i;*/
	//printf("%g\n", result[maxDegreeOfResult]);


	//result[maxDegreeOfResult] = dividend[maxDegreeOfDividend] / divider[maxDegreeOfDivider];

	//_multipyPolynomials(tempPolynomial, maxDegreeOfDividend + 1, divider, maxDegreeOfDivider, maxDegreeOfResult, result[maxDegreeOfResult]);

	/*printfNewLine();
	_printfNewLine();
	_printOutPolynomial(tempPolynomial, maxDegreeOfDividend);

	SubductPolynoms(dividend, tempPolynomial, maxDegreeOfDividend);
	_printfNewLine();
	_printfNewLine();
	_printOutPolynomial(dividend, maxDegreeOfDividend);

	_printfNewLine();
	_printfNewLine();

	lastKnownMaxDegreeOfDividend = FindOutWhatIsHighestDegreeThatCoefficientIsNotZero(dividend, maxDegreeOfDividend);

	if ((lastKnownMaxDegreeOfDividend < maxDegreeOfDivider) || (lastKnownMaxDegreeOfDividend == maxDegreeOfDivider && dividend[lastKnownMaxDegreeOfDividend] < divider[lastKnownMaxDegreeOfDividend]))
	{
		printf("gotovo je sad ovo");
	}*/



	/*_printfNewLine();



	maxDegreeOfResult = lastKnownMaxDegree - maxDegreeOfDivider;
	result[maxDegreeOfResult] = dividend[lastKnownMaxDegree] / divider[maxDegreeOfDivider];

	_multipyPolynomials(tempPolynomial, maxDegreeOfDividend + 1, divider, maxDegreeOfDivider, maxDegreeOfResult, result[maxDegreeOfResult]);

	_printfNewLine();
	_printfNewLine();
	_printOutPolynomial(tempPolynomial, maxDegreeOfDividend);

	SubductPolynoms(dividend, tempPolynomial, maxDegreeOfDividend);
	_printfNewLine();
	_printfNewLine();
	_printOutPolynomial(dividend, maxDegreeOfDividend);

	_printfNewLine();
	_printfNewLine();
	lastKnownMaxDegree = FindOutWhatIsHighestDegreeThatCoefficientIsNotZero(dividend, maxDegreeOfDividend);

	if ((lastKnownMaxDegree < maxDegreeOfDivider) || (lastKnownMaxDegree == maxDegreeOfDivider && dividend[lastKnownMaxDegree] < divider[lastKnownMaxDegree]))
	{
		printf("gotovo je sad ovo");
	}*/
}