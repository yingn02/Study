#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	char input_str[100] = { "\0" };
	char result_str[100] = { "\0" };
	int num;
	int length, i;
	int str_to_int;
	printf("����� ���ڿ��� �Է��Ͻÿ� : ");
	gets(input_str);
	length = strlen(input_str);
	while (1) {
		printf("----------------------- ���ڿ� ó�� ���α׷�-----------------------\n");
		printf("1. �ҹ��� to �빮��                    \n");
		printf("2. �빮�� to �ҹ���                    \n");
		printf("3. ����   to ���� �� 300�� ���ϱ�      \n");
		printf("4. ���ڸ� �Ųٷ� ���                  \n");
		printf("0. ���α׷� ����                       \n");
		printf("-------------------------------------------------------------------\n");
		printf("���Ͻô� ó���� ���ڷ� �Է� ���ּ���:");
		scanf_s("%d", &num);
		fflush(stdin);

		switch (num) {
		case 1:
			for (i = 0; i < length; i++) {
				if (input_str[i] <= 122 && input_str[i] >= 97)		result_str[i] = input_str[i] - 32;
				else result_str[i] = input_str[i];
			}
			printf("�ҹ��� to �빮�� : %s\n", result_str);
			break;
		case 2:
			for (i = 0; i < length; i++) {
				if (input_str[i] <= 90 && input_str[i] >= 65)		result_str[i] = input_str[i] + 32;
				else result_str[i] = input_str[i];
			}
			printf("�빮�� to �ҹ��� : %s\n", result_str);
			break;
		case 3:
			str_to_int = atoi(input_str);
			printf("%d + 300 = %d\n", str_to_int, str_to_int + 300);
			break;
		case 4:
			for (i = 0; i < length; i++) {
				result_str[i] = input_str[length - 1 - i];
			}
			printf("%s\n", result_str);
			break;
		case 0:
			return 0;
		default:
			printf("default");
			break;
		}
	}
}