#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	char op;
	int num1;
	int num2;

	printf("A : Add \nS : Subtract \nM : Multiply \nD : Divide \nQ : Quit \n");
	do {
		printf("������ �����Ͻʽÿ�: ");
		scanf(" %c", &op);
		
		//���� X
		if (op == 'Q')
			break;
		if (op != 'A' && op != 'S' && op != 'M' && op != 'D')
			continue;

		//���� O
		printf("�� ���� �������� �и��Ͽ� �Է��Ͻÿ�: ");
		scanf("%d %d", &num1, &num2);

		if (op == 'A')
			printf("%d\n", num1 + num2);

		if (op == 'S')
			printf("%d\n", num1 - num2);

		if (op == 'M')
			printf("%d\n", num1 * num2);

		if (op == 'D')
			printf("%d\n", (double)num1 / num2);

	} while (1);

	return 0;
}