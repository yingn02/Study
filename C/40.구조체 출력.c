#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book {
	int id;
	char title[100];
	char auther[20];
};

int main(void) {
	struct book b1 = {1, "�ٶ��� �Բ� �������", "������ ��ÿ"};

	printf("{ %d, %s, %s }", b1.id, b1.title, b1.auther);

	return 0;
}
