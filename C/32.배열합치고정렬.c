#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void merge(int *A, int *B, int *C, int size);

int main(void) {
	int A[4] = { 2,5,7,8 };
	int B[4] = { 1,3,4,6 };
	int C[8] = { 0 };

	merge(A, B, C, 8);
	
	return 0;
}

void merge(int* A, int* B, int* C, int size) {
	int i;
	int ai = 0, bi = 0, cnt = 0;

	for (i = 0; i < size; i++) {
		if (A[ai] < B[bi]) {
			C[i] = A[ai++];
		}

		else {
			C[i] = B[bi++];
		}
		
		printf("%d, ", C[i]);
		cnt = i;

		if (ai > 3 || bi > 3) {
			break;
		}
	}


	while (ai < 4 || bi < 4) {
		if (ai > 3) {
			C[cnt] = B[bi++];
			printf("%d, ", C[cnt]);
		}

		if (bi > 3) {
			C[cnt] = A[ai++];
			printf("%d, ", C[cnt]);
		}
	}
}