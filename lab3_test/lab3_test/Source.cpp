#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
//#include<stdlib.h>
int mediaPare(int a[], int n);
int main() {
	int a[20], n, i;
	FILE *f;
	f = fopen("text.txt", "r");
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++)
	fscanf(f, "%d", &a[i]);
	printf("\nThe sum of the even numbers is: %d", mediaPare(a, n));
	fclose(f);

	 /*printf("\nEnter the number of the elements: ");
	scanf("%d", &n);
	printf("\nEnter the numbers: ");
	for (i = 0; i<n; i++)
		scanf("%d", &a[i]);
	printf("\nThe sum of the even numbers is: %d", mediaPare(a, n)); */
	//printf("\nDomnule Vaida, profesorul sa fie multumit cu saracia studentului sau. Si sa cititi din fisier tu, cu ma ta si cu mama.");
	_getch();
}//main
int mediaPare(int a[], int n)
{
	if (n == 0)
		return 0;
	else
		if (a[n - 1] % 2 == 0)
			return mediaPare(a, n - 1) + a[n - 1];
		else
			return mediaPare(a, n - 1);
}//mediaPare