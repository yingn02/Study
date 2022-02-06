#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void arrat_copy(int* A, int* B, int size);

int main(void) {
	int A[10] = { 1,2,3 };
	int B[10] = { 0 };

	printf("A[] = 1 2 3 0 0 0 0 0 0 0\n");
	arrat_copy(A, B, 10); //복사된 배열 B[]를 출력

	return 0;
}

void arrat_copy(int* A, int* B, int size) {
	int i;

	for (i = 0; i < size; i++)
		B[i] = A[i];

	printf("B[] = ");

	for (i = 0; i < size; i++)
		printf("%d ", B[i]);
}