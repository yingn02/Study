#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double sin_degree(double degree);

int main(void) {
	double count = 0.0;
	int x = 0;

	printf("0������ ������� ���� ���� ���Ͻðڽ��ϱ�?: ");
	scanf("%d", &x);

	while (count <= x) {
		printf("sin(%lf)�� ���� %lf \n", count, sin_degree(count));
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