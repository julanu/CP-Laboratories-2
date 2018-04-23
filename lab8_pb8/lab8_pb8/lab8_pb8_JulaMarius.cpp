/*
Author: Jula Marius
Date: 24/4/18
Description: Consider the Fraction class that has two private integer attributes a and b for the denominator and
nominator. Use two setter and getter methods for all the class’s attributes. Declare a friend function named
simplify() that receives as parameter a Fraction object and returns the corresponding simplified object.
Consider a private static integer variable icount that will be initialized with 0 and incremented in the
class’s constructors. Define an explicit constructor without parameters that initializes a with 0 and b with
1 and another explicit constructor with two integer parameters. For this constructor is verified if b!=0
before to be called. Define an explicit destructor that displays and decrements the value of icount. Define a
friend function f_add_fraction(...) that returns an object reflecting the sum of the objects received as
parameters. Implement similar functions for fractions subtraction, multiplication and division. Instantiate
two Fraction objects and read the appropriate data from the keyboard. Display the initial attributes and the
ones obtained after simplifying. Call the implemented friend functions and store the results into another
different four objects. Display the results and the objects counter using the corresponding accesor
methods.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Fraction {
	int a;
	int b;
	static int icount;
public:
	int getA();
	int getB();
	void setA(int);
	void setB(int);
	Fraction();
	~Fraction();
	Fraction(int, int);
	friend Fraction simplify(Fraction);
};

int Fraction::icount = 0;

//Constructor w/o parameters
Fraction::Fraction() {
	this->a = 0;
	this->b = 1;
}

//Constructor w/ parameters
Fraction::Fraction(int newA, int newB) {
	if (b != 0) {
		this->a = newA;
		this->b = newB;
	}
	else
	{
		this->a = newA;
		this->b = 1;
	}
}

//Destructor
Fraction::~Fraction() {
	cout << this->icount;
	icount -= 1;

}

//Getter for the denominator
int Fraction::getA() {
	return this->a;
}

//Getter for the nominator
int Fraction::getB() {
	return this->b;
}

//Setter for the denominator
void Fraction::setA(int newA) {
	this->a = newA;
}

//Setter for the nominator
void Fraction::setB(int newB) {
	this->b = newB;
}

//Method that simplifies a fraction and then returns it
Fraction simplify(Fraction x) {
	int c;
	c = gcd(x.a, x.b);
	x.a = x.a / c;
	x.b = x.b / c;
	return x;
}

//Greatest common divider
int gcd(int a, int b)
{
	int t;
	while (b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}


