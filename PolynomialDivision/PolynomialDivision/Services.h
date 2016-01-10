#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void _printfNewLine()
{
	printf("\n");
}

float absValue(float number)
{
	if (number >= 0)
	{
		return number;
	}
	else
	{
		return -(number);
	}
}