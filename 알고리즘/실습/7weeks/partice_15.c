#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

// �ʱ�ȭ �Լ�
void init(LinkedStackType* s){
	s->top = NULL;
}
// ���� ���� ���� �Լ�
int is_empty(LinkedStackType* s){
	return (s->top == NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(LinkedStackType* s){
	return 0;
}
// ���� �Լ�
void push(LinkedStackType* s, element item){
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		exit(1);
	}
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}
void print_stack(LinkedStackType* s){
	for (StackNode* p = s->top; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

// ���� �Լ�
element pop(LinkedStackType* s){
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

int main(void) {
	char name[] = "Kwangseob Kim";
	LinkedStackType s;

	for (int i = 0; i < strlen(name); i++) {
		push(&s, name[i]);
	}
	
	while (!is_empty(&s)) {
		printf("%c", pop(&s));
	}
	
	return 0;
}
