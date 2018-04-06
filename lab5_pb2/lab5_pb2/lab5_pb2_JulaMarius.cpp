/*
	Author: Jula Marius
	Date: 6/4/18
	Description: 2. Declare a class called String and store it in a file named strClass.h. The methods in the class perform
	the following tasks:
	a. determine the length of the array of characters received as parameter;
	b. determine the index of the last occurence of a certain character in the array;
	c. return the array of characters received as parameter, all letters being transformed into capital
	letters.
	d. return the number of occurences of a certain character;
*/

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50

#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

class String {
private:
	char *str;
	int length;
public:
	String(void);
	~String(void);
	void getStr(void);
	void SetString(char *);
	int StrLength(char *);
	int LastOccurence(char *, char);
	char * StrUp(char *);
	int OccurenceNum(char *, char);

};
//destructor
String::~String(void)
{
	delete [] str;
}
//constructor
String::String(void)
{
	char std[] = "Standard text";
	strcpy(str, std);
}
//accessor
void String::getStr(void)
{
	cout << endl << "string: " << str;
}
//changing the string
void String::SetString(char *initStr)
{
	strcpy(str, initStr);
}
//determine the length of the string
int String::StrLength(char *str)
{
	int sz;
	sz = sizeof(str) / sizeof(char);
	return sz;
}
//last occurence of a character
int String::LastOccurence(char *str, char c)
{
	int i, sz, ind;
	char *p;
	p = &str[0];
	sz = sizeof(p) / sizeof(char);
	for (i = 0; i < sz; i++)
		if (*(p + i) == c)
			ind = i;
	return ind;
}
//all lowercase characters transformed to uppercase
char * String::StrUp(char *str)
{
	int i = 0;
	char *pc;
	pc = &str[0];
	while (str[i])
	{
		*(pc + i) = toupper(*(pc + i));
		i++;
	}
	return str;
}
//the number of occurences of a certain character
int String::OccurenceNum(char *str, char c)
{
	int i, count;
	char *pc;
	pc = &str[0];
	count = i = 0;
	while (!pc)
	{
		if (*(pc + i) == c)
			count += 1;
		i += 1;
	}
	return count;
}

void main()
{
	String str1;
	char *strInit;
	strInit = new char[SIZE];
	strcpy(strInit, "buzunarul meu vb");
	str1.SetString(strInit); //init the string
	str1.getStr();
	_getch();
}