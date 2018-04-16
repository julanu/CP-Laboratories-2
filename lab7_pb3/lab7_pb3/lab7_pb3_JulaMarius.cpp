/*
Author: Jula Marius
Date: 16/4/18
Description: Model in OOP a class named Student containing name, surname and the marks from the
winter session exams. Display the name of the students who have arears exams and the first
three students in the group.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Student {
	char *name;
	char *surname;
	float marks[5]; //5 exams
public:
	Student();
};

Student::Student() {
	name = new char[0];
	surname = new char[0];
}