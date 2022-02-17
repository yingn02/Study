#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int search(int *A, int size, int search_value);

int main(void) {
	int A[10] = { 180, 190, 200, 230, 250, 300, 320, 360, 400, 500 };
	int search_value;
	printf("월급이 얼마인 사람을 찾고 싶습니까? : ");
	scanf("%d", &search_value);

	search(A, 10, search_value);

	return 0;
}

int search(int* A, int size, int search_value) {
	int i;

	for (i = 0; i < size; i++) {
		if (A[i] == search_value) {
			printf("월급이 %d 인 사람의 인덱스는 %d", search_value, i);

		}
	}
}