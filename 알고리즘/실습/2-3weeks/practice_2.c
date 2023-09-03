#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	char input_str[100] = { "\0" };
	char result_str[100] = { "\0" };
	int num;
	int length, i;
	int str_to_int;
	printf("사용할 문자열을 입력하시오 : ");
	gets(input_str);
	length = strlen(input_str);
	while (1) {
		printf("----------------------- 문자열 처리 프로그램-----------------------\n");
		printf("1. 소문자 to 대문자                    \n");
		printf("2. 대문자 to 소문자                    \n");
		printf("3. 문자   to 숫자 후 300과 더하기      \n");
		printf("4. 문자를 거꾸로 출력                  \n");
		printf("0. 프로그램 종료                       \n");
		printf("-------------------------------------------------------------------\n");
		printf("원하시는 처리를 숫자로 입력 해주세요:");
		scanf_s("%d", &num);
		fflush(stdin);

		switch (num) {
		case 1:
			for (i = 0; i < length; i++) {
				if (input_str[i] <= 122 && input_str[i] >= 97)		result_str[i] = input_str[i] - 32;
				else result_str[i] = input_str[i];
			}
			printf("소문자 to 대문자 : %s\n", result_str);
			break;
		case 2:
			for (i = 0; i < length; i++) {
				if (input_str[i] <= 90 && input_str[i] >= 65)		result_str[i] = input_str[i] + 32;
				else result_str[i] = input_str[i];
			}
			printf("대문자 to 소문자 : %s\n", result_str);
			break;
		case 3:
			str_to_int = atoi(input_str);
			printf("%d + 300 = %d\n", str_to_int, str_to_int + 300);
			break;
		case 4:
			for (i = 0; i < length; i++) {
				result_str[i] = input_str[length - 1 - i];
			}
			printf("%s\n", result_str);
			break;
		case 0:
			return 0;
		default:
			printf("default");
			break;
		}
	}
}