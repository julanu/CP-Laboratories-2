/*
	Author: Jula Marius
	Date: 11/3/18
	Problem:  greatest common divisor
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

int cmmdc(int, int);

void main()
{
	int a, b;
	printf("\nPlease enter the two numbers: ");
	scanf("%d%d", &a, &b);
	printf("\nThe greatest common divisor is: %d", cmmdc(a, b));
	_getch();
}
 
//greatest common divisor calculated recursively
int cmmdc(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (b > a)
		return cmmdc(a, b % a);

	return cmmdc(b, a % b);
}