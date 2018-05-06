/*
Author: Jula Marius
Date: 6/5/18
Description: Write the program that uses a class called Calculator that has as overloaded public methods:
- int calcul(int x) that returns the square value of x;
- int calcul(int x, int y) that returns the product of x and y;
- double calcul(int x, int y, int z) that returns the result of f(x,y,z) = (x-y)(x+z)/2.;
The program receives the parameters from the command line.
Consider the case when all the methods are static. Is it possible to have in the same time static and non-static
public methods? Analyze the case that the class has 3 private attributes of type int, x, y, z, that are modified
with setter adequate methods. What must be modified to perform the required operations?
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Calculator {
	int x;
	int y;
	int z;
public:
	void setX(int);
	void setY(int);
	void setZ(int);
	int getX() { return this->x; }
	int getY() { return this->y; }
	int getZ() { return this->z; }
	int calcul(int x);
	int calcul(int x, int y);
	double calcul(int x, int y, int z);
};

//Setter for the value of X
void Calculator::setX(int newX) {
	this->x = newX;
}

//Setter for the val of Y
void Calculator::setY(int newY) {
	this->y = newY;
}

//Setter for the val of Z
void Calculator::setZ(int newZ) {
	this->z = newZ;
}

//Method that returns the square value of the parameter
int Calculator::calcul(int x) {
	return x * x;
}

//Method that returns the product of the two parameters
int Calculator::calcul(int x, int y) {
	return x * y;
}

//Method that returns the value of the function
double Calculator::calcul(int x, int y, int z) {
	return ( (x - y)*(x + z) / 2.);
}


int main() {
	int xx, yy, zz;
	cout << "\nEnter the values of ";
	cout << "\nx = "; cin >> xx;
	cout << "\ny = "; cin >> yy;
	cout << "\nz = "; cin >> zz;
	Calculator ob;
	ob.setX(xx);
	ob.setY(yy);
	ob.setZ(zz);
	cout << "\nSquare value: " << ob.calcul(ob.getX());
	cout << "\nProduct of the first two params: " << ob.calcul(ob.getX(), ob.getY());
	cout << "\nResult of the function: " << ob.calcul(ob.getX(), ob.getY(), ob.getZ());
	cin.get(); cin.ignore();
	return 0;

}