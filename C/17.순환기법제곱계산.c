#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int power(int base, int power_raised);

int main(void) {
	int b, p;

	printf("¹Ø¼ö: ");
	scanf("%d", &b);
	printf("Áö¼ö: ");
	scanf("%d", &p);

	power(b, p);
	printf("%d^%d = %d", b, p, power(b, p));

	return 0;
}

int power(int base, int power_raised) {

	if (power_raised < 1)
		return 1;
	else
		return base * power(base, power_raised - 1);

}