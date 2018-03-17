/* testting recursive functions */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

int rec_call(int);

void main()
{
	int n;
	printf("N = ");
	scanf("%d", &n);

	printf("%d", rec_call(n));

	_getch();
}

int rec_call(int n)
{
	if (n == 0)
		return 0;
	else
		return (1 + rec_call(n - 1));

}