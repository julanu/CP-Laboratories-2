/*
Author: Jula Marius
Date: 6/4/18
Description: Write a program that reads from the keyboard an array of maximum 10 characters and performs all
the operations implemented in the class defined at problem 3.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "strclass.h"


//Constructorul w/ no param that initializes str
StrClass::StrClass()
{
	str = new char[0];
}


//Constructor w/ 1 param that initializes this->str w/ str
StrClass::StrClass(char *str)
{
	this->str = new char[strlen(str) + 1];
	strcpy(this->str, str);
}


//Destructor
StrClass::~StrClass()
{
	delete[] str;
}


//Getter for str
char* StrClass::getStr()
{
	return str;
}


//Setter for str
void StrClass::setStr(char* str)
{
	this->str = new char[strlen(str) + 1];
	strcpy(this->str, str);
}


//Length of str
int StrClass::getLength()
{
	return strlen(str);
}


//Last occurence of ch in str, -1 if nothing is found
int StrClass::lastOccurence(char ch)
{
	int last = -1;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ch)
			last = i;
	}

	return last;
}


//Capitalize
char* StrClass::strUp()
{
	for (int i = 0; i < strlen(str); i++)
		str[i] = toupper(str[i]);

	return str;
}


//Num of occurences of ch in str
int StrClass::numOccurence(char ch)
{
	int ap = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ch)
			ap++;
	}

	return ap;
}


//main
void main()
{
	char *strTest;
	strTest = new char[20];
	StrClass str1; // apelam constructorul cu parametrii pentru a initializa (StrClass(char* str)
	cout << endl << "Start: ";
	cin >> strTest; //read
	str1.setStr(strTest);
	str1.getStr();
	cout << endl << "Length of our variable " << str1.getLength() << endl; // lungimea variabilei str din clasa
	cout << endl << "Getter: " << str1.getStr() << endl; // test getter
	cout << endl << "Last occurence of t: " << str1.lastOccurence('t') << endl; // last occurence of t
	cout << endl << "Capitalize: " << str1.strUp() << endl; // capitalize
	cout << endl << "Num of occurences of T: " << str1.numOccurence('T'); // num of occurences of T
	cin.get(); cin.get();
}