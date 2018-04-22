/*
Author: Jula Marius
Date: 22/4/18
Description: Create a class named Student that has as private attributes the name, surname, some marks,
the group and the average_mark. Allocate the necessary amount of memory for storing n
students. The constructor method will initialize 6 marks corresponding to the disciplines
studied in the 1st semester. Determine the average mark for each student and use it for sorting
the students. Display the ordered array (name, surname, group, average_mark). The
destructor will display a message.
*/
#define _CRT_SECURE_NO_WARNINGS

#include  <iostream>
#include  <cstring>
#include <cstdlib>
using  namespace  std;

class  Student {
	char  *name;
	char  *surname;
	int group;
	float marks[6];
	float avg_mark; 
public:
	Student();
	Student(char  *, char  *, int);
	~Student();
	char*  getName();
	char*  getSurname();
	float getAvg();
	int getGroup();
	void  setName(char  *);
	void  setSurname(char  *);
	void  avgMark();
};

//Constructor  w/  no  parameters
Student::Student() {
	name = new  char[30];
	surname = new  char[30];
	cout << "\nName:  ";
	cin >> this->name;
	cout << "\nSurname:  ";
	cin >> this->surname;
	cout << "Enter the group: ";
	cin >> this->group;
	cout << "\nEnter  the  marks from the first semester:  ";
	for (int i = 0; i < 6; i++) {
		cout << "\nExam  " << i + 1 << ":";
		cin >> *(marks + i);
	}
}

//Constructor  w/  parameters
Student::Student(char  *newName, char  *newSurname, int  newGroup) {
	strcpy(this->name, newName);
	strcpy(this->surname, newSurname);
	this->group = newGroup;
	cout << "\nEnter  the  marks:  ";
	for (int i = 0; i < 6; i++) {
		cout << "\nExam  " << i + 1 << ":";
		cin >> *(marks + i);
	}
}

//Destructor
Student::~Student() {
	cout << "\nDestructor";
	delete[] marks;
	group = 0;
}

//The  mean  value  of  the  exams
void Student::avgMark()
{
	float  s = 0.0;
	for (int i = 0; i < 6; i++)
		s += *(marks + i);
	this->avg_mark = s / 6;
}

//Getter for the average mark
float Student::getAvg() {
	return avg_mark;
}

//Getter for the group of the student
int Student::getGroup() {
	return group;
}

//Getter  for  the  name  of  the  student
char*  Student::getName() {
	return  name;
}

//Getter  for  the  surname  of  the  student
char*  Student::getSurname() {
	return  surname;
}

//Setter  for  the  name
void  Student::setName(char  *newName) {
	strcpy(name, newName);
}

//Setter  for  the  surname
void  Student::setSurname(char  *newSurname) {
	strcpy(surname, newSurname);
}

//Cmp function for qsort
int compareByAvg(Student elem1, Student elem2) {
	//Student ob1 = elem1;
	//Student ob2 = elem2;
	return ((int)((float)elem1.getAvg() - (float)elem2.getAvg()));
}
int  main()
{
	int  nrStuds;
	cout << "\nEnter  the  number  of  students:  ";
	cin >> nrStuds;
	Student  *group = new  Student[nrStuds];
	//call the sorting function
	qsort(group, nrStuds, sizeof(Student), compareByAvg(group[0], group[1]));
	//display the sorted array
	for (int i = 0; i < 6; i++) {
		cout << "\n" << group[i].getName();
		cout << "\n" << group[i].getSurname();
		cout << "\n" << group[i].getGroup();
		cout << "\n---------- ";
	}
	
	cin.ignore();
	cin.get();

}