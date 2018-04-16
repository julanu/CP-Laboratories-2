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
	float getElement(int);
	friend RealNum substractArray(RealNum, RealNum);
};

//Constructor w/ no parameters
RealNum::RealNum() {
	array = new float[MAX];
}

//Constructor w/ parameters
RealNum::RealNum(int num) {
	tab = new float[num];
}

//Destructor
RealNum::~RealNum(){
	delete[] tab;
}

//Getter for an element of the array
float RealNum::getElement(int pos) {
	return tab[pos];
}

RealNum substractArray(RealNum tab1, RealNum tab2){
	RealNum tab3

}
void main() {




	cin.ignore();
	cin.get();
}