/*
Author: Jula Marius
Date: 13/4/18
Description: Write a class named Safe that has as private attributes the cipher and the amount of money.
Implement the private methods getMoney() and setMoney(). The public methods putInSafe()and getFromSafe() will call the previous
methods only if the cipher sent as parameter matches the value stored inside the class. 
Display a message if the cipher is not correct.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Safe {
private:
	int cipher = 4321;
	double money;
	//Private getter for the amount of money
	double getMoney() {
		return money;
	}
	//Private setter for the amount of money
	void setMoney(double newAmount) {
		this->money = newAmount;
	}
public:
	void putInSafe(int, double);
	double getFromSafe(int);
};

//Setter for the amount of money
void Safe::putInSafe(int testCipher, double newAmount)
{
	if (this->cipher == testCipher)
		setMoney(newAmount);
	else
		cout << "Wrong cipher.";
}

//Getter for the amount of money
double Safe::getFromSafe(int testCipher)
{
	if (this->cipher == testCipher)
		return getMoney();
	else
		return -1;
}


void main() {
	Safe obj;
	int ciph;
	double sumMoney;

	cout << "Please enter the cipher: ";
	cin >> ciph;
	cout << "\nPlease enter the amount of money you want to deposit: ";
	cin >> sumMoney;
	obj.putInSafe(ciph, sumMoney);
	cout<< "\nMoney in the safe: " << obj.getFromSafe(ciph);

	cin.ignore();
	cin.get();
}