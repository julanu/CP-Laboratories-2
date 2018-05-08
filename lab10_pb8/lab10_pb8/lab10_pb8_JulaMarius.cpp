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
//prototype for the GCD function
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
		f.setA((f1.getA() * f2.getB()) - (f1.getB() * f2.getA()));
		f.setB(f1.getB() * f2.getB());
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
	//Method to overload the pre incremmentation operator
	friend Fraction operator++(Fraction &f1) {
		f1.setA(f1.getA() + 1);
		f1 = f1.simplify();
		return f1;
	}
	//Method to overload the pre decrementation operator
	friend Fraction operator--(Fraction &f1) {
		f1.setA(f1.getA() - 1);
		f1 = f1.simplify();
		return f1;
	}
};

//Derived class
class Fraction_ext : public Fraction {
public:
	Fraction_ext(int a, int b) : Fraction(a, b) {
		cout << "\nMessage from the derived constructor";
	}
};

int main() {
	int aa, bb;
	Fraction f1, f2;
	cout << "\nf1.a = "; cin >> aa;
	f1.setA(aa);
	cout << "\nf1.b = "; cin >> bb;
	f1.setB(bb);
	cout << "\nf2.a = "; cin >> aa;
	f2.setA(aa);
	cout << "\nf2.b = "; cin >> bb;
	f2.setB(bb);
	cout << "\nFraction 1: " << f1.getA() << "/" << f1.getB();
	cout << "\t\tFraction 2: " << f2.getA() << "/" << f2.getB() << "\n";
	Fraction f11, f12, f13, f14;
	f11 = f1 + f2;
	cout << "\nSum = " << f11.getA() << "/" << f11.getB();
	f12 = f1 - f2;
	cout << "\nDifference = " << f12.getA() << "/" << f12.getB();
	f13 = f1 * f2;
	cout << "\nProduct = " << f13.getA() << "/" << f13.getB();
	f14 = f1 / f2;
	cout << "\nDivision = " << f14.getA() << "/" << f14.getB();

	cout << "\n\nNew fraction:";
	cout << "\na = "; cin >> aa;
	cout << "\nb = "; cin >> bb;
	Fraction_ext ob1(aa, bb);
	cout << "\nSecond fraction";
	cout << "\na = "; cin >> aa;
	cout << "\nb = "; cin >> bb;
	++ob1;
	cout << "\nFraction after using the pre-incrementation operator" << ob1.getA() << "/" << ob1.getB();
	Fraction ob2(aa, bb);
	--ob2;
	cout << "\nFraction after using the pre-decrementation operator" << ob2.getA() << "/" << ob2.getB();

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