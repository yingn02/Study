#include <stdio.h>
#include <stdlib.h>

// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(char* message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q){
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q){
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q){
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void queue_print(QueueType* q){
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void enqueue(QueueType* q, element item){
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q){
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// q의 맨 앞에 있는 데이터 읽기
element peek(QueueType* q){
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front+1) % MAX_QUEUE_SIZE];
}
// ===== 원형큐 코드 끝 ======

int main(void){
	QueueType queue;

	init_queue(&queue);
	enqueue(&queue, 0);
	enqueue(&queue, 1);
	for (int i = 0; i < 13; i++) {
		element e1 = dequeue(&queue);
		element e2 = dequeue(&queue);
		element e3 = e1 + e2;
		printf("%d ", e3);
		enqueue(&queue, e2);	// 큐에 추가한다. 
		enqueue(&queue, e3);	// 큐에 추가한다. 
	}
	return 0;
}