#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double sin_degree(double degree);

int main(void) {
	double count = 0.0;
	int x = 0;

	printf("0도부터 몇도까지의 사인 값을 구하시겠습니까?: ");
	scanf("%d", &x);

	while (count <= x) {
		printf("sin(%lf)의 값은 %lf \n", count, sin_degree(count));
		count += 10.0;
	}
	return 0;
}

double sin_degree(double degree) {
	double pi = 3.141592;
	double angle = pi * degree / 180.0;
	double s = sin(angle);

	return s;
}