#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* token; //�������� �ʼ�

int main(void) {
	char s[50];
	int cnt = 1;


	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(s, 50);

	printf("�ܾ��� ��: ");
	strtok(s, " ");


	while (token = strtok(NULL, " ")) //�ܾ����� �� ���� ��� �ݺ�
		cnt++;

	printf("%d", cnt);

	return 0;
}