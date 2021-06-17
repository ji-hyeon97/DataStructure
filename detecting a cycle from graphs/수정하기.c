#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int map[50][50];
int visit[50];
void dfs(int node, int size, int* Cycle) {
	if (*Cycle) {//����Ŭ�� ������
		return;//����
	}
	for (int i = 0; i < size; i++) {//�׷���ũ��ݺ�
		visit[node] = 1;//�湮�Ѱ� üũ
		if (map[node][i] == 1) {//������ �ִ� ���
			if (visit[i]) {//��湮��
				*Cycle = 1;//����Ŭ�� ����
				return;//����
			}
			dfs(i, size, Cycle);//map���� 1�̵� �� �������� �Ͽ��� dfsŽ���õ� 
		}
		else {
			visit[node] = 0;//visit�迭�� 0���� �����(node �ε���)
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
			printf("%d��° ���� %d\n", i + 1, Cycle);
		}
	}
	fclose(in);
	fclose(ot);
	return 0;
}