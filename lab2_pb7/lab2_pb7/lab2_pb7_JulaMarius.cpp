/*
	Author: Jula Marius
	Date: 11/3/18
	Problem: Calculate the sum of the even numbers from an array of integer values, using a recursive
			function. The numbers from the array are read from a file. The first value in the array
			represents the array’s length.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX 50 

int sum_array(int *tab, int n);

void main()
{
	FILE *f;
	char fileName[20];
	int n, tab[MAX], i;
	printf("Enter the name of the file: ");
	scanf("%s", fileName);

	f = fopen(fileName, "r");
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
		if (tab[n - 1] % 2 == 0)
			return sum_array(tab, n - 1) + tab[n - 1];
		else
			return sum_array(tab, n - 1);
}