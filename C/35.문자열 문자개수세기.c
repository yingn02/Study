#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char str[20] = "";
	char search;
	int i, count = 0;

	printf("���ڿ��� �Է��ϼ���: ");
	gets(str);

	printf("������ �� ���ڸ� �Է��ϼ���: ");
	scanf("%c", &search);

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == search)
			count++;
	}

	printf("%c�� ������ %d",search, count);

	return 0;
}