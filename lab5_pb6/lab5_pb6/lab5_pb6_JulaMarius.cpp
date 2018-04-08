/*
	Author: Jula Marius
	Date: 8/4/18
	Description:  Define a class that manages complex numbers. Write the program that uses this class.
*/

#include <iostream>
#include <math.h>

using namespace std;

//class that manages complex numbers
class Complex{
	double re, im;
public:
	Complex(double, double);
	~Complex();
	double setRe(double);
	double setIm(double);
	double getIm();
	double getRe();
	double module();
	void ad_complex(Complex);
	void sc_complex(Complex);
};

//Constructor w/ implicit parameters
Complex::Complex(double x = 0.0, double y = 0.0)
{
	this->re = x;
	this->im = y;
}

//Destructor
Complex::Complex()
{
	this->re = 0;
	this->im = 0;
}

//getter for the real part of a complex num
double Complex::getRe()
{
	return re;
}

//Getter for the imaginary part of a complex num
double Complex::getIm()
{
	return im;
}

//The module of a complex number
double Complex::module() {
	return sqrt(re*re + im * im);
}

//Setter for the imaginary part
void Complex::setIm(double newIm) {
	im = newIm;
}

//Setter for the real part
void Complex::setRe(double newRe) {
	re = newRe;
}

//difference of two complex numbers
void Complex::sc_complex(Complex b) //recomandat a returna un obiect
{
	re -= b.re;
	im -= b.im;
}

//sum of two complex numbers
void Complex::ad_complex(Complex b)
{
	re += b.re;
	im += b.im;
}

void main(void) {
	Complex ob1, ob2;
	double aux;
	cout << "\nPartea reala a obiectului 1 este \t";
	cin >> aux;
	ob1.setRe(aux);
	cout << "Partea imaginara a obiectului 1 este \t";
	cin >> aux;
	ob1.setIm(aux);
	ob1.ad_complex(ob2);
	cout << "Partea reala a obiectului 1 este \t\n" << ob1.getRe();
	cout << "Partea imaginara a obiectului 1 este \t \n" << ob1.getIm();
	//apelati metoda de scadere dupa definirea ei
	cin.ignore();
	cin.get();
}