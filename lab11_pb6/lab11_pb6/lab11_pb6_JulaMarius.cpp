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
	virtual void ft_strcat(char[], char[]) { }
	virtual void ft_interlace(char[], char[]) { }
	virtual void ft_reverse(char[]) { }
};

class Derived : public myString {
public:
	//Method to concatenate two char arrays
	void ft_strcat(char tab[], char tab2[]) {
		strcat(tab, tab2);
	}
	//Methode to reverse a char array
	void ft_reverse(char tab[]) {
		for (int i = 0; i < strlen(tab) / 2; i++)
		{
			char temp;
			temp = tab[i];
			tab[i] = tab[strlen(tab) - 1 - i];
			tab[strlen(tab) - 1 - i] = temp;
		}
	}
	//Method to interlace two arrays
	void ft_interlace(char tab[], char tab2[]) {
		char *inter = new char[(strlen(tab) * 2)];
		for (int i = 0; i < strlen(tab); i++)
		{
			if(i % 2 == 0)
			inter[i] = tab[i];
			else
			inter[i + 1] = tab2[i];
		}

		cout << "Interlaced\n";
		for (int i = 0; i < strlen(inter); i++) {
			cout << inter[i];
		}
	}
};

int main()
{
	char s1[MAX], s2[MAX];
	cout << "THE TWO STRINGS MUST HAVE THE SAME SIZE\n";
	cout << "First string: "; cin >> s1;
	cout << "Second string: "; cin >> s2;
	Derived ob;
	ob.ft_interlace(s1, s2);
	ob.ft_reverse(s1);
	cout << "\nReverse first: " << s1 << endl;
	ob.ft_strcat(s1, s2);
	cout << "Concatenated: " << s1 << endl;
	
	cin.get();
	cin.ignore();

	return 0;
}

