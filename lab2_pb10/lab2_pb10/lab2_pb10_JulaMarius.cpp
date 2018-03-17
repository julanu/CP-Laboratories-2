/*
	Author: Jula Marius
	Date: 17/3/18
	Description: Consider an array of n (<=30) integer values. Determine (recursively and nonrecursively) the number 
				of times a certain value x read from the keyboard appears in the array
*/

#define _CRT_SECURE_NO_WARNINGS

#define MAX 30

#include <stdio.h>
#include <conio.h>

int find_val_it(int *, int, int);
int find_val_rec(int *, int, int);

void main()
{
	int i, n, val, tab[MAX];
	printf("\nPlease enter the dimension(n <= 30): ");
	scanf("%d", &n);

	printf("\nPlease enter the values of the array: ");
	for (i = 0; i < n; i++)
		scanf("%d", &tab[i]);

	printf("\nPlease enter the value you want to find: ");
	scanf("%d", &val);

	printf("\nIterative: %d", find_val_it(tab, n, val));
	printf("\nRecursive: %d", find_val_rec(tab, n, val));

	_getch();
}

int find_val_it(int *tab, int n, int val)
{
	int count, i;
	count = 0;
	for (i = 0; i < n; i++)
		if (tab[i] == val)
			count++;
	return count;
}


int find_val_rec(int *tab, int n, int val)
{
	if (n == 0)
		return 0;
	else
		if (tab[n - 1] == val)
			return find_val_rec(tab, n - 1, val) + 1;
		else
			return find_val_rec(tab, n - 1, val);
}