#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int cmmdc(int a, int b);
int cmmdc_n(int p, int u, int a[50]);

int main()
{
	int a[100], n, i;
	printf("\nEnter number of elements: ");
	scanf("%d", &n);
	printf("\nEnter %d elements: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("\nCmmdc is: %d", cmmdc_n(0, n - 1, a));
	_getch();
}

int cmmdc(int a, int b)
{
	if (a == b)
		return a;
	else
		if (a>b)
			return cmmdc(a - b, b);
		else
			return cmmdc(a, b - a);
}
int cmmdc_n(int p, int u, int a[50])
{
	int m;
	if (u - p == 1)
		cmmdc(a[p], a[u]);
	else
		if (p == u)
			return a[p];
		else
		{
			m = (p + u) / 2;
			return cmmdc(cmmdc_n(p, m, a), cmmdc_n(m + 1, u, a));
		}
}
