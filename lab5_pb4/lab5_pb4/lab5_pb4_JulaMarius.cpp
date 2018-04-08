/*
Author: Jula Marius
Date: 6/4/18
Description:Write a program that implements a class called Number with an attribute of int type, val. In function
main(), declare two Number objects and a pointer to one object of this type, used to call a method int
sum_nr(Number) from the class that will calculate and display the sum of 2 int numbers read from the
keyboard, associated to the instantiated objects. Try to implement the method inside and outside the
class (with different names).
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Number {
private:
	int val;
public:
	Number();
	~Number();
	void setVal(int);
	int getVal();
	int sumNum(Number &, Number &);
	int sumNum2(Number &a, Number &b)
	{
		int v1, v2;
		v1 = a.getVal();
		v2 = b.getVal();
		return v1 + v2;
	}
}; 

//Constructor w/ no parameters
Number::Number()
{
	val = 1;
}


//Destructor 
Number::~Number()
{
	val = 0;
}

//Setter
void Number::setVal(int newVal)
{
	val = newVal;
}

//Getter
int Number::getVal()
{
	return val;
}

//Compute the sum between two numbers associated to the instantied objects
int Number::sumNum(Number &p, Number &p1)
{
	int x, y;
	x = p.getVal();
	y = p1.getVal();
	return x + y;
}

//main
int main()
{
	int n1, n2;
	Number nr1, nr2, *p;
	p = &nr1;
	cout << "Enter the two values: ";
	cin >> n1;
	cin >> n2;
	nr1.setVal(n1);
	nr2.setVal(n2);
	cout << endl << "The sum calculated using a method is: " << p->sumNum(nr1, nr2);
	cout << endl << "The sum calculated using a method inside the class is: " << p->sumNum2(nr1, nr2);
	cin.get(); cin.get();
	return 0;
}