#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.141592

int main(void) 
{	
	double rad;
	double sur;
	double vol;

	printf("구의 반지름을 입력하세요: ");
	scanf("%lf", &rad);
	sur = 4 * PI * rad * rad;
	vol = 4.0 / 3.0 * PI * rad * rad * rad;
	printf("표면적 : %lf", sur);
	printf("체적 : %lf", vol);

	return 0;
}