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

		_multipyPolynomials(tempPolynomial, maxDegreeOfDividend + 1, divider, maxDegreeOfDivider, i, result[i]);
		SubductPolynoms(dividend, tempPolynomial, maxDegreeOfDividend);
		lastKnownMaxDegreeOfDividend = FindOutWhatIsHighestDegreeThatCoefficientIsNotZero(dividend, maxDegreeOfDividend);

		if ((lastKnownMaxDegreeOfDividend < maxDegreeOfDivider) || (lastKnownMaxDegreeOfDividend == maxDegreeOfDivider && absValue(dividend[lastKnownMaxDegreeOfDividend]) < absValue(divider[maxDegreeOfDivider])))
		{
			return i;
		}
	}	
}