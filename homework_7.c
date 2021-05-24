#include <stdio.h>
#include <stdlib.h>
#include "geek.h"


void qs(int* arr, int first, int last) {
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last) qs(arr, i, last);
    if (first < j) qs(arr, first, j);
}

void sortShell(int* arr, int len) {
	int i;
	int j;
	int step;
	int temp;
	for (step = len /2; step > 0; step /=2) {
		for (i = step; i < len; ++i) {
			temp = arr[i];
			for (j = i; j >= step; j -= step) {
				if (temp < arr[j - step]) {
						arr[j] = arr[j - step];
					}	else {
						break;
					}
			}
			arr[j] = temp;
		}
	}
}

void updQs (int* arr, int first, int last) {
	if ((last + 1) > 10)
	{
		int med = arr[(first + last) / 2];
		med = (arr[first + last] + med) / 3;
		arr[(first + last) / 2] = med;
		
		int i = first;
    	int j = last;

    	int x = med;

    	do {
      	  while (arr[i] < x) i++;
      	  while (arr[j] > x) j--;

      	  if (i <= j) {
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }
   		} while (i <= j);

    	if (i < last) qs(arr, i, last);
   		 if (first < j) qs(arr, first, j);
	} else {
		int len = last + 1;
		int i;
		int j;
		int step;
		int temp;
		for (step = len /2; step > 0; step /=2) {
			for (i = step; i < len; ++i) {
				temp = arr[i];
				for (j = i; j >= step; j -= step) {
					if (temp < arr[j - step]) {
						arr[j] = arr[j - step];
					}	else {
						break;
					}
			}
			arr[j] = temp;
		}
	}
	}
}

void sortShellEven(int* arr, int len) {
	int i;
	int j;
	int step;
	int temp;
	for (step = len /2; step > 0; step /=2) {
		for (i = step; i < len; ++i) {
			if(arr[i] % 2 == 0) { 
			temp = arr[i];
			for (j = i; j >= step; j -= step) {
				if (temp < arr[j - step]) {
						arr[j] = arr[j - step];
					}	else {
						break;
					}
			}
			arr[j] = temp;
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	int arr1[12] = {0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3};
	const int SZ = 10;
	int arr[SZ];
	fillIntRandom(arr, SZ, 100);
	printIntArray(arr, SZ, 3);
	updQs(arr, 0, SZ - 1);
	printIntArray(arr, SZ, 3);
	printf("\n");
	printIntArray(arr1, 12, 3);
	sortShellEven(arr1, 12);
	printIntArray(arr1, 12, 3);
	




	return 0;
}	