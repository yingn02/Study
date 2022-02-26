#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* token;

int main(void) {
	int i;
	int count = 0;
	char str[50];

	char *word[50]; //그냥 배열이 아니라 포인터배열이어야만 여러글자를 한 칸에 넣을 수 있음

	printf("문자열을 입력하시오: ");
	gets_s(str, 50);

	token = strtok(str, " "); //첫 호출

	for (i = 0; token != NULL; i++) { //마지막 토큰의 주소값을 리턴하며 토큰이 더이상 없다면 NULL 포인터를 리턴 
		word[i] = token; //첫 호출 대입       
		token = strtok(NULL, " "); //두번째 호출
		count++;
	}

	printf("출력문자열: ");

	for (i = 0; i < count; i++) 
		printf("%s ", word[count - i - 1]);
		
	return 0;
}


//str[strlen(str) - 1] = NULL;
//남은 빈칸에 쓰레기값이 들어가는 것을 방지한다고함, 그러나 여기선 필요없었음