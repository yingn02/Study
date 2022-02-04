#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int s[3][5] = { {12,56,32,16,98}, {99,56,34,41,3}, {65,3,87,78,21} };
	int h = 0, r = 0, sum = 0;

	for (h = 0; h < 3; h++) { //행
		sum = 0;

		for (r = 0; r < 5; r++)
			sum += s[h][r];
		printf("%d행의 합계: %d\n", h, sum);
	}

	for (h = 0; h < 3; h++) { //열
		sum = 0;

		for (h = 0; h < 3; h++)
			sum += s[h][r];
		printf("%d열의 합계: %d\n", h, sum);
	}

	return 0;
}