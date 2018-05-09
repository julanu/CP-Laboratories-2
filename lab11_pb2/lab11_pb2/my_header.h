#pragma once
#include<iostream>
using namespace std;
#include<string.h>
enum Color { Co_red, Co_green, Co_blue };
// clasa de baza abstracta
class Shape {
protected:
	int xorig;
	int yorig;
	Color co;
public:
	Shape(int x, int y, Color c) : xorig(x), yorig(y), co(c) { ; }
	virtual ~Shape() { ; } // virtual destructor
	virtual void draw() = 0; // pure virtual method
};
//A pure virtual method makes the class in which it appears as an abstract class
//The pure virtual method must be defined in the derived classes or re-defined as a
//pure virtual method in the derived classes
//class Line (between the origin and the destination point)
class Line : public Shape {
	int xdest;
	int ydest;
public:
	Line(int x, int y, Color c, int xd, int yd) :
		xdest(xd), ydest(yd), Shape(x, y, c) {
		;
	}
	~Line() { cout << "~Line\n"; } // virtual destructor
	void draw() //virtual method
	{
		cout << "Line" << "(";
		cout << xorig << ", " << yorig << ", " << int(co);
		cout << ", " << xdest << ", " << ydest;
		cout << ")\n";
	}
};
// Clasa Circle : cerc cu raza
class Circle : public Shape {
	int raza;
public:
	Circle(int x, int y, Color c, int r) : raza(r), Shape(x, y, c) { ; }
	~Circle() { cout << "~Circle\n"; } // virtual destructor
	void draw() // virtual method
	{
		cout << "Circle" << "(";
		cout << xorig << ", " << yorig << ", " << int(co);
		cout << ", " << raza;
		cout << ")\n";
	}
};
// Clasa Text : text
class Text : public Shape {
	char* str;
public:
	Text(int x, int y, Color c, const char* s) : Shape(x, y, c)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	~Text() { delete[] str; cout << "~Text\n"; } // virtual destructor
	void draw() // virtual method
	{
		cout << "Text" << "(";
		cout << xorig << ", " << yorig << ", " << int(co);
		cout << ", " << str;
		cout << ")\n";
	}
};