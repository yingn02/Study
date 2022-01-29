#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_leap(int year);

int main(void) {
	
	int year, y;

	printf("연도를 입력하세요: ");
	scanf("%d", &year);
	y = is_leap(year);
	printf("%d년은 %d일 입니다.", year, y);

	return 0;
}

int is_leap(int year) {

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 366;
	else
		return 365;
}