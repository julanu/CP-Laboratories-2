/*
Author: Jula Marius
Date: 20/5/2018
Description: Write a C++ application that opens a binary file for reading. The filename is read from the
keyboard. Display a message if the file doesn’t exist and ask the user to re-enter the filename.
Assuming that the file contains some agenda records (name, city, phone number) overload the
insertion and extraction operators for reading the file’s content and for displaying it on the
screen.
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Class to store the data 
class Person {
public:
	char name[MAX];
	char city[MAX];
	long phone;
public:
	Person() {
		strcpy(name, "test");
		strcpy(city, "test_2");
		phone = 0;
	}
};

// Prototypes
istream& operator>>(istream&, Person&);
ostream& operator<<(ostream&, Person&);

int main() {
	char filename[MAX];
	cout << "Enter the filename: ";
	cin >> filename;

	ifstream in;
	in.open(filename);

	if (!in.good()) { // Checking if the file is present 
		cout << "File not present, please re-enter the filename: ";
		cin >> filename;
		cout << "\n";
	}

	Person ob; // We used an object to store all the data

	while (!in.eof()) { //Reading until the end of file
		in >> ob; // Read the data of one person
		cout << ob; //Display
	}

	in.close();
	cin.get();
	cin.ignore();
	return 0;
}

// Overloading the insertion and extraction operators

// Insertion
istream& operator>>(istream& stream, Person& ob) {
	stream >> ob.name;
	stream >> ob.city;
	stream >> ob.phone;
	return stream;
}

// Extraction
ostream& operator<<(ostream& stream, Person& ob) {
	stream << ob.name << '\n';
	stream << ob.city << '\n';
	stream << ob.phone << "\n---------------------\n"; // To separate the data of the different objects
	return stream;
}