#include<stdio.h>
typedef struct point {
	int xpos;
	int ypos;
}Point;
typedef struct rectangle {
	Point LeftUp;
	Point RightDown;
}Rectangle;

int main(void) {
	Rectangle rec ;
	int Istrue = 1;
	printf("�� ��� ��ǥ �Է�(x y): ");
	scanf_s("%d %d", &rec.LeftUp.xpos, &rec.LeftUp.ypos);
	do {
		printf("�� �ϴ� ��ǥ �Է�(x y): ");
		scanf_s("%d %d", &rec.RightDown.xpos, &rec.RightDown.ypos);
		if (rec.LeftUp.xpos < rec.RightDown.xpos && rec.LeftUp.ypos > rec.RightDown.ypos)
			Istrue = 0;
		else {
			printf("�߸��Է��ϼ̽��ϴ�. \n");
		}
	} while (Istrue);

	int area = (rec.RightDown.xpos - rec.LeftUp.xpos) * (rec.LeftUp.ypos - rec.RightDown.ypos);

	printf("�Է��Ͻ� ��ǥ�� �簢�� ����: %d\n", area);
	printf("[%3d, %3d] [%3d, %3d] \n", rec.LeftUp.xpos, rec.LeftUp.ypos, rec.RightDown.xpos, rec.LeftUp.ypos);
	printf("[%3d, %3d] [%3d, %3d] \n", rec.LeftUp.xpos, rec.RightDown.ypos, rec.RightDown.xpos, rec.RightDown.ypos);

	return 0;
}