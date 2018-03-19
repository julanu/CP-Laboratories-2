/*
Author: Jula Marius
Date: 19/3/18
Description: Use the library function "qsort()" for sorting an array of records that contain a name, a surname, a personal
			 identification code and an employment date. The sorting is based on the data stored in some specific fields
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

void readArr(int *, int);
void displayArr(int *, int);
int cmp(const struct employee *a, const struct employee *a1);

struct datac {
	int year;
	int month;
	int day;
};
struct employee {
	char name[30];
	char surname[30];
	int id;
	struct datac datan;
};


int main(void)
{
	struct employee angaj[] = {
		{ "jula", "marius" , 1, { 1990, 3, 15 } },
	    { "andrei","moldovan", 2, { 1960, 8, 2 } },
	    { "rus", "vasile", 3, { 1975, 2, 6 } },
	    { "marian", "chira", 4, { 1968, 11, 11 } },
	    { "ispas", "dorin", 5, { 1988, 2, 18 } }
	   };
	int i;
	//determining the length of the data table
	int n_emp = sizeof(angaj) / sizeof(struct employee);
	//calling the sorting function 
	qsort((employee *)angaj, n_emp, sizeof(angaj[0]), (int(*)(const void*, const void*))cmp);
	
	printf("Sorted data: \n");
	for (i = 0; i < n_emp; i++) {
		printf("\t%d, %s, %d, %d, %d\n", angaj[i].datan.year, angaj[i].name, angaj[i].id, angaj[i].datan.month, angaj[i].datan.day);
	}


	_getch();
}
//the sorting is bassed on the birth year of the employee, his first name and the id
int cmp(const struct employee *a, const struct employee *b)
{
	if (a->datan.year > b->datan.year) return 1;
	else
		if (a->datan.year < b->datan.year) return -1;
		else
			if ((strcmp(a->name, b->name) > 0)) return 1;
			else
				if ((strcmp(a->name, b->name) < 0)) return -1;
				else
				     if (a->id > b->id) return 1;
						else return -1;
		return 0;
}