//2개의 스택을 이용하여 큐를 구현하기
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define max_size 100
typedef struct stacktype {
	int stack[max_size];
	int top;
}stacktype;
void s_init(stacktype *s) {
	s->top = -1;
}
int empty(stacktype *s) {
	return s->top == -1;
}
int full(stacktype *s) {
	return s->top == max_size-1;
}
void push(stacktype *s, int item1) {
	s->stack[++(s->top)] = item1;
	return;
}
int pop(stacktype *s) {
	return s->stack[(s->top)--];
}
typedef struct queuetype {
	stacktype s1, s2;
}queuetype;
void q_init(queuetype *q) {
	q->s1.top = -1;
	q->s2.top = -1;
}
void enqueue(queuetype *q, int item2) {
	push(&(q->s1), item2);
	return;
}
int dequeue(queuetype *q) {
	if (empty(&(q->s2))) {
		while (!empty(&(q->s1))) {
			push(&(q->s2), pop(&(q->s1)));
		}
	}
	return pop(&(q->s2));
}
int main() {
	queuetype q;
	q_init(&q);
	enqueue(&q, 5);
	enqueue(&q, 4);
	enqueue(&q, 3);
	enqueue(&q, 2);
	enqueue(&q, 1);
	for (int i = 0; i < 5; i++) {
		printf("%d\n", dequeue(&q));
	}
	return 0;
}