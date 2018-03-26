/*
	Author: Jula Marius
	Date: 23/3/18
	Description: generate all the possible solutions for each one of the max 10 individual channels,
				considering that the main channel has the debit between 2MBps and 40 MBps.
				Calculate the solutions with a precision of MBps
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define USERS 10

void display_solutions(float *, int *, int, int);

int main(void)
{
	int x[USERS], i, k, count, min, max, n = 1;
	float weight[10], p_sum;
	p_sum = 0;
	min = 2;
	max = 40;

	printf("\n Enter the 10 weights: \n");
	//reading the weights
	for (i = 0; i < USERS; i++)
	{
		printf("\n p(%d)", i + 1);
		scanf("%f", &weight[i]);
		p_sum = p_sum + weight[i]; //total sum of the weights
	}
	//check weights sum
	if ((int)p_sum == 1.0)
	{
		while (n != 0)
		{
			printf("\n Data flow: ");
			scanf("%d", &n);
			printf("\n The solutions are: \n");
			if (n <= max)
			{
				count = 0;
				k = 0;
				x[k] = 0;
				do
				{
					while (x[k] < max)
					{
						x[k] = x[k] + 1;
						if (x[k] > min - 1)
							if (k == (USERS - 1))
								display_solutions(weight, x, count, n); //displaying the proper results
							else
							{
								k++;
								x[k] = 0;
							}
					}
					k--;
				} while (!(k < 0));
			}
			else
				printf("\nInvalid data flow");
		}
	}
	else
	{
		printf("\nError!");
		_getch();
	}
}
void display_solutions(float *weight, int *x, int count, int n)
{
	int i, l;
	double num;

	num = 0;
	for (i = 0; i < 10; i++)
		num = (double)(num + weight[i] * x[i]);

	l = (int)num;
	if (l == n)
	{
		for (i = 0; i < USERS; i++)
			printf("%.1f ", x[i] * weight[i]);
		printf("\n");
		count = count + 1;
		if (count > 20)
		{
			count = 0;
			printf("\nEnter a character to continue: ");
			_getch();
		}
	}
}//end afisare solutie