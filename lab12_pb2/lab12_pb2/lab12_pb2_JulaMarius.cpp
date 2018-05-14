/*
Author: Jula Marius
Date: 14/5/18
Description: Write a C++ application that reads from the keyboard a series of values of various types.
Display the values using the standard manipulators.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int x;
	double y;
	char c;
	cout << "Enter an int: ";
	cin >> x;
	cout << "Enter a double: ";
	cin >> y;
    cout << "Enter a char: ";
	cin >> c;
	//output in hex and oct
	cout << "\nHEX of " << x  << " : \n";
	cout.setf(ios::hex, ios::basefield);
	cout << x << " ";
	cout.unsetf(ios::hex);
	// oct
	cout << "\nOCT of " << x << " : \n";
	cout.setf(ios::oct, ios::basefield);
	cout << oct << x <<" " <<  '\n';
	cout.unsetf(ios::oct);
	//simple formatting and outputting
	cout << "\nSimple formatting: \n";
	cout << setfill('=') << setw(10);
	cout << x << '\n';
	cout << setfill('=') << setw(10);
	cout << y << '\n';
	cout << setfill('=') << setw(10);
	cout << c << '\n';
	cout.unsetf(ios::right);
	//scientific output with some formatting
	cout << "\nScientific output of " << x << " and " << y << ": \n";
	cout.setf(ios::scientific);
	cout << setfill('_') << setw(20);
	cout << x << '\n';
	cout << setfill('_') << setw(20);
	cout << y << '\n';
	cout.unsetf(ios::scientific);

	cin.get();
	cin.ignore();
	return 0;
}