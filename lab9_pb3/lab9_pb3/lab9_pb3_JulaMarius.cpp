/*
	Author: Jula Marius
	Date: 3/5/18
	Description: Overload the new and delete operators for one of the classes implemented before,
				in order to allocate / deallocate the necessary amount of memory.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <iostream>
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
	void *operator new(size_t sizeTab);
	void operator delete(void *p);
};

void *Department::operator new(size_t sizeTab) {
	cout << "\nOverloading the new operator . . . ";
	return malloc(sizeTab);
}

void Department::operator delete(void *p) {
	cout << "\nOverloading the delete operator . . .";
	free(p);
}

int main() {
	int n, p;
	cout << "How many employees?"; cout << "\n Nr.: ";
	cin >> n;
	if (n < 1)
	{
		cout << "\nThe number of employees must be greater or equal to 1!";
		cin.get(); cin.ignore();
		exit(0);
	}
	Department *ob;
	ob = new Department(n);
	if (!ob) {
		cout << "\nMemory allocation unsuccessful";
		cin.get(); cin.ignore();
		exit(0);
	}
	ob->introduce(n);
	cout << "\nEnter the index of the employee: ";
	cin >> p;
	ob[p];
	delete(ob);
	cin.get();
	cin.ignore();
	return 0;
}