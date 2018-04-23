#include <iostream>
using namespace std;
class myClass {
private:
	int x, y;
public:
	friend double media(myClass);
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
};
double media(myClass x) { // implementarea functiei friend
	double rez;
	rez = (x.x + x.y) / 2.;
	return rez;
}
int main(void) {
	myClass ob1;
	int x, y;
	cout << "\nValoarea lui x: ";
	cin >> x;
	cout << "\nValoarea lui y: ";
	cin >> y;
	ob1.setX(x);
	ob1.setY(y); cout << "\nMedia aritmetica a celor doua numere este: " << media(ob1);
	cin.ignore();
	cin.get();
	return 0;
}