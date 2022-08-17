#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ===== ���� �ڵ� ���� =====
#define MAX_STACK_SIZE 100

typedef int element; //int�� element��� �θ� �� �ִ�

typedef struct {
	element data[MAX_STACK_SIZE]; //����ü �迭�� �̿��� ����
	int top; //top
} StackType; //����ü �̸��� �ٷ� ������ �� �ִ�

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType *s) {
	s->top = -1; //�� ���� ����Ű�� top�� -1�̸�, ������ ��ٴ� �Ͱ� ����
}

// ���� ���� ���� �Լ�
int is_empty(StackType *s) {
	return (s->top == -1); //top�� -1�̸� ������ �� ���̰�, �̰Ϳ� ���� ���̸� 1 ��ȯ
}

// ��ȭ ���� ���� �Լ�
int is_full(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1)); //top�� MAX_STACK_SIZE - 1 ���� ���ٸ� ��ȭ���°� �� 
}

// �����Լ�
void push(StackType *s, element item) {
	if (is_full(s)) { //��á�ٸ�
		fprintf(stderr, "���� ��ȭ ����\n"); //�� �̻� ���� �� ���ٰ� ���
		return;
	}
	else
		s->data[++(s->top)] = item; //top�� ���� ���� ��Ų ��, �� �ڸ��� �� ����
}

// �����Լ�
element pop(StackType *s) {
	if (is_empty(s)) { //�����̶��
		fprintf(stderr, "���� ���� ����\n"); //�� �̻� �� �� ���ٰ� ���
		exit(1); //����
	}
	else
		return s->data[(s->top)--]; //���� top���� ���� ��ȯ�� ��, top �� ���ҽ�Ų��.
}

// ��ũ�Լ�
element peek(StackType *s) {
	if (is_empty(s)) { //�����̶��
		fprintf(stderr, "���� ���� ����\n"); //������ �� �ִ� ���� ���ٰ� ���
		exit(1); //����
	}
	else
		return s->data[s->top]; //�� ���� �ִ� ���� ��ȯ (���� ���� �ƴϹǷ� top���� ����)
}

// ===== ���� �ڵ� �� =====

int main() {
	StackType s; // ����ü ���� ����

	init_stack(&s); // ������ �ʱ�ȭ�Ѵ�

	push(&s, 1); // ���� s�� 1�� �״´�
	push(&s, 2); // ���� s�� 2�� �״´�
	push(&s, 3); // ���� s�� 3�� �״´�

	printf("%d\n", pop(&s)); // ���� s���� ������ �ִ� ���� ������ ���
	printf("%d\n", pop(&s)); // ���� s���� ������ �ִ� ���� ������ ���
	printf("%d\n", pop(&s)); // ���� s���� ������ �ִ� ���� ������ ���

	return 0;
}