#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void str_upper(char *s);

int main(void) {
	char s[100];
	printf("문자열을 입력하세요: ");
	gets_s(s, 100);

	str_upper(s);

	printf("변화된 문자열: ");
	puts(s);

	return 0;
}

void str_upper(char* s) {
	int i;

	for (i = 0; s[i] != NULL; i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 'a' + 'A';
		else if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 'a' - 'A';
	}
}