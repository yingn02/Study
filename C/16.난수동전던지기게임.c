#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <time.h>

int b_rand(void);

int main(void) {
	int user, cont;

	while (cont != 'n') {
		user = 0;
		cont = 0;

		printf("앞면 또는 뒷면 (1 또는 0): ");
		scanf(" %d", &user);

		if (user == b_rand())
			printf("맞았습니다.\n");
		else
			printf("틀렸습니다.\n");

		printf("계속하시겠습니까?(y 또는 n): \n");
		scanf(" %c", &cont);
	}
	return 0;
}

int b_rand(void) {
	int coin = 0;
	
	srand((unsigned)time(NULL));
	coin = rand() % 2;

	return coin;
}