#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int element;
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
		else {	//연산자이면 피연산자를 스택에서 제거
			op2 = pop(&s);	//연산자는 피연산자가 2개가 있어야 처리 가능하므로..
			op1 = pop(&s);
			switch (ch) { //연산을 수행하고 스택에 저장 
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
	printf("후위표기식은 2 200 2 5 * 3 - + *\n");
	result = eval("2 200 2 5 * 3 - + *");
	printf("결과값은 %d\n", result);
	return 0;
}