//주어진 정수에서 반복되는 숫자를 제거하는 프로그램 작성
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
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
int size(stacktype *s) {
	return s->top + 1;
}
int main() {
	stacktype *s1 = (stacktype*)malloc(sizeof(stacktype));	
	init(s1);
	//for example
	push(s1, 1);
	push(s1, 2);
	push(s1, 3);
	push(s1, 4);
	push(s1, 5);
	printf("%d\n", size(s1));	
	return 0;
}