#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char element;
#define MAX_STACK_SIZE 100

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;
void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}
 
int main(void) {
	StackType s;
	char string[100];

	init_stack(&s);
	printf("���ڿ��� �Է����ּ���(�ҹ���):");
	gets_s(string, 100);

	int cnt = 1;
	push(&s, string[0]);
	for (int i = 1; i < strlen(string); i++) {
		char c = peek(&s);
		if (string[i] == c) {
			cnt++;
			push(&s, string[i]);
		}
		else {
			printf("%d", cnt);
			printf("%c", c);
			init_stack(&s);
			cnt = 1;
			push(&s, string[i]);
		}
	}	
	printf("%d", cnt);
	printf("%c", pop(&s));

	return 0;
}