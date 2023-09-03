#include <stdio.h>


void swap(int* a, int* b) {
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

int main() {
	int a = 5, b = 7;

	printf("a: %d, b: %d\n", a, b);

	swap(&a, &b);

	printf("a: %d, b: %d", a, b);



}