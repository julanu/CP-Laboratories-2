/*
	Author: Jula Marius
	Date: 30/3/2018
	Description: Write a program that sorts a stock of computers, represented in the program as objects created from a structure
				that stores the computers’ characteristics: name (string of characters), processor type(string of characters),
				frequency (long int), RAM memory (int), price (float). The sorting is performed, as specified by the user, by
				price, memory amount, frequency or processor type. Use the qsort() library function or any other sorting
				technique. Next sort the data using a character string and a numerical field. Display the results.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 30

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct compt {
	char name[MAX];
	char processor_type[MAX];
	long frequency;
	int RAM;
	double price;
};

void readData(struct compt *);
int cmp(const struct compt *a, const struct compt *b);

void main()
{
	struct compt work[] = {
	{ "i3", "kaby lake", 2500, 8, 410.0 },
	{ "i5", "coffee lake", 2000, 4, 500.0 },
	{ "i4", "haswell", 1000, 8, 200.3},
	{ "i7", "ivy_bridge", 3400, 6, 300.4},
	{ "i8", "kaby_lake", 2500, 8, 200.3},
	};
	int i;
	int computers = sizeof(work) / sizeof(struct compt);
	// apel functie de sortare
	qsort((compt *)work, computers, sizeof(work[0]), (int(*)(const void*, const void*))cmp);
	printf("Datele sortate :\n");
	for (i = 0; i < computers; i++) {
		printf("\t%s, %s, %d, %d %f\n", work[i].name, work[i].processor_type, work[i].frequency,
			work[i].RAM, work[i].price);
	}
	_getch();
}

void readData(struct compt *b)
{
	printf("\nEnter the name of the system: ");
	scanf("%s", b->name);
	printf("\nEnter the processor: ");
	scanf("%s", b->processor_type);
	printf("\nEnter the frequency: ");
	scanf("%d", &b->frequency);
	printf("\nRAM: ");
	scanf("%d", &b->RAM);
	printf("\nEnter the price: ");
	scanf("%lf", &b->price);
}


int cmp(const struct compt *a, const struct compt *b)
{

	if ((_stricmp(a->name, b->name) > 0)) return 1;
	else if ((_stricmp(a->name, b->name) < 0)) return -1;
		else if ((_stricmp(a->processor_type, b->processor_type) > 0)) return 1;
			else if ((_stricmp(a->processor_type, b->processor_type) < 0)) return -1;
				else if (a->frequency < b->frequency) return -1;
					else if (a->frequency > b->frequency) return 1;
						else if (a->RAM < b->RAM) return -1;
						else if (a->RAM > b->RAM) return 1;
							else return 0;

}