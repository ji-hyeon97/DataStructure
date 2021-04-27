//회문
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
	stacktype *s = (stacktype*)malloc(sizeof(stacktype));
	init(s);
	int i = 0;
	while (input[i] != NULL) {
		if ('a' <= input[i] && input[i] <= 'z') {
			push(s, input[i]);
		}
		else if ('A' <= input[i] && input[i] <= 'Z') {
			push(s, input[i] - ('A' - 'a'));
		}
		i++;
	}
	int decide = 1;
	i = 0;
	while (input[i] != NULL) {
		if ('a' <= input[i] && input[i] <= 'z') {
			if (pop(s) != input[i]) {
				decide = 0;
				break;
			}
		}
		else if ('A' <= input[i] && input[i] <= 'Z') {
			decide = 0;
			break;
		}
		i++;
	}
	if (decide) {
		printf("회문입니다\n");
	}
	else {
		printf("회문이 아닙니다\n");
	}
	free(s);
	return 0;
}