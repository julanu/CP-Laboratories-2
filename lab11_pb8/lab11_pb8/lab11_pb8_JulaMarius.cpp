/*
Author: Jula Marius
Date: 11/5/18
Description: Write a C++ application that defines the abstract base class AbstractQuadrilateral having as
private attributes four instances of the Point class (a pair of x and y coordinates, getter andsetter methods) that represent the quadrilateral’s corners. Declare two pure virtual methods for
determining the area and the perimeter of the shape. Implement the derived class
ActualQuadrilateral that implements the inherited abstract methods and has another method
for determining whether the quadrilateral is a rectangle. Instantiate the derived class and call
the defined methods.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setX(int newX) {
		x = newX;
	}
	void setY(int newY) {
		y = newY;
	}
};

class AbstractQuadrilateral {
public:
	virtual double calcArea() = 0;
	virtual double calcPerimeter() = 0;
};

class ActualQuadrilateral : public AbstractQuadrilateral {
public:
	double calcArea(Point c1, Point c2, Point c3, Point c4) {

	}
	double calcPerimeter(Point c1, Point c2, Point c3, Point c4) {

	}

};

int main() {
	double x, y;
	cout << "Enter the four corners of the Quadrilateral: ";
	cout << "C1 - x : "; cin >> x;
	cout << "C1 - y : "; cin >> y;
	Point c1(x, y);
	cout << "C2 - x : "; cin >> x;
	cout << "C2 - y : "; cin >> y;
	Point c2(x, y);
	cout << "C3 - x : "; cin >> x;
	cout << "C3 - y : "; cin >> y;
	Point c3(x, y);
	cout << "C4 - x : "; cin >> x;
	cout << "C4 - y : "; cin >> y;
	Point c4(x, y);
	ActualQuadrilateral ob;
	ob.calcArea(c1, c2, c3, c4);
	ob.calcPerimeter(c1, c2, c3, c4);



	cin.get();
	return 0;
}