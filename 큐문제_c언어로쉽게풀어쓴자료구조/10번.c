//큐를 이용하여 피보나치 수열 계산하기
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
int dequeue(queuetype *q) {
	if (empty(q)) {
		exit(1);
	}
	else {
		q->front = (q->front + 1) % max_size;
		return q->queue[q->front];
	}
}
int fibo(queuetype *q, int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	for (int i = 2; i <= n; i++) {
		int d = dequeue(q);
		enqueue(q, d + q->queue[q->rear]);
	}
	return q->queue[q->rear];
}
int main() {
	queuetype *q = (queuetype*)malloc(sizeof(queuetype));
	init(q);
	enqueue(q, 0);
	enqueue(q, 1);
	printf("숫자 입력 : ");
	int n;
	scanf("%d", &n);
	printf("%d번째 피보나치 수열의 값은 : %d입니다.\n",n,fibo(q,n));
	return 0;
}