/*
	Author: Jula Marius
	Date: 17/3/18
	Description: Read from the keyboard an integer value n (base 10). Use a recursive function for
				converting n into another base 1< b<10, also read from the keyboard.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

int change_base(int, int);

void main()
{
	int n, b;
	printf("\nN: ");
	scanf("%d", &n);
	printf("\nB: ");
	scanf("%d", &b);

	printf("\nRes: %d", change_base(n, b));
	_getch();
}

int change_base(int n, int b)
{
	if (n == 0 || b == 10)
		return n;
	else
		return change_base(n / b, b) * 10 + (n % b);
}
