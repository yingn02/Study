#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

// ===== ����ť �ڵ� ���� =====
#define MAX_QUEUE_SIZE 5

typedef int element; //int ��� element�� �����ִ�

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear; //front�� ù��° ����� ��ĭ���� ����Ŵ, rear�� ������ ��Ҹ� ����Ŵ
} QueueType; //�� ����ü�� �̸��� QueueType�� ����

// �����Լ�
void error(char *message) {
	fprintf(stderr, "%s\n", message); //�޽����� ����ϰ�
	exit(1); //����
}

//ť �ʱ�ȭ
void init_queue(QueueType *q) {
	q->front = q->rear = 0; //front�� rear�� 0�̸� ť�� ��Ұ� �ϳ��� ���� ��
}

// ���� ���� ���� �Լ�
int is_empty(QueueType *q) {
	return (q->front == q->rear); //front�� rear ���� ������ ������°� ������ ��ȯ
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType *q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); //�������� 0�̸� ��ȭ�� ��
}

// ����ť ����Լ�
void queue_print(QueueType *q) {
	printf("QUEUE(front=%d reat=%d) = ", q->front, q->rear);
	if (!is_empty(q)) { //������ �ƴϸ�
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear) break;
		} while (i != q->front); //front�� rear�� ��� �ε����� �ִ��� ��
	}
	printf("\n");
}

// ���� �Լ�
void enqueue(QueueType *q, element item) {
	if (is_full(q)) { // ���̻� ���� �� ���ٸ�
		error("ť�� ��ȭ�����Դϴ�");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType *q) {
	if (is_empty(q)) { // �� �����Ұ� ���ٸ�
		error("ť�� ��������Դϴ�");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// ��ũ �Լ�
element peek(QueueType* q) {
	if (is_empty(q)) { // �� �����ٰ� ���ٸ�
		error("ť�� ��������Դϴ�");
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

// ===== ����ť �ڵ� �� =====

int main() {
	QueueType queue; // ����ü ���� ����
	element a; // int a

	init_queue(&queue); //ť �ʱ�ȭ

	printf("--������ �߰� �ܰ�--\n");
	while (!is_full(&queue)) //���������� �ݺ�
	{
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &a);
		enqueue(&queue, a);
		queue_print(&queue);
	}

	printf("ť�� ��ȭ�����Դϴ�.\n\n");

	printf("--������ ���� �ܰ�--\n");
	/*
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("������ ����: %d \n", element);
		queue_print(&queue);
	}
	*/
	a = dequeue(&queue);
	printf("������ ����: %d \n", a);
	queue_print(&queue);
	a = dequeue(&queue);
	printf("������ ����: %d \n", a);
	queue_print(&queue);

	printf("������ �Է�\n");
	enqueue(&queue, 100);
	queue_print(&queue);
	printf("������ �Է�\n");
	enqueue(&queue, 200);
	queue_print(&queue);
	//printf("ť�� ��������Դϴ�.\n");

	return 0;



}