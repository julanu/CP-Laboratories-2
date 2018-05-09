/*/
Author: Jula Marius
Date: 9/5/18
Description:Considering the first example (simple inheritance, the base class Pozitie and the derived class
Punct), resolve the following tasks:
a. verify the order in which the constructors and destructors are called
b. extend the main function in order to use all the methods from the base and derived
class
c. write a new class called Cerc (attributes and methods) derived from Pozitie
d. write a program that uses the classes mentioned before
*/

#include <iostream>
using namespace std;
// clasa de baza
class Pozitie {
protected:
	int x, y;
public:
	Pozitie(int = 0, int = 0);
	Pozitie(const Pozitie &);
	~Pozitie();//void afisare();
			   //void deplasare(int, int);
	virtual void afisare();
	virtual void deplasare(int, int);
};
// constructor
Pozitie::Pozitie(int abs, int ord)
{
	x = abs; y = ord;
	cout << "Constructor CB \"Pozitie\", ";
	afisare();//CB
}
//constructor de copiere
Pozitie::Pozitie(const Pozitie &p)
{
	x = p.x;
	y = p.y;
	cout << "Constructor de copiere CB \"Pozitie\", ";
	afisare();//CB
}
// destructor
Pozitie::~Pozitie()
{
	cout << "Destructor CB \"Pozitie \", ";
	afisare();//CB
}
void Pozitie::afisare()
{
	cout << " CB afisare: coordonate: x = " << x << ", y = " << y << "\n";
}
void Pozitie::deplasare(int dx, int dy)
{
	cout << "CB: deplasare" << endl;
	x += dx; y += dy;
}
// clasa derivata
class Punct : public Pozitie {
	int vizibil;
	char culoare;
public:
	Punct(int = 0, int = 0, char = 'A');
	Punct(const Punct &);
	~Punct();
	void arata() {
		vizibil = 1;
	}
	void ascunde() {
		vizibil = 0;
	}
	void coloreaza(char c) {
		culoare = c;
	}
	void deplasare(int, int);
	void afisare();
};
// constructor
Punct::Punct(int abs, int ord, char c) :Pozitie(abs, ord)
{
	vizibil = 0;
	culoare = c;
	cout << "Constructor CD \"Punct\", ";
	afisare();//CD
}
// constructor de copiere
Punct::Punct(const Punct &p) :Pozitie(p.x, p.y)
{
	vizibil = p.vizibil;
	culoare = p.culoare;
	cout << "Constructor de copiere CD \"Punct\", ";
	afisare();//CD
}
// destructor
Punct::~Punct()
{
	cout << "Destructor CD \"Punct\", ";
	afisare();//CD
}
// redefinire functie de afisare in clasa derivata
void Punct::afisare()
{
	cout << "CD afisare: Pozitie: x = " << x << ", y = " << y;
	cout << ", culoare: " << culoare;
	if (vizibil)
		cout << ", vizibil \n";
	else
		cout << ", invizibil \n";
}
// redefinire functie de deplasare in clasa derivata
void Punct::deplasare(int dx, int dy)
{
	if (vizibil) {
		cout << " CD: Deplasare: ";
		afisare();//CD
	}
	x += dx;
	y += dy;
	if (vizibil) {
		cout << "la coordonatele: ";
		Pozitie::afisare();//CB
	}
}


class Cerc :public Pozitie {
protected:
	double radius;
public:
	Cerc(double r) : Pozitie(r){
		cout << "\nMessage from derived constructor";
}
};// program ce utlizeaza clasa derivata
int main(void)
{
	Pozitie pp0(7, 7);
	cout << "\n Metode CB \n";
	pp0.afisare();
	pp0.deplasare(6, 9);
	pp0.afisare();
	cout << "\n Metode CD \n";
	Punct p0(1, 1, 'V');
	p0.afisare();
	Punct p1(p0);
	p1.arata();
	p1.deplasare(10, 10);
	cout << "\nUpcasting - obiecte:\n";
	pp0 = p0;//upcasting
	pp0.afisare();//CB
	cout << "\nUpcasting - pointeri:\n ";
	Pozitie *p;//base class pointer
	p = new Punct(100, 100, 'Z');//derived object to the base class pointer
								 //cout<<"\nAfisare CB: \n"; non virtual
	cout << "\nAfisare CD: derived class object if virtual, else base class CB \n";
	p->afisare();
	p = &pp0;
	cout << "\nAfisare CB: base class object always\n";
	p->afisare();
	p = &p1;
	//cout<<"\nAfisare CB: \n"; non virtual
	cout << "\nAfisare CD: derived class object if virtual, else base class CB \n";
	p->afisare();
	Punct *pp;
	pp = &p1;
	cout << "\nAfisare CD: derived class object always\n";
	pp->afisare();
	cout << "\nAfisare CB: derived object displayed with base class method always\n";
	pp->Pozitie::afisare();
	cout << "\nDowncasting:\n ";
	Punct *pdown;//derived pointer
	pdown = (Punct*)&pp0;//base class object
	cout << "\nAfisare CB: base class object using a derived pointer, else derived class CD \n";
	pdown->afisare();
	cin.get();
	return 0;
}//main