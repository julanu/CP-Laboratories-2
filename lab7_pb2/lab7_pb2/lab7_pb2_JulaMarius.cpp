/*
Author: Jula Marius
Date: 16/4/18
Description: Write a C/C++ application that models in OOP a real numbers one dimensional array.
Instantiate two objects of this class with the same length n and store in a third one the results
of subtracting each of the two real number arrays’ elements. If the source arrays have different
lengths, the result has the length of the shortest array.
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <iostream>
using namespace std;

class RealNum {
	float *tab;
	int length;
public:
	RealNum();
	RealNum(int);
	~RealNum();
	void dispArray(int);
	float getElement(int);
	friend RealNum diffArrays(RealNum tab1, RealNum tab2);
};

//Constructor w/ no parameters
RealNum::RealNum() {
	this->length = MAX;
	tab = new float[length];
	for (int i = 0; i < length; i++)
		*(tab + i) = 0;
}

//Constructor w/ parameters
RealNum::RealNum(int num) {
	this->length = num;
	tab = new float[length];
	cout << "\nPlease enter the numbers: ";
	for (int i = 0; i < length; i++) {
		cout << "arr[" << i << "]";
		cin >> *(tab + i);
	}
}

//Destructor
RealNum::~RealNum() {
	this->length = 0;
	delete[] tab;
}

//Method to display an array
void RealNum::dispArray(int length) {
	cout << "\nArray: ";
	for (int i = 0; i < length; i++)
		cout << *(tab + i)<< " ";
}

//Getter for an element of the array
float RealNum::getElement(int pos) {
	return tab[pos];
}

RealNum diffArrays(RealNum tab1, RealNum tab2) {
	int newLength;
	if (tab1.length == tab2.length)
		newLength = tab1.length;
	else
		if (tab1.length < tab2.length)
			newLength = tab1.length;
		else
			newLength = tab2.length;
	for (int i = 0; i < newLength; i++)
		*(tab + i) = tab1.tab[i] - tab2.tab[i];
	return newLength;
}

int main() {
	int n1, n2, n3;
	cout << "Length of the first array: ";
	cin >> n1;
	cout << "Length of the second array: ";
	cin >> n2;

	RealNum ob1(n1), ob2(n2), tab3;
	ob1.dispArray(n1);
	ob2.dispArray(n2);
	n3 = tab3.diffArrays(ob1, ob2);
	tab3.dispArray(n3);
	cin.ignore();
	cin.get();
}