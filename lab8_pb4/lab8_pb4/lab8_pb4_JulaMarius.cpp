/*
Author: Jula Marius
Date: 23/4/18
Description: Write a C++ application that stores inside a class a public static integer variable called var_static. The
variable is incremented each time the class’s constructor is called. After instantiating several objects,
display their number using the value of the static variable.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//Class that stores how many apples we have, hence the apples attribute
class Test {
	int apples;
public:
	Test();
	Test(int);
	static int var_stat;
	
};

int Test::var_stat = 0; //Init

//Constructor w/o parameters
Test::Test() {
	this->apples = 5;
	var_stat += 1;
}

//Constructor w/ parameteres
Test::Test(int howManyApples) {
	this->apples = howManyApples;
	var_stat += 1;
}

int main()
{
	Test ob1, ob2(13), ob3(1), ob4;
	Test ob5(2);
	cout << "The constructor has been called " << ob1.var_stat << " times";
	cout << "\nPress any key to exit . . .";
	getchar();
	return 0;
}