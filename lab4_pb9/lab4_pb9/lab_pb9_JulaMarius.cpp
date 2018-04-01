/*
	Author: Jula Marius
	Date: 1/4/18
	Description: Generate in a random mode maximum 200 smaller than 100 integer numbers and store them into an array.
				Determine and display the minimum, the median and the maximum value and sort the array in order to
				accomplish that. Determine the average value and display the difference between it and the calculated median.
				Check if the average value is part of the initial array.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 200

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int linSearch(int *, int, int);
int cmp(const void *, const void *);
void dispArr(int *, int);

void main(void)
{
	int tab[MAX], n, s, i, avg;
	// avg-average s-sum
	s = 0;
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);

	srand(time(NULL)); //we set the seed
	for (i = 0; i < n; i++)
	{
		int nr; //this will exist only when the loop is executed
		nr = 1 + rand() % 100;
		tab[i] = nr;
		s = s + nr;
	}
	printf("\nThe generated array is: ");
	dispArr(tab, n);
	qsort(tab, n, sizeof(int), cmp); //sorting
	printf("\nSorted array: ");
	dispArr(tab, n);

	avg = s / n;
	printf("\nMin: %d", tab[0]);
	printf("\nMax: %d", tab[n - 1]);
	printf("\nMiddle val: %d", tab[n / 2]);
	printf("\nAvg value: %d", avg);
	printf("\n The diff between middle val and average val: %d", tab[n / 2] - avg);

	if (linSearch(tab, n, avg))
		printf("\nThe value was found");
	else
		printf("\nThe value was not found");

	_getch();
}

//linear search function for a specific value
int linSearch(int *tab, int n, int val)
{
	int i;
	for (i = 0; i < n; i++)
		if (tab[i] == val)
			return 1;
		else
			return 0;
	return 0;
}

//function to compare two integers
int cmp(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

//function to display a uni-dimensional table of integer values
void dispArr(int *tab, int n)
{
	int i;
	printf("\n");
	for (i = 0; i < n; i++)
		printf("%d ", tab[i]);
}