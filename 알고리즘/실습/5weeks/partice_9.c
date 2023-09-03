#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char element;
#define MAX_STACK_SIZE 100


typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//스택 초기화 -1, 비어있음으로 판별
void init_stack(StackType* s) {
	s->top = -1;
}

//스택 비어있는지 확인 (-1인지)
int is_empty(StackType* s) {
	return (s->top == -1);
}

//스택이 꽉 차 있는지 (MAX_STACK_SIZE -1 과 같으면)
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

//스택에 데이터 삽입
void push(StackType* s, element item) {
	if (is_full(s)) {//꽉 차 있는지 검색
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item; //삽입 후 top 부분 +1
}

//스택 데이터 추출 (맨 위부터)
element pop(StackType* s) {
	if (is_empty(s)) {//공백인지 검색
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];//그냥 맨 위를 아래로)
}

element peek(StackType* s) {
	if (is_empty(s)) {//빈 공간인지 확인
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];//peek는 데이터를 확인함으로 그냥 top 데이터 확인
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