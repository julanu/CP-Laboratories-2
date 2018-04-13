/*
Author: Jula Marius
Date: 12/4/18
Description: Write a C++ class that has as private variable a date field. The date is defined as a structure
declared outside the class and it contains the fields day – int, month – int, year – int. The class
contains public accessor/getter and mutator/setter methods that are capable of using the
private information. The class also contains two public methods that:
- test the validity of the stored date;
- write into a file all the dates from the current year that precede chronologically the class
stored date;
In the main() function, after instantiating the class and after reading from the keyboard all the
components of a date, call the member methods and then verify the obtained results.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
using namespace std;

struct datan {
	int day;
	int month;
	int year;
};

class Date {
private:
	datan d;
public:
	void setDate(int, int, int);
	datan getDate();
	int getDay();
	int getMonth();
	int getYear();
	void isValid(Date& date);
	void printToFile(FILE *, Date& date);
};

//Getter for the date struct
datan Date::getDate() {
	return d;
}

//Setter for the date
void Date::setDate(int newDay, int newMonth, int newYear) {
	d.day = newDay;
	d.month = newMonth;
	d.year = newYear;
}

//Getters for the day, month year
int Date::getDay() {
	return d.day;
}
int Date::getMonth() {
	return d.month;
}
int Date::getYear() {
	return d.year;
}

void Date::isValid(Date& date) {
	int dd, mm, yy;
	dd = date.getDay();
	mm = date.getMonth();
	yy = date.getYear();
	//check year
	if (yy >= 1900 && yy <= 9999)
	{
		//check month
		if (mm >= 1 && mm <= 12)
		{
			//check days
			if ((dd >= 1 && dd <= 31) 
				&& (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
				cout <<"Date is valid.\n";
			else if ((dd >= 1 && dd <= 30) 
				&& (mm == 4 || mm == 6 || mm == 9 || mm == 11))
				cout <<"Date is valid.\n";
			else if ((dd >= 1 && dd <= 28) && (mm == 2))
				cout <<"Date is valid.\n";
			else if (dd == 29 && mm == 2 
				&& (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))
				cout <<"Date is valid.\n";
			else
				cout <<"Day is invalid.\n";
		}
		else
		{
			cout <<"Month is not valid.\n";
		}
	}
	else
	{
		cout <<"Year is not valid.\n";
	}
}

void Date::printToFile(FILE *fs, Date& date) {
	//to work on this
	int j, i = date.getMonth(); //we use the index as an index for the months
	std::fstream fs; // I DONT KNOW 
	fs.open("test.txt", std::fstream::in | std::fstream::out | std::fstream::app); //THIS NEITHER

	if (fs.is_open())
		for (j = i; j <= 12; i++)
			if (j == 4 || j == 6 || j == 9 || j == 11)
				for (int k = 1; k <= 31; k++)
					fs << k << j << date.getYear() << endl;
			else
				for (int k = 1; k <= 30; k++)
					fs << k << j << date.getYear() << endl;
	fs.close();
}

void main()
{
	Date obj;
	FILE *f;
	std::fstream fs; //fuck is this
	fs.open("test.txt", std::fstream::in | std::fstream::out | std::fstream::app); //fuck is that

	obj.setDate(1, 3, 2000);
	obj.isValid(obj);
	obj.printToFile(fs, obj); //aici tre dat file-ul
	cin.ignore();
	cin.get();
}