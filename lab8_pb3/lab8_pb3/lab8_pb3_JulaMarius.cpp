/*
Author: Jula Marius
Date: 23/4/18
Description: Define a class called Repository that has 2 integer private variables. The class contains an empty
constructor and another one with 2 parameters. An accesor method that displays the variables values is
also included in the class. Write another class called Mathematics which is friend to the first one. This
class contains the implementation of the elementary arithmetical operations (+, -, *, /) applied to the
values stored in the first class. Each arithmetical method receives as parameter an object instantiated from
the first class
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Repository {
	int a;
	int b;
public:
	Repository();
	Repository(int, int);
	void getAttributes();
	friend class Mathematics;
};

//Constructor w/o parameters
Repository::Repository() {
	this->a = 10;
	this->b = 10;
}

//Constructor w/ parameters
Repository::Repository(int newA, int newB) {
	this->a = newA;
	this->b = newB;
}

//Method to display the attributes
void Repository::getAttributes() {
	cout << "a = " << this->a << endl;
	cout << "b = " << this->b;
}

//Class with methods that implement the elementary arithmetical operations
class Mathematics {
public:
	void sum(Repository& x) {
		cout << (x.a + x.b);
	}
	void substract(Repository& x) {
		cout << (x.a - x.b);
	}
	void multiply(Repository& x) {
		cout << (x.a * x.b);
	}
	void divide(Repository& x) {
		cout << (x.a / x.b);
	}
};

int main() {
	Repository ob(13, 5); //we set the attributes the values of 13 and 5
	Mathematics abc;
	ob.getAttributes();
	cout << "\nSum: ";
	abc.sum(ob);
	cout << "\nDifference: "; 
	abc.substract(ob);
	cout << "\nDivision: ";
	abc.divide(ob);
	cout << "\nMultiplying: ";
	abc.multiply(ob);
	cout << "\nPress any key to exit . . .";
	getchar();
	return 0;
}