/*
Author: Jula Marius
Date:22/4/18
Description: Define a class called Complex that stores the double variables real, imag and a pointer of
character type that holds the name of the complex number. Define an explicit constructor with
2 parameters that have 1.0 as implicit value. The constructor also initializes the pointer with a
7 characters wide memory zone. Define a copy constructor for this class. Implement the
mutator/setter and accessor/getter methods for each variable stored inside the class. All the
operations related to the complex numbers are also emulated using some specific methods. An
explicit destructor method is also part of the class. Define an array of 10 complex numbers.
Determine the sum of all the numbers in this array and use this value for initializing a new
instance of the class named complex_sum. Repeat this action for all the rest of the operations
implemented inside the class
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Complex {
	float real;
	float imag;
	char *name;
public:
	Complex(float, float);
	float getReal();
	float getImag();
	void setReal(float);
	void setImag(float);
	void setName(char *);
	char* getName();
};

//Constructor w/ implicit parameters
Complex::Complex(float newReal = 1.0, float newImag = 1.0) {
	this->real = newReal;
	this->real = newImag;
	name = new char[7];
	strcpy(name, "test");
}

//Destructor 
//Getter for the real part
float Complex::getReal(){
	return real;
}

//Getter for the imaginary part
float Complex::getImag() {
	return imag;
}

//Setter for the real part
void Complex::setReal(float newReal) {
	this->real = newReal;
}

//Setter for the imaginary part
void Complex::setImag(float newImag) {
	this->imag = newImag;
}

//Setter for the name
void Complex::setName(char *newName) {
	strcpy(this->name, newName);
}

//Getter for the name
char* Complex::getName() {
	return name;
}

//complex ob; ob = ob.ad_complex(ob[i])
void sumC(Complex b) {
	this->real += b.real;
	this->imag += b.imag;
}

int main() {
	Complex c1;


	cin.ignore();
	cin.get();
}