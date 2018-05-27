/*
Author: Jula Marius
Date: 20/5/2018
Description: Consider the Fraction class that has two private attributes a and b for the nominator and
denominator and two corresponding setter and getter methods. Declare a method
named simplify() that simplifies a fraction. Define an explicit constructor without parameters
that initializes a with 0 and b with 1 and another explicit constructor that receives two
parameters representing the values of the nominator and denominator. This constructor
verifies if the fraction can be defined (b != 0). Overload the addition, subtraction,
multiplication and division operators (+, -, *, /) using member methods that simplify (if
necessary) the obtained results.
Overload the input (>>, extraction) and output (<<, insertion) operators using friend functions
that allow reading and writing the data related to an entire object. Instantiate two Fraction
objects with data read from the keyboard. Display the initial attributes of the objects by usign
the insertion operator. Read another four objects using the extraction operator. Perform the
operations implemented with member methods (the addition and subtraction of the first two
objects, the multiplication and division of the last ones) and store the results into another four
objects. Display the results. Write into a file the original values and the obtained results, on
different rows.
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 30
#include <iostream>
#include <fstream>
using namespace std;

// Prototypes
int gcd(int, int);

class Fraction {
private:
	int a;
	int b;
public:
	~Fraction();
	Fraction();
	Fraction(int, int);
	int getA() {
		return a;
	}
	int getB() {
		return b;
	}
	void setA(int a) {
		this->a = a;
	}
	void setB(int b) {
		this->b = b;
	}
	double   simplify();
	//Method to sum two fractions
	friend Fraction operator+(Fraction &f1, Fraction &f2) {
		Fraction f;
		f.setB(gcd(f1.getB(), f2.getB()));
		f.setB((f1.getB() * f2.getB()) / f.getB());
		f.setA(f1.getA() * (f.getB() / f1.getB()) + f2.getB()*(f.getB() / f2.getB()));
		f.simplify();
		return f;
	}
	//Method to substract two fractions
	friend Fraction operator-(Fraction &f1, Fraction &f2) {
		Fraction f;
		f.setA((f1.getA() * f2.getB()) - (f1.getB() * f2.getA()));
		f.setB(f1.getB() * f2.getB());
		f.simplify();
		return f;
	}
	//Method to multiply two fractions
	friend Fraction operator*(Fraction &f1, Fraction &f2) {
		Fraction f;
		f.setA(f1.getA() * f2.getA());
		f.setB(f1.getB() * f2.getB());
		f.simplify();
		return f;
	}
	//Method to divide two fractions
	friend Fraction operator/(Fraction &f1, Fraction &f2) {
		Fraction f;
		f.setA(f1.getA() * f2.getB());
		f.setB(f1.getB() * f2.getA());
		f.simplify();
		return f;
	}
	//Overloading the insertion and extraction operators
	friend ostream& operator<<(ostream& stream, Fraction &obj) {
		stream << "Fraction -> ";
		stream << obj.a;
		stream << " / ";
		stream << obj.b << '\n';
		return stream;
	}
	friend istream& operator>>(istream& stream, Fraction &obj) {
		cout << "Enter the fraction: \n";
		stream >> obj.a;
		cout << " / ";
		stream >> obj.b;
		return stream;
	}
};

// Destructor
Fraction::~Fraction() {
	this->a = 0;
	this->b = 0;
}

// Constructor w / o parameters
Fraction::Fraction() {
	this->a = 0;
	this->b = 1;
}

//Constructor w/ parameters
Fraction::Fraction(int a, int b) {
	if (b != 0) {
		this->a = a;
		this->b = b;
	}
	else {
		this->a = a;
		this->b = 1;
	}
}

//Method to simplify a fraction using the cmmmdc function
double Fraction::simplify() {
	int c;
	c = gcd(a, b);
	a = a / c;
	b = b / c;
	return ((double)a / (double)b);
}


int main() {
	cout << "INSTANTIATING TWO OBJECTS AND DISPLAYING THEIR DATA\n";
	Fraction ob, ob2;
	cin >> ob;
	cout << ob;
	cin >> ob2;
	cout << ob2;
	cout << "\nINSTANTIATING FOUR OBJECTS FOR THE OPERATIONS( AND DISPLAYING THEIR DATA) \n";
	Fraction f1, f2, f3, f4;
	cin >> f1; cout << f1;
	cin >> f2; cout << f2;
	cin >> f3; cout << f3;
	cin >> f4; cout << f4;
	cout << "\nTHE OPERATIONS ON THE OBJECTS AND THE RESULTS\n";
	Fraction r1, r2, r3, r4;
	r1 = f1 + f2;
	cout << "SUM--" << r1;
	r2 = f1 - f2;
	cout << "SUBSTRACTION--" << r2;
	r3 = f3 * f4;
	cout << "MULTIPLICATION--" << r3;
	r4 = f3 / f4;
	cout << "DIVISION--" << r4;

	char filename[MAX];
	cout << "Enter the filename: ";
	cin >> filename;
	ofstream out;
	out.open(filename);

	if (!out.good()) { // Checking if the file is present 
		cout << "File not present, please re-enter the filename: ";
		cin >> filename;
		cout << "\n";
	}
	out.write("The initial values\n", 21);
	out << f1 << f2 << f3 << f4;
	out.write("Results\n", 10);
	out << "SUM--" << r1;
	out << "SUBSTRACTION--" << r2;
	out << "MULTIPLICATION--" << r3;
	out << "DIVISION--" << r4;
	cin.get();
	cin.ignore();
	return 0;
}

// Greatest common divider
int gcd(int a, int b)
{
	int t;
	while (b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}
