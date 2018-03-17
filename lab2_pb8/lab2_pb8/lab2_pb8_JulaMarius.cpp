/*
	Author: Jula Marius
	Date: 11/3/18
	Problem: Using the code developed for the previous problem, calculate the sum of the prime
			 numbers in the array
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX 50 

int sum_array(int *tab, int n);
int isPrime(int);


void main()
{
	FILE *f;
	int n, tab[MAX], i;
	char fileName[MAX];
	pritnf("Please enter the file name: ");
	scanf("%s", fileName);
	f = fopen(fileName , "r");
	fscanf(f, "%d", &n);

	for (i = 0; i < n; i++)
		fscanf(f, "%d", &tab[i]);

	printf("\nThe result is: %d", sum_array(tab, n));
	fclose(f);

	_getch();
}

int sum_array(int *tab, int n)
{
	if (n == 0)
		return 0;
	else
		if (isPrime(tab[n-1]))
			return sum_array(tab, n - 1) + tab[n - 1];
		else
			return sum_array(tab, n - 1);
}

int isPrime(int n)
{
	int i;
	if (n == 0 || n == 1)
		return 0;
	if (n == 2)
		return 1;
	if (n % 2 == 0)
		return 0;

	for (i = 3; i < n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}