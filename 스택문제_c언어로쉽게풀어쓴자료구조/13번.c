//�־��� �������� �ݺ��Ǵ� ���ڸ� �����ϴ� ���α׷� �ۼ�
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
	printf("������ �Է��Ͻÿ� : ");
	char input[max_size];
	scanf("%s", input);
	stacktype *s1 = (stacktype*)malloc(sizeof(stacktype));
	stacktype *s2 = (stacktype*)malloc(sizeof(stacktype));
	init(s1);
	init(s2);
	int i = 0;
	while (input[i] != NULL) {
		if (input[i] != input[i + 1]) {
			push(s1, input[i] - '0');
		}
		i++;
	}
	while (!empty(s1)) {
		push(s2, pop(s1));
	}
	printf("��� : ");
	while (!empty(s2)) {
		printf("%d", pop(s2));
	}
	return 0;
}