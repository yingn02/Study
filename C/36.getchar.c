#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	char user = 0;

	printf("��ҹ��� ��ȯ\n");


	while (user != '.') {
		printf("\n���� �ϳ� �Է�(. �Է� �� ����) : ");
		user = getchar();

		if (isupper(user)) {
			putchar(tolower(user));
		}

		else {
			putchar(toupper(user));
		}
		getchar(); //�ٹٲ� ���ڸ� �����ϱ� ���Ͽ� �ѹ� �� ȣ����
	}
	return 0;
}
