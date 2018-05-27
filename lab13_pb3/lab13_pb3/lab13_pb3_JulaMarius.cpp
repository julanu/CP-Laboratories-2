/*
Author: Jula Marius
Date: 20/5/2018
Description: Write a C++ application that reads a file’s content using the read() method. The obtained data
is displayed on the screen. Check the system’s state after each reading operation. The filename
is read from the command line
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	char str[11] = ""; // Buff

	if (argc != 2) { // Check nr of arguments
		cout << "Please enter the filename";
		cin.get();
		exit(1);
	}
	ifstream in; // Prepping the file, opening and assigning
	in.open(argv[1]);

	if (!in) {
		cout << "File can't be opened";
		cin.get();
		exit(1);
	}
	while (1) {
		in.read(str, 10);   // Reading 10 characters at a time, it will read as multiple of 10, if the number of characters is 35
		if (in.eof())break; // it will output only the first 30 characters
		cout << str;
	}
	in.close();
	cin.get();
	return 0;


}