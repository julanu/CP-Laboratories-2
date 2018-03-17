/*
Date: 5/03/2018
Author: Jula Marius
Problem:  program that performs a simple coding operation by increasing with 3 the value of the ASCII code of a
		character using macro functions. example A becomes C
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

#define modify_code(a,val)  ((a)+val)

#define modify 2  

void  main(void) {
	int  val = modify;
	char c;

	printf("\nEnter a char: ");
	scanf("%c", &c);

	printf("\nThe character %c becomes %c", c, modify_code(c, val));
	_getch();
}