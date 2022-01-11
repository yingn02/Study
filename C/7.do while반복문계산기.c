#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	char op;
	int num1;
	int num2;

	printf("A : Add \nS : Subtract \nM : Multiply \nD : Divide \nQ : Quit \n");
	do {
		printf("연산을 선택하십시오: ");
		scanf(" %c", &op);
		
		//실행 X
		if (op == 'Q')
			break;
		if (op != 'A' && op != 'S' && op != 'M' && op != 'D')
			continue;

		//실행 O
		printf("두 수를 공백으로 분리하여 입력하시오: ");
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