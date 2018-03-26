/*
	Author: Jula Marius
	Date: 23/3/18
	Description: Write a C/C++ application that finds and displays the images that represent the closest match to a certain
				searching key. The searching key is stored in each image's header and it is represented using a structure with
				the following fields: a filename (string of characters), a path (string of characters), an intensity resolution
				(integer value) and a dimension in bytes (integer value)
*/

#define _CRT_SECURE_NO_WARNINGS

#define MAX 30

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <search.h>
#include <conio.h>

struct img {
	char name[MAX];
	char path[MAX];
	int resolution;
	int dim;
};

void readData(struct img *);
int cmpName(struct img *a, struct img *b);
int cmpRes(struct img *a, struct img *b);

void main(void){
	//pointers to our img struct
	struct img *pt, *pt1, *pt2, *b, c;
	int n, i;
	char num[MAX];

	printf("\nEnter the number of the images: ");
	scanf("%d", &n);
	b = &c;
	//memory allocation
	pt = (img*)malloc(n * sizeof(img));
	//checking if the allocation is successful
	if (pt != NULL)
	{
		//processing begins
		for (i = 0; i< n; i++)
		{
			printf(" \n\tImage %d: ", i + 1);
			readData(pt + i);
		}
		printf("\nSearched image: ");
		scanf("%s", num);
		printf("\nResolution of the searched image: ");
		scanf("%d", &b->resolution);
		pt1 = (struct img*)_lfind(&num, pt, (size_t*)& n, sizeof(img), (int(*)(const void*, const void*))cmpName);
		
		if (pt1 == 0)
			printf("\nImage with the name %s found", num);
		if(pt1 != 0)
			printf("\nImage with the name %s not found", num);

		pt2 = (struct img*)_lfind(&b, pt, (size_t*)& n, sizeof(img), (int(*)(const void*, const void*))cmpRes);
		if (pt2 == 0)
			printf("\nImage with the resolution %d found", b->resolution);
		if(pt2 != 0)
			printf("\nImage with the resolution %d not found", b->resolution);

	}
	else
	{
		printf("\nError");
		_getch();
	}

	if (pt)
		free(pt);
	_getch();
}

   //function to compare the resolution of two images
int cmpRes(struct img *a, struct img *b)
{
	return ((a->resolution) - (b->resolution));
}

//function to compare the filenames
int cmpName(struct img *a, struct img *b)
{
	return _stricmp(a->name, b->name);
}

//function to read the data stored in the table of structs
void readData(struct img *pt)
{
	printf("\nName: ");
	scanf("%s", pt->name);
	printf("\nPath: ");
	scanf("%s", pt->path);
	printf("\nDimension: ");
	scanf("%d", &pt->dim);
	printf("\nResolution: ");
	scanf("%d", &pt->resolution);
}

