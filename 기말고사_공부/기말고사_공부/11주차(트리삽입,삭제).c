
#pragma warning(disable:4996)
#include<stdio.h>
#define MAX 100
typedef struct node {
	int valid;
	int data;
	struct node *left;
	struct node *right;
}NODE;

NODE tree[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		tree[i].valid = 0;
		tree[i].data = -1;
		tree[i].left = tree[i].right = NULL;
	}
}

int isEmpty(int curIdx) {
	return tree[curIdx].valid == 0;
}
void add(int curIdx, int data) {
	if (isEmpty(curIdx)) {
		tree[curIdx].data = data;
		tree[curIdx].valid = 1;
		if (curIdx == 0) {
			return;
		}
		int parentIdx = (curIdx - 1) / 2;
		if (curIdx % 2 == 0) {
			tree[parentIdx].right = &tree[curIdx];
		}
		else {
			tree[parentIdx].left = &tree[curIdx];
		}
		return;
	}
	if (data < tree[curIdx].data) {
		add(curIdx * 2 + 1, data);
	}
	else {
		add(curIdx * 2 + 2, data);
	}
}
int largest(int curIdx) {
	if (tree[curIdx].right == NULL && tree[curIdx].valid == 1) {
		return curIdx;
	}
	if (tree[curIdx].right != NULL) {
		return largest(curIdx * 2 + 2);
	}
	return 0;
}
void del(int curIdx, int target) {
	if (tree[curIdx].valid == 0) {
		return;
	}
	int parentIdx = (curIdx - 1) / 2;
	if (tree[curIdx].data == target) {
		tree[curIdx].valid = 0;

		if (tree[curIdx].left == NULL && tree[curIdx].right == NULL) {
			if (curIdx % 2 == 0) {
				tree[parentIdx].right = NULL;
			}
			else {
				tree[parentIdx].left = NULL;
			}
		}
		else if (tree[curIdx].left == NULL && tree[curIdx].right != NULL) {
			if (curIdx % 2 == 0) {
				tree[parentIdx].right = &tree[curIdx * 2 + 2];
			}
			else {
				tree[parentIdx].left = &tree[curIdx * 2 + 2];
			}
		}
		else if (tree[curIdx].left != NULL && tree[curIdx].right == NULL) {
			if (curIdx % 2 == 0) {
				tree[parentIdx].right = &tree[curIdx * 2 + 1];
			}
			else {
				tree[parentIdx].left = &tree[curIdx * 2 + 1];
			}
		}
		else {
			int idxLargest = largest(curIdx * 2 + 1);
			tree[curIdx].data = tree[idxLargest].data;
			tree[curIdx].valid = 1;

			if (idxLargest % 2 == 0) {
				tree[(idxLargest - 1) / 2].right = NULL;
			}
			else {
				tree[(idxLargest - 1) / 2].left = NULL;
			}
		}
		return;
	}
	if (target < tree[curIdx].data) {
		del(curIdx * 2 + 1,target);
	}
	else {
		del(curIdx * 2 + 2, target);
	}
}

int main() {
	init();
	add(0, 23);
	add(0, 18);
	add(0, 44);
	add(0, 12);
	add(0, 20);
	add(0, 35);
	add(0, 52);
	add(0, 19);
	add(0, 38);

	del(0, 44);
	return 0;
}

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int map[50][50];
int visit[50];
int finish[50];
void dfs(int node, int size, int* Cycle) {
	if (*Cycle) {//사이클이 생긴경우
		return;//종료
	}
	visit[node] = 1;//방문한거 체크	
	for (int i = 0; i < size; i++) {//그래프크기반복
		int next = node;
		if (!visit[next])
			dfs(next,size,Cycle);
		else if (finish[next] == 0) { //  next가 이미 방문했지만, 종료되지 않는 정점이면
			*Cycle = 1;
		}
	}
	finish[node] = 1;
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
			dfs(1, a, &Cycle);
			printf("%d번째 정답 %d\n", i + 1, Cycle);
		}
	}
	fclose(in);
	fclose(ot);
	return 0;
}
*/