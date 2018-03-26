/*
	Author: Jula Marius
	Date: 23/3/18
	Description: Read from the keyboard a one dimensional array of maximum 20 integer values. Using the binary search
				mechanism, determine if another value a (also read from the standard input) is part of the array. If so,
				determine and display all its prime factors
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

int binarySearch(int *, int, int, int);
int isPrime(int);

int main()
{
	int *tab, *pt, val, i, n;
	printf("\nEnter how many elements: ");
	scanf("%d", &n);
	//memory allocation
	tab = (int *)malloc(n * sizeof(int));
	pt = &tab[0];

	printf("\nEnter the values of the array");
	for (i = 0; i < n; i++)
		scanf("%d", (pt + i ));

	printf("\nEnter the searched value: ");
	scanf("%d", &val);
	if (binarySearch(pt, 0, n - 1, val))  //look for the value
	{ //looking for the prime factors
		printf("\nThe prime factors of %d are: ", val);
		for (i = 1; i < val / 2; i++) //a/2
			if (val % i == 0 && isPrime(i))
			{
				printf("%d ", i);
			}
	}
	_getch();
}

//binary search implemented recursively
int binarySearch(int *tab, int first, int last, int val)
{
	int middle;
	middle = (first + last) / 2;

	if (tab[middle ] == val)
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
//the function verifies if a number is prime
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