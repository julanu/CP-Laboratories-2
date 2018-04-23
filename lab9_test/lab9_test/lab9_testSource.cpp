/*
Author: MJ
Date: 23/4/18
Description: from the lab
*/
g
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int MAX = 30;
class String {
	char sir[MAX];
public:
	String() { ; }
	String(char x[MAX]) {
		strcpy_s(sir, x);
	}
	char* getSir() {
		return sir;
	}
	String operator + (String x1) { // supraincarcare cu metoda membra
		String rez;
		strcpy_s(rez.sir, sir);
		strcat_s(rez.sir, x1.sir);
		return rez;
	}
	//functia prietena care supraincarca operatorul de scadere este definite in exteriorul clasei mai jos
	friend String operator-(String& x1, String& x2); char operator[](int poz) { // supraincarcarea op [] pt. returnarea unui
		char rez; // caracter din pozitia data in sir
		rez = sir[poz];
		return rez;
	}
};
// supraincarc. op. prin f-ctie friend, in exteriorul clasei
String operator-(String &x1, String &x2) {
	char *pp;
	pp = strstr(x1.sir, x2.sir); // adresa unde începe sirul x2.sir in sirul x1.sir
	if (pp == NULL) // sirul nu se gaseste in x1.sir
		return String(x1.sir);
	else {
		char buf[MAX];
		strncpy_s(buf, x1.sir, pp - x1.sir);
		strcpy(buf + (pp - x1.sir), pp + strlen(x2.sir));
		return String(buf);
	}
}
int main() {
	char xx[MAX];
	String ob3;
	char c;
	cout << "\n Dati un sir de caractere (I obiect): ";
	gets_s(xx, _countof(xx));
	String ob1(xx);
	cout << "\n Dati un sir de caractere (al II-lea obiect): ";
	cin.getline(xx, _countof(xx));
	String ob2(xx);
	ob3 = ob1 + ob2;
	cout << "\nSirul obtinut in urma adunarii: " << ob3.getSir();
	cout << "\n Sirul care va fi scazut din cel initial: ";
	gets_s(xx, _countof(xx));
	String ob4(xx);
	String ob5;
	ob5 = ob1 - ob4;
	cout << "\nSirul obtinut in urma scaderii: " << ob5.getSir();
	c = ob5[1];
	cout << "\n Al 2-lea caracter din sirul de mai sus este: " << c;
	cin.get();
	return 0;
}