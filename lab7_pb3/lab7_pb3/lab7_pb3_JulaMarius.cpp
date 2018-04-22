/*
Author: Jula Marius
Date: 16/4/18
Description: Model in OOP a class named Student containing name, surname and the marks from the
winter session exams. Display the name of the students who have arears exams and the first
three students in the group.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

class Student {
	char *name;
	char *surname;
	int nr_marks;
	float *marks;
public:
	Student();
	Student(char *, char *, int);
	~Student();
	char* getName();
	char* getSurname();
	void setName(char *);
	void setSurname(char *);
	float meanValue();
	int arearsStud();
};

//Constructor w/ no parameters
Student::Student() {
	name = new char[30];
	surname = new char[30];
	cout << "\nName: ";
	cin >> this->name;
	cout << "\nSurname: ";
	cin >> this->surname;
	cout << "\nNumber of exams: ";
	cin >> this->nr_marks;
	marks = new float[nr_marks];
	cout << "\nEnter the marks: ";
	for (int i = 0; i < nr_marks; i++) {
		cout << "\nExam " << i + 1 << ":";
		cin >> *(marks + i);
	}
}

//Constructor w/ parameters
Student::Student(char *newName, char *newSurname, int NrMarks) {
	strcpy(this->name, newName);
	strcpy(this->surname, newSurname);
	this->nr_marks = NrMarks;
	marks = new float[nr_marks];
	cout << "\nEnter the marks: ";
	for (int i = 0; i < nr_marks; i++) {
		cout << "\nExam " << i + 1 << ":";
		cin >> *(marks + i);
	}
}

//Destructor
Student::~Student() {
	delete[] marks;
	nr_marks = 0;
}

//The mean value of the exams
float Student::meanValue()
{
	float s = 0.0;
	for (int i = 0; i < nr_marks; i++)
		s += *(marks + i);
	return (s / nr_marks);
}

//Method to check if a student has arears
int Student::arearsStud()
{
	for (int i = 0; i < nr_marks; i++)
		if (*(marks + i) < 5) {
			cout << this->surname;
			return -1; //not ok
		}
	cout << this->surname;
	return 1; // ok
}

//Getter for the name of the student
char* Student::getName() {
	return name;
}

//Getter for the surname of the student
char* Student::getSurname() {
	return surname;
}

//Setter for the name
void Student::setName(char *newName) {
	strcpy(name, newName);
}

//Setter for the surname
void Student::setSurname(char *newSurname) {
	strcpy(surname, newSurname);
}


int main()
{
	int nrStuds;
	cout << "\nEnter the number of students: ";
	cin >> nrStuds;

	//we check if there are students who have arears
	Student *group = new Student[nrStuds];
	cout << "\n1 = no arears | -1 = arears\n";
	for (int i = 0; i < nrStuds; i++)
		group[i].arearsStud();

	float *exams;
	exams = new float[nrStuds];
	//mean value of the exams for each student
	for (int i = 0; i < nrStuds; i++)
		*(exams + i) = group[i].meanValue();

	char buffer[30];
	//we now sort the group of students based on the exams and the results, simple bubble sort
	int flag, count;
	count = 0; //iterations
	for (int i = 0; i < nrStuds; i++) {
		flag = 0;
		for (int j = 1; j < nrStuds - count; j++) {
			if (*(exams + j - 1) > *(exams + j)) {//it will be sorted decreasing
				float temp;
				temp = *(exams + j - 1);
				*(exams + j - 1) = *(exams + j);
				*(exams + j) = temp;
				//we must sort also the names, surnames of the students
				//name
				strcpy(buffer, (group + j - 1)->getName()); // no pointer to value needed for getName
				group[j - 1].setName((group + j)->getName()); //can't use  *(group + j).setName(smth);
				group[j].setName(buffer);
				//surname
				strcpy(buffer, (group + j - 1)->getSurname());
				group[j - 1].setSurname((group + j)->getSurname()); //no pointer to value need for getSurname
				group[j].setSurname(buffer);
			}//if
		}
		count += 1;
		if (!flag)
			break;
	}//bubble
	cout << "\nTOP 3\n";
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << "."<< group[i].getName() << " ";
		cout << group[i].getSurname() << "\n";
	}
	cin.ignore();
	cin.get();

}