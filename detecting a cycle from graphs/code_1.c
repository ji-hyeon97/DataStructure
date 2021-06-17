#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int map[50][50];//�������� ������ �迭
typedef struct {
	int direct;//����
	int **matrix;//�׷���
}graphType;//����ü �̸� graphType
graphType *new(int size){//map = g->matrix�� �����ϱ� ���Ͽ�
	int i = 0;
graphType *g = (graphType *)malloc(sizeof(graphType));//�����Ҵ�
g->direct = size;//�ִ� ���� ���� ����
g->matrix = (int **)malloc(sizeof(int *)*size);//��Ʈ������ �������迭�̸� �����Ҵ��� �ϰڽ��ϴ�.
for (i = 0; i < size; i++) {
	g->matrix[i] = (int *)malloc(sizeof(int)*size);//������ �迭 matrix�� ���� ���� �����޸� �Ҵ��ϰڽ��ϴ�.
	memset(g->matrix[i], 0, sizeof(int)*size);//�޸� 0���� �ʱ�ȭ
}
return g;
}
void delete(graphType *g) {//�����Ҵ��� g, g->matrix �޸� �����ϱ�
	int i = 0;
	for (i = 0; i < g->direct; i++) {
		free(g->matrix[i]);//������ �迭 matrix�� ���� ���� �����޸� �����ϰڽ��ϴ�.
	}
	free(g->matrix);//��Ʈ���� �޸� ����
	free(g);//�����Ҵ� �޾Ҿ��� �׷��� �޸� ����
}
void add(graphType *g, int first, int final) {
	g->matrix[first][final] = 1;//������ ������ ������ ������ �����ϰڽ��ϴ�.
}
int viewGraph(graphType *g) {//�ڼ��� ���������� �ľ��ϱ� ���� �ۼ��Ͽ����ϴ�.
	int i = 0;
	int j = 0;
	for (i = 0; i < g->direct; i++) {
		printf("%d ���� �� �� �ִ� ����:", i);
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
int answer(graphType *g) {//���� ���ϱ� ���� �Լ��Դϴ�
	int i = 0;
	int j = 0;
	for (i = 0; i < g->direct; i++) {
		for (j = 0; j < g->direct; j++) {
			for (int k = 0; k < g->direct; k++) {
				if (i == j) {//pdf���Ͽ� ������ no self-loops �Դϴ�
					continue;
				}
				if (g->matrix[i][j] == 1 && g->matrix[j][i] == 1) {// 2���� ��尡 ���οԴٰ��� �ϴ� ���
					return 1;//����Ŭ ����
				}
				if (g->matrix[i][j] == 1) {//32��° ��Ȳ�� �ذ��ϱ� ���� �ۼ��Ͽ����ϴ�.
					if (g->matrix[j][k] == 1) {//32��° ��Ȳ�� �ذ��ϱ� ���� �ۼ��Ͽ����ϴ�.
						if (g->matrix[k][i] == 1) {//32��° ��Ȳ�� �ذ��ϱ� ���� �ۼ��Ͽ����ϴ�.
							return 1;//����Ŭ����
						}
					}
				}
			}
		}
	}
	return 0;//����Ŭ ��������
}
void init(int a) {//�ʱ�ȭ
	for (int i = 0; i<a; i++) {
		for (int j = 0; j<a; j++) {
			map[i][j] = 0;//�������迭 map�� 0���� ����
		}
	}
}
int main(void) {
	graphType *g;
	int n;//50�б�
	int a;//ũ���б�
	FILE *in = fopen("input.txt", "r");//input.txt�����б�
	FILE *ot = fopen("output.txt", "w");//output.txt���Ͼ���
	while (feof(in) == 0) {//������ ����������
		fscanf(in, "%d", &n);//50����
		for (int i = 0; i < n; i++) {
			fscanf(in, "%d", &a);//ũ�� �б�
			init(a);//�ʱ�ȭ
			for (int k = 0; k < a; k++) {
				for (int j = 0; j < a; j++) {
					fscanf(in, "%d ", &map[k][j]);//������� �б�
				}
			}
			g = new(a);
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < a; j++) {
					if (map[i][j] == 1) {
						add(g, i, j);//���� �߰�
					}
				}
			}
			/*
			�ڼ��� ��Ȳ�� �˾ƺ��� ���� ��±��� �Դϴ�.
			printf("%d��° ������ ��Ȳ��\n", i + 1);
			printf("�̸� ������ %d �Դϴ�.\n\n", viewGraph(graph));
			*/
			printf("%d\n", answer(g));//�Ｎ���� ���ñ� ���ϰ� �ܼ�â�� ��������ϴ�
			fprintf(ot, "%d\n", answer(g));//output.txt���Ͽ� ���
			delete(g);//�׷��� �Ҹ�
		}
	}
	fclose(in);//���ϴݱ�
	fclose(ot);//���ϴݱ�
	return 0;
}