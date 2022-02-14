#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void get_sum_diff(int x, int y, int *p_sum, int *p_diff);

int main(void) {
	int a = 100;
	int b = 200;

	get_sum_diff(a, b, &a, &b);
	printf("Че:%d , Тї:%d", a, b);

}

void get_sum_diff(int x, int y, int* p_sum, int* p_diff) {
	*p_sum = x + y;
	*p_diff = x - y;
}