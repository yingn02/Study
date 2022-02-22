#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	char user = 0;

	printf("대소문자 변환\n");


	while (user != '.') {
		printf("\n문자 하나 입력(. 입력 시 종료) : ");
		user = getchar();

		if (isupper(user)) {
			putchar(tolower(user));
		}

		else {
			putchar(toupper(user));
		}
		getchar(); //줄바꿈 문자를 제거하기 위하여 한번 더 호출함
	}
	return 0;
}
