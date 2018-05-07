/*
Author: Jula Marius
Date: 7/5/18
Description: Implement a class that has 2 protected integer variables, that contains a setter and getter
methods for each attributes. Write a second class that inherits the first defined class and
implements the elementary arithmetic operations (+, -, *, /) applied on the variables mentioned
above the results being stored in protect class attributes (plus, minus of int type, mul, div of
double type). Write a third class derived from the second one that implements the methods for
calculating the square root of a number (mul result obtained by the previous derived class)
received as parameter, and for raising a numeric value to a certain power (the base (plus,
result obtained by the previous derived class) and the power (minus, result obtained by the
previous derived class) are sent to the method as parameters). Verify the methods’s calling
using objects at different hierchies levels.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>

using namespace std;

class Base {
protected:
	int a;
	int b;
public:
	Base() { //constructor
		a = 1;
		b = 1;
	}
	~Base() { //destructor
		a = 0;
		b = 0;
	}
	int getA() { //getter
		return a;
	}
	int getB() { //getter
		return b;
	}
	void setA(int a) { //setter
		this->a = a;
	}
	void setB(int b) { //setter
		this->b = b;
	}
	void display() {
		cout << "\na = " << a;
		cout << "\tb = " << b;
	}
};

class Derived1:public Base {
public:
	int sum() { //sum
		return a + b;
	}
	int substract() {//substraction
		return a - b;
	}
	double mul() { //multiply
		return a * b;
	}
	double div() { //divide
		return (double)a / (double)b;
	}
};

class Derived2:public Derived1 {
public:
	//method to compute the square root of a numeric value
	double root(double val) {
		return sqrt(val);
	}
	//method for raising a number to a certain value
	double power(int base, int power) {
		double res = 1.;
		for (int i = 0; i < power; i++)
			res *= base;
		return res;
	}
};

int main() {
	//working w/ the base class
	Base ob_base;
	ob_base.display();
	ob_base.setA(3);
	ob_base.setB(4);
	ob_base.display();
	//working w/ the first derived class
	Derived1 ob_deriv1;
	cout << "\n\tWorking w/ the first derived class";
	ob_deriv1.display(); //will display the implicit val from the constructor of the base class
	ob_deriv1.setA(2);
	ob_deriv1.setB(2);
	ob_deriv1.display();
	cout << "\nThe product is = " << ob_deriv1.mul();
	cout << "\nThe sum is = " << ob_deriv1.sum();
	cout << "\nThe decrease is = " << ob_deriv1.substract();
	cout << "\nThe division is = " << ob_deriv1.div();
	//working w/ the second derived class
	cout << "\n\tWorking w/ the second derived class";
	Derived2 ob_deriv2;
	ob_deriv2.display();
	ob_deriv2.setA(5);
	ob_deriv2.setB(10);
	ob_deriv2.display();
	cout << "\nThe root of "<< ob_deriv1.mul()<<" is " <<ob_deriv2.root(ob_deriv1.mul());
	cout << "\n" << ob_deriv1.sum() << " at the power of " << ob_deriv1.substract() << " is " << ob_deriv2.power(ob_deriv1.sum(), ob_deriv1.substract());
	cin.get();
	cin.ignore();

	return 0;
}