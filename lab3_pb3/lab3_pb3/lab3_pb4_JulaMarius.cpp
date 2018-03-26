/*
	Author: Jula Marius
	Date: 23/3/18
	Description: The optimum capital investment: an investor has a capital C and n offers; he has to invest it into fi investment
				funds each of them being associated with a corresponding benefit bi. Generate all the possible investing
				solutions. Indicate the solution that brings the maximum profit.	
*/

#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


//prototypes
void readData(int, int, int *, int *);
void bkt_fct(int , int , int, int, int, int, int *, int *, int *, int *, int *);
void save(int , int, int, int *, int *);
void displaySolutions(int, int *);

void main()
{
	int n, c, bm, f[20], b[20], x[20], m[20], u[20];
	printf("\nPlease enter the capital: ");
	scanf("%d", &c);
	printf("\nHow many offers there are?");
	scanf("%d", &n);
	readData(n, c, f, b);
	bm = 0;
	bkt_fct(1, 0, 0, c, n, bm, m, u, f, b, x);
	displaySolutions(bm ,m);
	_getch();
}

//function to read the data from the KB
void readData(int n, int c, int *f, int *b)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nEnter the funds and the advantages for the ofer nr.: %d", i);
		printf("\nf[%d]=", i);
		scanf("%d", &f[i]);
		printf("\na[%d]=", i);
		scanf("%d", &b[i]);

	}
}
//function to display all the possible solutions
void displaySolutions(int bm, int *m)
{
	printf("\nThe maximum benefit is: %d, which was obtained investing in: ", bm);
	for (int i = 0; i < m[0]; i++)
	{
		printf("\n%d", m[i]);
	}
	printf("\n");
}
//the savings functions
void savings(int k, int max, int bm, int *m, int *x)
{
	if (max > bm)
	{
		m[0] = k;
		for (int i = 0; i < k; i++)
			m[i] = x[i];
		bm = max;
	}
}
//the backtracking function which calls saving and itself
void bkt_fct(int k, int fp, int bp, int c, int n, int bm, int *m, int *u, int *f, int *b, int *x)
{
	if (fp > c)
		savings(k - 2, bp - b[x[k - 1]], bm, m, x);
	else
		for (int i = 0; i < n; i++)
			if (!u[i])
			{

				x[k] = i;
				u[i] = 1;
				bkt_fct(k + 1, fp + f[i], bp + b[i], c, n, bm, m, u, f, b, x);
				u[i] = 0;
			}

}