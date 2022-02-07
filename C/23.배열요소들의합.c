#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int array_sum(int* A, int size);

int main(void) {
	int A[10] = {1,2,3};

	printf("A[] = 1 2 3 0 0 0 0 0 0 0\n");
	printf("월급의 합 = %d", array_sum(A, 10));

	return 0;
}

int array_sum(int* A, int size) {
	int i, sum = 0;
	int *p;

	p = A;
	for (i = 0; i < size; i++) {
		sum += *(p++);
	}
	return sum;
}