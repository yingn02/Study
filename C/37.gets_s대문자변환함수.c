#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_upper(char *s);

int main(void) {
	char s[50];

	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(s, 50);

	printf("��ȯ�� ���ڿ�: ");
	str_upper(s);

	return 0;
}

void str_upper(char* s) {
	int i;

	for (i = 0; s[i] != '\0'; i++) {
		if (islower(s[i]))
			s[i] = toupper(s[i]);
		printf("%c", s[i]);
	}
}

//if ('a' <= s[i] && s[i] <= 'z')
//	s[i] - 'a' + 'A';
// 
// �̷��� Ǯ�� ��ĵ� ����