#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
	int x = 0;

	printf("2�� ������ ��ȯ�ϴ� ���α׷�\n");
	printf("������ �Է��ϼ���: ");
	scanf("%d", &x);
	printf("2�� ���� : %d", ~x + 1);

	return 0;
}