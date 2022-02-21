#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char str[20] = "";
	char search;
	int i, count = 0;

	printf("문자열을 입력하세요: ");
	gets(str);

	printf("개수를 셀 문자를 입력하세요: ");
	scanf("%c", &search);

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == search)
			count++;
	}

	printf("%c의 개수는 %d",search, count);

	return 0;
}