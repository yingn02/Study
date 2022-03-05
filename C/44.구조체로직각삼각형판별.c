#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct tri
{
	int len;
};

void main()
{
	struct tri t1[3] = { 3, 4, 5 };
	int i, pc, idx, tmp, a, b, c;

	pc = t1[0].len;

	for (i = 1; i < 3; i++) {
		if (pc < t1[i].len) {
			pc = t1[i].len;
			idx = i;
		}
	}
	tmp = t1[idx].len;
	t1[idx].len = t1[0].len;
	t1[0].len = tmp;

	c = t1[0].len;
	a = t1[1].len;
	b = t1[2].len;

	if (c * c == a * a + b * b)
		printf("Á÷°¢»ï°¢Çü\n");
	else
		printf("Á÷°¢»ï°¢Çü ¾Æ´Ô\n");


		return 0;
}
