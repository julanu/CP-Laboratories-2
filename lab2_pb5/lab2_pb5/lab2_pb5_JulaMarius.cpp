/*
	Date: 11/3/18
	Author: Jula Marius
	Problem: Read a string of caracters from the keyboard, one character at a time, using a character
			 function (_getche()). Reverse the string using a recursive function
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>
void reverse_str(char *, int);

void main()
{
	char test[40];
	int i, n;
	printf("\nThe number of chars you want to enter: ");
	scanf("%d", &n);
	printf("\nEnter the chars: ");
	for (i = 0; i < n; i++)
		_getche();


	reverse_str(test, n);

	_getch();
}

void reverse_str(char *test, int n)
{
	if (n == 0)
		printf("\nNothing to reverse");
	else
	{
		return reverse_str(test, n - 1);
		printf("%c", test[n - 1]);
	}
}