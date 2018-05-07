/*
Author: Jula Marius
Date: 7/5/18
Description: Define a class Shape that defines a shape with a name attribute. Derive in public mode a
Circle class with an adequate constructor (name, radius) that calculates the area and the
perimeter of the Circle with the radius r introduced from the KB in the main() function. In the
same mode define other classes (Square, Rectangle, etc.) Instantiate objects from the derived
classes and display the area and the perimeter. The data will be introduced from the KB
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 30
#define PI 3.14
#include <iostream>
#include <cstring>
using namespace std;

class Shape {
protected:
	char name[MAX];
};

class Circle :public Shape {
protected:
	double radius;
public:
	Circle(char name[], double radius) {
		strcpy(this->name, name);
		this->radius = radius;
	}
	double calcArea(double r) {
		return PI * r * r;
	}
	double calcPerimeter(double r) {
		return 2 * PI * r;
	}
};

class Square : public Shape {
protected:
	double side;
public:
	Square(char name[], double side) {
		strcpy(this->name, name);
		this->side = side;
	}
	double calcArea(double side) {
		return side * side;
	}
	double calcPerimeter(double side) {
		return 4. * side;
	}
};

class Rectangle : public Shape {
protected:
	double length;
	double width;
public:
	Rectangle(char name[], double length, double width) {
		this->length = length;
		this->width = width;
	}
	double calcArea(double length, double width) {
		return length * width;
	}
	double calcPerimeter(double length, double width) {
		return (length + width) * 2.;
	}
};

class Hexagon : public Shape {
protected:
	double side;
public:
	Hexagon(char name[], double side) {
		strcpy(this->name, name);
		this->side = side;
	}
	double calcArea(double side) {
		return ((3. * 1.71 * side * side) / 2.);
	}
	double calcPerimeter(double side) {
		return 6. * side;
	}
};

int main() {
	double val, val2;
	char shape[MAX];
	//--------
	cout << "\nEnter the radius of the circle: ";
	cin >> val;
	strcpy(shape, "circle");
	class Circle ob1(shape, val);
	cout << "\nArea = " << ob1.calcArea(val);
	cout << "\nPerimeter = " << ob1.calcPerimeter(val);
	//--------
	cout << "\nEnter the value of the side of the square: ";
	cin >> val;
	strcpy(shape, "square");
	class Square ob2(shape, val);
	cout << "\nArea = " << ob2.calcArea(val);
	cout << "\nPerimeter = " << ob2.calcPerimeter(val);
	//---------
	cout << "\nEnter the value of the length of the rectangle: ";
	cin >> val;
	cout << "\nEnter the value of the width of the rectangle: ";
	cin >> val2;
	strcpy(shape, "rectangle");
	class Rectangle ob3(shape, val, val2);
	cout << "\nArea = " << ob3.calcArea(val, val2);
	cout << "\nPerimeter = " << ob3.calcPerimeter(val, val2);
	//---------
	cout << "\nEnter the value of the side of the hexagon: ";
	cin >> val;
	strcpy(shape, "hexagon");
	class Hexagon ob4(shape, val);
	cout << "\nArea = " << ob4.calcArea(val);
	cout << "\nPerimeter = " << ob4.calcPerimeter(val);

	cin.get();
	cin.ignore();

	return 0;
}