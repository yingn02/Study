#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define USER 10

int main(void) {
	int s[USER] = { 0 };
	int i;
	double m = 0, v = 0;

	for (i = 0; i < USER; i++) { //입력
		printf("정수 1개를 입력하세요: ");
		scanf("%d", &s[i]);
	}

	for (i = 0; i < USER; i++) //평균 m
		m += s[i];
	m /= USER;

	for (i = 0; i < USER; i++) //표준편차 v
		v += (s[i] - m) * (s[i] - m);
	v /= USER;

	printf("평균은 %lf 입니다.\n", m);
	printf("표쥰편차는 %lf 입니다.\n", v);

	return 0;
}