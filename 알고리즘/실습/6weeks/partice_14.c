#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10
typedef int element;
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} DequeType;
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init_deque(DequeType* q) {
	q->front = q->rear = 0;
}
int is_empty(DequeType* q) {
	return (q->front == q->rear);
}
int is_full(DequeType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void add_rear(DequeType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element get_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void deque_print(DequeType* q) {
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
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
void add_front(DequeType* q, element val) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
element get_rear(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[q->rear];
}
element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element delete_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

/// get_count
int get_count(DequeType* q) {
	int count = q->rear - q->front;
	if (count < 0) count += MAX_QUEUE_SIZE;
	return count;
}
void main() {
	DequeType queue;
	char string[100];
	printf("문자열을 입력해주세요: ");
	gets_s(string, 100);

	init_deque(&queue);
	for (int i = 0; i < strlen(string); i++) {
		add_rear(&queue, string[i]);
	}
	int equal = 1;

	while (get_count(&queue) > 1 && equal) {
		char first = delete_front(&queue);
		char last = delete_rear(&queue);
		if (first != last)
			equal = 0;
	}
	if (equal)
		printf("%s 회문", string);
	else
		printf("%s 회문 아님", string);
}
