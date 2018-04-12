/*
Author: Jula Marius
Date: 12/4/18
Description:Write a C++ application that implements a class called F1Pilot. The class defines the private
variables name (array of characters), team (array of characters), age (int), best_time (int) and
pole_position_nr. As public members, the class contains mutator/setter and accessor/getter
methods for each of the class’s attributes.
In function main(), create 3 different instances of the F1Pilot class and use the mutator
methods for initializing each object’s data with the corresponding information read from the
keyboard. Using the accessor methods, display all the data related to the pilot that has the best
time.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

class F1Pilot {
	char *name;
	char *team;
	int age;
	int best_time;
	int pole_position_nr;
public:
	void setAge(int);
	void setTime(int);
	void setPolePos(int);
	void setName(char *);
	void setTeam(char *);
	char* getTeam();
	char* getName();
	int getAge();
	int getTime();
	int getPos();
};

//main
int main()
{
	F1Pilot ob1[3];
	char *name, *team; //variables used for reading the data from the KB
	int time, pos, age;
	//initialize the arrays of chars
	name = new char[30];
	team = new char[30];
	for (int i = 0; i < 3; i++)
	{
		cout << "Please enter the name for pilot " << i + 1 << ":";
		cin >> name;
		cout << "Please enter the team for pilot " << i + 1 << ":";
		cin >> team;
		cout << "Please enter the age for pilot " << i + 1 << ":";
		cin >> age;
		cout << "Please enter the best time for pilot " << i + 1 << ":";
		cin >> time;
		cout << "Please enter the pole position number for pilot " << i + 1 << ":";
		cin >> pos;
		ob1[i].setAge(age); //we now set the data for the class
		ob1[i].setTime(time);
		ob1[i].setPolePos(pos);
		ob1[i].setName(name);
		ob1[i].setTeam(team);
	}

	int min = ob1[0].getTime();
	int i = 0;//we use this index to determine the position of the object with the best time
	if (min > ob1[1].getTime()) {
		min = ob1[1].getTime();
		i = 1;
	}
	if (min > ob1[2].getTime()) {
		min = ob1[2].getTime();
		i = 2;
	}
	//now to display the data 
	cout << endl << "RESULTS" << endl;
	cout << "Pilot " << i << endl;
	cout << "Name: " << ob1[i].getName() << endl;
	cout << "Age: " << ob1[i].getAge() << endl;
	cout << "Team: " << ob1[i].getTeam() << endl;
	cout << "Time: " << ob1[i].getTime() << endl;
	cout << "Position: " << ob1[i].getPos();
	cin.get(); cin.get();
}

//Setter for the age of the pilot
void F1Pilot::setAge(int newAge) {
	age = newAge;
}

//Setter for the best time of the pilot
void F1Pilot::setTime(int newTime) {
	best_time = newTime;
}

//Setter for the pole_position_nr
void F1Pilot::setPolePos(int newPos) {
	pole_position_nr = newPos;
}

//Setter for the name of the pilot
void F1Pilot::setName(char *newName) {
	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);
}

//Setter for the team of the pilot
void F1Pilot::setTeam(char *newTeam) {
	this->team = new char[strlen(newTeam) + 1];
	strcpy(this->team, newTeam);
}

//Getter
char* F1Pilot::getTeam() {
	return team;
}

//Getter
char* F1Pilot::getName() {
	return name;
}

//Getter
int F1Pilot::getAge() {
	return age;
}

//Getter
int F1Pilot::getTime() {
	return best_time;
}

//Getter 
int F1Pilot::getPos() {
	return pole_position_nr;
}
