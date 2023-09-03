#include <stdio.h>
#include <Windows.h>

typedef struct point {
	int x;
	int y;
}Point;
typedef struct line {
	Point startXY;
	Point endXY;
}Line;
typedef struct circle {
	Point center;
	float radius;
}Circle;
void shapePrint(Line* lptr, int cur_line, Circle* cptr, int cur_cir);
void ClearLineFromReadBuffer(void);

int main(void) {
	Line lines[10];
	Circle circles[10];
	int input, cur_line = 0, cur_cir = 0;

	while (1) {
		printf("-----------------------------------\n");
		printf("1. ���� �Է�\n");
		printf("2. �� �Է�\n");
		printf("3. ����� ���� ���\n");
		printf("4. ����\n");
		printf("-----------------------------------\n");
		printf("���ϴ� ��ȣ�� �Է��Ͻÿ�[����� ���� (����:%d, ��: %d)]\n", cur_line, cur_cir);
		scanf_s("%d", &input);
		switch (input) {
		case 1:
			printf("������(x,y) �Է� ��)0 0 :"); scanf_s("%d %d", &lines[cur_line].startXY.x, &lines[cur_line].startXY.y);
			printf("����(x,y) �Է� ��)1 1 :"); scanf_s("%d %d", &lines[cur_line].endXY.x, &lines[cur_line].endXY.y);
			cur_line++;
			break;
		case 2:
			printf("�߽���(x,y) �Է� ��)0 0 :"); scanf_s("%d %d", &circles[cur_cir].center.x, &circles[cur_cir].center.y);
			printf("������ �Է� ��)5 :"); scanf_s("%f", &circles[cur_cir].radius);
			cur_cir++;
			break;
		case 3:
			shapePrint(lines, cur_line, circles, cur_cir);
			break;
		case 4:
			return 0;
		default:
			printf("���ϴ� ��ȣ�� �����ϴ�\n");
		}
		system("cls");
	}

}

void ClearLineFromReadBuffer(void) {
	while (getchar() != '\n');
}
void shapePrint(Line* lptr, int cur_line, Circle* cptr, int cur_cir) {
	int i;
	printf("�Է��� �� ���\n");
	for (i = 0; i < cur_line; i++) {
		printf("  %d��° �� : ������(%d, %d) ����(%d, %d) \n", i + 1, lptr[i].startXY.x, lptr[i].startXY.y, lptr[i].endXY.x, lptr[i].endXY.y);
	}
	printf("�Է��� �� ���\n");
	for (i = 0; i < cur_cir; i++) {
		printf("  %d��° �� : �߽���(%d, %d) ������ :%f \n", i + 1, cptr[i].center.x, cptr[i].center.y, cptr[i].radius);
	}
	puts("�޴��ε��ư����� ���͸� �����ñ� �ٶ��ϴ�");
	ClearLineFromReadBuffer();
	getchar();
}