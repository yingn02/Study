#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct circle CIRCLE;

double area(CIRCLE c); //원의 면적 구하는 함수
double perimeter(CIRCLE c); //원의 둘레 구하는 함수

struct point{
	int x, y;
};

struct circle { //CIRCLE
	struct point center;
	double radius;
};

int main(void) {
	CIRCLE c1;
	
	printf("원의 중심점: ");
	scanf("%d %d", &c1.center.x, &c1.center.y);
	printf("원의 반지름: ");
	scanf("%lf", &c1.radius);

	printf("원의 면적 = %lf, 원의 둘레 = %lf", area(c1), perimeter(c1));
}

double area(CIRCLE c) {
	return c.radius * c.radius * 3.14;
}

double perimeter(CIRCLE c) {
	return 2 * 3.14 * c.radius;
}