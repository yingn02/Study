#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void palin_scan(char *s);

int main(void) {
	char s[100];
	char space[] = " ";

	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(s, 100);

	palin_scan(s);

	return 0;
}

void palin_scan(char *s) {
	int i, len, sc = 0;

	for (i = 0; s[i] != NULL; i++) { //�빮�� ����
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 'a' + 'A';
		else if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 'a' - 'A';
		}

	len = strlen(s);

	for (i = 0; i < len / 2; i++) { //�ٱ��ʺ��� ���� �����ϸ� ��
		if (s[i] != s[len - i - 1])
			sc += 1;
	}

	if (sc == 0)
		printf("ȸ���Դϴ�.");
	else
		printf("ȸ���� �ƴմϴ�.");
}