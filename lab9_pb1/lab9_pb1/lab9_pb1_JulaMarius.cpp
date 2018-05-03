/*
Author: Jula Marius
Date: 3/5/18
Description: Starting with the 4-th example, verify/resolve the following tasks:
a. reading/writing a matrix with dimensions from KB;
b. test all the overloaded operators;
c. display the elements located on both diagonals
*/

//4. Implementarea clasei Matrix pt. efectuarea unor operatii cu matrici
// prin supraincarcarea unor operatori (=, +, -, *, () )
#include<iostream>
using namespace std;
const int linii = 2;
const int coloane = 3;
class Matrix {
	int rows;
	int cols;
	int *elems;
public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix&);
	~Matrix(void) { delete elems; }
	int& operator () (int row, int col);
	Matrix& operator=(const Matrix&);
	friend Matrix operator+(Matrix&, Matrix&);
	friend Matrix operator-(Matrix&, Matrix&);
	friend Matrix operator*(Matrix&, Matrix&);
	int getRows(void) { return rows; }
	int getCols(void) { return cols; }
	void init(int r, int c);
	void citire();
	void afisare();
	void afis_diag(Matrix&);
};//Matrix
Matrix::Matrix() : rows(linii), cols(coloane)
{
	elems = new int[rows * cols];
}
Matrix::Matrix(int r, int c) : rows(r), cols(c)
{
	elems = new int[rows * cols];
}
Matrix::Matrix(const Matrix &m) : rows(m.rows), cols(m.cols)
{
	int n = rows * cols;
	elems = new int[n];
	for (int i = 0; i < n; i++)
		elems[i] = m.elems[i];
}
void Matrix::init(int r, int c) {
	rows = r;
	cols = c;
	elems = new int[rows*cols];
}
int& Matrix:: operator()(int row, int col)
{
	return elems[row*cols + col];
}
Matrix& Matrix:: operator=(const Matrix &m) {
	if (this != &m)
	{
		int n = rows * cols;
		for (int i = 0; i < n; i++)
			elems[i] = m.elems[i];
	}
	return *this;
}
Matrix operator+(Matrix &p, Matrix &q) {
	Matrix m(p.rows, p.cols);
	for (int r = 0; r < p.rows; ++r)
		for (int c = 0; c < p.cols; ++c)
			m(r, c) = p(r, c) + q(r, c);
	return m;
}
Matrix operator-(Matrix &p, Matrix &q) {
	Matrix m(p.rows, p.cols);
	for (int r = 0; r < p.rows; ++r)for (int c = 0; c < p.cols; ++c)
		m(r, c) = p(r, c) - q(r, c);
	return m;
}//op
Matrix operator*(Matrix &p, Matrix &q) {
	Matrix m(p.rows, q.cols);
	for (int r = 0; r < p.rows; ++r)
		for (int c = 0; c < q.cols; ++c) {
			m(r, c) = 0;
			for (int i = 0; i < p.cols; ++i)
				m(r, c) += p(r, i) * q(i, c);
		}
	return m;
}//op*
void Matrix::citire() {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			cout << "Dati elem. [" << i << "][" << j << "] ";
			cin >> elems[cols*i + j];
		}
}//citire
void Matrix::afisare() {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << elems[cols*i + j] << "\t";
		cout << endl;
	}
}//afisare
void Matrix::afis_diag(Matrix &p) {
	cout << "\nElementele de pe diagonala principala:\n";
	for (int i = 0; i < p.rows; i++)
		for (int j = 0; j < p.cols; j++)
			if (i == j)
				cout << p(i, j) << "\t";
	cout << "\nElementele de pe diagonala secundara:\n";
	for (int i = 0; i < p.rows; i++)
		for (int j = 0; j < p.cols; j++)
			if (i + j == p.rows - 1)
				cout << p(i, j) << "\t";
}
int main(void) {
	int i, j, liniiKB, coloaneKB;
	cout << "\nDati numarul de linii(> 1):"; cin >> liniiKB;
	cout << "\nDati numarul de coloane(> 1):"; cin >> coloaneKB;

	Matrix m(liniiKB, coloaneKB);
	cout << "\nSupraincarcarea operatorului() pentru atribuirea unei valori pentru fiecare element din matrice: \n";
	for (int i = 0; i < liniiKB; i++)
		for (int j = 0; j < coloaneKB; j++)
			m(i, j) = i + (j + 1) * 10;
	for (i = 0; i < liniiKB; i++)
	{
		for (j = 0; j < coloaneKB; j++)
			cout << m(i, j) << "\t";
		cout << endl;
	}
	int l, c;
	cout << "Verificarea supraincarcarii operatorului () pentru un element de pe o pozitie citita de la tastatura\n";
	cout << "Dati numarului liniei (>=1): ";
	cin >> l;
	cout << "Dati numarului coloanei (>=1): ";
	cin >> c;
	if ((l >= 1 && l <= m.getRows()) && (c >= 1 && c <= m.getCols()))
		cout << "Elementul m[" << l << "," << c << "]=" << m(l - 1, c - 1) << endl;
	else
		cout << "\nIndici eronati!" << endl;
	cout << "\nUtilizare constructor de copiere:\n";
	if (m.getRows() > 0 && m.getCols() > 0) {
		Matrix mcopy = m;
		cout << "Matricea \"mcopy\" este:" << endl;
		mcopy.afisare();
	}
	else cout << "\nDimensiuni invalide pentru matricea care se copiaza la instantiere!\n";
	cout << "\nInstantiem un nou obiect matrice \"n\" ";
	Matrix n(liniiKB, coloaneKB);
	cout << "\nDati matricea:" << endl; n.citire();
	cout << "\nMatricea \"n\" este:" << endl;
	n.afisare();
	cout << "\nSupraincarcarea operatorului =, copiere matrice \"m\" in matrice \"n\"" << endl;
	if (m.getRows() == n.getRows() && m.getCols() == n.getCols()) {
		n = m;
		//n.afisare();
		for (i = 0; i < liniiKB; i++) {
			for (j = 0; j < coloaneKB; j++)
				cout << n(i, j) << "\t";//afisare prin Supraincarcarea operatorului()
			cout << endl;
		}///end for
	}
	else
		cout << "\nMatricile nu au aceleasi dimensiuni, deci nu pot fi copiate\n";
	cout << "\nInstantiem un nou obiect matrice \'m1\' ";
	Matrix m1(liniiKB, coloaneKB);
	cout << "\nDati matricea:\n";
	m1.citire();
	cout << "\nMatricea \"m1\" este:\n";
	m1.afisare();
	Matrix m2(liniiKB, coloaneKB);
	cout << "\nSupraincarcarea operatorului +\n";
	if (m.getRows() == m1.getRows() && m.getCols() == m1.getCols()) {
		m2 = m + m1;
		cout << "\nMatricea rezultata din suma matricilor m+m1 este: \n";
	}
	m2.afisare();
	cout << "\nSupraincarcarea operatorului - \n";
	if (m.getRows() == m1.getRows() && m.getCols() == m1.getCols()) {
		m2 = m - m1;
		cout << "\nMatricea rezultata din diferenta matricilor m-m1 este: \n";
	}
	m2.afisare();
	/*matricea m are 2 linii si 3 coloane deci pentru a fi posibil produsul m3 trebuie sa aiba 3 linii si 2 coloane*/
	cout << "\nDati matricea pentru produs \"m3\' (numarul de linii egal cu numarul de coloane al matricii \"m\")\n";
	cout << "Numar de linii: ";
	cin >> l;
	cout << "Numar coloane: ";
	cin >> c;
	Matrix m3;
	if (l > 0 && c > 0) m3.init(l, c);
	else cout << "\nDimensiuni negative (gresite)! Val. initiale implicite (2 linii, 3 coloane)\n";
	m3.citire();
	cout << endl << "Matricea \"m3\" este:" << endl;
	m3.afisare();
	cout << "\nSupraincarcarea operatorului * ";
	// pentru inmultire m*m3 nr. de coloane al matricii m trebuie sa fie egal cu numarul de randuri al matricii m3
	if (m.getCols() == m3.getRows())
	{
		Matrix m4(m.getRows(), m3.getCols());
		m4 = m * m3;
		cout << "\nMatricea rezultata prin inmultirea matricilor m*m3 este: \n";
		m4.afisare();
	}
	else
		cout << "\nMatricile nu pot fi inmultite - numarul de linii nu e egal cu numarul de coloane\n";

	if (m.getRows() == m.getCols())
		m.afis_diag(m);
	else
		cout << "\nLiniile nu sunt egale cu coloane, nu putem afisa diagonalele.";
	cin.ignore();
	cin.get();
	return 0;
}//end main