#include <stdio.h>
#include <stdlib.h>

typedef int element;	// ����� Ÿ��
typedef struct QueueNode {	// ť�� ����� Ÿ�� 
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct {		// ť ADT ����
	QueueNode* front, * rear;
} LinkedQueueType;

// ���� �Լ�
void enqueue(LinkedQueueType* q, element data){
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data; 		// ������ ����
	temp->link = NULL; 		// ��ũ �ʵ带 NULL
	if (is_empty(q)) { 		// ť�� �����̸�
		q->front = temp;
		q->rear = temp;
	}
	else { 		// ť�� ������ �ƴϸ�
		q->rear->link = temp;  // ������ �߿�
		q->rear = temp;
	}
}
// ���� �Լ�
element dequeue(LinkedQueueType* q){
	QueueNode* temp = q->front;
	element data;
	if (is_empty(q)) {		// �������
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		data = temp->data; 	// �����͸� ������.
		q->front = q->front->link; // front�� �������
		if (q->front == NULL) 	// ���� ����
			q->rear = NULL;
		free(temp); 		// �����޸� ����
		return data; 		// ������ ��ȯ
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
		enqueue(&queue, e2);	// ť�� �߰��Ѵ�. 
		enqueue(&queue, e3);	// ť�� �߰��Ѵ�. 
	}
	return 0;
}