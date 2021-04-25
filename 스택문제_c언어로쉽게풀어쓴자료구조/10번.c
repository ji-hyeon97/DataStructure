#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define max_size 100
typedef struct stacktype {
	int stack[max_size];
	int top;
}stacktype;
void init(stacktype *s) {
	s->top = -1;
}
int empty(stacktype *s) {
	return s->top == -1;
}
int full(stacktype *s) {
	return s->top == max_size - 1;
}
void push(stacktype *s, int item) {
	s->stack[++(s->top)] = item;
	return;
}
int pop(stacktype *s) {
	return s->stack[(s->top)--];
}
int main(void) {
	int n, number;
	stacktype s;
	init(&s);
	printf("�����迭�� ũ�� : ");
	scanf("%d", &n);
	printf("������ �Է��Ͻÿ� : ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &number);
		push(&s, number);
	}
	printf("������ ���� �迭 : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", pop(&s));
	}
	return 0;
}


