#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	char h;

	printf("���ڸ� �Է��ϼ���: ");
	scanf("%c", &h);

	switch (h)
	{
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			printf("�����Դϴ�");
			break;
	default:
		printf("�����Դϴ�");
		break;
	}

	return 0;
}