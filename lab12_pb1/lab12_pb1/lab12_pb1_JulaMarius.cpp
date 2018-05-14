/*
Author: Jula Marius
Date: 14/5/18
Description: Write a C++ program that displays some numerical values in decimal, octal and hexadecimal.
Display the values left and right aligned, inside a field that can hold 15 characters. Use the
setfill() manipulator for setting the filling character and the width() and precision() methods
for setting the displaying field size and the values representation precision.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << "Alignment to the left and right on a filed of width 15\n";
	cout << setfill('-') << setw(15); //setting the fill char and the width of the fild
	cout.setf(ios::left); // all will be aligned to the right
	cout << 50;
	cout.unsetf(ios::left); // reset the align
	cout << "\n";
	cout << setfill('=') << setw(20);
	cout.setf(ios::right); //align to the right
	cout << 100;
	cout << "\n";
	cout << hex << "Hex of 100: " << 100 << endl;
	cout << oct << "Oct of 100: " << 100 << endl;
	cout.setf(ios::fixed); // resetting the precision
	cout << "Precisions on a field of 20\n";;
	cout << setprecision(12); // setting the preciosion
	cout << "Precision of 12 for (100.12390): " << 100.12390 << "\n";
	cout << setprecision(4);
	cout << "Precision of 4 for (-10.12500): " << -10.12500 << "\n";
	cin.get();
	cin.ignore();
}