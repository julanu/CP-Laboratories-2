/*
Author: Jula Marius
Date: 16/4/18
Description: Modify example 3 in order to allow the addition of two CPunctText points. The name of the
new point will be created from the names of the compounding points. Add a method that
returns the distance from a point to origin.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

const int dim_sir = 20;

class CPunctText {
	int x;
	int y;
	int lungime_sir;
	char *sNume;
public:
	//Explicit constructor w/ no parameters
	CPunctText();
	//Constructor w/ parameters
	CPunctText(int ix, int iy, const char *sText = "Punct");
	//Copy constructor
	CPunctText(const CPunctText &pct);
	//Destructor
	~CPunctText();
	//Method for the sum of two points
	friend CPunctText SumTwoPoints(CPunctText, CPunctText);
	//Display method
	void Afis() {
		cout << "\nObj has x= " << x;
		cout << "\nObj has y= " << y;
		cout << "\nObj has the string = " << sNume;
	}//afis
};
CPunctText::CPunctText() {
	cout << "\nExplicit constructor w/ no parameter";
	lungime_sir = dim_sir;
	sNume = new char[lungime_sir];
}

CPunctText::CPunctText(int ix, int iy, const char *sText) {
	cout << "\nConstructor w/ parameters";
	lungime_sir = strlen(sText) + 1;
	sNume = new char[lungime_sir];
	x = ix;
	y = iy;
	strcpy(sNume, sText);
}

CPunctText::CPunctText(const CPunctText &pct) {
	cout << "\nCopy constructor";
	sNume = new char[pct.lungime_sir];
	x = pct.x;
	y = pct.y;
	lungime_sir = pct.lungime_sir;
	strcpy(sNume, pct.sNume);
}
CPunctText::~CPunctText() {
	cout << "\nDestructor";
	delete[] sNume;
}

//Method for the sum of two points
CPunctText SumTwoPoints(CPunctText ob1, CPunctText ob2) {
	CPunctText ob;
	ob.x = ob1.x + ob2.x;//sum of the coordinates
	ob.y = ob.y + ob2.y;
	ob.lungime_sir = ob1.lungime_sir + ob2.lungime_sir;
	strcpy(ob.sNume, ob1.sNume);
	strcat(ob.sNume, ob2.sNume); //concatenate the two names	
	return ob;
}
void main(void) {
	CPunctText cpt1(1, 2, "Punct1");//call of the constructor w/ parameters
	CPunctText cpt2(cpt1); //call of the copy constructor
	CPunctText cpt3 = cpt2; //call of the copy constructor
	cpt3.Afis();
	CPunctText cpt4(4, 5); //call of the constructor w/ parameters
	cpt4.Afis();
	CPunctText cpt5 = SumTwoPoints(cpt1, cpt2); //call of the method
	cpt5.Afis();
	 cin.get();
}//main