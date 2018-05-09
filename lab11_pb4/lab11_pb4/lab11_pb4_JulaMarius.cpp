/*
Author: Jula Marius
Date: 9/5/18
Description: Write a C++ program that defines a class called Militar that has a public virtual method
sunt_militar(). Define the classes Soldat and Ofiter, both being derived from the first class.
Extend further the Ofiter class by implementing the classes Locotenent, Colonel, Capitan,
General. Override the method sunt_militar() for indicating the military degree represented by
each class. Instantiate each of the classes Soldat, Locotenent,...,General and call the
sunt_militar() method
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Militar {
public:
	virtual void sunt_militar() {
		cout << "Sunt militar.\n";
	}
};

class Soldat : public Militar {
public:
	void sunt_militar() {
		cout << "Sunt soldat.\n";
	}
};

class Ofiter : public Militar {
public:
	void sunt_militar() {
		cout << "Sunt ofiter.\n";
	}
};

class Locotenent : public Ofiter {
public:
	void sunt_militar() {
		cout << "Sunt locotenent.\n";
	}
};

class Colonel : public Ofiter {
public:
	void sunt_militar() {
		cout << "Sunt colonel.\n";
	}
};

class General : public Ofiter {
public:
	void sunt_militar() {
		cout << "Sunt general.\n";
	}
};

int main() {
	Militar ob1;
	ob1.sunt_militar();
	Ofiter ob2;
	ob2.sunt_militar();
	Locotenent ob3;
	ob3.sunt_militar();
	Colonel ob4;
	ob4.sunt_militar();
	General ob5;
	ob5.sunt_militar();

	cin.get();
	cin.ignore();

	return 0;
}