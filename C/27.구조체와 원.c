#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct circle CIRCLE;

double area(CIRCLE c); //���� ���� ���ϴ� �Լ�
double perimeter(CIRCLE c); //���� �ѷ� ���ϴ� �Լ�

struct point{
	int x, y;
};

struct circle { //CIRCLE
	struct point center;
	double radius;
};

int main(void) {
	CIRCLE c1;
	
	printf("���� �߽���: ");
	scanf("%d %d", &c1.center.x, &c1.center.y);
	printf("���� ������: ");
	scanf("%lf", &c1.radius);

	printf("���� ���� = %lf, ���� �ѷ� = %lf", area(c1), perimeter(c1));
}

double area(CIRCLE c) {
	return c.radius * c.radius * 3.14;
}

double perimeter(CIRCLE c) {
	return 2 * 3.14 * c.radius;
}