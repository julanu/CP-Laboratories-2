/*
Author: Jula Marius
Date: 20/5/2018
Description:Write a program that uses the seekg() method for mid-file positioning and then displays the
file’s content, starting with this position. The filename is read from the command line.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 2) {  // Check if the number of arguments is correct
		cout << "\nPlease enter the filename";
		cin.get();
		exit(1);
	}
	ifstream in;
	in.open(argv[1]); // Open the file
	if (!in) {
		cout << "File can't be opened";
		cin.get();
		exit(1);
	}
	char c;
	in.seekg(0, ios_base::end);
	int length = in.tellg(); // File length
	in.seekg(length / 2, ios_base::beg); // Setting the position to the middle

	while (in.good()) { // Reading 
		c = in.get();
		cout << c;
	}
	
	in.close();
	cin.get();
	cin.ignore();
	return 0;
}