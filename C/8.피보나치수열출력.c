#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int h = 0;
	int count = 0;
	int a = 0;
	int b = 1;
	int c = 0;

	printf("���° �ױ��� ���Ͻðڽ��ϱ�?: ");
	scanf("%d", &h);

	while (count <= h) {
		printf("%d, ", a);

		c = a + b;
		a = b;
		b = c;
	
		count += 1;
	}

	return 0;
}