#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int equal(struct point *p1, struct point *p2);

struct point
{
	int x, y;
};

int main(void) {
	struct point po1, po2;
	struct point *p1, *p2;

	p1 = &po1;
	p2 = &po1;

	printf("ù��° ��ǥ(x y)�� �Է�: ");
	scanf(" %d %d", &po1.x, &po1.y);

	printf("�ι�° ��ǥ(x y)�� �Է�: ");
	scanf(" %d %d", &po2.x, &po2.y);

	if (equal(&po1, &po2) == 1)
		printf("�� ��ǥ�� �����ϴ�");
	else
		printf("�� ��ǥ�� �ٸ��ϴ�");

	return 0;
}

int equal(struct point *p1, struct point *p2) {
	if (p1->x == p2->x && p1->y == p2->y)
		return 1;
	else
		return 0;
}