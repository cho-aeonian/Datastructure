#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 5

typedef int element;

// Queue 구조체 정의
typedef struct {
	int front;
	int rear;
	element data[MAX_Q_SIZE];
} Queue;

void error(char* message) {
	printf("%s", message);
	exit(0); // 메인함수 종료
}

void initQueue(Queue* q) {
	q->front = -1;
	q->rear = -1;
}

int isFull(Queue* q) {
	if ((q->rear + 1) % MAX_Q_SIZE == q->front)
		return 1; // 큐가 가득 찼을 때
	else
		return 0;
}

int isEmpty(Queue* q) {
	if (q->front == q->rear)
		return 1; // 큐가 비어있을 때
	else
		return 0;
}

void enQueue(Queue* q, element item) {
	if (isFull(q))
		error("큐가 가득 찼습니다.");
	else {
		q->rear = (q->rear + 1) % MAX_Q_SIZE;
		q->data[q->rear] = item;
	}
}

element deQueue(Queue* q) {
	if (isEmpty(q))
		error("큐가 비어있습니다.");
	else {
		q->front = (q->front + 1) % MAX_Q_SIZE;
		return q->data[q->front];
	}
}

void queuePrint(Queue* q) {
	int i;
	for (i = 0; i < MAX_Q_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf(" | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

int main() {
	element item = 0;
	Queue q;
	initQueue(&q);
	enQueue(&q, 10);
	queuePrint(&q);
	enQueue(&q, 20);
	queuePrint(&q);
	enQueue(&q, 30);
	queuePrint(&q);
	item = deQueue(&q);
	queuePrint(&q);
	item = deQueue(&q);
	queuePrint(&q);
	return 0;
}