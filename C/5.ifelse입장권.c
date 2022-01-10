#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int time;
	int age;
	int won = 0;

	printf("현재 시간과 나이를 입력하세요(시간 나이): ");
	scanf("%d %d", &t, &age);

	if (t >= 17)
		won += 10000;
	else
		if ((3 <= age && age <= 12) || age >= 65)
			won += 25000;
		else
			won += 34000;

	printf("요금은 %d 입니다.", won);

	return 0;
}