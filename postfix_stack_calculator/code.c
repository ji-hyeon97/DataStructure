#define _CRT_SECURE_NO_WARNINGS//���ȹ����� ���� Ư������ �ذ��ϰڽ��ϴ�.
#include <stdio.h>
#include<stdlib.h>//exit(1)�� �����ϱ� ���� ����ϰڽ��ϴ�.
#include<string.h>//strlen�� �����ϱ� ���� ����ϰڽ��ϴ�.
#define MAX_SIZE_STACK 38//MAX_SIZE_STACK�� 38�̶�� �����ϰڽ��ϴ�.
typedef struct {//����ü�����ϰڽ��ϴ�.
	int stack[MAX_SIZE_STACK];//stack�̶�� �迭�� ũ��� 38�Դϴ�.
	int top;//stack�̶�� �迭�� �ε������� ���� �����Ͽ����ϴ�.
}stackType; //����ü�̸��� stackType�Դϴ�.
void init(stackType *s) {//�ʱ�ȭ�ϰڽ��ϴ�.
	s->top = -1;//s->top�� stack�迭�� �ε��� ������ �ϴµ� �ʱ�ȭ�ϰԵǸ� -1�� �ϰڽ��ϴ�.
}
int empty(stackType *s) {//������ ����ִ°��
	return s->top == -1;//�ʱ�ȭ���¶� ���� ��������� s->top���� -1�� ��ȯ�� �ݴϴ�.
}
int full(stackType *s) {//������ �������ִ� ���
	return s->top == MAX_SIZE_STACK - 1;//s->top���� MAX_SIZE_STACK-1�� ��ȯ�� �ݴϴ�.
}
void push(stackType *s, int item) {//���ÿ��� �����͸� �Է��մϴ�.
	if (full(s)) {//������ ������ ���
		exit(1);//���α׷�����
	}
	s->stack[++(s->top)] = item;//�ε��� ��ȣ 1�߰��� ���� �Է°��� �־��ݴϴ�.
}
int pop(stackType *s) {//���ÿ��� �����͸� ����մϴ�.
	if (empty(s)) {//������ ����ִ� ���
		exit(1);//���α׷�����
	}
	return s->stack[(s->top)--];//������ ���� ���� ���� ��ȯ���ݴϴ�. �׸��� �ε��������� -1���ݴϴ�.

}
int answer(char *postfix) {//�켱 input.txt������ ������ postfix��� �迭�� ���� �޾ҽ��ϴ�. �̸� ����ϰ� ���� ���ϴ� �Լ��Դϴ�.
	int op1, op2, value;//op1, op2, value�� ��� ���������� �������ְڽ��ϴ�.
	int length = (int)strlen(postfix);//�о���� postfix�� ���ڿ� ���̸� ���ѵ� length��� ������ ��ҽ��ϴ�.
	char ch;//char���� ���� ch�� �����ϰڽ��ϴ�.
	stackType s;//����ü�̸��� stackType�Դϴ�. �� ����ü�� ������ s��� �ΰڽ��ϴ�.
	init(&s);//�ʱ�ȭ���ݴϴ�.
	for (int i = 0; i<length; i++) {//���ڿ����̸�ŭ �ݺ����� ���ݴϴ�.
		ch = postfix[i];//postfix�迭������ �ܾ� �ϳ�, �ϳ� �����ڽ��ϴ�.
		if (ch != '*' && ch != '+' && ch != '-') {//ch�� ���깮�ڰ� �ƴѰ�� �� �����ΰ�� �Դϴ�.
			value = ch - '0';//ch�� char���Դϴ�. ���⼭ 0�̶�� �ƽ�Ű�ڵ� ���� �������μ� ���� ������ ���� ������ ����� �־����ϴ�.
			push(&s, value);//���� value���� ���ÿ� �Է����ݴϴ�.
			continue;//���ڰ� �Է½� �޺κ��� �ڵ�� �����ϰ� ���� �迭������ ���� ���ؼ� �Դϴ�.
		}
		op2 = pop(&s);//������ ���� �ε����� ���� ū���� pop�ϰڽ��ϴ� �׸��� �� ���� op2��� ������ ��ڽ��ϴ�
		op1 = pop(&s);//������ ���� �ε����� ���� ū���� pop�ϰڽ��ϴ� �׸��� �� ���� op1��� ������ ��ڽ��ϴ�
		switch (ch) {//ch���ڰ� ��Ģ������ ��� 
		case '*'://ch���ڰ� *�� ��� 
			value = op1 * op2;//value��� ������ pop���� 2���� ������ �����ݴϴ�.
			break;//switch�� ����
		case '+'://ch���ڰ� +�� ���
			value = op1 + op2;//value��� ������ pop���� 2���� ������ �����ݴϴ�.
			break;//switch�� ����
		case '-'://ch���ڰ� -�� ���
			value = op1 - op2;//value��� ������ pop���� 2���� ������ ���ְڽ��ϴ�.
			break;//switch�� ����
		default://*,+,-�� �ƴ� Ư�������� ����Դϴ�.
			exit(1);//���α׷�����
			break;//switch�� ����	
		}
		push(&s, value);//���� ������� �ٽ� ���ÿ� �Է��մϴ�.
	}
	int last = pop(&s);//���� ������� �����ϴ�. �׸��� �� ���� last��� ������ ��ҽ��ϴ�.	
	if (!empty(&s)) {//������ ������� �ʴٸ� ��, ������������ �ȵǴ� ���� �ǹ��մϴ�
		return 0;//������ pdf���Ͽ� ������ 0�� ����϶�� �ϼ̽��ϴ�.
	}
	else {//������ ����ִٸ�
		return last;//���������� ���� ������� ��ȯ�մϴ�.
	}
}
int main() {//�����Լ��Դϴ�.
	stackType s;//����ü�̸��� stackType�Դϴ�. �� ����ü�� ������ s��� �ΰڽ��ϴ�.
	int n;//input.txt���� 100�� �ޱ� ���Ͽ� �ۼ��Ͽ����ϴ�.
	char postfix[38];//postfix�迭�� ũ�⸦ 38���� �ϰڽ��ϴ�.
	int result;//���ֿ����� ����� ������� ��Ÿ���ϴ�.
	FILE *in = fopen("input.txt", "r");//����������Դϴ�. input.txt���� �б�
	FILE *ot = fopen("output.txt", "w");//����������Դϴ�. output.txt���� ����(���)
	while (feof(in) == 0) {//������ ������ ����
		fscanf(in, "%d ", &n);//100�� �޽��ϴ�.
		for (int i = 0; i < n; i++) {//100�� �ݺ��մϴ�.
			init(&s);//�ʱ�ȭ �����ְڽ��ϴ�
			fscanf(in, "%s", &postfix);//input�ؽ�Ʈ������ �н��ϴ�.
			result = answer(postfix);//answer�Լ����� �Ű������� postfix�迭�̰� 0�ƴ� last���� ��ȯ�մϴ�. �� �����ϳ��� result�� ����ϴ�.
			fprintf(ot, "%d\n", result);//output�ؽ�Ʈ ������ ������� ��µ˴ϴ�.
			printf("%d\n", result);//�����Բ��� �Ｎ���� ���ñ� ���ϰ� �ܼ�â�� ��������ϴ�.
		}
	}
	fclose(in);//input�ؽ�Ʈ������ �ݽ��ϴ�.
	fclose(ot);//output�ؽ�Ʈ������ �ݽ��ϴ�.
	return 0;//0�� ��ȯ�մϴ�.
}