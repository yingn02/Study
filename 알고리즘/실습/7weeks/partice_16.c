#include <stdio.h>
#include <stdlib.h>

typedef int element;	// 요소의 타입
typedef struct QueueNode {	// 큐의 노드의 타입 
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct {		// 큐 ADT 구현
	QueueNode* front, * rear;
} LinkedQueueType;

// 삽입 함수
void enqueue(LinkedQueueType* q, element data){
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data; 		// 데이터 저장
	temp->link = NULL; 		// 링크 필드를 NULL
	if (is_empty(q)) { 		// 큐가 공백이면
		q->front = temp;
		q->rear = temp;
	}
	else { 		// 큐가 공백이 아니면
		q->rear->link = temp;  // 순서가 중요
		q->rear = temp;
	}
}
// 삭제 함수
element dequeue(LinkedQueueType* q){
	QueueNode* temp = q->front;
	element data;
	if (is_empty(q)) {		// 공백상태
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		data = temp->data; 	// 데이터를 꺼낸다.
		q->front = q->front->link; // front로 다음노드
		if (q->front == NULL) 	// 공백 상태
			q->rear = NULL;
		free(temp); 		// 동적메모리 해제
		return data; 		// 데이터 반환
	}
}

int is_empty(LinkedQueueType* q) {
	//if (q->front == NULL) {
	//	return 1;
	//}
	//else {
	//	return 0;
	//}
	return q->front == NULL;
}
void init(LinkedQueueType* q) {
	q->front = q->rear = NULL;
}

int main(void) {
	LinkedQueueType queue;
	
	init(&queue);	 
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