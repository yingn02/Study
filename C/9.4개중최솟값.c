#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int a, b, c, d, min = 0;

	printf("4���� ������ �Է��ϼ���: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	if (a < b && a < c && a < d)
		min = a;
	else if (b < a && b < c && b < d)
		min = b;
	else if (c < b && c < a && c < d)
		min = c;
	else if (d < b && d < c && d < a)
		min = d;

	printf("%d %d %d %d �� �ּڰ��� %d �Դϴ�", a, b, c, d, min);

	return 0;
}