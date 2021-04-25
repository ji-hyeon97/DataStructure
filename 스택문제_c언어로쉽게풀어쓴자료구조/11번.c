//수식이 있는 괄호의 번호를 출력하는 프로그램, 왼쪽괄호가 나올경우 괄호번호 증가, 오른쪽괄호가 나올경우 매칭되는 왼쪽 괄호번호 출력
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
int main() {
	stacktype *s = (stacktype*)malloc(sizeof(stacktype));
	init(s);
	char input[max_size];
	printf("수식 : ");
	scanf("%s", input);
	int i = 0, count = 1;
	while (input[i] != NULL) {
		if (input[i] == '(') {
			push(s, count);
			printf("%d ", count);
			count++ ;
		}
		else {
			printf("%d ", pop(s));
		}
		i++;
	}
	return 0;
}