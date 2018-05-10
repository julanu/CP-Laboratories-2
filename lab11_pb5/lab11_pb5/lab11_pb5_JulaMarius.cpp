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

//Abstract base class
class Animal {
public:
	virtual void respira() = 0; // Pure virtual method
	virtual void mananca() { } // Virtual methods
	virtual void doarme() { }
};

//Derived class
class Caine : public Animal {
public:
	void respira() { }
	void mananca() {
		cout << "mananca - caine \n";
	}
};

//Derived class 
class Peste : public Animal {
public:
	void respira() {
		cout << "respira - peste\n";
	}
};

int main() {
	cout << "Instantiating objects and calling the methods\n";
	Caine ob;
	ob.mananca();
	Peste ob1;
	ob1.respira();
	Animal *animals[3];
	animals[0] = &Caine();
	animals[1] = &Peste();
	animals[2] = &Caine();
	cout << "Now we will call the methods from the uni-dim table of objects\n";
	animals[0]->mananca();
	animals[1]->respira();
	animals[2]->mananca();
	cin.get();
	cin.ignore();

	return 0;
}