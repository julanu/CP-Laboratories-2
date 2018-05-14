/*
Author: Jula Marius
Date: 14/5/18
Description: Define a class called AcceleratedMovement that contains the private variables dc (the current
distance), vc (the current speed) and a (the acceleration). The values of dc and vc are
initialized in the constructor and their values are equal to d0 and v0 (as parameters).The class
overloads the extraction and insertion operators for initializing and displaying the
characteristics of a certain instance.
Implement the method determineMovement that re-calculates the values of dc and vc,
considering a number of seconds (received as paramenter) and the law of uniformly
accelerated linear motion. Instantiate the class and use the defined members.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class AcceleratedMovement {
private:
	double dc; // The current distance
 	double vc; // The current speed
	double a; // The acceleration
public:
	AcceleratedMovement(double d0, double v0) { // Constructor
		dc = d0;
		vc = v0;
		a = 1; // modify
	}
	void determineMovement(int s) { // Method to re-calculate dc and vc based on a nr. of seconds
		// ...
	}
	friend istream& operator>>(istream& stream, AcceleratedMovement obj) {
		cout << "Enter the current distance: ";
		stream >> obj.dc;
		cout << "Enter the current speed: ";
		stream >> obj.vc;
		return stream;
	}
	friend ostream& operator<<(ostream& stream, AcceleratedMovement obj) {
		cout << "\nCurrent distance: ";
		stream << obj.dc;
		cout << "\nCurrent speed: ";
		stream << obj.vc;
		cout << "\nAcceleration: ";
		stream << obj.a;
		return stream;
	}
};

int main()
{
	double dc, vc;
	int sec;

	cout << "Enter the value of the current distance: ";
	cin >> dc;
	cout << "Enter the value of the current speed: ";
	cin >> vc;
	AcceleratedMovement obj(dc, vc);
	cout << "\nMyObject\n";
	cout << obj;
	cout << "Enter a number of seconds to re-calculate the speed and distance: ";
	cin >> sec;
	obj.determineMovement(sec);
	cout << obj;

	cin.get();
	cin.ignore();
	return 0;
}
