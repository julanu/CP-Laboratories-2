/*
Author: Jula Marius
Date: 23/4/18
Description: Implement a C++ application that defines the class called CurrentHour with hour, minute, second as
private members. The class has public setter/getter methods for each attribute. Add a friend function that
copies the content of a CurrentHour object into another instance of the class. Use the computer current
time.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
using namespace std;

class CurrentHour {
	int hour;
	int minute;
	int second;
public:
	CurrentHour();
	CurrentHour(int, int, int);
	~CurrentHour();
	void setHour(int);
	void setMinutes(int);
	void setSeconds(int);
	int getHour();
	int getMinutes();
	int getSeconds();
	friend void copyCurrentHour(CurrentHour ob);
};

//Constructor w/o parameters
CurrentHour::CurrentHour() {
	this->hour = 12;
	this->minute = 30;
	this->second = 0;
}

//Constructor w/ parameters
CurrentHour::CurrentHour(int newH, int newM, int newS) {
	this->hour = newH;
	this->minute = newM;
	this->second = newS;
}

//Destructor
CurrentHour::~CurrentHour() {
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}

//Setter for the hour
void CurrentHour::setHour(int newHour) {
	this->hour = newHour;
}

//Setter for the minutes
void CurrentHour::setMinutes(int newMinutes) {
	this->minute = newMinutes;
}

//Setter for the seconds
void CurrentHour::setSeconds(int newSeconds) {
	this->second = newSeconds;
}

//Getter for the hour
int CurrentHour::getHour() {
	return this->hour;
}

//Getter for the minutes
int CurrentHour::getMinutes() {
	return this->minute;
}

//Getter for the seconds
int CurrentHour::getSeconds() {
	return this->second;
}

//Method that copies the content of a CurrentHour object into another instance of the clas
void copyCurrentHour(CurrentHour ob) {
	time_t now = time(0);

	// convert now to string form
	char* dt = ctime(&now);
	cout << dt;
}

int main() {
	CurrentHour ob1, ob2;
	ob2.setHour(13); 
	ob2.setMinutes(24);
	ob1.copyCurrentHour(ob2);
	return 0;
}