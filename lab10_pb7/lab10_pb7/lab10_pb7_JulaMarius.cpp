/*
Author: Jula Marius
Date: 7/5/18
Description: Consider a base class Circle defined by a protected attribute radius, that contains a constructor
with parameters and a method that will determine the area of the circle. Consider other base
class, Square with a protected attribute, length, similar to Circle class. Derive in public mode
the class RoundSquare from both classes that will contain a constructor that will call the
constructors from base classes and a method that will verify if the square of length l may be
included in the circle of radius r. The derived class will also determine the perimeter of both
shapes. Instantiate an object from the derived class (data from the KB) and determine the area
and perimeter of the composed shapes. Display a message if the square may be included in the
circle
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Circle { // base class
protected:
	double radius;
public:
	Circle(double radius) { //constructor
		this->radius = radius;

	}
	double calcArea() { //method to compute the area
		return 3.14 * radius * radius;
	}
};

class Square { // base class
protected:
	double length;
public:
	Square(double length) { //constructor
		this->length = length;
	}
	double calcArea() { //method
		return length * length;
	}
};

class RoundSquare : public Square, public Circle { // derived class from two base classes
public:
	RoundSquare(double value) : Square(value), Circle(value) { 
		cout << "Message from derived constructor";
	}
	void check(double length, double radius) {
		if (length <= radius)
			cout << "\nThe square of lenght " << length << " can be included in the circle of radius " << radius;
		else
			cout << "\nThe square can't be included in the circle";
	}
	void calcPerimeter() {
		cout << "\nPerimeter of square = " << Square::length * 4.;
		cout << "\nPerimeter of the circle = " << Circle::radius * 2. * 3.14;
	}
	void dispArea() {
		cout << "\nArea of circle: " << Circle::calcArea();
		cout << "\nArea of square: " << Square::calcArea();
	}
};

int main()
{
	double val;
	cout << "\nPlease enter a value that will represent the radius of a circle and the length of a square: ";
	cin >> val;
	RoundSquare ob(val);
	ob.calcPerimeter();
	ob.dispArea();
	cout << "\nWe now want to check if a square of length L can be included in a circle of radius R";
	double l, r;
	cout << "\nL = "; cin >> l;
	cout << "R = "; cin >> r;
	ob.check(l, r);
	cin.get();
	cin.ignore();

	return 0;
}