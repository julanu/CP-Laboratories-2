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
	~Complex();
	float getReal();
	float getImag();
	void setReal(float);
	void setImag(float);
	void setName(char *);
	char* getName();
	void sumC(Complex);
	void diffC(Complex);
	void divC(Complex);
	void prodC(Complex);
};

//Constructor w/ implicit parameters
Complex::Complex(float newReal = 1.0, float newImag = 1.0) {
	this->real = newReal;
	this->imag = newImag;
	name = new char[7];
	strcpy(name, "test");
}

//Destructor 
Complex::~Complex() {
	real = 0.0;
	imag = 0.0;
	delete[] name;
}
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
	imag = newImag;
}

//Setter for the name
void Complex::setName(char *newName) {
	strcpy(this->name, newName);
}

//Getter for the name
char* Complex::getName() {
	return name;
}

//complex ob; ob = ob.ad_complex(ob[i]) Sum for a complex number
void Complex::sumC(Complex b) {
	real += b.getReal();
	imag += b.getImag();
}

//Difference for a complex number
void Complex::diffC(Complex b) {
	real -= b.getReal();
	imag -= b.getImag();
}

//Product for a complex number
void Complex::prodC(Complex b) {
	real *= b.getReal();
	imag *= b.getImag();
}

//Division for a complex number
void Complex::divC(Complex b) {
	real /= b.getReal();
	imag /= b.getImag();
}
int main() {
	Complex *c1;
	c1 = new Complex[10];
	for (int i = 0; i < 10; i++){
		c1[i].setImag((float)i + 1.0);
		c1[i].setReal((float)i + 0.5);
	}
	Complex complex_sum; // sum of the complex numbers
	for (int i = 0; i < 10; i++) {
		complex_sum.sumC(c1[i].getReal());
	}
	cout << "\nSum real: " << complex_sum.getReal();
	cout << "\nSum imag: " << complex_sum.getImag();
	complex_sum.~Complex();
	Complex complex_diff; // difference
	for (int i = 0; i < 10; i++) {
		complex_diff.diffC(c1[i].getReal());
	}
	cout << "\nDiff real: " << complex_diff.getReal();
	cout << "\nDiff simag: " << complex_diff.getImag();
	complex_diff.~Complex();
	Complex complex_prod; //product
	for (int i = 0; i < 10; i++) {
		complex_prod.prodC(c1[i].getReal());
	}
	cout << "\nProd real: " << complex_prod.getReal();
	cout << "\nProd imag: " << complex_prod.getImag();
	complex_prod.~Complex();
	Complex complex_div; // division
	for (int i = 0; i < 10; i++) {
		complex_div.divC(c1[i].getReal());
	}
	cout << "\nDiv real: " << complex_div.getReal();
	cout << "\nDiv imag: " << complex_div.getImag();
	complex_div.~Complex();

	cin.get();
	cin.ignore();
}