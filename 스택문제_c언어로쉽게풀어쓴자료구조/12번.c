//문자열 압축 프로그램
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
int main() {
	printf("문자열을 입력하시오 : ");
	char input[max_size];
	scanf("%s", input);
	stacktype *s1 = (stacktype*)malloc(sizeof(stacktype));
	stacktype *s2 = (stacktype*)malloc(sizeof(stacktype));
	init(s1);
	init(s2);
	int i = 0;
	while (input[i] != NULL) {
		int count = 0;
		char compare = input[i++];
		count++;
		while (compare == input[i] || compare + ('A' - 'a') == input[i] || compare - ('A' - 'a') == input[i]) {
			count++;
			i++;
		}
		push(s1, count+ '0');
		if ('a' <= compare && compare <= 'z') {
			push(s1, compare);
		}
		else {
			push(s1, compare - ('A' - 'a'));
		}
	}
	while (!empty(s1)) {
		push(s2, pop(s1));
	}
	printf("압축된 문자열 : ");
	while (!empty(s2)) {
		printf("%c", pop(s2));
	}
	return 0;
}