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
	friend Fraction f_add_fraction(Fraction, Fraction);
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
	cout << "\nicount = " << this->icount;
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

//Method that simplifies a fraction and then returns it
Fraction simplify(Fraction x) {
	int c;
	c = gcd(x.a, x.b);
	x.a = x.a / c;
	x.b = x.b / c;
	return x;
}

//Method to sum two fractions
Fraction f_add_fraction(Fraction x, Fraction y) {
	Fraction f;
	if (x.b == y.b) {
		f.a = x.a + y.a;
		f.b = x.b;
		return f;
	}
	else
	{
		x.a *= y.b;
		y.a *= x.b;
		f.a = x.a + y.a;
		f.b = x.b * y.b;
		return f;
	}
	return f;
}

//Method to substract two fractions

int main() {
	int a, b;
	cout << "\nEnter the denominator and nominator of the first fraction: ";
	cout << "\na = "; cin >> a;
	cout << "\nb = "; cin >> b;
	Fraction ob1(a, b);
	cout << "\nEnter the denominator and nominator of the second fraction: ";
	cout << "\na = "; cin >> a;
	cout << "\nb = "; cin >> b;
	Fraction ob2(a, b);
	ob1 = simplify(ob1);
	cout << "\nFirst fraction simplified: " << ob1.getA() << "/" << ob1.getB();
	ob2 = simplify(ob2);
	cout << "\nSecond fraction simplified: " << ob2.getA() << "/" << ob2.getB();
	Fraction ob_sum;
	ob_sum = f_add_fraction(ob1, ob2);
	cout << "\nThe sum of the two fractions is: " << ob_sum.getA() << "/" << ob_sum.getB();
	Fraction ob_diff;
	//cout << "\nThe difference of the two fractions is: " << ob_diff.getA() << "/" << ob_dif.getB();
	cin.get(); cin.ignore();
	return 0;
}


