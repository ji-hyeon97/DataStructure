//ť�� �̿��� ȸ��
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
void enqueue(queuetype *q, int item) { //enqueue�� front�� back�� �����ϰ� ������ ������,,��
	if (!full(q)) {
		q->rear = (q->rear + 1) % max_size;
		q->queue[q->rear] = item;
	}
	else {
		exit(1);
	}
	return;
}
int dequeue_front(queuetype *q) {
	if (empty(q)) {
		exit(1);
	}
	else {
		q->front = (q->front + 1) % max_size;
		return q->queue[q->front];
	}
}
int dequeue_back(queuetype *q) {
	if (empty(q)) {
		exit(1);
	}
	else {
		int ans = q->queue[q->rear];
		q->rear = (q->rear - 1) % max_size;
		return ans;
	}
}
void pelindrome(char *input) {
	queuetype *q = (queuetype*)malloc(sizeof(queuetype));
	init(q);
	int i = 0, j = 0;
	while (input[i] != NULL) {
		if ('a' <= input[i] <= 'z') {
			enqueue(q, input[i]);
			j++;
		}
		else if ('A' <= input[i] <= 'Z') {
			enqueue(q, input[i] - ('A' - 'a'));
			j++;
		}
		i++;
	}
	while (!(j == 0 || j == 1)) {
		if (dequeue_front(q) != dequeue_back(q)) {
			printf("ȸ���� �ƴմϴ�.\n");
			break;
		}
		j = j - 2;
		printf("ȸ���� �½��ϴ�.\n");
		break;
	}
	return;
}
int main() {
	char input[30];
	printf("���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", input);
	pelindrome(input);
	return 0;
}