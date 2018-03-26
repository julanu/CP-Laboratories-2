/*
	Author: Jula Marius
	Date: 23/3/18
	Description: Write a C/C++ application that generates 10 integer random values and stores them in an array. 
				Check if another randomly generated value belongs to this array, using _lsearch() function
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

void displayArr(int *, int);
int comp(int *, int *);
int checkAndAdd(int *, int *, int);

void main()
{
	int *p, *key, val, n, i;
	n = 10; //the number of elements
	p = (int*)malloc(11 * sizeof(int)); //memory allocation of 11 for the new element(if needed)

	if (p != NULL) //check if the allocation is sucessfull
	{
		//we set the seed
		srand((unsigned)time(NULL));
		//we start to generate the values
		for (i = 0; i < n; i++)
			*(p + i) = rand();
		printf("\nNew arr:");
		displayArr(p, n);
		//generating the next random value
		val = rand();
		key = &val;
		printf("\nThe number we look for: %d", val);
		if (checkAndAdd(key, p, n))
			printf("\n%d Already exists", *key);
		else {
			n++; //if we have to add the number
			printf("\nAdded %d", *key);

			printf("\nUpdated arr:");
			displayArr(p, n);
			printf("\n");
		}
	}
	else
	{
		printf("\nError");
		_getch();
	}
	if (p)
		free(p);

	_getch();

}

//function to compare two nums
int comp(int *a, int *b)
{
	return (*a - *b);
}

//function to display a uni dimensional table of elements
void displayArr(int *tab, int n)
{
	int i;
	printf("\n");
	for (i = 0; i < n; i++)
		printf("%d ", tab[i]);
}

//function in which we use lsearch with our keys
int checkAndAdd(int *key, int *p, int n)
{
	int m = n;
	_lsearch(key, p, (size_t*)& n, sizeof(int), (int(*)(const void*, const void*))comp);
	return (n == m);
}

