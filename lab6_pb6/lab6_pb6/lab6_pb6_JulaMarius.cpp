/*
Author: Jula Marius
Date: 13/4/18
Description:Write a C++ application that defines a class called Triangle. The class contains as private
variables the triangle's sides a, b and c. The methods included in the class will determine
whether the values of a,b and c form a triangle and will calculate the shape's area and
perimeter. Write a distinct method that will print a specific message if the triangle is right.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Triangle {
private:
	double a, b, c;
public:
	
	void setValues(double, double, double);
	void isTriangle();
	void isRight();
	double getPerimeter();
	double getArea();
};

//Setter for the values of the sides
void Triangle::setValues(double newA, double newB, double newC) {
	this->a = newA;
	this->b = newB;
	this->c = newC;
}

//Method to determine the triangle's area
double Triangle::getArea() {
	double p;
	p = (a + b + c) / 2;
	return (sqrt(p*(p - a)*(p - b)*(p - c)));
}

//Method to determine the triangle's perimeter
double Triangle::getPerimeter()
{
	return (this->a + this->b + this->c);
}

//Method to determine if the 3 numbers can form a triangle
void Triangle::isTriangle()
{
	if ((a > 0) && (b > 0) && (c > 0) && (a + b > c) && (a + c > b) && (b + c > a))
	{
		if ((a == b) && (b == c))
			cout << "\nThe values can form a triangle"; //equal-sided
		else
			if (a == b || b == c || c == a)
				cout << "\nThe values can form a triangele"; //isosceles
			else
				cout << "\nThe values can form a triangle";
	}
	else
		cout << "\nImpossible to form a triangle";
}

//Method to check if the triangle is a right triangle
void Triangle::isRight()
{
	if ((a * a + b * b) == c * c)
		cout << "\nThis is a right triangle.";
	else
		cout << "\nNot a right triangle.";
}

void main()
{
	Triangle obj;
	double aa, bb, cc;
	cout << "Please enter the 3 values for the sides of triangle: ";
	cin >> aa >> bb >> cc;

	obj.setValues(aa, bb, cc);
	obj.isTriangle();
	cout << "\nThe triangle perimeter is: " << obj.getPerimeter();
	cout << "\nThe triangle area is :" << obj.getArea();
	obj.isRight();

	cin.ignore();
	cin.get();
}