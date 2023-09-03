#include <stdio.h>
#include <time.h> 
#include <Windows.h>

int randNumber(int[]); 

void main() {
	int i, j, z, question[3] = { 0 }, answer[3] = { 0 }, sbo[3] = { 0 };
	int limit = 9;

	while (1) {
		printf("문제를 생성 중입니다....\r");
		randNumber(question);		
		printf("\n");
		printf("%d %d %d\n", question[0], question[1], question[2]);

		for (i = 6; i >= 0; i--) {
			printf("%d번 남았습니다.. 숫자를 x x x와 같이 입력해주세요 :", i + 1);
			scanf_s("%d %d %d", &answer[0], &answer[1], &answer[2]);

			if (answer[0] == answer[1] || answer[0] == answer[2] || answer[1] == answer[2]) {
				printf("같은 숫자를 입력하시면 안됩니다 다시 입력 해주세요.\n");
				if (i != 7)	i = i + 1;
				continue;
			}

			if (answer[0] > limit || answer[1] > limit || answer[2] > limit) {
				printf("0-9 사이의 숫자를 입력해 주시기 바랍니다. 다시 입력 해주세요.\n");
				if (i != 7)	i = i + 1;
				continue;
			}

			for (j = 0; j < 3; j++) {
				if (question[j] == answer[j]) {
					sbo[0]++;
				}  //스트라이크 
				else {
					for (z = 0; z < 3; z++) {
						if (j == z) {
							continue;
						}
						else if (question[j] == answer[z]) {
							sbo[1]++;
						}  //볼 
					}
				}
			}

			sbo[2] = 3 - (sbo[0] + sbo[1]);
			printf("결과 : %d %d %d \t S: %d, B: %d, O:%d \n", answer[0], answer[1], answer[2], sbo[0], sbo[1], sbo[2]);
			if (sbo[0] == 3) {
				printf("문제를 맞히셨습니다 ^^\n");
				break;
			}
			if (i == 0) {
				printf("답을 못맞추셨군요.... 답은 %d %d %d 입니다.\n", question[0], question[1], question[2]);
			}
			sbo[0] = sbo[1] = sbo[2] = 0;
		}
	}
}

int randNumber(int q[]) {
	int i = 0, j = 0;
	int size = sizeof(q) / sizeof(int);
	srand(time(NULL));
	for (i = 0; i < size; i++) {
		q[i] = rand() % 9;
		for (j = 0; j < i; j++) {
			if (q[i] == q[j]) {
				i--;
				break;
			}
		}
	}
	return rand() % 9;
} 