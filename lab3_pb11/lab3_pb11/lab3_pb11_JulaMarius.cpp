/* 
	Author: Dumitras Adelina
	Date: 23/3/18
	Description: Read from the keyboard a one dimensional array of maximum 20 integer values.
				Using the binary search mechanism, determine if another value a (also read from the standard input) 
				is part of the array. If so, determine and display all its prime factors.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int binary(int *, int, int, int);
int binary_it(int *, int, int);
int cmpfunc(const void *, const void *);

int main()
{
	int x[20], a, i, n, *b;
	FILE *f;
	char fileName[50];
	printf("\nEnter the name of the file: ");
	scanf("%s", &fileName);
	f = fopen(fileName, "r");
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(f, "%d", &x[i]);
	printf("\nEnter the searched value: ");
	scanf("%d", &a);
	if (binary(x, 0, n - 1, a))
	{
		printf("\nThe value %d is the array :", a);
		for (i = 0; i < n; i++)
			printf("%d ", x[i]);
	}
	if (binary_it(x, n, a) == 0)
	{
		printf("\nThe value %d is in the array :", a);
		for (i = 0; i < n; i++)
			printf("%d ", x[i]);
	}
	b = (int*)bsearch(&a, x, n, sizeof(int), cmpfunc);  //the bsearch() library function
	if (b != NULL)
		printf("\nFound item = %d\n", *b);
	fclose(f);
	_getch();
}  //main

//binary search implemented recursively
int binarySearch(int *tab, int first, int last, int val)
{
	int middle;
	middle = (first + last) / 2;

	if (tab[middle] == val)
		return middle;

	if (first <= last)
	{
		if (tab[middle] > val)
			last = middle - 1;
		else
			first = middle + 1;
		return binarySearch(tab, first, last, val);
	}
	return -1; //error
}

int binarySearchIt(int *tab, int n, int a)  //iterative binary search
{
	int mij, inf, sup, ind;
	inf = 1; sup = n;
	ind = 0;
	do
	{
		mij = (inf + sup) / 2;
		if (p[mij] == a)
			ind = 1;
		else
			if (p[mij]<a)
				inf = mij + 1;
			else
				sup = mij - 1;
	} while (inf <= sup && ind == 0);
	if (ind == 1)
		return mij;
	else
		return 0;
}  //binaty_it

int cmpfunc(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}  //cmpfunc
