/*
Author: Jula Marius
Date: 3/5/18
Description:Write a program that implements the simple function int myFunction(...) that returns either the value of the
received parameter or the product of all the values sent to the function. The criteria that controls the
functioning way of the method is the number of received parameters.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdarg.h>
using namespace std;

int myFunction(int, ...);

int main() {
	cout << "\nFirst res of myFunction(2, 3, 4, 5): " << myFunction(3, 3, 4, 5);
	cout << "\nmyFunction(1, 2): " << myFunction(1, 2);
	cout << "\nmyFunction(0,3,4): " << myFunction(2, 3, 4);
	cin.get(); cin.ignore();
	return 0;
}

int myFunction(int num, ...) {
	va_list valist;

	int prod = 1, i;
	//init
	va_start(valist, num);
	//computing
	for (i = 0; i < num; i++)
		prod *= va_arg(valist, int);
	//clean the memory
	va_end(valist);

	return prod;
}