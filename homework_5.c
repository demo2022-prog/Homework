#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "geek.h"

void fillRandom(int* arr, int len, int border) {
	for (int i = 0; i < len; ++i)
	{
		*(arr + i) = rand() % border;
	}
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void bubbleSort (int* arr, int len) {
	for(int j = 0; j < len; j++) {
		for (int i = 0; i < len - 1; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
			}
	}
	}
}

void TPK () {
	const int SIZEARR = 11;
	int arrTPK[SIZEARR];
	for (int i = 0; i < SIZEARR; ++i) {
		printf("Enter the number %d\n",(i + 1));
	    scanf("%d", &arrTPK[i]);
	}
	printIntArray(arrTPK, SIZEARR, 3);

	int a = 0;
	for (int i = 0; i < SIZEARR / 2; ++i) {
		a = arrTPK[i];
		arrTPK[i] = arrTPK[SIZEARR-1-i];
		arrTPK[SIZEARR-1-i] = a;
	}
	printIntArray(arrTPK, SIZEARR, 3);
	int result = 0;
	for (int i = 0; i < SIZEARR; ++i) {
		result = sqrt(fabs(arrTPK[i])) + 5 * pow(arrTPK[i], 3);
		if (result > 400) {
			printf("Result %d > 400\n", (i + 1));
		}
	}
}

int main(int argc, char const *argv[])
{
	const int SIZE = 10;
	int arr[SIZE];
	fillRandom(arr, SIZE, 10); //lesson 1
	printIntArray(arr, SIZE, 3); 
	printf("\n");
	bubbleSort(arr, SIZE);
	printIntArray(arr, SIZE, 3); 
	TPK();

	return 0;
}