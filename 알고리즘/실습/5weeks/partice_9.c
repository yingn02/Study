#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char element;
#define MAX_STACK_SIZE 100


typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//���� �ʱ�ȭ -1, ����������� �Ǻ�
void init_stack(StackType* s) {
	s->top = -1;
}

//���� ����ִ��� Ȯ�� (-1����)
int is_empty(StackType* s) {
	return (s->top == -1);
}

//������ �� �� �ִ��� (MAX_STACK_SIZE -1 �� ������)
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

//���ÿ� ������ ����
void push(StackType* s, element item) {
	if (is_full(s)) {//�� �� �ִ��� �˻�
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item; //���� �� top �κ� +1
}

//���� ������ ���� (�� ������)
element pop(StackType* s) {
	if (is_empty(s)) {//�������� �˻�
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];//�׳� �� ���� �Ʒ���)
}

element peek(StackType* s) {
	if (is_empty(s)) {//�� �������� Ȯ��
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];//peek�� �����͸� Ȯ�������� �׳� top ������ Ȯ��
}

int main(void) {
	char name[] = "Kwangseob Kim";
	StackType s;

	init_stack(&s);
	for (int i = 0; i < strlen(name); i++) {
		push(&s, name[i]);
	}

	while(!is_empty(&s)){
		printf("%c", pop(&s));
	}

	return 0;
}