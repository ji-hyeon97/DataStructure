#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int map[50][50];
int visit[50];
void dfs(int node, int size, int* Cycle) {
	if (*Cycle) {//사이클이 생긴경우
		return;//종료
	}
	for (int i = 0; i < size; i++) {//그래프크기반복
		visit[node] = 1;//방문한거 체크
		if (map[node][i] == 1) {//방향이 있는 경우
			if (visit[i]) {//재방문시
				*Cycle = 1;//사이클이 생김
				return;//종료
			}
			dfs(i, size, Cycle);//map에서 1이된 그 정점으로 하여금 dfs탐색시도 
		}
		else {
			visit[node] = 0;//visit배열을 0으로 만들기(node 인덱스)
		}
	}
}
void init(int a) {
	for (int i = 0; i<a; i++) {
		for (int j = 0; j <= a; j++) {
			map[i][j] = 0;
		}
		visit[i] = 0;
	}
}
int main(void) {
	int n;
	int a;
	FILE *in = fopen("input.txt", "r");
	FILE *ot = fopen("output.txt", "w");
	while (feof(in) == 0) {
		fscanf(in, "%d", &n);
		for (int i = 0; i < n; i++) {
			fscanf(in, "%d", &a);
			init(a);
			for (int k = 0; k < a; k++) {
				for (int j = 0; j < a; j++) {
					fscanf(in, "%d ", &map[k][j]);
				}
			}
			int Cycle = 0;
			for (int i = 0; i < a; i++) {
				dfs(i, a, &Cycle);
			}
			printf("%d번째 정답 %d\n", i + 1, Cycle);
		}
	}
	fclose(in);
	fclose(ot);
	return 0;
}