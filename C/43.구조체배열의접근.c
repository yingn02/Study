#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct food
{
	int kcal;
};

int main(void) {
	struct food food_array[3];

	printf("오늘 먹은 음식 3가지의 칼로리를 입력하세요(a b c): ");
	scanf(" %d %d %d", &food_array[0].kcal, &food_array[1].kcal, &food_array[2].kcal);

	printf("\n총 칼로리: %d", food_array[0].kcal + food_array[1].kcal + food_array[2].kcal);

	return 0;
}