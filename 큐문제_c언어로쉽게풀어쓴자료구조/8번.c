//원형큐에 존재하는 요소의 개수 반환
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define max_size 100
typedef struct queuetype {
	int queue[max_size];
	int front, rear;
}queuetype;
void init(queuetype *q) {
	q->front = q->rear = 0;
	return;
}
int full(queuetype *q) {
	return((q->rear + 1) % max_size == q->front);
}
int empty(queuetype *q) {
	return q->front == q->rear;
}
void enqueue(queuetype *q, int item) {
	if (!full(q)) {
		q->rear = (q->rear + 1) % max_size;
		q->queue[q->rear] = item;
	}
	else {
		exit(1);
	}
	return;
}
int pop(queuetype *q) {
	if (!empty(q)) {
		exit(1);
	}
	else {
		q->front = (q->front + 1) % max_size;
		return q->queue[q->front];
	}
}
int get_Count(queuetype *q) {
	if (q->front <= q->rear) {
		return q->rear - q->front;
	}
	else {
		return max_size - (q->front - q->rear);
	}
}
int main() {
	queuetype q;
	init(&q);
	//for example
	enqueue(&q, 5);
	enqueue(&q, 4);
	enqueue(&q, 3);
	enqueue(&q, 2);
	enqueue(&q, 1);
	printf("%d\n", get_Count(&q));
	return 0;
}