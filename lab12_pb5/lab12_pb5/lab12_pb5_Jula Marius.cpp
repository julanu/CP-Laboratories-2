/*
Author: Jula Marius
Date: 14/5/18
Description: Overload the extraction and insertion operators for the Complex class (both the imaginary and
real parts are represented as protected real values). Create another class named Point that
inherits the first class and introduces the color attribute for a point that has as coordinates the
real and imaginary parts of the complex number. Overload again the extraction and insertion
operators. Create some instances of the defined classes and verify the functionality of the
overloaded operators. Assign an object of Point type to an object of Complex type and dispaly
the attributes of the obtained object.
*/
#define _CRT_SECURE_NO_WARNNGS
#define MAX 10

#include <iostream>
using namespace std;


class Complex {
protected:
	double re;
	double im;
public:
	Complex() {
		int a; // Done so we avoid some errors
		a = 0; // code has no effect whatsoever
	}
	Complex(double re = 0, double im = 0) {
		this->re = re;
		this->im = im;
	}
	void setRe(double re) {
		this->re = re;
	}
	void setIm(double im) {
		this->im = im;
	}
	friend ostream& operator<<(ostream& stream, Complex obj) {
		cout << "\nThe complex number is: ";
		stream << obj.re << " + " << obj.im << "*j";
		return stream;
	}
	friend istream& operator>>(istream& stream, Complex& obj) {
		cout << "Enter the real part: ";
		stream >> obj.re;
		cout << "Enter the imaginary part: ";
		stream >> obj.im;
		return stream;
	}
};

class Point : public Complex {
protected:
	double x; // The coordinates
	double y;
	char c; // Colour
public:
    	Point()  { // Constructor w/o parameters
		this->x = 1.;
		this->y = 1.;
		this->c = 'r'; // r for red
	}
	//THE PROBLEM SEEMS TO BE THIS CONSTRUCTOR
	Point(Complex obj, char c) { // Constructor w/ parameters
		this->x = obj.re;
		this->y = obj.im;
		this->c = c;
	}
	friend ostream& operator<<(ostream& stream, Point obj) {
		cout << "The point has the coordinates: ";
		stream << "( " << obj.x << " , " << obj.y << " )";
		stream << " and the colour: " << obj.c;
		return stream;
	}
	friend istream& operator>>(istream& stream, Point& obj) {
		cout << "Enter the X coordinate: ";
		stream >> obj.x;
		cout << "Enter the Y coordinate: ";
		stream >> obj.y;
		cout << "Enter the colour of the point(one character, the initial of the colour): ";
		stream >> obj.c;
		return stream;
	}
};

int main() {
	//double im, re;
	Complex ob1;
	cin >> ob1;
	cout << ob1;




	cin.get();
	cin.ignore();
	
	return 0;
}
