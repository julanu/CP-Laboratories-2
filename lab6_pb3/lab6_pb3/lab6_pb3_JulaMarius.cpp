/*
Author: Jula Marius
Date: 12/4/18
Description: Starting with the code that exemplifies the matrix operations, add the specific methods for:
- displaying the elements from the main diagonal of the matrix, in case the matrix is square;
if not, display a significant message;
- displaying the elements which are below the secondary diagonal;
- displaying a matrix that has identical dimensions with the original matrix and its elements
can have as possible values 0’s (if the corresponding element is greater than a certain
threshold value) or 1’s (otherwise);
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

const int Max1 = 10;
const int Max2 = 10;

class Matrix {
	//atributes
	int matrix[Max1][Max2], dim1, dim2;
public:
	//getter for an element of the matrix
	int returnElement(int row, int column);
	//explicit constructor
	Matrix(int dim1, int dim2) {
		this->dim1 = dim1;
		this->dim2 = dim2;
	}
	//declaration of the method for reading the elements of the matrix
	void readMatrix();
	//declaration of the method for displaying the matrix
	void displayMatrix();
	//method that displays a column of the matrix
	void displayColumn(int col);
	//method that displays the elems on the main diag.
	void displayMainDiag();
	//method that displays the elems under the sec. diag.
	void displaySecDiag();
	//method for the twin matrix
	void twinMatrix(int val);
};

void Matrix::twinMatrix(int val) {
	cout << "\nThe new matrix is: \n";
		for (int i = 0; i < dim1; i++) {
			for (int j = 0; j < dim2; j++)
				if (this->matrix[i][j] > val)
					cout << "0 ";
				else
					cout << "1 ";
			cout << "\n";
		}
}

//Reading the elements of the matrix
void Matrix::readMatrix()
{
	for (int i = 0; i < dim1; i++)
		for (int j = 0; j < dim2; j++)
		{
			cout << "\nmat[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}
}

//Getter for one column of the matrix
void Matrix::displayColumn(int col) {
	if (col < 0 || col >= dim2) {
		cout << "\nThe column with the num " << col << " doesn't exist in the matrix of the class!\n";
	}
	else {
		cout << "\nElements of the column " << col << ": ";
		for (int i = 0; i < dim1; i++) {
			cout << returnElement(i, col) << " ";
		}
	}
}

//Getter for an element of the matrix
int Matrix::returnElement(int row, int column) {
	return matrix[row][column];
}

//Method to display the matrix
void Matrix::displayMatrix() {
	int i, j; //locals
	cout << "\nElements of the matrix: ";
	for (i = 0; i < dim1; i++) {
		cout << "\n";
		for (j = 0; j < dim2; j++) {
			cout << returnElement(i, j) << " ";
		}
	}cout << endl;
}

//Method to display the main diagonal
void Matrix::displayMainDiag() {
	//check if the matrix is square
	if (dim1 == dim2) {
		cout << "\nThe elements on the main diagonal are: ";
		for (int i = 0; i < dim1; i++)
			cout << returnElement(i, i) << " ";
	}
	else
		cout << "The matrix is not square!No elements will be displayed.";
}

//Method to display the elems under the sec diag
void Matrix::displaySecDiag() {
	cout << "\nThe elements under the second diagonal are: ";
	for (int i = 1; i < dim1; i++)
		for (int j = dim1 - i; j < dim2; j++)
				cout << returnElement(i, j) << " ";
}

int main(void) {
	int dim1, dim2, thrVal;
	cout << "\nEnter the dimensions 1 & 2 of the matrix: (<=10):\n";
	cin >> dim1;
	cin >> dim2;
	if (dim1 == 0 && dim2 == 0)
		cout << "Error! The dimensions are not valid!";
	else
	{
		Matrix m1(dim1, dim2); //instantiation w/ reading values
		m1.readMatrix();
		m1.displayMatrix();
		int c;
		cout << "\nEnter the number of the column of which the elements will be displayed: (<dim2) ";
		cin >> c;
		m1.displayColumn(c);
		m1.displayMainDiag();
		m1.displaySecDiag();
		cout << "\nEnter the threshold value: ";
		cin >> thrVal;
		m1.twinMatrix(thrVal);
	}
	cin.ignore();
	cin.get();
}