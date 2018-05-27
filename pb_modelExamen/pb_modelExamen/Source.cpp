#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 50;

class Carte {
protected:
	char title[MAX];
	char author[MAX];
	int domain;
public:
	char *getAuthor() {
		return author;
	}
	char *getTitle() {
		return title;
	}
	int getDomain() {
		return domain;
	}
	Carte() { }
	Carte(char title[], char author[], int domain) { // Constructor w/ parameters
		strcpy(this->title, title);
		strcpy(this->author, author);
		this->domain = domain;
	}
	virtual void afis() {
		cout << "\nTitle: " << title;
		cout << "\nAuthor: " << author;
		cout << "\nDomain: " << domain;
	}
	friend ostream& operator<< (ostream &stream, Carte &ob){
		stream << "Title: " << ob.title << endl;
		stream << "Author: " << ob.author << endl;
		stream << "Domain: " << ob.domain << endl;
		return stream;
	}
};

class Carte_Probleme : public Carte {
private:
	int nr_probleme_propuse;
	int nr_probleme_rezolvate;
public:
	Carte_Probleme() { }
	Carte_Probleme(char title[], char author[], int domain, int pb_prop, int pb_rez) : Carte(title, author, domain) {
		strcpy(this->title, title);
		strcpy(this->author, author);
		nr_probleme_propuse = pb_prop;
		nr_probleme_rezolvate = pb_rez;
	}
	virtual void afis() {
		cout << "\nTitle: " << title;
		cout << "\nAuthor: " << author;
		cout << "\nDomain: " << domain;
		cout << "\nProbl. rez.: " << nr_probleme_rezolvate;
		cout << "\nProbl. prop.: " << nr_probleme_propuse;
	}
};

// Overloading the insertion operator


int main() {
	char titlu[MAX], autor[MAX];
	int domeniu;
	cout << "Title: "; cin >> titlu;
	cout << "Author: "; cin >> autor;
	cout << "Domain: "; cin >> domeniu;
	// Instantiating
	Carte ob_base(titlu, autor, domeniu);
	Carte_Probleme ob_deriv(titlu, autor, domeniu, 100, 10);
	cout << "DISP BASE OBJ\n";
	ob_base.afis();
	cout << "\nDISP DERIVED OBJ\n";
	ob_deriv.afis();
	// Class specific pointer
	cout << "\nDISP THROUGH SPECIFIC POINTER\n";
	Carte *ptOB;
	ptOB = &ob_base;
	ptOB->afis();
	// Start to process for file
	char filename[MAX];
	cout << "\nName of the file for the object to be saved: ";
	cin >> filename;
	ofstream out;
	out.open(filename);
	if (!out.good()) { // Checking if the file is present
		cout << "File does not exist, re-enter the name: ";
		cin >> filename;
	}
	// Writting the base object in the file
	out << ob_base;
	cin.get();
	cin.ignore();
	return 0;
}
