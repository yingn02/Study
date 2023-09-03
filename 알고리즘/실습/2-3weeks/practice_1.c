#include <stdio.h>

int min(int num[], int array_size);
int max(int num[], int array_size);

void main() {
	int num[] = { 8, 54, 11, -45, 43, 26, 66, 12, 13, 65 };
	int array_size = sizeof(num) / sizeof(int);
	int i;

	printf("배열 값 :");
	for (i = 0; i < array_size; i++) {
		printf("%d ", num[i]);
	}

	printf("\n최대값 : %d\n", max(num, array_size));
	printf("최소값 : %d\n", min(num, array_size));

}
int max(int num[], int array_size) {
	int max = num[0], i;
	for (i = 0; i < array_size; i++) {
		if (num[i] > max) {
			max = num[i];
		}
	}
	return max;
}

int min(int num[], int array_size) {
	int min = num[0], i;
	for (i = 0; i < array_size; i++) {
		if (num[i] < min) {
			min = num[i];
		}
	}
	return min;
}