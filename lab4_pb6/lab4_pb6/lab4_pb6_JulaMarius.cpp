/*
	Author: Jula Marius
	Date: 28/3/18
	Description:Read from the keyboard a string of m integers and an integer value n<m. Split the string in 2 substrings as it
				follows: a) the first substring will contain the first n elements of the initial string
				b) the second substring will contain the rest elements of the initial string
				Realize the following operations: - sort increasingly the substrings
				- sort the initial string, by interlacing the sorted substrings (merge-sort)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

void copyStr(char *, char *, char *, int, int);
void printStr(char *);
void sort(char *);
void swap(char, char);
void merge(char *, char *, char *);

void main()
{
	char *str, *str_1, *str_2;
	char *p, *p1, *p2; //pointers
	int m, n;
	printf("\nHow many characters you want to enter?: ");
	scanf("%d", &m);
	printf("\nPlease enter a value N smaller than %d: ", m);
	scanf("%d", &n);
	//memory allocation
	str = (char *)malloc(m * sizeof(char));
	str_1 = (char *)malloc(n * sizeof(char));
	str_2 = (char *)malloc((m - n) * sizeof(char));
	p = &str[0]; p1 = &str_1[0]; p2 = &str_2[0]; //initializing the pointers
	//reading
	printf("\nPlease enter the string of chars(all chars must be entered at once): \n");
	scanf("%s", p);
	copyStr(str, str_1, str_2, n, m);//copying 
	if (p) free(p); //we empty the initial string
	p = (char *)malloc(m * sizeof(char)); //re-alloc the memory for the merge sort
	//sorting the substrings
	printf("\nInitial substrings and the sorted versions\n");
	printStr(p1); sort(p1); printStr(p1);
	printStr(p2); sort(p2); printStr(p2);
	merge(p1, p2, p);
	printf("\nAfter merging the substring");
	printStr(p);
	printStr(p);
	_getch();

}

void copyStr(char *str, char *str_1, char *str_2, int n, int m)
{
	int i;
	//copy the first part of the string in the substring
	strncpy(str_1, str, n - 1);
	//we copy the rest in the second substring
	for (i = n; i < m; i++)
		str_2[0] = str[i];
}
//swap function
void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}


//simple sorting function
void sort(char *str)
{
	int i, j;
	int l;
	l = sizeof(str) / sizeof(char);
	for (i = 0; i < l - 1; i++)
		for (j = i + 1; j < l; j++)
			if (str[i] > str[j])
				swap(&str[i], &str[j]); // simply swap the characters
}

//function to print a string of chars
void printStr(char *str)
{
	int i, sz;
	sz = sizeof(str) / sizeof(char);
	printf("\n");
	for (i = 0; i < sz; i++)
		printf("%c", str[i]);
}

//function to merge 2 arrays
void merge(char *str, char *str_1, char *third)
{

	int ind1, ind2, count, n, m;
	ind1 = ind2 = count = 0;
	//determining the lengths of the strings
	n = sizeof(str) / sizeof(char); 
	m = sizeof(str_1) / sizeof(char);

	while (ind1 < n && ind2 < m) // !! <=
		if (str[ind1] <= str_1[ind2])
		{
			third[count++] = str[ind1];
			ind1++;
		}
		else
		{
			third[count++] = str_1[ind2];
			ind2++;
		}
	while (ind1 < n) //overflow !! <=
	{
		third[count++] = str[ind1];
		ind1++;
	}
	while (ind2 < m) //overflow  !! <= 
	{
		str[count++] = str_1[ind2];
		ind2++;
	}
}