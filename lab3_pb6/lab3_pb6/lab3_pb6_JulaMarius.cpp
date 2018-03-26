/*
	Author: Jula Marius
	Date: 23/3/18
	Description: Write a program that uses the „divide et impera” method for determining the greatest common divider of a
				series of maximum 2000 values stored in an array
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 2000

int gCommonDiv(int, int);
int gCommonDivArr(int *, int, int);

int main()
{
	int tab[MAX], n, i;

	printf("\nEnter num. of el.: ");
	scanf("%d", &n);

	printf("\nPlease start introducing the numbers: \n");
	for (i = 0; i < n; i++)
		scanf("%d", &tab[i]);

	printf("\nThe greatest common divider is: %d", gCommonDivArr(tab, 0, n - 1));
	_getch();
}

//the greatest common divider for two numbers
int gCommonDiv(int a, int b)
{
	if (a == b)
		return a;
	else
		if (a > b)
			return gCommonDiv(a - b, b);
		else
			return gCommonDiv(a, b - a);
}

//the greatest common divider for a uni dimensional table of integer numbers
int gCommonDivArr(int *tab, int first, int last)
{
	int middle;
	if (first - last == 1)
		gCommonDiv(tab[last], tab[first]);
	else
		if (first == last)
			return tab[last];
		else
		{
			middle = (first + last) / 2;
			return gCommonDiv(gCommonDivArr(tab, first, middle), gCommonDivArr(tab, middle + 1, last));
		}
	return -1;
}