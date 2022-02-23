#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_upper(char *s);

int main(void) {
	char s[50];

	printf("문자열을 입력하시오: ");
	gets_s(s, 50);

	printf("변환된 문자열: ");
	str_upper(s);

	return 0;
}

void str_upper(char* s) {
	int i;

	for (i = 0; s[i] != '\0'; i++) {
		if (islower(s[i]))
			s[i] = toupper(s[i]);
		printf("%c", s[i]);
	}
}

//if ('a' <= s[i] && s[i] <= 'z')
//	s[i] - 'a' + 'A';
// 
// 이러한 풀이 방식도 있음