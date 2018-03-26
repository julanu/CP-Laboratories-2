#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

#define DIM 50000

void init(int numere[]);
void afis(int numere[]);
void bubble(int numere[]);
void quick(int numere[]);
int comparare(const void *arg1, const void *arg2);


void main() {
	int numere[DIM];
	init(numere);
	//afis(numere);
	bubble(numere);
	init(numere);
	//afis(numere);
	quick(numere);
	//afis(numere);
	cin.get();
}
void init(int numere[])
{
	clock_t start, end;
	double dif;
	start = clock();
	srand((unsigned)time(NULL));
	for (int i = 0; i<DIM; i++) {
		numere[i] = rand();
	}
	end = clock();
	dif = (double)(end - start);
	//cout << "\nGenerarea numerelor a durat " << dif << " milisecunde.\n";
	cout << "\nGenerarea numerelor a durat (clicks) " << dif << " si (seconds) " << ((float)dif) /
		CLOCKS_PER_SEC << endl;
}
void afis(int numere[])
{
	clock_t start, end;
	double dif;
	start = clock();
	for (int i = 0; i<DIM; i++) {
		cout << "\n" << numere[i];
	}
	end = clock();
	dif = (double)(end - start);
	//cout << "\nAfisarea numerelor a durat " << dif << " milisecunde.\n";
	cout << "\nAfisarea numerelor a durat (clicks) " << dif << " si (seconds) " << ((float)dif) /
		CLOCKS_PER_SEC << endl;
}
void bubble(int numere[])
{
	clock_t start, end;
	double dif;
	int aux, ok;
	start = clock();
	do {
		ok = 1;
		for (int i = 0; i<DIM - 1; i++) {
			if (numere[i]>numere[i + 1]) {
				aux = numere[i];
				numere[i] = numere[i + 1];
				numere[i + 1] = aux;
				ok = 0;
			}
		}
	} while (ok == 0);
	end = clock();
	dif = (double)(end - start);
	//cout << "\nOrdonarea cu \"bubble sort\" a numerelor a durat " << dif << " milisecunde.\n";
	cout << "\nOrdonarea cu \"bubble sort\" a numerelor a durat (clicks) " << dif << " si (seconds) " <<
		((float)dif) / CLOCKS_PER_SEC << endl;
}
void quick(int numere[]) {
	clock_t start, end;
	double dif;
	start = clock();
	qsort((int*)numere, DIM, sizeof(int), comparare);
	end = clock();
	dif = (double)(end - start);
	//cout << "\nOrdonarea cu \"quick sort\" a numerelor a durat " << dif << " milisecunde.\n";
	cout << "\nOrdonarea cu \"quick sort\" a numerelor a durat (clicks) " << dif << " si (seconds) " <<
		((float)dif) / CLOCKS_PER_SEC << endl;
}
int comparare(const void *arg1, const void *arg2)
{
	if (*(int *)arg1<*(int *)arg2)
		return -1;
	if (*(int *)arg1 == *(int *)arg2)
		return 0;
	if (*(int *)arg1>*(int *)arg2)
		return 1;
}