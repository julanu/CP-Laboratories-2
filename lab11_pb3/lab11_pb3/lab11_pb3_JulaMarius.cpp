/*
Author: Jula Marius
Date: 9/5/18
Description: Extend the base class from the second example by adding some other virtual methods, which
will be implemented in the derived classes (like the setter and getter for the value of greutate).
*/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

class Vehicul {
	int roti;
	float greutate;
public:
	virtual void mesaj(void)
	{
		cout << "Mesaj din clasa Vehicul\n";
	}
	virtual float getGreutate(void) {
		return greutate;
	}
	virtual void setGreutate(float greutate) {
		this->greutate = greutate;
	}
};
class Automobil : public Vehicul {
	int incarcatura_pasageri;
public:
	void mesaj(void)
	{
		cout << "Mesaj din clasa Automobil\n";
	}
};
class Camion : public Vehicul {
	int incarcatura_pasageri;
	float incarcatura_utila;
public:
	//getter
	int pasageri(void)
	{
		return incarcatura_pasageri;
	}
};
class Barca : public Vehicul {
	int incarcatura_pasageri;
public:
	//getter for the nr of passengers
	int pasegeri(void)
	{
		return incarcatura_pasageri;
	}
	void mesaj(void)
	{
		cout << "Mesaj din clasa Barca\n";
	}
};
int main(void)
{
	// direct call, through some specific objects
	Vehicul monocicleta;
	Automobil ford;
	Camion semi;
	Barca barca_de_pescuit;
	monocicleta.mesaj();
	ford.mesaj();
	semi.mesaj(); 
	barca_de_pescuit.mesaj();
	ford.setGreutate(14);
	cout << "Greutate ob ford: " << ford.getGreutate() << "\n";
	// calling through a pointer
	Vehicul *pmonocicleta;
	Automobil *pford;
	Camion *psemi;
	Barca *pbarca_de_pescuit;
	cout << "\n";
	pmonocicleta = &monocicleta;
	pmonocicleta->mesaj(); pford = &ford;
	pford->mesaj();
	psemi = &semi;
	psemi->mesaj();//din CB
	pbarca_de_pescuit = &barca_de_pescuit;
	pbarca_de_pescuit->mesaj();
	pbarca_de_pescuit->setGreutate(2000);
	cout << "Greutate ob barca de pescuit " << pbarca_de_pescuit->getGreutate() << "\n";
	// calling through a pointer to a object of the base class
	cout << "\n";
	pmonocicleta = &monocicleta;
	pmonocicleta->mesaj();//Vehicul
	pmonocicleta = &ford;//upcasting
	pmonocicleta->mesaj();//Automobil
	pmonocicleta = &semi;//upcasting
	pmonocicleta->mesaj();//Vehicul
	pmonocicleta = &barca_de_pescuit;//upcasting
	pmonocicleta->mesaj();//Barca
	pmonocicleta->setGreutate(400);
	cout << "Greutate ob monocicleta " << pmonocicleta->getGreutate() << "\n";
	cin.get();
	cin.ignore();
	return 0;
}