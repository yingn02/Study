#include <stdio.h>

void main() {
	int A[2][2] = { {5,7}, {3,2} };
	int B[2][1] = { {2}, {4} };
	int result[2][1], sum, i, j, k;

	printf("행렬 A*B 구하기\n\n");
	for (i = 0; i < 2; i++) {
		printf("│");
		for (j = 0; j < 2; j++) {
			printf(" %d ", A[i][j]);
		}
		printf("│");
		printf("\t│%d│", B[i][0]);
		printf("\n");
		if (i == 0) {
			printf("│      │  *   │ │\n");
		}
	}
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 1; j++) {
			sum = 0;
			for (k = 0; k < 2; k++) {
				sum += A[i][k] * B[k][j];
			}
			result[i][j] = sum;
		}
	}
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 1; j++) {
			printf("\t\t     │%d│ ", result[i][j]);
		}
		printf("\n");
		if (i == 0) {
			printf("\t\t   = │  │\n");
		}
	}
}