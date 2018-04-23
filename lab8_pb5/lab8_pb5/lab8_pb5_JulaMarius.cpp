/*
Author: Jula Marius
Date: 23/4/18
Description: Implement the 4-th problem by changing the static variable’s access modifier to private. Define a method
that returns the counter’s value
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//Class that stores how many apples we have, hence the apples attribute
class Test {
	int apples;
	static int var_stat;
public:
	Test();
	Test(int);
	int how_many_times();

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

//Getter for the static attribute that is private
int Test::how_many_times() {
	return var_stat;
}

int main()
{
	Test ob1, ob2(13), ob3(1), ob4;
	Test ob5(2);
	cout << "The constructor has been called " << ob1.how_many_times() << " times";
	cout << "\nPress any key to exit . . .";
	getchar();
	return 0;
}