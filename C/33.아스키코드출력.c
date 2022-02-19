#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char c;

	printf("아스키 코드값을 구할 문자를 입력하시오: ");
	scanf("%c", &c);
	printf("아스키 코드값: %d", c);


	return 0;
}