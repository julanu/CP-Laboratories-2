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

#include <iostream>
#include <conio.h>

using namespace std;

struct CircleStr {
	int rad;
};

class Circle {
private:
	int rad;
public:
	double getArea(void);
	double getPerimeter(void);
	void setVal(int);
	int getRadius(void);
	~Circle(void);
	Circle(int x = 1) {//explicit constructor w/ 1 implicit parameter
		rad = x;
	}
};

//prototypes using the struct
double Perimeter(struct CircleStr *, int);
double Area(struct CircleStr *, int);


int main()
{
	Circle c1, c2;
	struct CircleStr c[2] = {10, 2};
	cout << "Struct calling of functions" << endl << "Area" << endl;
	cout << Area(c, 0) << "\t" << Area(c, 1) << endl;
	cout << "Perimeter" << endl;
	cout << Perimeter(c, 0) << "\t" << Perimeter(c, 1) << endl;
	cout << "Class calling of functions" << endl;
	c1.setVal(3);//we set the values for our objects
	c2.setVal(7);
	cout << "The radius fetched by an accessor has the value of " << c1.getRadius() << endl;
	cout << "Area" << endl;
	cout << c1.getArea() << "\t" << c2.getArea() << endl;
	cout << "Perimeter" << endl;
	cout << c1.getPerimeter() << "\t" << c2.getPerimeter() << endl;
	c1.~Circle(); //call of the destructor
	_getch();
}

//functions for the struct CircleStr
//compute the area of a circle
double Area(struct CircleStr *c, int i)
{
	return (3.14 * c[i].rad * c[i].rad);
}
//compute the perimeter of a circle
double Perimeter(struct CircleStr *c, int i)
{
	return (2 * 3.14 * c[i].rad);
}

//functions for the class Circle
//
void Circle::setVal(int init_rad)
{
	rad = init_rad;
}
//compute the area of a circle
double Circle::getArea(void)
{
	return (3.14 * rad * rad);
}
//compute the perimeter of a circle
double Circle::getPerimeter(void)
{
	return (2 * 3.14 * rad);
}
//accessor
int Circle::getRadius(void)
{
	return rad;
}
//destructor
Circle::~Circle(void)
{
	rad = 0;
}
