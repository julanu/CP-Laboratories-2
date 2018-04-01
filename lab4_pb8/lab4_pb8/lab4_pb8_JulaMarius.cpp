/*
	Author: Jula Marius
	Date: 30/3/2018
	Description: Read from two files two one dimensional arrays composed of real values. Generate a third array that contains
				all the values from the initial arrays and all the values obtained by calculating the average of the corresponding
				numbers. If the initial arrays have different numbers of values, the average is calculated between the existent
				values and 0.0. Order the last array and count the number of non-unique elements.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#define MAX2 100
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void main(void)
{
	FILE *f, *g;
	char fileName1[MAX], fileName2[MAX];
	int arr[MAX2], arr2[MAX2], arr3[MAX2], i, j;
	i = j = 0;
	printf("\nPlease enter the name of the first file: ");
	scanf("%s", fileName1);
	printf("\nPlease enter the name of the second file: ");
	scanf("%s", fileName2);
	f = fopen(fileName1, "r");
	g = fopen(fileName2, "r");
	//read values from the files and store them in arrays
	while (!feof(f))
	{
		fscanf(f, "%d", &arr[i++]);
	}
	fclose(f);
	while (!feof(g))
	{
		fscanf(g, "%d", &arr2[j++]);
	}


	_getch();
}

void average(int *arr, int *arr2, int *arr3, int i, int j)
{
	
	if (i == j)
	{
		int c;
		for (c = 0; c < i; c++)
			arr3[c] = (arr2[c] + arr[c]) / 2;
	}
	else
		if(i < )
}