#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int h, m, s;
	int sec = 0;

	while (1)
	{
		printf("�ʸ� �Է��ϼ���(���� �Է� �� ����)");
		scanf(" %d", &s);
		sec = s;

		if (s < 0)
			break;

		m = s / 60;
		s = s % 60;

		h = m / 60;
		m = m % 60;

		printf("%d�� -> %d�ð� %d�� %d�� �Դϴ�.\n", sec, h, m, s);
	}

	return 0;
}