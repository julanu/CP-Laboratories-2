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
using namespace std;

class myString {
	virtual char * ft_strcat(char [], char []);
	virtual void ft_interlace();
	virtual char * ft_reverse(char []);
};

class Derivated : public myString {
public:
	char * ft_strcat(char tab[], char tab2[]) {
		char cat[MAX];
		strcpy(tab, tab2);
		strcat(cat, tab);
		return cat;
	}
};