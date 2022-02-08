#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_gcd(int x, int y);
void get_lcm_gcd(int x, int y, int *p_lcm, int *p_gcd);

void main(void) {
	int x, y;
	int lcm, gcd;

	printf("�� ���� ������ �Է��ϼ���: ");
	scanf("%d %d", &x, &y);

	get_gcd(x, y);
	get_lcm_gcd(x, y, &lcm, &gcd);

	printf("�ּҰ������ %d �Դϴ�.\n", lcm);
	printf("�ִ������� %d �Դϴ�.\n", gcd);

	return 0;
}

int get_gcd(int x, int y) { //��Ŭ����
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