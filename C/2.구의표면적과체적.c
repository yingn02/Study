#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.141592

int main(void) 
{	
	double rad;
	double sur;
	double vol;

	printf("���� �������� �Է��ϼ���: ");
	scanf("%lf", &rad);
	sur = 4 * PI * rad * rad;
	vol = 4.0 / 3.0 * PI * rad * rad * rad;
	printf("ǥ���� : %lf", sur);
	printf("ü�� : %lf", vol);

	return 0;
}