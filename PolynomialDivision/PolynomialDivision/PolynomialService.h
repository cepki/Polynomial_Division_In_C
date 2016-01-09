#pragma once
#include <stdio.h>

int FindOutWhatIsHighestDegreeThatCoefficientIsNotZero(float *polynomialToCheck, int lastKnownMaxDegree)
{
	for (int i = lastKnownMaxDegree; i >= 0; i--)
	{
		if (polynomialToCheck[i] != 0)
		{
			return i;
		}
	}
	return -1;
}