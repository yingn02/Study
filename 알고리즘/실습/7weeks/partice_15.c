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

// 초기화 함수
void init(LinkedStackType* s){
	s->top = NULL;
}
// 공백 상태 검출 함수
int is_empty(LinkedStackType* s){
	return (s->top == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedStackType* s){
	return 0;
}
// 삽입 함수
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

// 삭제 함수
element pop(LinkedStackType* s){
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
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
