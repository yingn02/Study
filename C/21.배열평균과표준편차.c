#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define USER 10

int main(void) {
	int s[USER] = { 0 };
	int i;
	double m = 0, v = 0;

	for (i = 0; i < USER; i++) { //�Է�
		printf("���� 1���� �Է��ϼ���: ");
		scanf("%d", &s[i]);
	}

	for (i = 0; i < USER; i++) //��� m
		m += s[i];
	m /= USER;

	for (i = 0; i < USER; i++) //ǥ������ v
		v += (s[i] - m) * (s[i] - m);
	v /= USER;

	printf("����� %lf �Դϴ�.\n", m);
	printf("ǥ�������� %lf �Դϴ�.\n", v);

	return 0;
}