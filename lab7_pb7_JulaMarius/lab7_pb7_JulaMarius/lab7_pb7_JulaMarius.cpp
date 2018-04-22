/*
Author: Jula Marius
Date: 22/4/18
Description: Consider a class named Fraction that has two private integer attributes a and b for the
denominator and nominator, two set() and get() methods and a method simplify() that will
simplify the current calling Fraction object and will return as result a Fraction object.
simplify() method will call a private cmmdc() method to simplify the fraction. Define an
explicit constructor without parameters that initializes a with 0 and b with 1. Define another
explicit constructor that receives 2 integer parameters. For this constructor is verified if b!=0
before to be called. Define a method named add_fraction() that returns the object obtained by
adding the current object with the one received as parameter, as a Fraction object. Define in
the same manner the methods that subtract, multiply and divide two fractions. Instantiate two
Fraction objects having the corresponding data read from the keyboard. Display the initial
attributes and the ones obtained after simplifying the fractions. Call the methods that apply the
implemented arithmetical operations and display the results.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Fraction {
	int a;
	int b;
public:
	Fraction();
	Fraction(int, int);
	void setA(int);
	void setB(int);
	int getA();
	int getB();
	Fraction simplify();
	Fraction add_fraction(Fraction);
	Fraction diff_fraction(Fraction);
	Fraction prod_fraction(Fraction);
	Fraction div_fraction(Fraction);
};

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
	else {
		this->a = newA;
		this->b = 1;
	}
}

//Setter for the A attribute
void Fraction::setA(int newA) {
	this->a = newA;
}

//Setter for the B attribute
void Fraction::setB(int newB) {
	this->b = newB;
}

//Getter for the A attribute
int Fraction::getA() {
	return a;
}

//Getter for the B attribute
int Fraction::getB() {
	return b;
}

//CMMMDC
int cmmdc(int a, int b)
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

//Method to simplify a fraction using the cmmmdc function
Fraction Fraction::simplify() {
	int c;
	c = cmmdc(a, b);
	a = a / c;
	b = b / c;
	return *this;
}

//Method to add a fraction
Fraction Fraction::add_fraction(Fraction ob) {
	if (b == ob.getB()) {
		a = a + ob.getA();
	}
	else
	{
		a = a * ob.getB();
		ob.setA(ob.getA() * b);
		b = b * ob.getB();
		a = a + ob.getA();
	}
	return *this;
}

//Method to substract a fraction
Fraction Fraction::diff_fraction(Fraction ob) {
	if (b == ob.getB()) {
		a = a - ob.getA();
		cout << "it's zero \t";
		return *this;
	}
	else
	{
		a = a * ob.getB();
		ob.setA(ob.getA() * b);
		b = b * ob.getB();
		a = a - ob.getA();
		if (a == 0) {
			cout << "it's zero";
			return *this;
		}
	}
	return *this;
}
//Method to divide a fraction
Fraction Fraction::div_fraction(Fraction ob) {
	if (b == ob.getB()) {
		a = a / ob.getA();
		return *this;
	}
	else {
		a = a * ob.getB();
		ob.setA(ob.getA() * b);
		a = a / ob.getA();
	}
	return *this;
}

//Method to multiply a fraction
Fraction Fraction::prod_fraction(Fraction ob) {
		a = a * ob.getA();
		b = b * ob.getB();
	return *this;
}

int main() {
	int num, nom;
	cout << "\nEnter the nominator and numerator for the fraction: ";
	cout << "\nNum"; cin >> num;
	cout << "\nNom"; cin >> nom;
	Fraction ob1(num, nom);
	cout << "\nNon-Simplified obj1: ";
	cout << ob1.getA() << "/" << ob1.getB();
	cout << "\nEnter the nominator and numerator for the second fraction: ";
	cout << "\nNum"; cin >> num;
	cout << "\nNom"; cin >> nom;
	Fraction ob2(num, nom);
	cout << "\nNon-Simplified obj2: ";
	cout << ob2.getA() << "/" << ob2.getB();
	cout << "\n----------";
	ob2 = ob2.simplify();
	cout << "\nSimplified ob2: " << ob2.getA() << "/" << ob2.getB();
	cout << "\nSum: ";
	ob2.add_fraction(ob1);
	cout << ob2.getA() << "/" << ob2.getB();
	ob2.setA(num); ob2.setB(nom);
	cout << "\nDiff: ";
	ob2 = ob2.diff_fraction(ob1);
	cout << ob2.getA() << "/" << ob2.getB();
	ob2.setA(num); ob2.setB(nom);
	cout << "\nDiv: "; 
	ob2 = ob2.div_fraction(ob1);
	cout << ob2.getA() << "/" << ob2.getB();
	ob2.setA(num); ob2.setB(nom);
	cout << "\nProd: ";
	ob2 = ob2.prod_fraction(ob1);
	cout << ob2.getA() << "/" << ob2.getB();

	cin.get();
	cin.ignore();
}