#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	double h = 0;
	int t = 0;
	double g = 9.80665;

	do {
		h = 1000 - 0.5 * g * t * t;
		printf("초: %d, 물체높이: %.2f \n", t, h);
		t++;
	} while (h > 0);

	return 0;
}