#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double recursive(double mo);

int main(void) {
	double m = 10;

	printf("%lf", recursive(m));

	return 0;
}

double recursive(double mo) {
	if (mo == 1)
		return 1.0;
	else
		return 1.0/mo + recursive(mo - 1);
}