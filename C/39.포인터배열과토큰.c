#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* token;

int main(void) {
	int i;
	int count = 0;
	char str[50];

	char *word[50]; //�׳� �迭�� �ƴ϶� �����͹迭�̾�߸� �������ڸ� �� ĭ�� ���� �� ����

	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(str, 50);

	token = strtok(str, " "); //ù ȣ��

	for (i = 0; token != NULL; i++) { //������ ��ū�� �ּҰ��� �����ϸ� ��ū�� ���̻� ���ٸ� NULL �����͸� ���� 
		word[i] = token; //ù ȣ�� ����       
		token = strtok(NULL, " "); //�ι�° ȣ��
		count++;
	}

	printf("��¹��ڿ�: ");

	for (i = 0; i < count; i++) 
		printf("%s ", word[count - i - 1]);
		
	return 0;
}


//str[strlen(str) - 1] = NULL;
//���� ��ĭ�� �����Ⱚ�� ���� ���� �����Ѵٰ���, �׷��� ���⼱ �ʿ������