/*
Author: Jula Marius
Date: 5/3/18
Description: Overload the [] operator for the Department class that contains an array of Employee objects (that has as
variables the name (character array) and the salary (float)). When the operator is applied to a Department
object, it returns (or displays) all the data related to the Employee object with that index.
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <iostream>
#include <cstring>
using namespace std;
class Employee {
	char name[MAX];
	float salary;
public:
	Employee() {
		strcpy(name, "Unknown");
		salary = 1200;
	}
	Employee(char *newName, float newSalary) {
		strcpy(name, newName);
		salary = newSalary;
	}
	float getSalary() {
		return salary;
	}
	char* getName() {
		return name;
	}
	void display() {
		cout << "\nName: " << this->name;
		cout << "\nSalary: " << this->salary;
	}
};

class Department {
	Employee *tab;
	int nr;
public:
	Department() {
		tab = new Employee[5];
		nr = 5;
	}
	Department(int newNr) {
		tab = new Employee[newNr];
		nr = newNr;
	}
	void introduce(int nr) {
		char name[MAX];
		float salary;
		for (int i = 0; i < nr; i++) {
			cout << "\nEnter the data for person " << i + 1;
			cout << "\nName = "; 
			cin >> name;
			cout << "Salary = ";
			cin >> salary;
			tab[i] = Employee(name, salary);
		}
	}
	void operator[](int pos) {
				tab[pos - 1].display();
	}
};

int main() {
	int n, p;
	cout << "How many employees?"; cout << "\n Nr.: ";
	cin >> n;
	Department ob(n);
	ob.introduce(n);
	cout << "\nEnter the index of the employee: "; 
	cin >> p;
	ob[p];
	cin.get();
	cin.ignore();
	return 0;
}