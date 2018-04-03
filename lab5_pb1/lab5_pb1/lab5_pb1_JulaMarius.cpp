/*
	Author: Jula Marius
	Date: 4/3/18
	Description:
	Write a C/C++ application that uses a data structure named Circle. The structure has an integer
variable that represents the circle’s radius. In the main() function that uses the Circle structure, declare
2 Circle variables (c1 and c2) and calculate the area and the perimeter (using 2 methods) for 2 circles
with the value of the radius read from the keyboard.
Perform the same operations using a class called Circle (the radius is a private member of the
class). The class contains, besides those 2 methods defined in the first application, an explicit
constructor with 1 parameter, a destructor and another accessor method getRadius() that returns the
circle’s radius.
Extend the application by defining several Circle objects, pointers to the declared objects and
refferences to those objects.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

struct Circle {
	int rad;
};
double Perimeter(struct Circle *);
double Area(struct Circle *);

class Circle {
private:
	int rad;
public:
	double getArea(void);
	double getPerimeter(void);
	void setVal(int);
};
void Circle::setVal(int init_rad)
{
	rad = init_rad;
}
double Circle::getArea(void)
{
	return (3. 14 * rad * rad);
}
double Circle::getPerimeter(void)
{
	return (2 * 3.14 * rad);
}



void main()
{
	/*Circle c1, c2;
	c1.setVal(3);
	printf("\n%.2lf",c1.getArea());*/

	//to call functions
	_getch();
}

double Area(struct Circle *c)
{
	return (3.14 * c.rad * c.rad);
}

double Perimeter(struct Circle *c)
{
	return (2 * 3.14 * c.rad);
}