/*
Author: Jula Marius
Date: 12/4/2018
Description: Modify the 2-nd example so that the code could be launched into execution. The attribute of
the class will be considered private.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Test2 {
private:
	int x;
public:
	Test2() {
		cout << "\nApel constructor explicit vid.";
	}
	friend void MyFriend(int);
};

void MyFriend(int a)
{
	Test2 obj;
	obj.x = a;
}

void main(void) {
	Test2 ob1; //instantiere imposibila, constructorul este privat!
	int a;
	cout << "\nIntroduceti valoarea variabilei de tip \"int\" din clasa: ";
	cin >> a;
	MyFriend(a);
	cin.ignore();
	cin.get();
}