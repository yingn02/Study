#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email
{
	char title[30];
	char receiver[30];
	char content[300];
};

int main(void) {
	struct email e1;

	printf("������ �Է��ϼ���: ");
	gets_s(e1.title, 30);
	printf("�޴� ����� �̸����� �ۼ��ϼ���: ");
	gets_s(e1.receiver, 30);
	printf("������ �Է��ϼ���: ");
	gets_s(e1.content, 30);

	printf("\n");
	printf("����: %s \n", e1.title);
	printf("�޴� ���: %s \n", e1.receiver);
	printf("����: %s \n", e1.content);

	return 0;
}