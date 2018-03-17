/*
	Author: Jula Marius
	Date: 11/3/18
	Problem: determine the scalar product of 2 vectors using a recursive function	
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

float scalar_product(float, float, float, float);

void main()
{
	float a, b, a2, b2;
	printf("\nPlease enter the values for the scalar product(4 nums): ");
	scanf("%f%f%f%f", &a, &b, &a2, &b2);
	printf("\nThe scalar product is: %.2f", scalar_product(a, b, a2, b2));
	_getch();
}

float scalar_product(float a, float b, float a2, float b2)
{
	if ((a <= 0) && (a2 == 0))
		return 0;
	else
		return scalar_product(a - 1, b, a2 - 1, b2) + b + b2;
}