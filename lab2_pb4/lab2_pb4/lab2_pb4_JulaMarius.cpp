/*
	Author: Jula Marius
	Date: 11/3/18
	Problem: Considering the following recursive formulas (Gauss arithmetical-geometrical media):
					an=(an-1+bn-1)/2 and bn=sqrt(an-1*bn-1),
			determine an and bn for n, a0 and b0 read from the standard input.
*/

#define _CRT_SECURE_NO_WARNINGS	

#include <conio.h>
#include <stdio.h>
#include <math.h>

void call_gauss(int, float, float);

int main()
{
	int n;
	float a0, b0;

	printf("\nEnter the first values of a0 and b0: ");
	scanf("%f%f", &a0, &b0);	
	printf("\nEnter the value of N: ");
	scanf("%d", &n);

	call_gauss(n, a0, b0);
	_getch();
}

//Gauss arithmetical-geometrical media
void call_gauss(int n, float a0, float b0)
{
	if (n == 0)
		printf("\n%.2f - %.2f", a0, b0);
	else
	{
		printf("\n%.2f - %.2f", a0, b0);
		return call_gauss(n - 1, (a0 + b0) / 2, sqrt(a0 * b0));
	}

}