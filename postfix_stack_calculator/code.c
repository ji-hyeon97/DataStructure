#define _CRT_SECURE_NO_WARNINGS//보안문제로 인한 특수함은 해결하겠습니다.
#include <stdio.h>
#include<stdlib.h>//exit(1)을 정의하기 위해 사용하겠습니다.
#include<string.h>//strlen을 정의하기 위해 사용하겠습니다.
#define MAX_SIZE_STACK 38//MAX_SIZE_STACK을 38이라고 정의하겠습니다.
typedef struct {//구조체정의하겠습니다.
	int stack[MAX_SIZE_STACK];//stack이라는 배열의 크기는 38입니다.
	int top;//stack이라는 배열의 인덱스값을 위해 선언하였습니다.
}stackType; //구조체이름은 stackType입니다.
void init(stackType *s) {//초기화하겠습니다.
	s->top = -1;//s->top은 stack배열의 인덱스 역할을 하는데 초기화하게되면 -1로 하겠습니다.
}
int empty(stackType *s) {//스택이 비어있는경우
	return s->top == -1;//초기화상태랑 같은 경우임으로 s->top으로 -1을 반환해 줍니다.
}
int full(stackType *s) {//스택이 가득차있는 경우
	return s->top == MAX_SIZE_STACK - 1;//s->top으로 MAX_SIZE_STACK-1을 반환해 줍니다.
}
void push(stackType *s, int item) {//스택에서 데이터를 입력합니다.
	if (full(s)) {//스택이 가득찬 경우
		exit(1);//프로그램종료
	}
	s->stack[++(s->top)] = item;//인덱스 번호 1추가한 값에 입력값을 넣어줍니다.
}
int pop(stackType *s) {//스택에서 데이터를 출력합니다.
	if (empty(s)) {//스택이 비어있는 경우
		exit(1);//프로그램종료
	}
	return s->stack[(s->top)--];//스택의 가장 위의 값을 반환하줍니다. 그리고 인덱스값에서 -1해줍니다.

}
int answer(char *postfix) {//우선 input.txt파일의 수식을 postfix라는 배열을 통해 받았습니다. 이를 계산하고 답을 구하는 함수입니다.
	int op1, op2, value;//op1, op2, value를 모두 정수형으로 선언해주겠습니다.
	int length = (int)strlen(postfix);//읽어들인 postfix의 문자열 길이를 구한뒤 length라는 변수에 담았습니다.
	char ch;//char형인 변수 ch를 선언하겠습니다.
	stackType s;//구조체이름은 stackType입니다. 이 구조체의 변수를 s라고 두겠습니다.
	init(&s);//초기화해줍니다.
	for (int i = 0; i<length; i++) {//문자열길이만큼 반복문을 해줍니다.
		ch = postfix[i];//postfix배열에서의 단어 하나, 하나 나누겠습니다.
		if (ch != '*' && ch != '+' && ch != '-') {//ch가 연산문자가 아닌경우 즉 숫자인경우 입니다.
			value = ch - '0';//ch는 char값입니다. 여기서 0이라는 아스키코드 값을 빼줌으로서 정수 본연의 값을 가지게 만들어 주었습니다.
			push(&s, value);//정수 value값을 스택에 입력해줍니다.
			continue;//숫자가 입력시 뒷부분의 코드는 무시하고 다음 배열값으로 가기 위해서 입니다.
		}
		op2 = pop(&s);//스택의 가장 인덱스의 값이 큰것을 pop하겠습니다 그리고 그 값을 op2라는 변수에 담겠습니다
		op1 = pop(&s);//스택의 가장 인덱스의 값이 큰것을 pop하겠습니다 그리고 그 값을 op1라는 변수에 담겠습니다
		switch (ch) {//ch문자가 사칙연산인 경우 
		case '*'://ch문자가 *인 경우 
			value = op1 * op2;//value라는 변수에 pop해준 2개의 정수를 곱해줍니다.
			break;//switch문 종료
		case '+'://ch문자가 +인 경우
			value = op1 + op2;//value라는 변수에 pop해준 2개의 정수를 더해줍니다.
			break;//switch문 종료
		case '-'://ch문자가 -인 경우
			value = op1 - op2;//value라는 변수에 pop해준 2개의 정수를 빼주겠습니다.
			break;//switch문 종료
		default://*,+,-이 아닌 특수문자인 경우입니다.
			exit(1);//프로그램종료
			break;//switch문 종료	
		}
		push(&s, value);//계산된 결과값을 다시 스택에 입력합니다.
	}
	int last = pop(&s);//계산된 결과값을 꺼냅니다. 그리고 그 값을 last라는 변수에 담았습니다.	
	if (!empty(&s)) {//스택이 비어있지 않다면 즉, 후위연산계산이 안되는 식을 의미합니다
		return 0;//교수님 pdf파일에 따르면 0을 출력하라고 하셨습니다.
	}
	else {//스택이 비어있다면
		return last;//최종적으로 계산된 결과값을 반환합니다.
	}
}
int main() {//메인함수입니다.
	stackType s;//구조체이름은 stackType입니다. 이 구조체의 변수를 s라고 두겠습니다.
	int n;//input.txt에서 100을 받기 위하여 작성하였습니다.
	char postfix[38];//postfix배열의 크기를 38으로 하겠습니다.
	int result;//후휘연산자 계산한 결과값을 나타냅니다.
	FILE *in = fopen("input.txt", "r");//파일입출력입니다. input.txt파일 읽기
	FILE *ot = fopen("output.txt", "w");//파일입출력입니다. output.txt파일 쓰기(출력)
	while (feof(in) == 0) {//파일이 끝날때 까지
		fscanf(in, "%d ", &n);//100을 받습니다.
		for (int i = 0; i < n; i++) {//100번 반복합니다.
			init(&s);//초기화 시켜주겠습니다
			fscanf(in, "%s", &postfix);//input텍스트파일을 읽습니다.
			result = answer(postfix);//answer함수에서 매개변수는 postfix배열이고 0아님 last값을 반환합니다. 이 값중하나를 result에 담습니다.
			fprintf(ot, "%d\n", result);//output텍스트 파일을 결과값이 출력됩니다.
			printf("%d\n", result);//교수님께서 즉석으로 보시기 편하게 콘솔창을 만들었습니다.
		}
	}
	fclose(in);//input텍스트파일을 닫습니다.
	fclose(ot);//output텍스트파일을 닫습니다.
	return 0;//0을 반환합니다.
}