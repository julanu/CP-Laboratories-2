/*
Author: Jula Marius
Date: 22/4/18
Description: Write a C/C++ application that reads a point from the keyboard by giving the x, y and z
coordinates. Write a method that moves the point with a given distance on each of the three
axes. Verify if the line between the first and the second position of the point crosses a third
given point.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Point {
	float x;
	float y;
	float z;
public:
	Point();
	Point(float, float, float);
	Point(const Point &obj);
	~Point();
	float getX();
	float getY();
	float getZ();
	void setX(float);
	void setY(float);
	void setZ(float);
	void moveAxis(float);
	float distance(Point, Point);
	int isOnLine(const Point, const Point, const Point);
};

//Constructor w/o parameters
Point::Point() {
	this->x = 1;
	this->y = 1;
	this->z = 1;
}

//Constructor w/ parameters
Point::Point(float newX, float newY, float newZ) {
	this->x = newX;
	this->y = newY;
	this->z = newZ;
}

//Destructor
Point::~Point() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

//Copy constructor
Point::Point(const Point &obj) {
	this->x = obj.x;
	this->y = obj.y;
	this->z = obj.z;
}

//Getter for the X coordinate
float Point::getX() {
	return x;
}

//Getter for the Y coordinate
float Point::getY() {
	return y;
}

//Getter for the Z coordinate
float Point::getZ() {
	return z;
}

//Setter for X
void Point::setX(float newX) {
	this->x = newX;
}

//Setter for Y
void Point::setY(float newY) {
	this->y = newY;
}

//Setter for Z
void Point::setZ(float newZ) {
	this->z = newZ;
}

//Move along the coordinates
void Point::moveAxis(float move) {
	this->x += move;
	this->y += move;
	this->z += move;
}

//Distance between two points
float Point::distance(Point ob1, Point ob2) {
	float dist = 0.0;
	dist = sqrt((ob1.getX() - ob2.getX()) * (ob1.getX() - ob2.getX()) + (ob1.getY() - ob2.getY()) * (ob1.getY() - ob2.getY()) + (ob1.getZ() - ob2.getZ()) * (ob1.getZ() - ob2.getZ()));
	return dist;
}

//Verifying if a third point is on the line determined by two other points
int Point::isOnLine(const Point A, const Point B, const Point C) {
	if ((distance(A, C) + distance(B, C)) == distance(A, B))
		return 1; // C is on the line
	return -1;
}

int main() {
	float x, y, z, dist = 0.0;
	cout << "Please enter the coordinates";
	cout << "\nX:"; cin >> x;
	cout << "\nY:"; cin >> y;
	cout << "\nZ:"; cin >> z;
	Point ob1(x, y, z);
	cout << "\nEnter the distance to move the points";
	Point ob2 = ob1;
	cout << "Enter the coordinates of the third point: ";
	cout << "\nX:"; cin >> x;
	cout << "\nY:"; cin >> y;
	cout << "\nZ:"; cin >> z;
	Point ob3(x, y, z);
	int check = isOnLine(ob1, ob2, ob3);
	if (check)
		cout << "\nThe point is on the line";
	else
		cout << "\nThe point is not on the line";
	cin.ignore();
	cin.get();
}