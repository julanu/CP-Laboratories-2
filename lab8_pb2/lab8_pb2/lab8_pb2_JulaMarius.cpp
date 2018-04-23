/*
Author: Jula Marius
Date: 23/4/18
Description: Write a C++ application in which the class Calculator has a private attribute called RAM_memory (int)
and a friend function named service_technician() that can modify the attribute’s value. The friend function
will be member in the class Motherboard, that encapsulates the processor_type variable (string of
characters). Write the code that allows the modifying of the processor_type’s value and the RAM_memory
from the friend function.
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 30

#include <iostream>
using namespace std;

class Motherboard;

class Calculator {
	int RAM_memory;
public:
	Calculator();
	int getRAM();
	friend void service_tehnician(Calculator&, int, Motherboard, char *);
};

//Constructor
Calculator::Calculator() {
	RAM_memory = 10;
}

//Getter
int Calculator::getRAM() {
	return RAM_memory;
}

//-----------------

class Motherboard {
	char *processor_type;
public:
	Motherboard();
	char* getCPU();
	friend void service_tehnician(Calculator&, int, Motherboard, char *);
};

//Constructor
Motherboard::Motherboard() {
	processor_type = new char[30];
	strcpy(processor_type, "i9800k");
}

//Getter
char* Motherboard::getCPU() {
	return processor_type;
}

//Method to modify the attribute
void service_tehnician(Calculator &y, int newRAM, Motherboard x, char *newProcessor) {
	y.RAM_memory = newRAM;
	strcpy(x.processor_type, newProcessor);
}



int main()
{
	Calculator ob;
	Motherboard ob2;
	//the attributes with the implicit values
	cout << "RAM: " << ob.getRAM() << endl;
	cout << "CPU: " << ob2.getCPU();
	int RAM;
	char *cpu;
	cpu = new char[MAX];
	cout << "\nInsert the new amount of RAM:"; cin >> RAM;
	cout << "Insert the new CPU: "; cin >> cpu;
	service_tehnician(ob, RAM, ob2, cpu);
	//attributes with the values modified
	cout << "RAM: " << ob.getRAM() << endl;
	cout << "CPU: " <<  ob2.getCPU();
	cin.get();
	cin.ignore();
}
