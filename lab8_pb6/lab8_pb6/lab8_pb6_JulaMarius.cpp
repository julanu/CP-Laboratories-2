/*
Author: Jula Marius
Date: 23/4/18
Description: Write a C++ application that defines a class named Point with the private attributes x and y. Implement a
friend function that calculate the area and perimeter of different shapes objects defined by two Point
parameters P0(x0, y0) and P1(x1, y1). Introduce another parameter named shape that controls the manner
in which the two points are used. If we consider a circle, the points delimit the circle’s diameter
(shape=1). If we are dealing with a right triangle (shape=2), the points determine the hypotenuse and the
other sides are determined considering the 2 initial points. The point’s coordinates and the shape selection
will be realized using parameters introduced from KB.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Point {
	int x;
	int y;
public:
	Point();
	Point(int, int);
	int getX();
	int getY();
	friend void compute(Point, Point, int);
};

//Constructor w/o parameters
Point::Point() {
	this->x = 1;
	this->y = 1;
}

//Constructor w/ parameters
Point::Point(int newX, int newY) {
	this->x = newX;
	this->y = newY;
}

int Point::getX() {
	return this->x;
}

//Getter for Y
int Point::getY(){
	return this->y;
}

//Method to compute the perimeter and area of a shape based on the shape selected and the points given
void compute(Point x1, Point x2, int shape) {
	if (shape == 1) { //The shape is a circle
		double diam, r; //The diameter and the radius
		//------
		//the if statements help to properly compute the data
		//based on the coordinates and their position
		//-------
		if (x1.getX() > x2.getX()) {
			diam = x1.getX() - x2.getX(); //We compute the radius determined by the two points
			r = diam / 2; //Radius
			cout << "\nThe area is equal to: " << (3.14 * 3.14 * r);
			cout << "\nThe perimeter is equal to: " << (2 * 3.14 * r);
		}
		else
			if (x1.getX() < x2.getX()) {
				diam = x2.getX() - x1.getX();
				r = diam / 2.;
				cout << "\nThe area is equal to: " << (3.14 * 3.14 * r);
				cout << "\nThe perimeter is equal to: " << (2 * 3.14 * r);
			}
			else
			{
				cout << "\nCan not compute the requested. An error has been made.";
			}

	}
	else
		if (shape == 2) { //The shape represents a right triangle
			double ip, c1, c2;
			if (x1.getY() > x2.getY()) { 
				ip = x1.getY() - x2.getY();
				c1 = ip / 2.; //The cathetus that opposes the angle of 30 is half the hypotenuse (doesn't matter which one)
				c2 = sqrt(ip * ip - c1 * c1); //The second cathetus
				cout << "\nThe area is equal to: " << ((c1 *c2) / 2.);
				cout << "\nThe perimeter is: " << (c1 + c2 + ip);
			}
			else
				if (x1.getY() < x2.getY()) {
					ip = x2.getY() - x1.getY();
					c1 = ip / 2; //The cathetus that opposes the angle of 30 is half the hypotenuse (doesn't matter which one)
					c2 = sqrt((ip * ip) - (c1 * c1)); //The second cathetus
					cout << "\nThe area is equal to: " << ((c1 *c2) / 2);
					cout << "\nThe perimeter is: " << (c1 + c2 + ip);
				}
				else {
					cout << "\nCan not compute the requested. An error has been made.";
				}
		}
	if((shape != 1) && (shape != 2))
			cout << "\nShape ID error.";
	cin.get();
}

int main() {
	int x, y, shape;
	cout << "Please enter the coordinates of the first point";
	cout << "\nx = "; cin >> x;
	cout << "\ny = "; cin >> y;
	Point x1(x, y);
	cout << "Please enter the coordinates of the second point";
	cout << "\nx = "; cin >> x;
	cout << "\ny = "; cin >> y;
	Point x2(x, y);
	cout << "Please enter the shape of the object you want to compute the area and perimeter";
	cout << "\n1 = circle\n2 = right triangle\nelse = no computation\n---------------------------";
	cout << "\nShape = "; cin >> shape;
	compute(x1, x2, shape);
	cout << "\nPlease enter any key to exit . . .";
	getchar();
	return 0;
}