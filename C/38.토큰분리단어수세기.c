#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* token; //전역변수 필수

int main(void) {
	char s[50];
	int cnt = 1;


	printf("문자열을 입력하시오: ");
	gets_s(s, 50);

	printf("단어의 수: ");
	strtok(s, " ");


	while (token = strtok(NULL, " ")) //단어있을 때 까지 계속 반복
		cnt++;

	printf("%d", cnt);

	return 0;
}