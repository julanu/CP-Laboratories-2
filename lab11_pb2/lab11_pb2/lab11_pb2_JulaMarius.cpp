/*
Author: Jula Marius
Date: 9/5/18
Description: Implement the example programs and include the classes in separate header files. Test their
functionality.
*/
#define _CRT_SECURE_NO_WARNINGS
//abstract classes and virtual methods
#include "my_header.h"
#include "my_header2.h"
#include "my_header3.h"

int main(void)
{
	const int N = 5;
	int i;
	Shape* sptrs[N];
	//upcasting
	sptrs[0] = new Line(1, 1, Co_blue, 4, 5);
	sptrs[1] = new Line(3, 2, Co_red, 9, 75);
	sptrs[2] = new Circle(5, 5, Co_green, 3);
	sptrs[3] = new Text(7, 4, Co_blue, "Hi, welcome back!");
	sptrs[4] = new Circle(3, 3, Co_red, 10);
	for (i = 0; i < N; i++)
		sptrs[i]->draw();
	for (i = 0; i < N; i++)
		delete sptrs[i];
	cin.get();
	cin.ignore();
	return 0;
}