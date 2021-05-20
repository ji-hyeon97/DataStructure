#define _CRT_SECURE_NO_WARNINGS//visual studio의 보안관련 문제를 무시하겠습니다.
#pragma warning(disable : 4047)//큐 구조체와 트리 구조체 사이에서의 간접 참조받는 문법적인 부분(int형)에서 혹시나 build가 되지 않을까봐 작성했습니다.
#pragma warning(disable : 4024)//큐 구조체와 트리 구조체 사이에서의 간접 참조받는 문법적인 부분(int형)에서 혹시나 build가 되지 않을까봐 작성했습니다.
#include <stdio.h>//출력, 등의 기능을 제공합니다.
#include <stdlib.h>//트리에서의 동적할당을 위해 작성하였습니다.
#define max_size 100//max_size는 100으로 정의하겠습니다.
typedef struct treenode {//treenode의 구조체
	int data;//정수 data값
	struct treenode *left;//링크필드 왼쪽
	struct treenode *right;//링크필드 오른쪽
}treeNode;//구조체 이름은 treeNode입니다.
typedef struct queuetype {//queue구조체 작성
	int queue[max_size];//정수형 queue의 배열
	int front, rear;//원형큐를 작성하기 위해서 필요한 개념
}queuetype;//구조체이름은queuetype입니다.
void init_q(queuetype *q) {//초기화
	q->front = q->rear = 0;//초기화 상황입니다.
	return;//종료
}
int empty(queuetype *q) {//비어있는경우
	return (q->rear == q->front);//큐가 비어있는 상황입니다.
}
int full(queuetype *q) {//가득찬경우
	return ((q->rear + 1) % max_size == q->front);// 큐가 가득찬 상황입니다.(원형큐)
}
void enqueue(queuetype *q, int item) {//큐 배열에 삽입
	if (full(q)) {//큐가 가득차있는 경우
		exit(1);//프로그램 종료
	}
	else {//큐가 가득차 있지 않는 경우
		q->rear = (q->rear + 1) % max_size;//rear값 증가
		q->queue[q->rear] = item;//정수 삽입
	}
	return;//종료
}
int dequeue(queuetype *q) {//추출
	if (empty(q)) {//큐가 비어있는 경우
		exit(1);//프로그램 종료
	}
	else {//큐가 비어있지 않는 경우
		q->front = (q->front + 1) % max_size;//front값 증가(원형큐에서는 처음 front값은 null값입니다.)
		return q->queue[q->front];//정수 추출
	}
}
treeNode *makeNode(int value) {//노드 생성
	treeNode *node = (treeNode *)malloc(sizeof(treeNode));//동적할당
	node->data = value;//노드의 데이터 값으로 value를 받음
	node->left = node->right = NULL;//단말노드
	return node;//노드반환
}
treeNode *BST_insert(treeNode *root, int data) {//BST트리구조를 작성하겠습니다.
	if (root == NULL) {//값이 없는 경우
		root = makeNode(data);//처음값을 root로 설정
	}
	else {//값이 있는 경우
		if (root->data > data)//루트의 데이터 값이 새로 들어오는 데이터보다 큰 경우
			root->left = BST_insert(root->left, data);//링크필드를 통해 왼쪽으로 이동
		else//루트의 데이터 값이 새로 들어오는 데이터보다 작은 경우
			root->right = BST_insert(root->right, data);//링크필드를 통해 오른쪽으로 이동
	}
	return root;//루트반환
}
void DFS(treeNode *root, int *count, int aimNumber, int *answer) {//dfs탐색
	if (!root) {//트리가 없는 경우
		return;//종료
	}
	if (*count > aimNumber) {//count값이 aimNumber값보다 큰경우
		return;//종료
	}
	if (*count == aimNumber) {//count값이랑 aimNumber값이랑 같은 경우
		*count += 1;//ㅅㅂ 과제제출할때 왜이걸 생각 못햇지,, 아 자식 노드가 2개인 경우도 생각했어야 하는데 아 ㅁㅊ ㅋㅋㅋㅋ
		*answer = root->data;//그 탐색값을 answer이라는 주소에 저장하겠습니다.
		return;//종료
	}
	*count += 1;//count값이 aimNumber값보다 작은 경우
	DFS(root->left, count, aimNumber, answer);//왼쪽으로 탐색
	DFS(root->right, count, aimNumber, answer);//오른쪽으로 탐색
}
void BFS(treeNode *root, int *count, int aimNumber, int *answer) {//bfs탐색
	queuetype q;//구조체 queuetype의 변수 q (인스턴스 역할)
	init_q(&q);//초기화
	if (!root)//값이 없는 경우
		return;//종료
	else {//값이 있는경우
		enqueue(&q, root);//queue배열에 넣음
		while (!empty(&q)) {//비어있지 않는 경우 무한반복
			root = dequeue(&q);//queue배열에서 추출
			++(*count);//count값증가
			if (*count == aimNumber + 1) {//++count 형식으로 코드를 작성해서 +1해줍니다.
				*answer = root->data;//원하는 값 도출
				return;//종료
			}
			if (root->left) {//왼쪽탐색
				enqueue(&q, root->left);//왼쪽값을 queue배열에 넣음
			}
			if (root->right) {//오른쪽 탐색
				enqueue(&q, root->right);//오른쪽 값을 queue배열에 넣음
			}
		}
	}
	return;//종료
}
int main(void) {
	FILE *in = fopen("input.txt", "r");//교수님께서 주신 input.txt파일 읽기
	FILE *ot = fopen("output.txt", "w");//결과값을 output.txt파일에 출력
	int n = 0;//변수 n선언
	fscanf(in, "%d", &n);//50을 받습니다.
	for (int i = 0; i < n; i++) {//50번 반복
		int nodeNumber = 0;//노드의 개수를 받기 위해 선언하였습니다.
		fscanf(in, "%d", &nodeNumber);//각각의 테스트 값의 노드 개수 받기
		char cmd[50] = { 0 };//문자열 받기위해서 선언하였습니다.
		fscanf(in, "%s", cmd);//문자열의 받겠습니다.
		treeNode *root = NULL;//root 정의하겠습니다.
		for (int j = 0; j < nodeNumber; j++) {//노드의 갯수만큼 반복하겠습니다.
			int data = 0;//삽입할 데이터값을 위해 선언하였습니다.
			fscanf(in, "%d", &data);//삽입할 데이터 값을 읽기 
			root = BST_insert(root, data);//읽은 데이터 값을 bst트리를 그리기 위해서 작성
		}
		int aimNumber = 0;//몇번째 탐색값을 정할지 위해 선언하였습니다.
		sscanf(cmd + 4, "%d", &aimNumber);//dfs(n)의 경우 n값을 aimNumber이라는 변수에 담기 위해 작성했습니다.
		int count = 1;//count는 몇번째 인지 알기 위해서 작성했습니다
		int answer = 0;//asnwer은 n번째 탐색값을 저장하기 위해 작성하였습니다.
		if (cmd[0] == 'd') {//dfs로 진행해야하는 경우입니다.
			DFS(root, &count, aimNumber, &answer);//dfs함수로 이동
		}
		else {//bfs로 진행해야 하는 경우입니다.
			BFS(root, &count, aimNumber, &answer);//bfs함수로 이동
		}
		printf("%d\n", answer);//교수님이 즉석으로 보시기 편하게 콘솔창도 만들었습니다.
		fprintf(ot, "%d\n", answer);//output.txt파일에 결과값 출력
	}
	fclose(in);//파일닫기
	fclose(ot);//파일닫기
	return 0;//0반환, 종료
}
