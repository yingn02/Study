#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
	int x = 0;

	printf("2의 보수로 변환하는 프로그램\n");
	printf("정수를 입력하세요: ");
	scanf("%d", &x);
	printf("2의 보수 : %d", ~x + 1);

	return 0;
}