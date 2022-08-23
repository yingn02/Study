#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

// ===== 원형큐 코드 시작 =====
#define MAX_QUEUE_SIZE 5

typedef int element; //int 대신 element를 쓸수있다

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear; //front는 첫번째 요소의 한칸앞을 가리킴, rear는 마지막 요소를 가리킴
} QueueType; //이 구조체의 이름을 QueueType로 설정

// 오류함수
void error(char *message) {
	fprintf(stderr, "%s\n", message); //메시지를 출력하고
	exit(1); //종료
}

//큐 초기화
void init_queue(QueueType *q) {
	q->front = q->rear = 0; //front와 rear가 0이면 큐에 요소가 하나도 없는 것
}

// 공백 상태 검출 함수
int is_empty(QueueType *q) {
	return (q->front == q->rear); //front와 rear 값이 같으면 공백상태가 참임을 반환
}

// 포화 상태 검출 함수
int is_full(QueueType *q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); //나머지가 0이면 포화가 참
}

// 원형큐 출력함수
void queue_print(QueueType *q) {
	printf("QUEUE(front=%d reat=%d) = ", q->front, q->rear);
	if (!is_empty(q)) { //공백이 아니면
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear) break;
		} while (i != q->front); //front와 rear가 어느 인덱스에 있는지 모름
	}
	printf("\n");
}

// 삽입 함수
void enqueue(QueueType *q, element item) {
	if (is_full(q)) { // 더이상 넣을 수 없다면
		error("큐가 포화상태입니다");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType *q) {
	if (is_empty(q)) { // 비어서 삭제할게 없다면
		error("큐가 공백상태입니다");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 피크 함수
element peek(QueueType* q) {
	if (is_empty(q)) { // 비어서 보여줄게 없다면
		error("큐가 공백상태입니다");
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

// ===== 원형큐 코드 끝 =====

int main() {
	QueueType queue; // 구조체 변수 선언
	element a; // int a

	init_queue(&queue); //큐 초기화

	printf("--데이터 추가 단계--\n");
	while (!is_full(&queue)) //꽉찰때까지 반복
	{
		printf("정수를 입력하시오: ");
		scanf("%d", &a);
		enqueue(&queue, a);
		queue_print(&queue);
	}

	printf("큐는 포화상태입니다.\n\n");

	printf("--데이터 삭제 단계--\n");
	/*
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("꺼내진 정수: %d \n", element);
		queue_print(&queue);
	}
	*/
	a = dequeue(&queue);
	printf("꺼내진 정수: %d \n", a);
	queue_print(&queue);
	a = dequeue(&queue);
	printf("꺼내진 정수: %d \n", a);
	queue_print(&queue);

	printf("데이터 입력\n");
	enqueue(&queue, 100);
	queue_print(&queue);
	printf("데이터 입력\n");
	enqueue(&queue, 200);
	queue_print(&queue);
	//printf("큐는 공백상태입니다.\n");

	return 0;



}