/*
	Author: Jula Marius
	Date: 19/3/18
	Description: implement the Bubble-Sort method using a flag indicator and optimize the inner loop.
				Write the function that orders an array of integer values read from the keyboard. 
				Display the original and the sorted arrays.
*/	

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

void readArr(int *, int);
void displayArr(int *, int);
void SortBubble(int *, int);

void main()
{
	int *tab, *pt, n;

	printf("\nLength of the array: ");
	scanf("%d", &n);

	tab = (int *)malloc(n * sizeof(int));
	pt = &tab[0];

	readArr(pt, n);
	printf("\nUnsorted array: "); displayArr(pt, n);
	SortBubble(pt, n);
	printf("\nSorted array: "); displayArr(pt, n);


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

void SortBubble(int *tab, int n)
{
	int i, j, aux, flag;

	for (i = 0; i < n; i++)
	{
		flag = 0;
		for (j = 1; j < n - i; j++)
		{
			if (tab[j - 1] > tab[j]) {
				aux = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = aux;
				flag = 1;
			}
		}
		//if the flag was not modified we stop
		if (flag == 0) break;
	}
}