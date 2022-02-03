#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fib(int n);

int main(void) {
	int n = 10;
	int i = 0;

	for (i = 0; i < n; i++)
		printf("fib(%d) = %d\n", i, fib(i));

	return 0;
}

int fib(int n) {
	if (n == 0 || n == 1)
		return n;
	else
		return fib(n - 2) + fib(n - 1);
}