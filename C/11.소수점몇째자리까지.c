#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	double f = 0;
	double c = 0;

	printf("ȭ���µ�: ");
	scanf("%lf", &f);

	c = 5.0 / 9.0 * (f - 32);
	printf("�����µ� : %.3f", c);

	return 0;
}