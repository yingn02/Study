#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	char h;

	printf("문자를 입력하세요: ");
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
			printf("모음입니다");
			break;
	default:
		printf("자음입니다");
		break;
	}

	return 0;
}