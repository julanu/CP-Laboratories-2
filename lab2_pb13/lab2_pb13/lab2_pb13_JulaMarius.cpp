/*
	Author: Jula Marius
	Date: 17/3/18
	Description: Write a program that calculates recursively and non-recursively (two distinct functions)
				the value of the harmonic series sn=1/1+1/2+1/3+…1/n, where n is a natural number. Call
				the functions with 2 different values for n
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

float compute_rec(int);
float compute_it(int);

void main()
{
	int n;
	printf("n="); scanf("%d", &n);
	printf("\nRec: %.2f", compute_rec(n));
	printf("\nRec: %.2f", compute_rec(n + 2));
	printf("\nRec: %.2f", compute_it(n + 3));
	printf("\nRec: %.2f", compute_it(n - 1));

	_getch();
}
float compute_rec(int n)
{
	if (n == 0)
		return 0;
	return compute_rec(n - 1) + 1. / n;
}

float compute_it(int n)
{
	float sum = 0;
	int i;
	for (i = 1; i <= n; i++)
		sum = sum + 1. / i;
	return sum;
}