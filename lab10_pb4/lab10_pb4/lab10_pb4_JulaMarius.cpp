/*
Author: Jula Marius
Date: 7/5/18
Description: Define a class called Triangle with 3 attributes for the triangle sides that has a method that
calculates the perimeter of the triangle with the sides introduced from the KB. Another class,
Triangle_extended, is derived in public mode from Triangle and defines a method for
calculating the triangle’s area. Using objects from both classes call the allowed methods.
Verify before to instantiate the objects the possibility to define a Triangle object
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
	double calcPerimeter(double a, double b, double c) {
		double res = 0.;
		res = a + b + c;
		return res;
	}
};

class Triangle_extended :public Triangle {
public:
	double calcArea(double a, double b, double c) {
		double p, s;
		p = s = 0.;
		p = (a + b + c) / 2.;
		s = sqrt(p * (p - a)*(p - b)*(p - c));
		return s;
	}
};

int main() {
	double side1, side2, side3;
	cout << "\nPlease enter the values of the sides";
	cout << "\ns1 = "; cin >> side1;
	cout << "\ns2 = "; cin >> side2;
	cout << "\ns3 = "; cin >> side3;
	Triangle ob_base;
	cout << "\nThe triangle perimeter is: " << ob_base.calcPerimeter(side1, side2, side3);
	Triangle_extended ob_derv;
	cout << "\nThe area of the triangle is: " << ob_derv.calcArea(side1, side2, side3);
	cout << "\n\nThe triangle perimeter is: " << ob_derv.calcPerimeter(side1, side2, side3);
	//cout << "\nThe area of the triangle is: " << ob_base.calcArea(side1, side2, side3); //error because of the inheritance
	
	cin.get();
	cin.ignore();

	return 0;
}