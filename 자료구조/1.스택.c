#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ===== 스택 코드 시작 =====
#define MAX_STACK_SIZE 100

typedef int element; //int를 element라고 부를 수 있다

typedef struct {
	element data[MAX_STACK_SIZE]; //구조체 배열을 이용한 스택
	int top; //top
} StackType; //구조체 이름을 바로 설정할 수 있다

// 스택 초기화 함수
void init_stack(StackType *s) {
	s->top = -1; //맨 위를 가리키는 top이 -1이면, 스택이 빈다는 것과 같음
}

// 공백 상태 검출 함수
int is_empty(StackType *s) {
	return (s->top == -1); //top이 -1이면 스택이 빈 것이고, 이것에 대해 참이면 1 반환
}

// 포화 상태 검출 함수
int is_full(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1)); //top과 MAX_STACK_SIZE - 1 값과 같다면 포화상태가 참 
}

// 삽입함수
void push(StackType *s, element item) {
	if (is_full(s)) { //꽉찼다면
		fprintf(stderr, "스택 포화 에러\n"); //더 이상 넣을 수 없다고 경고
		return;
	}
	else
		s->data[++(s->top)] = item; //top값 먼저 증가 시킨 후, 그 자리에 값 삽입
}

// 삭제함수
element pop(StackType *s) {
	if (is_empty(s)) { //공백이라면
		fprintf(stderr, "스택 공백 에러\n"); //더 이상 뺄 수 없다고 경고
		exit(1); //종료
	}
	else
		return s->data[(s->top)--]; //현재 top값을 먼저 반환한 후, top 값 감소시킨다.
}

// 피크함수
element peek(StackType *s) {
	if (is_empty(s)) { //공백이라면
		fprintf(stderr, "스택 공백 에러\n"); //보여줄 수 있는 것이 없다고 경고
		exit(1); //종료
	}
	else
		return s->data[s->top]; //맨 위에 있는 것을 반환 (빼는 것이 아니므로 top값은 유지)
}

// ===== 스택 코드 끝 =====

int main() {
	StackType s; // 구조체 변수 선언

	init_stack(&s); // 스택을 초기화한다

	push(&s, 1); // 스택 s에 1을 쌓는다
	push(&s, 2); // 스택 s에 2을 쌓는다
	push(&s, 3); // 스택 s에 3을 쌓는다

	printf("%d\n", pop(&s)); // 스택 s에서 맨위에 있는 것을 꺼내서 출력
	printf("%d\n", pop(&s)); // 스택 s에서 맨위에 있는 것을 꺼내서 출력
	printf("%d\n", pop(&s)); // 스택 s에서 맨위에 있는 것을 꺼내서 출력

	return 0;
}