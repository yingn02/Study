#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int s;

	printf("���� �Է�: ");
	scanf("%d", &s);
	s /= 10;

	switch (s)
	{
		case (10):
		case (9):
			printf("A");
			break;
		case (8):
			printf("B");
			break;
		case (7):
			printf("C");
			break;
		case (6):
			printf("D");
			break;
		default:
			printf("F");
			break;
	}

	return 0;
}