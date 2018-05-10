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
public:
	virtual void ft_strcat(char [], char []) { }
    virtual void ft_interlace(char [], char []) { }
	virtual void ft_reverse(char []) { }
};

class Derived : public myString {
public:
	//Method to concatenate two char arrays
	void ft_strcat(char tab[], char tab2[]) {
		strcat(tab, tab2);
	}
	//Methode to reverse a char array
	void ft_reverse(char tab[]) {
		for (int i = 0; i < strlen(tab); i++)
		{
			char temp;
			temp = tab[i];
			tab[i] = tab[strlen(tab) - 1 - i];
			tab[strlen(tab) - 1 - i] = temp;
		}
	}
	//Method to interlace two arrays
	void ft_interlace(char tab[], char tab2[]) {
		for
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

