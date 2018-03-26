/*
	Author: Jula Marius
	Date: 24/3/2018
	Description: Using the "divide et impera" programming method, read the integer values generated in a random mode
					previously stored into file. Determine the minimum and maximum values from the array. Update the 
					original file by adding the determined values
*/

#define _CRT_SECURE_NO_WARNINGS

#define MAX 30

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

int findMin(int *, int, int);
int findMax(int *, int, int);

int main()
{
	FILE *f;
	int *tab, *pt, i, n;
	char fileName[MAX];

	printf("\nEnter the name of the file: ");
	scanf("%s", &fileName);

	printf("\nEnter the number of the elements: ");
	scanf("%d", &n);
	//memory allocation
	tab = (int *)malloc(n * sizeof(int));
	pt = &tab[0];

	//generating the random numbers using rand() and writting them in the file
	f = fopen(fileName, "w");
	for (i = 0; i < n; i++)
	{
		int r;
		r = rand();
		fprintf(f, "%d ", r);
	}
	fclose(f);
	f = fopen(fileName, "r"); //open for reading
	for (i = 0; i < n; i++)
		fscanf(f, "%d", (pt + i));
	printf("\nThe maximum value is: %d", findMax(pt, 0, n - 1));
	printf("\nThe minimum value is: %d", findMin(pt, 0, n - 1));
	//we finished processing the data
	fclose(f);
	f = fopen(fileName, "a"); //append to the file the values
	fprintf(f, "\nmax: %d", findMax(pt, 0, n - 1));
	fprintf(f, "\nmin: %d", findMin(pt, 0, n - 1));
	fclose(f);
	_getch();
}

//the function determins the minimum value from the one dim array using the divide et impera method
int findMin(int *tab, int first, int last)
{
	int call, call2, middle;

	if (first == last)
		return tab[first];
	else
	{
		middle = (first + last) / 2;
		call = findMin(tab, first, middle);
		call2 = findMin(tab, middle + 1, last);
		if (call < call2)
			return call;
		else
			return call2;
	}
}

//the function determins the maximum value from the one dim array using the divide et impera method
int findMax(int *tab, int first, int last)
{
	int call, call2, middle;

	if (first == last)
		return tab[first];
	else
	{
		middle = (first + last) / 2;
		call = findMax(tab, first, middle);
		call2 = findMax(tab, middle + 1, last);
		if (call > call2)
			return call;
		else
			return call2;
	}
}
