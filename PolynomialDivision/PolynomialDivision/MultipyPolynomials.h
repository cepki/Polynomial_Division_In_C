#pragma once
void _multipyPolynomials(float* tempPolynomial, int maxDegreeOfTempPloynomial, float* divider, int degreeOfDivider, int degreeOfResultReacentlyAdded, float coefficient)
{
	for (int i = 0; i <= maxDegreeOfTempPloynomial; i++) //tempPolynomial coefficients = 0
	{
		tempPolynomial[i] = 0.0;
	}

	for (int i = 0; i <= degreeOfDivider; i++)
	{
		tempPolynomial[i + degreeOfResultReacentlyAdded] = divider[i] * coefficient;
	}

}