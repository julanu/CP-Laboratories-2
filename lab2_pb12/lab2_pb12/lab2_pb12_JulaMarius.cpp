/*
	Author: Jula Marius
	Date: 17/3/18
	Description: Consider the 2-nd degree equation x2 –sx +p=0. Without calculating the solutions x1 and
				x2 deternine Sn = x1n + x2n using this sum’s recursive definition: Sum(n) ={ 2, if n=0; s, if
				n=1; s*Sum(n-1) – p*Sum(n-2), if n>1; }. s and p are float values, n is an integer value

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

float compute(float, float, int);

void main()
{
	float s, p;
	int n;

	printf("\nPlease enter the values of s and p: ");
	scanf("%f%f", &p, &s);
	printf("\nPlease enter the value of n: ");
	scanf("%d", &n);
	//questioning the result
	printf("\nThe result is: %.2f", compute(s, p, n));

	_getch();
}

float compute(float s, float p, int n)
{
	if (n == 0)
		return 2;
	if (n == 2)
		return s;
	else
		if (n > 1)
			return s * compute(s, p, n - 1) - p * compute(s, p, n - 2);

}