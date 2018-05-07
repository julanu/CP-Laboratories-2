/*
Author:
Date:
Description: Implement the program presented in the 1-st example and examine the compilation errors if
are? Modify the program so the object obiect_derivat will be able to access the aduna() and
scade() methods, from the main() function.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Baza
{
protected:
	int a, b;
public:
	void setA(int a) { this->a = a; }
	void setB(int b) { this->b = b; }
	Baza() { a = 1, b = 1; }
	
	void disp_base() {
		cout << "\nAfis din baza: " << a << " " << b << '\n';
	}
};
class Derivata : public Baza
{
public:
	int multiply() {
		return a * b;
	}
	int sum() {
		return a + b;
	}
	int substract() {
		return a - b;
	}
};
int main(void)
{
	Baza obiect_baza;
	obiect_baza.disp_base();
	obiect_baza.setA(2);
	obiect_baza.setB(3);
	obiect_baza.disp_base();
	Derivata obiect_derivat;
	obiect_derivat.setA(2);
	obiect_derivat.setB(3);
	cout << "\nThe product is= " << obiect_derivat.multiply(); // all of the methods will have implicit values
	cout << "\nThe sum is= " << obiect_derivat.sum();
	cout << "\nThe decrease is= " << obiect_derivat.substract();
	cin.get();
	return 0;
}