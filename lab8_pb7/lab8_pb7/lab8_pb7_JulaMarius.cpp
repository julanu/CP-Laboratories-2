/*
Author: Jula Marius
Date: 23/4/18
Description: A kiosk sells newspapers, magazines and books. Each publication has a name, an editorial house, a
number of pages, the number of copies and a price (no VAT). Write the class that models the publications.
Introduce a static member named VAT_value (percentage) and a static method that modifies the value of
this variable. Determine the total income and the average price per page for each publication type. Modify
the VAT and redo the calculations. Order the printing houses by the total income and display the result.
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#include <iostream>
using namespace std;

class Publication {
	char *name;
	char *ed_house;
	int nr_pages;
	int nr_copies;
	double price;
public:
	static int VAT;
	Publication();
	Publication(char *, char *, int, int, double);
	void setVAT(int);
	int getPages();
	int getCopies();
	char* getPrintHouse();
	double getPrice();
	double getIncome(Publication);

};

//Constructor w/o parameters
Publication::Publication() {
	name = new char[MAX];
	ed_house = new char[MAX];
	strcpy(this->name, "Unknown");
	strcpy(this->ed_house, "Unknown");
	this->nr_pages = 0;
	this->nr_copies = 0;
	this->price = 0.0;
}

int Publication::VAT = 19; //we set the VAT to 19%

//Constructor w/ parameters
Publication::Publication(char *newName, char *newEdHouse, int newNrPages, int newNrCopies, double newPrice) {
	name = new char[MAX];
	ed_house = new char[MAX];
	strcpy(this->name, newName);
	strcpy(this->ed_house, newEdHouse);
	this->nr_pages = newNrPages;
	this->nr_copies = newNrCopies;
	this->price = newPrice;
}

//Getter for the number of pages
int Publication::getPages() {
	return this->nr_pages;
}

//Getter for the number of copies
int Publication::getCopies() {
	return this->nr_copies;
}

//Getter for the price
double Publication::getPrice() {
	return this->price;
}

//Setter for the VAT
void Publication::setVAT(int newVAT) {
	this->VAT = newVAT;
}

//Getter for the print house
char* Publication::getPrintHouse() {
	return this->ed_house;
}

//Method to compute the total income of a publication
double Publication::getIncome(Publication x) {
	double total_income = 0.0, price_withVAT = 0.0;
	price_withVAT = x.price + x.VAT * x.price;
	total_income = x.nr_copies * price_withVAT;
	return total_income;
}

//Swap function
void ft_swap(double a, double b) {
	double temp;
	temp = a;
	a = b;
	b = temp;
}



int main() {
	char *carte, *editura;
	carte = new char[50];
	editura = new char[50];


	cout << "\nIntroduceti numele ziarului: "; cin >> carte;
	cout << "\nIntroduceti numele editurii: "; cin >> editura;
	Publication journal(carte, editura, 15, 500, 5.5);
	cout << "\nIntroduceti numele revistei: "; cin >> carte;
	cout << "\nIntroduceti numele editurii: "; cin >> editura;
	Publication magazine(carte, editura, 40, 2000, 11.99);
	cout << "\nIntroduceti numele cartii: "; cin >> carte;
	cout << "\nIntroduceti numele editurii: "; cin >> editura;
	Publication book(carte, editura, 600, 1500, 32.5);

	double inc1, inc2, inc3;
	inc1 = journal.getIncome(journal);
	inc2 = magazine.getIncome(magazine);
	inc3 = book.getIncome(book);
	if (inc1 > inc2)
		ft_swap(inc1, inc2);
	if (inc1 > inc3)
		ft_swap(inc1, inc3);
	if (inc2 > inc3)
		ft_swap(inc2, inc3);
	cout << "\n" << book.getPrintHouse();
	cout << "\nProfit: " << inc3;
	cout << "\n" << magazine.getPrintHouse();
	cout << "\nProfit: " << inc2;
	cout << "\n" << journal.getPrintHouse();
	cout << "\nProfit: " << inc1;
	cin.get();
	int newVAT;
	cout << "\nEnter the new VAT: "; cin >> newVAT;
	Publication::VAT = newVAT;
	//re calculation of the profits
	inc1 = journal.getIncome(journal);
	inc2 = magazine.getIncome(magazine);
	inc3 = book.getIncome(book);
	if (inc1 > inc2)
		ft_swap(inc1, inc2);
	if (inc1 > inc3)
		ft_swap(inc1, inc3);
	if (inc2 > inc3)
		ft_swap(inc2, inc3);
	cout << "\nThe print houses sorted by profit ";
	cout << "\n" << book.getPrintHouse();
	cout << "\nProfit: " << inc3;
	cout << "\n" << magazine.getPrintHouse();
	cout << "\nProfit: " << inc2;
	cout << "\n" << journal.getPrintHouse();
	cout << "\nProfit: " << inc1;
	cin.get();
	cout << "\nPress any key to exit . . . ";
	getchar();
	return 0;
}