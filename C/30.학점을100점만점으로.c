#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	void convert(double *grades, int size);

	double grades[10] = { 00.00, 00.50, 01.00, 01.50, 02.00, 02.50, 03.00, 03.50, 04.00, 04.30 };
	convert(grades, 10);

	return 0;
}

void convert(double* grades, int size) {
	int i;
	for (i = 0; i < size; i++) {
		grades[i] = 100.0 / 4.3 * grades[i];
	}

	for (i = 0; i < size; i++) {
		printf("%.2lf, ", grades[i]);
	}
}