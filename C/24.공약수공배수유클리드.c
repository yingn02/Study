#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_gcd(int x, int y);
void get_lcm_gcd(int x, int y, int *p_lcm, int *p_gcd);

void main(void) {
	int x, y;
	int lcm, gcd;

	printf("두 개의 정수를 입력하세요: ");
	scanf("%d %d", &x, &y);

	get_gcd(x, y);
	get_lcm_gcd(x, y, &lcm, &gcd);

	printf("최소공배수는 %d 입니다.\n", lcm);
	printf("최대공약수는 %d 입니다.\n", gcd);

	return 0;
}

int get_gcd(int x, int y) { //유클리드
	while (y != 0) {
		int tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}

void get_lcm_gcd(int x, int y, int* p_lcm, int* p_gcd) {
	*p_gcd = get_gcd(x, y);
	*p_lcm = (x * y) / *p_gcd;
}