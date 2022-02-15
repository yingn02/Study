#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

void array_fill(int *A, int size);

int main(void) {
	int A[10] = { 0 };

	array_fill(A, 10);
	return 0;
}

void array_fill(int* A, int size) {
	int i;
	for (i = 0; i < size; i++) {
		A[i] = rand();
	}
	for (i = 0; i < size; i++) {
		printf("%d, ",A[i]);
	}
}