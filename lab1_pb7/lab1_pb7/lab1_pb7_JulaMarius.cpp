/*
	Author: Jula Marius
	Date: 18/3/18
	Description: write a program that display the name of the program, the date and time and the number of lines
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

void main()
{
	printf("\n The name of the program is: %s", _FILE_);
	printf("\n Compiled at the date of: %s, at the time %s ", _DATE_, _TIME_);
	printf("\n The number of lines is: %d", _LINE_);
	_getch();
}