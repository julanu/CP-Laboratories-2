/*
Author: Jula Marius
Date: 13/4/18
Description: Develop the application from example 6 with new facilities that allow :
-using the returned values of the method setValidCnp() to suplementary validate the
CNP(month and day) in main()
- introducing CNP codes that start with numbers different than 1 or 2 and analyze the
significance of the new numbers(odd values – boys, even values - girls).
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include <time.h>

const int dim_sir = 24;

class Person {
	// membri private
	char nume[dim_sir];
	char prenume[dim_sir];
	char cnp[14];
	// structura CNP: S AN LU ZI 6cifre; total 13 cifre
public:
	// membri publici
	void setNume(char *n);
	void setPrenume(char *p);
	int setValidCnp(char *c);
	char* getNume(void) {
		return nume;
	}
	char* getPrenume(void) {
		return prenume;
	}
	char* getCnp(void) {
		return cnp;
	}
	char get_gender(void);
	int get_an_nast(void);
	int get_luna_nast(void);
	int get_zi_nast(void);
	int get_varsta(void);
};
void Person::setNume(char *n) {
	if (n != 0)
		strncpy_s(nume, n, dim_sir - 1);
	else
		strcpy_s(nume, "Necunoscut");
}
void Person::setPrenume(char *p) {
	if (p != 0)
		strncpy_s(prenume, p, dim_sir - 1);
	else
		strcpy_s(prenume, "Necunoscut");
}
int Person::setValidCnp(char *c) {
	char buf[3];
	int n;
	if (c != 0) {
		// validare CNP: numai pentru cifra gen, cifrele pentru AN, LU, ZI
		if (strlen(c) != 13)//lungime cnp
			return 1;
		if (c[0] != '1' && c[0] != '2')//cod cnp
			return 2;
		strncpy_s(buf, c + 1, 2);//an
		buf[2] = '\0';
		n = atoi(buf);
		if (n > 99)
			return 3;
		strncpy_s(buf, c + 3, 2);//luna
		buf[2] = '\0';
		n = atoi(buf);
		if (n == 0 || n > 12)
			return 4; strncpy_s(buf, c + 5, 2);//zi
		buf[2] = '\0';
		n = atoi(buf);
		if (n == 0 || n > 31)
			return 5;
		strcpy_s(cnp, c);//copiere sir c valid in cnp
		return 0;
	}
	else return -1;
}
char Person::get_gender(void) {
	if (cnp[0] == '1') return 'M';
	if (cnp[0] == '2') return 'F';
	return 'X';
}
int Person::get_an_nast(void) {
	char buf[3];
	strncpy_s(buf, cnp + 1, 2);
	buf[2] = '\0';
	return(1900 + atoi(buf));
}
int Person::get_luna_nast(void) {
	char buf[3];
	strncpy_s(buf, cnp + 3, 2);
	buf[2] = '\0';
	return(atoi(buf));
}
int Person::get_zi_nast(void) {
	return((cnp[5] - '0') * 10 + (cnp[6] - '0'));
}
int Person::get_varsta(void) {
	struct tm newTime;
	time_t szClock;
	time(&szClock);
	localtime_s(&newTime, &szClock);
	int an_c = 1900 + newTime.tm_year;
	int an_n = get_an_nast();
	int n = an_c - an_n;
	int lu_c = newTime.tm_mon + 1;
	int lu_n = get_luna_nast();
	if (lu_c < lu_n)
		n--;
	else {
		if (lu_c == lu_n) {
			int zi_c = newTime.tm_mday;
			int zi_n = get_zi_nast();
			if (zi_c < zi_n)
				n--;
		}
	}return n;
}
int main() {
	Person p1;
	char aux_string[dim_sir];

	cout << "\nEnter Name: ";
	cin >> aux_string;//Popescu
	p1.setNume(aux_string);
	cout << "\nEnter SurName: ";
	//cin >> aux_string;//Bitanescu
	cin.ignore();
	gets_s(aux_string, dim_sir);//Preia Prenume si cu spatiu
	p1.setPrenume(aux_string);
	cout << "\nEnter CNP: ";
	cin >> aux_string;//1890403120671
	int t_cnp = p1.setValidCnp(aux_string);
	switch (t_cnp) {
	case 0: cout << "\nCNP valid\n";
		cout << "\nDate despre obiect: " << endl;
		cout << "\tNume: " << p1.getNume() << ", Prenume: " << p1.getPrenume() << ",
			CNP: " << p1.getCnp() << endl;
			cout << "\tGen: " << p1.get_gender() << endl;
		cout << "\tData nasterii: " << p1.get_an_nast() << "/" << p1.get_luna_nast() <<
			"/" << p1.get_zi_nast() << endl;
		cout << "\tVarsta: " << p1.get_varsta() << endl; break;
	case 1: cout << "\nLungime sir CNP invalid"; break;
	case 2: cout << "\nGen invalid"; break;
	case 3: cout << "\nAn invalid"; break;
	case 4: cout << "\nLuna invalida"; break;
	case 5: cout << "\nZi invalida"; break;
	default: cout << "\nProbleme CNP"; break;
	}
	cin.ignore();
	cin.get();
	return 0;
}