/*
	Author: Jula Marius
	Date: 19/3/18
	Description: Write a C/C++ application that reads from the keyboard 2 arrays of positive numbers. The program determines
				 a 3-rd array that contains all the elements in the initial arrays, increasingly ordered. The elements that have the
				same value must appear a single time in the ordered array.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

void displayArr(int *, int);
void readArr(int *, int);
void quick_Sort(int *, int, int);
void merge(int *, int, int *, int, int *);
void rmdup(int *, int);

void main()
{
	int *arr1, *arr2, *pt1, *pt2, *arrFinal, *pF, n, m, l;
	printf("\nLength of the first array: ");
	scanf("%d", &n);
	arr1 = (int *)malloc(n * sizeof(int));
	pt1 = &arr1[0];
	readArr(pt1, n);

	printf("\nLength of the second array: ");
	scanf("%d", &m);
	arr2 = (int *)malloc(m * sizeof(int));
	pt2 = &arr2[0];
	readArr(pt2, m);

	l = n + m;//size of the third

	arrFinal = (int *)malloc(l * sizeof(int));
	pF = &arrFinal[0];
	//sorting the first two
	quick_Sort(pt1, 0, n - 1); displayArr(pt1, n); printf("\n");
	quick_Sort(pt2, 0, m - 1); displayArr(pt2, m); printf("\n");
	//here also
	merge(pt1, n, pt2, m, pF);
	displayArr(pF, l);
	//problema e aici cate elem raman ^ up 
	rmdup(pF, l);
	//alsso here
	printf("\nFinal array: ");
	displayArr(pF, l);

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

void rmdup(int *array, int length)
{
	int *current, *end = array + length - 1;

	for (current = array + 1; array < end; array++, current = array + 1)
	{
		while (current <= end)
		{
			if (*current == *array)
			{
				*current = *end--;
			}
			else
			{
				current++;
			}
		}
	}
}

void merge(int *tab, int n, int *tab1, int m, int *third)
{
	//function to merge 2 arrays

	int ind1, ind2, count;
	ind1 = ind2 = count = 0;

	while (ind1 < n && ind2 < m) // !! <=
		if (tab[ind1] <= tab1[ind2])
		{
			third[count++] = tab[ind1];
			ind1++;
		}
		else
		{
			third[count++] = tab1[ind2];
			ind2++;
		}
	while (ind1 < n) //overflow !! <=
	{
		third[count++] = tab[ind1];
		ind1++;
	}
	while (ind2 < m) //overflow  !! <= 
	{
		tab[count++] = tab1[ind2];
		ind2++;
	}
}

void quick_Sort(int *tab, int first, int last)
{
	int i, j, pivot, temp;

	i = first;
	j = last;
	pivot = tab[last];
	// partitioning
	do {
		while (tab[i] < pivot) // <  for increasing
			i++;
		while (tab[j] > pivot) // > for increasing
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