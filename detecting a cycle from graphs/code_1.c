#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int map[50][50];//전역변수 이차원 배열
typedef struct {
	int direct;//간선
	int **matrix;//그래프
}graphType;//구조체 이름 graphType
graphType *new(int size){//map = g->matrix로 설정하기 위하여
	int i = 0;
graphType *g = (graphType *)malloc(sizeof(graphType));//동적할당
g->direct = size;//최대 정점 개수 설정
g->matrix = (int **)malloc(sizeof(int *)*size);//매트릭스는 이차원배열이며 동적할당을 하겠습니다.
for (i = 0; i < size; i++) {
	g->matrix[i] = (int *)malloc(sizeof(int)*size);//이차원 배열 matrix의 행의 값에 동적메모리 할당하겠습니다.
	memset(g->matrix[i], 0, sizeof(int)*size);//메모리 0으로 초기화
}
return g;
}
void delete(graphType *g) {//동적할당한 g, g->matrix 메모리 해제하기
	int i = 0;
	for (i = 0; i < g->direct; i++) {
		free(g->matrix[i]);//이차원 배열 matrix의 행의 값에 동적메모리 해제하겠습니다.
	}
	free(g->matrix);//매트릭스 메모리 해제
	free(g);//동적할당 받았었던 그래프 메모리 해제
}
void add(graphType *g, int first, int final) {
	g->matrix[first][final] = 1;//방향을 가지기 때문에 간선을 설정하겠습니다.
}
int viewGraph(graphType *g) {//자세한 정보사항을 파악하기 위해 작성하였습니다.
	int i = 0;
	int j = 0;
	for (i = 0; i < g->direct; i++) {
		printf("%d 에서 갈 수 있는 정점:", i);
		for (j = 0; j < g->direct; j++) {
			if (g->matrix[i][j]) {
				printf("%d ", j);
			}
		}
		printf("\n");
	}
	for (i = 0; i < g->direct; i++) {
		for (j = 0; j < g->direct; j++) {
			for (int k = 0; k < g->direct; k++) {
				if (i == j) {
					continue;
				}
				if (g->matrix[i][j] == 1 && g->matrix[j][i] == 1) {
					return 1;
				}
				if (g->matrix[i][j] == 1) {
					if (g->matrix[j][k] == 1) {
						if (g->matrix[k][i] == 1) {
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}
int answer(graphType *g) {//답을 구하기 위한 함수입니다
	int i = 0;
	int j = 0;
	for (i = 0; i < g->direct; i++) {
		for (j = 0; j < g->direct; j++) {
			for (int k = 0; k < g->direct; k++) {
				if (i == j) {//pdf파일에 따르면 no self-loops 입니다
					continue;
				}
				if (g->matrix[i][j] == 1 && g->matrix[j][i] == 1) {// 2개의 노드가 서로왔다갔다 하는 경우
					return 1;//사이클 생성
				}
				if (g->matrix[i][j] == 1) {//32번째 상황을 해결하기 위해 작성하였습니다.
					if (g->matrix[j][k] == 1) {//32번째 상황을 해결하기 위해 작성하였습니다.
						if (g->matrix[k][i] == 1) {//32번째 상황을 해결하기 위해 작성하였습니다.
							return 1;//사이클생성
						}
					}
				}
			}
		}
	}
	return 0;//사이클 생성안함
}
void init(int a) {//초기화
	for (int i = 0; i<a; i++) {
		for (int j = 0; j<a; j++) {
			map[i][j] = 0;//이차원배열 map을 0으로 만듬
		}
	}
}
int main(void) {
	graphType *g;
	int n;//50읽기
	int a;//크기읽기
	FILE *in = fopen("input.txt", "r");//input.txt파일읽기
	FILE *ot = fopen("output.txt", "w");//output.txt파일쓰기
	while (feof(in) == 0) {//파일이 끝날때까지
		fscanf(in, "%d", &n);//50읽음
		for (int i = 0; i < n; i++) {
			fscanf(in, "%d", &a);//크기 읽기
			init(a);//초기화
			for (int k = 0; k < a; k++) {
				for (int j = 0; j < a; j++) {
					fscanf(in, "%d ", &map[k][j]);//인정행렬 읽기
				}
			}
			g = new(a);
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < a; j++) {
					if (map[i][j] == 1) {
						add(g, i, j);//간선 추가
					}
				}
			}
			/*
			자세한 상황을 알아보기 위한 출력구문 입니다.
			printf("%d번째 문제의 상황은\n", i + 1);
			printf("이며 정답은 %d 입니다.\n\n", viewGraph(graph));
			*/
			printf("%d\n", answer(g));//즉석으로 보시기 편하게 콘솔창도 만들었습니다
			fprintf(ot, "%d\n", answer(g));//output.txt파일에 출력
			delete(g);//그래프 소멸
		}
	}
	fclose(in);//파일닫기
	fclose(ot);//파일닫기
	return 0;
}