/*
//1. Implementarea clasei Rectangle pentru efectuarea
//unor operatii elementare cu forme geometrice dreptunghiulare
#include <iostream>
using namespace std;
// clasa Rectangle
class Rectangle {
	// membri private
	int height;
	int width;
public:
	// membri publici
	Rectangle(int h = 10, int w = 10); // constructor explicit cu val. implicite
	int get_area(void);
	void set_values(int, int);
	~Rectangle(void); // destructor explicit
};
Rectangle::Rectangle(int h, int w) // definire constructor explicit
{
	if ((h == 10) && (w == 10))
		cout << "\nApel constructor (cu valori implicite)...";
	else
		cout << "\nApel constructor (cu valori oarecare)...";
	height = h;
	width = w;
}
Rectangle::~Rectangle(void) // destructor
{
	cout << "\nApel destructor...";
	height = 0;
	width = 0;
}
int Rectangle::get_area(void) {
	return height * width;
}
void Rectangle::set_values(int init_height, int init_width)
{
	height = init_height;
	width = init_width;
}
void main() {
	// obiecte de tipul Rectangle
	Rectangle rect, square;//inst.cu val implicite
	cout << "\nObiecte(acces cu operatorul .): \n";
	cout << "\tValori implicite: \n";
	cout << "\t\tAria dreptunghiului: " << rect.get_area() << endl;
	cout << "\t\tAria patratului: " << square.get_area() << endl;
	cout << "\tValori oarecare: \n";
	rect.set_values(12, 8);
	cout << "\t\tAria dreptunghiului: " << rect.get_area() << endl;
	square.set_values(8, 8);
	cout << "\t\tAria patratului: " << square.get_area();
	cout << "\n...................................\n\n";
	// pointer la tipul Rectangle
	Rectangle *point;
	cout << "\nPointeri la obiecte (acces cu operatorul ->):";
	point = new Rectangle;//inst. cu val. implicite
	cout << "\n\tValori implicite: \n";
	cout << "\t\tAria dreptunghi(patrat)ului:" << point->get_area() << endl;
	cout << "\tValori oarecare: \n";
	point->set_values(12, 12);
	cout << "\t\tAria (dreptunghi)patratului: " << point->get_area() << endl;
	delete point;
	cout << "\n...................................\n\n";
	cin.get();
}//main

*/
//first example ^

//2. Implementarea clasei Point
#include <stdio.h>//e recomandat a folosi mecanismul de I/E din C++
#include <conio.h>
#include <math.h>

class Point {
	int x, y;
public:
	Point(int a = 0, int b = 0) {
		x = a; y = b;
	}
	// x2 - x1 + y2 - 1 allsquare
	double raza(int x2, int y2, int x1, int y1) {
		return sqrt((double)(x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	}//NOT WORKING
	void setX(int a) {
		x = a;
	}
	int getX() {
		return x;
	}
	void setY(int b) {
		y = b;
	}
	int getY() {
		return y;
	}
};
void main(void) {
	Point p1; // echivalent cu Point p1(0,0);
	printf("\nValori punct P1 -- x = %d\t y = %d\n", p1.getX(), p1.getY());//recomandat I/E C++
	Point p2(10); // echivalent cu Point p2(10,0);
	printf("\nValori punct P2 -- x = %d\t y = %d\n", p2.getX(), p2.getY());
	Point p3(10, 10);
	printf("\nValori punct P3 -- x = %d\t y = %d\n", p3.getX(), p3.getY());
	p1.setX(20);
	p1.setY(30);
	//afisati noile valori ale atributelor x si y ale punctului p1
	printf("\nValori punct P1 -- x = %d\t y = %d\n", p1.getX(), p1.getY());
	//Cerinta: Modificati operatiile de I / E folosind cele specifice C++.Adaugati si testati o metoda pentru
	//calculul razei vectoare(distantei dintre doua puncte).
	//THIS AINT WORKING
	printf("\nDistanta intre P3 si P1 este: %.2f", Point.raza(p1.getX(), p3.getX(), p1.getY(), p3.getY()));
	_getch();
}
