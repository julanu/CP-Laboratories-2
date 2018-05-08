/*
Author: Jula Marius
Date: 7/5/18
Description:Consider the Fraction class that has two protected attributes a and b for the nominator and
denominator and two corresponding setter and getter methods for all attributes. Declare a
public method named simplify() that simplifies a fraction. Define an explicit constructor
without parameters that initializes a with 0 and b with 1 and another explicit constructor with
two integer parameters. For this constructor is verified if b!=0 before to be called.--------//// Overload
the addition, subtraction, multiplication and division operators (+, -, *, /) using member
methods that simplify (if necessary) the obtained results. Define a class named Fraction_ext
that inherits in a public mode the Fraction class and has a parameterized constructor that calls
the constructor from the base class. Use member methods for overloading the preincrementation and
pre-decrementation operators that will add/subtract 1 to the value of a
Fraction_ext instance. Instantiate two Fraction objects without parameters. Set the attributes
using values read from the keyboard. Perform the implemented operations and initialize other
four objects with the obtained results. Simplify the results. Instantiate two objects of
Fraction_ext type with data from the KB. Perform the available operations. Assign the
operation results to other existing Fraction_ext objects. Simplify and display the obtained
results.

*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int gcd(int, int);

class Fraction {
protected:
	int a;
	int b;
public:
	//some getters and setters
	int getA() {
		return a;
	}
	int getB() {
		return b;
	}
	void setA(int a) {
		this->a = a;
	}
	void setB(int b) {
		this->b = b;
	}
	//Constructor  w/o  parameters
	Fraction() {
		this->a = 0;
		this->b = 1;
	}
	//Constructor  w/  parameters
	Fraction(int  newA, int  newB) {
		if (b != 0) {
			this->a = newA;
			this->b = newB;
		}
		else {
			this->a = newA;
			this->b = 1;
		}
	}
	//Method to simplify a fraction
	Fraction simplify() {
		int  c;
		c = gcd(a, b);
		a = a / c;
		b = b / c;
		return  *this;
	}
	//Method to sum two fractions
	friend Fraction operator+(Fraction &f1, Fraction &f2) {
		Fraction f;
		f.setB(gcd(f1.getB(), f2.getB()));
		f.setB((f1.getB() * f2.getB()) / f.getB());
		f.setA(f1.getA() * (f.getB() / f1.getB()) + f2.getB()*(f.getB() / f2.getB()));
		f = f.simplify();
		return f;
	}
	//Method to substract two fractions
	friend Fraction operator-(Fraction &f1, Fraction &f2) {
		Fraction f;
		f.setB(gcd(f1.getB(), f2.getB()));
		f.setB((f1.getB() * f2.getB()) / f.getB());
		f.setA(f1.getA() * (f.getB() / f1.getB()) - f2.getB()*(f.getB() / f2.getB()));
		f = f.simplify();
		return f;
	}
	//Method to multiply two fractions
	friend Fraction operator*(Fraction &f1, Fraction &f2) {
		Fraction f;
		f.setA(f1.getA() * f2.getA());
		f.setB(f1.getB() * f2.getB());
		f = f.simplify();
		return f;
	}
	//Method to divide two fractions
	friend Fraction operator/(Fraction &f1, Fraction &f2) {
		Fraction f;
		f.setA(f1.getA() * f2.getB());
		f.setB(f1.getB() * f2.getA());
		f = f.simplify();
		return f;
	}
};

class Fraction_ext : public Fraction {
	Fraction_ext(int a, int b) : Fraction(int a, int b) {
		cout << "\nMessage from the derived constructor";
	}
};

int main() {



	cin.get();
	cin.ignore();

	return 0;
}

//greatest common divider
int  gcd(int  a, int  b)
{
	int  t;
	while (b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return  a;
}