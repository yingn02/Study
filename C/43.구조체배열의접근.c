#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct food
{
	int kcal;
};

int main(void) {
	struct food food_array[3];

	printf("���� ���� ���� 3������ Į�θ��� �Է��ϼ���(a b c): ");
	scanf(" %d %d %d", &food_array[0].kcal, &food_array[1].kcal, &food_array[2].kcal);

	printf("\n�� Į�θ�: %d", food_array[0].kcal + food_array[1].kcal + food_array[2].kcal);

	return 0;
}