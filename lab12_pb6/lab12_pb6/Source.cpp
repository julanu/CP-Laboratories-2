/*
Author: Jula Marius
Date: 15/5/18
Description:Consider the Fraction class that has two private attributes a and b for the nominator and
denominator and two corresponding setter and getter methods. Declare a method
named simplify() that simplifies a fraction and returns a real value. Define an explicit
constructor without parameters that initializes a with 0 and b with 1 and another explicit
constructor that receives two parameters representing the values of the nominator and
denominator. For this constructor is verified if b!=0 before to be called. Define a destructor
that displays a message. Consider a static variable icount that will be initialized with 0 and
incremented in the class’s constructors. Overload the addition, subtraction, multiplication and
division operators (+, -, *, /) using friend functions, without simplifying the obtained results.
Instantiate two Fraction objects and read the corresponding data from the keyboard. Display
the initial attributes of the objects, on different lines, in 10 digits placeholders using * as
filling character. The denominator will be left aligned while the nominator will pe positioned
in the right part of the displaying field. Using an accesor method display the value of icount as
a signed integer, on 15 characters, left aligned, using ’$’ as filling character. Perform the
operations implemented with friend functions initializing another four objects with the
obtained results. Display the data (denominator/nominator) by overloading the output (<<,
insertion) operator and the counter (as a signed integer, on 20 characters, right aligned, using
’#’ as filling character) after the last operation. Simplify the results and display the resulting
values as fixed float numbers with 4 digits precision.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
using namespace std;

int gcd(int, int);

class Fraction {
private:
	int a;
	int b;
	static int icount;
public:
	~Fraction();
	Fraction();
	Fraction(int, int);
	int getICount() {
		return icount;
	}
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
	double	 simplify();
	//Method  to  sum  two  fractions
	friend  Fraction  operator+(Fraction  &f1, Fraction  &f2) {
		Fraction  f;
		f.setB(gcd(f1.getB(), f2.getB()));
		f.setB((f1.getB()  *  f2.getB()) / f.getB());
		f.setA(f1.getA()  *  (f.getB() / f1.getB()) + f2.getB()*(f.getB() / f2.getB()));
		return  f;
	}
	//Method  to  substract  two  fractions
	friend  Fraction  operator-(Fraction  &f1, Fraction  &f2) {
		Fraction  f;
		f.setA((f1.getA()  *  f2.getB()) - (f1.getB()  *  f2.getA()));
		f.setB(f1.getB()  *  f2.getB());
		return  f;
	}
	//Method  to  multiply  two  fractions
	friend  Fraction  operator*(Fraction  &f1, Fraction  &f2) {
		Fraction  f;
		f.setA(f1.getA()  *  f2.getA());
		f.setB(f1.getB()  *  f2.getB());
		return  f;
	}
	//Method  to  divide  two  fractions
	friend  Fraction  operator/(Fraction  &f1, Fraction  &f2) {
		Fraction  f;
		f.setA(f1.getA()  *  f2.getB());
		f.setB(f1.getB()  *  f2.getA());
		return  f;
	}
	friend ostream& operator<<(ostream& stream, Fraction &obj) {
		stream << obj.a;
		cout << " / ";
		stream << obj.b << '\n';
		return stream;
	}
};

int Fraction::icount = 0;

// Destructor
Fraction::~Fraction() {
	this->a = 0;
	this->b = 0;
	icount++;
}

// Constructor  w / o  parameters
Fraction::Fraction() {
	this->a = 0;
	this->b = 1;
	icount++;
}

//Constructor  w/  parameters
Fraction::Fraction(int  a, int b) {
	if (b != 0) {
		this->a = a;
		this->b = b;
	}
	else {
		this->a = a;
		this->b = 1;
	}
}

//Method  to  simplify  a  fraction  using  the  cmmmdc  function
double  Fraction::simplify() {
	int  c;
	c = gcd(a, b);
	a = a / c;
	b = b / c;
	return  ((double)a / (double)b);
}


int  main() {
	int  aa, bb;
	Fraction  f1, f2;
	cout << "\nf1.a  =  ";  cin >> aa;
	f1.setA(aa);
	cout << "\nf1.b  =  ";  cin >> bb;
	f1.setB(bb);
	cout << "\nf2.a  =  ";  cin >> aa;
	f2.setA(aa);
	cout << "\nf2.b  =  ";  cin >> bb;
	f2.setB(bb);
	cout << setfill('*') << setw(10);
	cout.setf(ios::left);
	cout << f1.getA();
	cout << f1.getB() << "\t <- Fraction 1\n";
	cout << setfill('*') << setw(10);
	cout.setf(ios::left);
	cout << f2.getA();
	cout << f2.getB() << "\t <- Fraction 2\n\n";
	cout << setfill('$') << setw(15);
	cout.setf(ios::left);
	cout << f1.getICount() << '\n';
	Fraction  f11, f12, f13, f14;
	f11 = f1 + f2;
	cout << "\nSum  =  " << f11;
	f12 = f1 - f2;
	cout << "\nDifference  =  " << f12;
	f13 = f1 * f2;
	cout << "\nProduct  =  " << f13;
	f14 = f1 / f2;
	cout << "\nDivision  =  " << f14 << '\n';
	cout << setfill('#') << setw(20);
	cout.unsetf(ios::left);
	cout.setf(ios::right);
	cout << f1.getICount() << '\n';

	cin.get();
	cin.ignore();

	return  0;
}

// Greatest common divider
int  gcd(int  a, int  b)
{
	int  t;
	while (b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return  a;
}

