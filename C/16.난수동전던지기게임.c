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

		printf("�ո� �Ǵ� �޸� (1 �Ǵ� 0): ");
		scanf(" %d", &user);

		if (user == b_rand())
			printf("�¾ҽ��ϴ�.\n");
		else
			printf("Ʋ�Ƚ��ϴ�.\n");

		printf("����Ͻðڽ��ϱ�?(y �Ǵ� n): \n");
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