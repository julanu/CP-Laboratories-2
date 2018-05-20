/*
Author: Jula Marius
Date: 20/5/2018
Description: Write a program that uses the write() method for writing some character arrays into a file.
Display the file’s content using the get() method. The filename is read from the keyboard
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

int main() {
	char filename[MAX];
	cout << "Enter the filename:";
	cin >> filename;
	
	ofstream out(filename);
	
	if (!out) {
		cout << "File can't be opened";
		cin.get();
		exit(1);
	}

	out.write("Sir de test de verificat\n", 27);
	out.write("To write in file", 17);
	out.close();

	ifstream in(filename);

	char c;
	while (in.good()) { // Reading 
		c = in.get();
		cout << c;
	}
	in.close();
	cin.get();
	cin.ignore();

	return 0;
}