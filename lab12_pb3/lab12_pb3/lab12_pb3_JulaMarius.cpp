/*
Author: Jula Marius
Date: 14/5/18
Description: Consider a data acquisition process from a hardware device (10 variables). Display, using an
appropriate message, the data in a minimal format (the integer part). Determine the average
value of the displayed numbers and if it is greater than a previously defined threshold, display
the data in a detailed format (float variables, 8 digits precision).
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include <iostream>
#include <iomanip>
using namespace std;

// Prototypes
double getAvg(double *);

int main() {
	double thr; //threshold value
	double *tab;
	cout << "Enter a threshold value for the table of data: ";
	cin >> thr;

	tab = new double[MAX];
	for (int i = 0; i < MAX; i++) {
		*(tab + i) = (double)i + 1. + 3. / (double)(i + 1); // generating some "random" double values
	}
	cout << "RAW TABLE(no precision set)\n";
	for (int i = 0; i < MAX; i++) {
		cout << *(tab + i) << " ";
	}
	cout << endl;
	cout << "MINIMAL FORMAT(showing the int part)\n";
	for (int i = 0; i < MAX; i++) {
		cout.setf(ios::fixed);
		cout << setprecision(0);
		cout << *(tab + i) << " ";
	}
	double res = getAvg(tab);
	cout << "\nThe threshold value is: " << res << '\n';

	cout << "DETAILED FORMAT IF THE THRESHOLD IS EXCEEDED\n";
	if (res > thr) {
		for (int i = 0; i < MAX; i++) {
			cout.setf(ios::fixed);
			cout << setprecision(8);
			cout << *(tab + i) << " ";
		}
	}

	cin.get();
	cin.ignore();

	return 0;
}

//function to determine the average value of a table of ints
double getAvg(double *tab) {
	double res = 0.;
	for (int i = 0; i < MAX; i++)
		res += *(tab + i);

	return res / (double)MAX;
}