#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email
{
	char title[30];
	char receiver[30];
	char content[300];
};

int main(void) {
	struct email e1;

	printf("제목을 입력하세요: ");
	gets_s(e1.title, 30);
	printf("받는 사람의 이메일을 작성하세요: ");
	gets_s(e1.receiver, 30);
	printf("내용을 입력하세요: ");
	gets_s(e1.content, 30);

	printf("\n");
	printf("제목: %s \n", e1.title);
	printf("받는 사람: %s \n", e1.receiver);
	printf("내용: %s \n", e1.content);

	return 0;
}