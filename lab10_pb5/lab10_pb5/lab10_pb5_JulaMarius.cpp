/*
Author: Jula Marius
Date: 7/5/18
Description:Extend the second class with a method that can compute the triangle’s height. Call the method
using an adequate object.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
protected:
	double a;
	double b;
	double c;
public:
	Triangle() {
		a = 1.;
		b = 1.;
		c = 1.;
	}
	void setA(double a) {
		this->a = a;
	}
	void setB(double b) {
		this->b = b;
	}
	void setC(double c) {
		this->c = c;
	}
	double calcPerimeter() {
		double res = 0.;
		res = this->a + this->b + this->c;
		return res;
	}
};

class Triangle_extended :public Triangle {
public:
	double calcArea() {
		double p, s;
		p = s = 0.;
		p = (a + b + c) / 2.;
		s = sqrt(p * (p - a)*(p - b)*(p - c));
		return s;
	}
	double calcHeight() {
		if ((a == b) && (b == c))
			return ((a * 1.71) / 2.);
		else {
			if (a == b)
				return (a * b) / c;
			if (a == c)
				return (a * c) / b;
			if (b == c)
				return (b * c) / a;
		}
		return -1;
	}
};

int main() {
	double side1, side2, side3;
	cout << "\nPlease enter the values of the sides";
	cout << "\ns1 = "; cin >> side1;
	cout << "\ns2 = "; cin >> side2;
	cout << "\ns3 = "; cin >> side3;
	Triangle ob_base;
	ob_base.setA(side1);
	ob_base.setB(side2);
	ob_base.setC(side3);
	cout << "\nThe triangle perimeter is: " << ob_base.calcPerimeter();
	Triangle_extended ob_derv;
	ob_derv.setA(side1);
	ob_derv.setB(side2);
	ob_derv.setC(side3);
	cout << "\nThe area of the triangle is: " << ob_derv.calcArea();
	cout << "\nThe height of the triangle is: " << ob_derv.calcHeight();

	cin.get();
	cin.ignore();

	return 0;
}