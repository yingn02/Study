#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int h, m, s;
	int sec = 0;

	while (1)
	{
		printf("초를 입력하세요(음수 입력 시 종료)");
		scanf(" %d", &s);
		sec = s;

		if (s < 0)
			break;

		m = s / 60;
		s = s % 60;

		h = m / 60;
		m = m % 60;

		printf("%d초 -> %d시간 %d분 %d초 입니다.\n", sec, h, m, s);
	}

	return 0;
}