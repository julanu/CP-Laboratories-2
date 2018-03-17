/*
	Author: Jula Marius
	Date: 11/3/18
	Problem: combinantions of N and K
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

int comb(int, int);
int comb2(int, int);
int fact(int);

void main()
{
	int n, k;
	printf("\nPlease enter N and K: ");
	scanf("%d%d", &n, &k);
	printf("\nResult C: %d", comb(n, k));
	printf("\nResult C2: %d", comb2(n, k));

	_getch();
}

int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return (n * fact(n - 1));
}

//combinations of N and K
int comb(int n, int k)
{
	if ((k == 0) || (n == k))
		return 1;
	if (k == 1)
		return n;
	return
		(comb(n - 1, k) + comb(n - 1, k - 1));
}

//combinations of N and K using the factorial method
int comb2(int n, int k)
{
	if (k == 1)
		return n;
	return
		(fact(n) / (fact(k) * fact(n - k)));
}