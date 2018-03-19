/*
	Author: Jula Marius
	Date: 19/3/18
	Description: Modify the program that implements the Quick-Sort algorithm so that it will sort 
				decreasingly the initial array of values
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

void readArr(int *, int);
void displayArr(int *, int);
void quick_Sort(int *, int, int);

void main()
{
	int *tab, *pt, n;
	printf("\nPlease enter the length of the array: ");
	scanf("%d", &n);

	tab = (int *)malloc(n * sizeof(int));
	pt = &tab[0];

	readArr(pt, n);
	printf("\nUnsorted array: ");
	displayArr(pt, n);
	quick_Sort(pt, 0, n - 1);
	printf("\nSorted array(decreasing: "); 
	displayArr(pt, n);


	_getch();
}

void displayArr(int *tab, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", tab[i]);
}

void readArr(int *tab, int n)
{
	int i;
	printf("\nPlease enter the arr: \n");
	for (i = 0; i < n; i++)
		scanf("%d", &tab[i]);
}

void quick_Sort(int *tab, int first, int last)
{
	int i, j, pivot, temp;

	i = first;
	j = last;
	pivot = tab[last];
	// partitioning
	do {
		while (tab[i] > pivot) // <  for increasing
			i++;
		while (tab[j] < pivot) // > for increasing
			j--;
		if (i < j)
		{
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
		}
		if (i <= j)
		{
			j--;
			i++;
		}
	} while (i < j);
	
	//recursivity
	if (first < j)
		quick_Sort(tab, first, j);
	if (i < last)
		quick_Sort(tab, i, last);
}