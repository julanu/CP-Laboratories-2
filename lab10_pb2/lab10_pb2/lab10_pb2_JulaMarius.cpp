/*
Author: Jula Marius
Date: 7/5/18
Description:  Using the classes from public inheritance example, implement 2 classes with the following
requests:
- the base class has the methods for:
- coding an array of characters (using a user-defined algorithm)
=> public;
- displaying the original and the coded array
= > public;
- the derived class has a method for:
- appending the coded array at the end of a previously created text file.Each record respects the format: record_number: coded_array;
The methods located in both classes are accessed using an instance of the derived class. The
program that uses the classes reads from the keyboard an array of characters and allows the
user to choose whether the input will be coded or will be appended at the end of the text file
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

#include <iostream>
using namespace std;

class Baza {
protected:
	char tab[MAX];
	int length;
public:
	Baza() //constructor
	{
		this->length = 15;
		for (int i = 0; i < length; i++)
			tab[i] = 10 + i;
	}
	void codeArr(); //method
	void dispArr(char *); //method
	
};// the base class

class Derivata : public Baza {
public:
	void appendArr(FILE *, char *, int); //method to append a array at the end of a file
}; //the derived class

//Method to code an array
void Baza::codeArr() {
	char code = 'd';
	for (int i = 0; i < length; i++)
		tab[i] += code;

}

//Method to display an array
void Baza::dispArr(char *arr, int arr_length) {
	cout << "\nThe array is: ";
	for (int i = 0; i < arr_length; i++)
		cout << " " << arr[i];
}

//Method to append the array at the end of a file
void Derivata::appendArr(FILE *f, char *arr, int length) {

}