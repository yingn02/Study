#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int element;
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

int eval(char exp[]) {
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	StackType s;

	init_stack(&s);
	for (i = 0; i < len; i++) {
		if (exp[i] == ' ') {
			i++;
		}
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			int value, j =0;
			char tmp[100];
			while (exp[i] != ' ') {
				tmp[j] = exp[i];
				i++;
				j++;
			}
			tmp[j] = '\0';
			value = atoi(tmp);
			push(&s, value);	
		}
		else {	//�������̸� �ǿ����ڸ� ���ÿ��� ����
			op2 = pop(&s);	//�����ڴ� �ǿ����ڰ� 2���� �־�� ó�� �����ϹǷ�..
			op1 = pop(&s);
			switch (ch) { //������ �����ϰ� ���ÿ� ���� 
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

int main(void) {
	int result;
	printf("����ǥ����� 2 200 2 5 * 3 - + *\n");
	result = eval("2 200 2 5 * 3 - + *");
	printf("������� %d\n", result);
	return 0;
}