#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char str[100];
    int i;

    printf("공백 문자가 있는 문자열을 입력하시오: ");
    gets(str); //scanf 사용 시 오류 발생

    for (i = 0; str[i] != NULL; i++) {
        if (str[i] != ' ')
            printf("%c", str[i]);
    }

    return 0;
}

//scanf는 공백, 줄 바꿈 또는 EOF(파일 끝)를 만나면 입력을받는 것을 종료하는 반면 
//gets는 공백을 입력 문자열의 일부로 간주하고 줄 바꿈 또는 EOF를 만나면 입력을 끝냅니다.