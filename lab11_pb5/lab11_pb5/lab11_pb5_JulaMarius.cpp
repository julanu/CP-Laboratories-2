/*
Author: Jula Marius
Date: 9/5/18
Description: Declare a class called Animal that contains a pure virtual method (respira()) and 2 virtual
methods (mananca() and doarme()). The classes Caine and Peste inherit the first class in a
public mode and implements the pure virtual method. The class Caine overrides the
mananca() method. The class Peste overrides the doarme() method. Instantiate the derived
classes and call the specific methods. After that, define an array of Animal objects that will
contain instances of the derived classes (if that’s possible). If not, find an appropriate solution.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <malloc.h>
using namespace std;

class Animal {
public:
	virtual void respira() = 0; // Pure virtual method
    virtual void mananca(); // Virtual methods
	virtual void doarme();
};

class Caine : public Animal {
public:
	virtual void respira() { }
	virtual void mananca() { } 
	virtual void doarme() {	}
};

//class Peste : public Animal {
//public:
//	virtual void mananca() {
//		cout << "mananca";
//	}
//};

int main() {
	Caine ob;
	ob.doarme();
	ob.mananca();


	cin.get();
	cin.ignore();

	return 0;
}