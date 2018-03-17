/*
	Date: 13/3/2018
	Author: Jula Marius
	Problem: arrangements n by k
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

int aran(int, int);
int aran2(int, int);
int fact(int);

void main()	
{
	int n, k;
	
	printf("\nPlease enter N and K: ");
	scanf("%d%d", &n, &k);
	printf("\nResult A: %d", aran(n, k));
	printf("\nResult A2: %d", aran2(n, k));

	_getch();
}

//arrangements of N and K
int aran(int n, int k)
{
	if (k == 1)
		return n;
	else
		return (n * aran(n - 1, k - 1));
}

//arrangements of N and K calculated using the factorial method
int aran2(int n, int k)
{
	if (k == 1)
		return n;
	else
		return (fact(n) / fact(n - k));
}

//factorial of N
int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return (n * fact(n - 1));
}