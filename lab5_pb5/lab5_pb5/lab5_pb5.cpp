/*
	Author: Jula Marius
	Date: 6/4/18
	Description: Implement
- int plus(int x, int y), which returns the sum of x and y;
- int minus(int x, int y), which returns the difference between x and y;
- int inmultit(int x, int y), which returns the result of x multiplied by y;
- float impartit(int x, int y), which returns the quotient of x and y;
Remark: prevent the division of a number by 0. If this situation occurs, display an error message
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Calculator {
private:
	int x, y;
public:
	Calculator(); //variables in class 
	~Calculator();// - || -
	int plus(); // - || -
	int plus(int, int);
	void setVal(int, int);
	int minus(int, int);
	int multiply(int, int);
	float division(int, int);
};

//Constructor w/ no params in case our variables are in the class
Calculator::Calculator()
{
	x = 10;
	y = 10;
}

//Destructor in case our variables are in the class
Calculator::~Calculator()
{
	x = 0;
	y = 0;
}

//Setter in case our variables are in the class
void Calculator::setVal(int a, int b)
{
	this->x = a;
	this->y = b;
}

//Sum of two variables that are in the class
int Calculator::plus()
{
	return x + y;
}

//Sum of two params x and y
int Calculator::plus(int x, int y)
{
	return x + y;
}

//Difference of two params x and y
int Calculator::minus(int x, int y)
{
	return x - y;
}

//Multiplying of two params x and y
int Calculator::multiply(int x, int y)
{
	return x * y;
}

//Division of two params x and y
float Calculator::division(int x, int y)
{
	if (y == 0)
	{
		cout << endl << "Division by 0 not possible.";
		return -1;
	}
	return (float)x / y;
}

//main
int main()
{
	int x, y;
	Calculator obt, *pt;
	pt = &obt;
	cout << "Enter the values of X and Y: ";
	cin >> x;
	cin >> y;
	//cout << endl << "Sum(X + Y): " << pt->plus(); // w/ no params as our variables are in the class
	cout << endl << "Sum(X + Y): " << pt->plus(x, y);
	cout << endl << "Diff(X - Y): " << pt->minus(x, y);
	cout << endl << "Multiplication(X * Y): " << pt->multiply(x, y);
	cout << endl << "Division(X / Y): " << pt->division(x, y);
	cin.get(); cin.get();
}