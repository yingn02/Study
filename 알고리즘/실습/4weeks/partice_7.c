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
		printf("1. 라인 입력\n");
		printf("2. 원 입력\n");
		printf("3. 저장된 도형 출력\n");
		printf("4. 종료\n");
		printf("-----------------------------------\n");
		printf("원하는 번호를 입력하시오[저장된 도형 (라인:%d, 원: %d)]\n", cur_line, cur_cir);
		scanf_s("%d", &input);
		switch (input) {
		case 1:
			printf("시작점(x,y) 입력 예)0 0 :"); scanf_s("%d %d", &lines[cur_line].startXY.x, &lines[cur_line].startXY.y);
			printf("끝점(x,y) 입력 예)1 1 :"); scanf_s("%d %d", &lines[cur_line].endXY.x, &lines[cur_line].endXY.y);
			cur_line++;
			break;
		case 2:
			printf("중심점(x,y) 입력 예)0 0 :"); scanf_s("%d %d", &circles[cur_cir].center.x, &circles[cur_cir].center.y);
			printf("반지름 입력 예)5 :"); scanf_s("%f", &circles[cur_cir].radius);
			cur_cir++;
			break;
		case 3:
			shapePrint(lines, cur_line, circles, cur_cir);
			break;
		case 4:
			return 0;
		default:
			printf("원하는 번호가 없습니다\n");
		}
		system("cls");
	}

}

void ClearLineFromReadBuffer(void) {
	while (getchar() != '\n');
}
void shapePrint(Line* lptr, int cur_line, Circle* cptr, int cur_cir) {
	int i;
	printf("입력한 선 출력\n");
	for (i = 0; i < cur_line; i++) {
		printf("  %d번째 선 : 시작점(%d, %d) 끝점(%d, %d) \n", i + 1, lptr[i].startXY.x, lptr[i].startXY.y, lptr[i].endXY.x, lptr[i].endXY.y);
	}
	printf("입력한 원 출력\n");
	for (i = 0; i < cur_cir; i++) {
		printf("  %d번째 원 : 중심점(%d, %d) 반지름 :%f \n", i + 1, cptr[i].center.x, cptr[i].center.y, cptr[i].radius);
	}
	puts("메뉴로돌아가려면 엔터를 누르시기 바랍니다");
	ClearLineFromReadBuffer();
	getchar();
}