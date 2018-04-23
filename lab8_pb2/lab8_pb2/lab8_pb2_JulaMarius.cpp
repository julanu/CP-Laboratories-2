/*
Author: Jula Marius
Date: 23/4/18
Description:Write a C++ application in which the class Calculator has a private attribute called RAM_memory (int)
and a friend function named service_technician() that can modify the attribute’s value. The friend function
will be member in the class Motherboard, that encapsulates the processor_type variable (string of
characters). Write the code that allows the modifying of the processor_type’s value and the RAM_memory
from the friend function.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Calculator {
	int RAM_memory;
public:
	friend void service_tehnician(int);
};

class Motherboard {
	char *processor_type;
public:

};