#pragma once
void SubductPolynoms(float *divider, float *tempPolynomial, int maxDegreeOfDividendPloynomial)
{
	for (int i= 0; i <= maxDegreeOfDividendPloynomial; i++)
	{
		divider[i] -= tempPolynomial[i];
	}
}