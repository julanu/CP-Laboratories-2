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
	friend void copy(CurrentHour&, CurrentHour);
};

//Constructor w/o parameters
CurrentHour::CurrentHour() {
	time_t t = time(0);  // current time: http://cplusplus.com/reference/clibrary/ctime/time/
	struct tm * now = localtime(&t);  // http://cplusplus.com/reference/clibrary/ctime/localtime/
									  // struct tm: http://cplusplus.com/reference/clibrary/ctime/tm/
	int hour2 = now->tm_hour;
	int minutes2 = now->tm_min;
	int seconds2 = now->tm_sec;
	this->hour = hour2;
	this->minute = minutes2;
	this->second = seconds2;
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

//Method that copies the content of a CurrentHour object into another instance of the class
void copy(CurrentHour &ob, CurrentHour ob2) {
	ob.hour = ob2.getHour();
	ob.minute = ob2.getMinutes();
	ob.second = ob2.getSeconds();
}

int main() {
	int hh, mm, ss;
	cout << "Please set the time for an obj: ";
	cout << "\nHour:"; cin >> hh;
	cout << "Minutes:"; cin >> mm;
	cout << "Seconds:"; cin >> ss;
	CurrentHour ob1(hh, mm, ss);
	cout << "\nTime in the first obj established by the user";
	cout << ob1.getHour() << ":" << ob1.getMinutes() << ":" << ob1.getSeconds() << endl;
	CurrentHour ob2;
	cout << "\nTime in the second obj taken from the local time";
	cout << ob2.getHour() << ":" << ob2.getMinutes() << ":" << ob2.getSeconds() << endl;
	copy(ob1, ob2);
	cout << "\nTime in the first object copied from the second obj";
	cout << ob1.getHour() << ":" << ob1.getMinutes() << ":" << ob1.getSeconds() << endl;
	cin.get(); 
	cin.ignore();
	return 0;
}