/*
Author: Jula Marius
Date: 10/5/18
Description: Define an abstract class that contains 3 method declarations for concatenating, interlacing two
arrays of characters and for reverting the character array received as parameter. A subclass
implements the methods declared in the base class. Instantiate the 2-nd class and display the
results produced by applying the methods mentioned above upon some data read from the
keyboard. Examine the error given by the attempt of instantiating the base class
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <iostream>
#include <cstring>
using namespace std;

class myString {
	int x;
public:
	virtual void test() = 0;
	virtual char * ft_strcat(char tab[], char tab2[]) { 
		return tab;
	}
//	virtual void ft_interlace();
//	virtual char * ft_reverse(char []);
};

class Derived : public myString {
	int y;
public:
	void test() { cout << "test\n"; }

	char * ft_strcat(char tab[], char tab2[]) {
		strcat(tab, tab2);
		return tab;
	}
};

int main()
{
	Derived ob;
	ob.test();
	char tab1[MAX], tab2[MAX];
	strcpy(tab1, "da"); strcpy(tab2, "nu");
	cout << ob.ft_strcat(tab1, tab2);
	cin.get();
	cin.ignore();

	return 0;
}

