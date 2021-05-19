#define _CRT_SECURE_NO_WARNINGS//visual studio�� ���Ȱ��� ������ �����ϰڽ��ϴ�.
#pragma warning(disable : 4047)//ť ����ü�� Ʈ�� ����ü ���̿����� ���� �����޴� �������� �κ�(int��)���� Ȥ�ó� build�� ���� ������� �ۼ��߽��ϴ�.
#pragma warning(disable : 4024)//ť ����ü�� Ʈ�� ����ü ���̿����� ���� �����޴� �������� �κ�(int��)���� Ȥ�ó� build�� ���� ������� �ۼ��߽��ϴ�.
#include <stdio.h>//���, ���� ����� �����մϴ�.
#include <stdlib.h>//Ʈ�������� �����Ҵ��� ���� �ۼ��Ͽ����ϴ�.
#define max_size 100//max_size�� 100���� �����ϰڽ��ϴ�.
typedef struct treenode {//treenode�� ����ü
	int data;//���� data��
	struct treenode *left;//��ũ�ʵ� ����
	struct treenode *right;//��ũ�ʵ� ������
}treeNode;//����ü �̸��� treeNode�Դϴ�.
typedef struct queuetype {//queue����ü �ۼ�
	int queue[max_size];//������ queue�� �迭
	int front, rear;//����ť�� �ۼ��ϱ� ���ؼ� �ʿ��� ����
}queuetype;//����ü�̸���queuetype�Դϴ�.
void init_q(queuetype *q) {//�ʱ�ȭ
	q->front = q->rear = 0;//�ʱ�ȭ ��Ȳ�Դϴ�.
	return;//����
}
int empty(queuetype *q) {//����ִ°��
	return (q->rear == q->front);//ť�� ����ִ� ��Ȳ�Դϴ�.
}
int full(queuetype *q) {//���������
	return ((q->rear + 1) % max_size == q->front);// ť�� ������ ��Ȳ�Դϴ�.(����ť)
}
void enqueue(queuetype *q, int item) {//ť �迭�� ����
	if (full(q)) {//ť�� �������ִ� ���
		exit(1);//���α׷� ����
	}
	else {//ť�� ������ ���� �ʴ� ���
		q->rear = (q->rear + 1) % max_size;//rear�� ����
		q->queue[q->rear] = item;//���� ����
	}
	return;//����
}
int dequeue(queuetype *q) {//����
	if (empty(q)) {//ť�� ����ִ� ���
		exit(1);//���α׷� ����
	}
	else {//ť�� ������� �ʴ� ���
		q->front = (q->front + 1) % max_size;//front�� ����(����ť������ ó�� front���� null���Դϴ�.)
		return q->queue[q->front];//���� ����
	}
}
treeNode *makeNode(int value) {//��� ����
	treeNode *node = (treeNode *)malloc(sizeof(treeNode));//�����Ҵ�
	node->data = value;//����� ������ ������ value�� ����
	node->left = node->right = NULL;//�ܸ����
	return node;//����ȯ
}
treeNode *BST_insert(treeNode *root, int data) {//BSTƮ�������� �ۼ��ϰڽ��ϴ�.
	if (root == NULL) {//���� ���� ���
		root = makeNode(data);//ó������ root�� ����
	}
	else {//���� �ִ� ���
		if (root->data > data)//��Ʈ�� ������ ���� ���� ������ �����ͺ��� ū ���
			root->left = BST_insert(root->left, data);//��ũ�ʵ带 ���� �������� �̵�
		else//��Ʈ�� ������ ���� ���� ������ �����ͺ��� ���� ���
			root->right = BST_insert(root->right, data);//��ũ�ʵ带 ���� ���������� �̵�
	}
	return root;//��Ʈ��ȯ
}
void DFS(treeNode *root, int *count, int aimNumber, int *answer) {//dfsŽ��
	if (!root) {//Ʈ���� ���� ���
		return;//����
	}
	if (*count > aimNumber) {//count���� aimNumber������ ū���
		return;//����
	}
	if (*count == aimNumber) {//count���̶� aimNumber���̶� ���� ���
		*answer = root->data;//�� Ž������ answer�̶�� �ּҿ� �����ϰڽ��ϴ�.
		return;//����
	}
	*count += 1;//count���� aimNumber������ ���� ���
	DFS(root->left, count, aimNumber, answer);//�������� Ž��
	DFS(root->right, count, aimNumber, answer);//���������� Ž��
}
void BFS(treeNode *root, int *count, int aimNumber, int *answer) {//bfsŽ��
	queuetype q;//����ü queuetype�� ���� q (�ν��Ͻ� ����)
	init_q(&q);//�ʱ�ȭ
	if (!root)//���� ���� ���
		return;//����
	else {//���� �ִ°��
		enqueue(&q, root);//queue�迭�� ����
		while (!empty(&q)) {//������� �ʴ� ��� ���ѹݺ�
			root = dequeue(&q);//queue�迭���� ����
			++(*count);//count������
			if (*count == aimNumber + 1) {//++count �������� �ڵ带 �ۼ��ؼ� +1���ݴϴ�.
				*answer = root->data;//���ϴ� �� ����
				return;//����
			}
			if (root->left) {//����Ž��
				enqueue(&q, root->left);//���ʰ��� queue�迭�� ����
			}
			if (root->right) {//������ Ž��
				enqueue(&q, root->right);//������ ���� queue�迭�� ����
			}
		}
	}
	return;//����
}
int main(void) {
	FILE *in = fopen("input.txt", "r");//�����Բ��� �ֽ� input.txt���� �б�
	FILE *ot = fopen("output.txt", "w");//������� output.txt���Ͽ� ���
	int n = 0;//���� n����
	fscanf(in, "%d", &n);//50�� �޽��ϴ�.
	for (int i = 0; i < n; i++) {//50�� �ݺ�
		int nodeNumber = 0;//����� ������ �ޱ� ���� �����Ͽ����ϴ�.
		fscanf(in, "%d", &nodeNumber);//������ �׽�Ʈ ���� ��� ���� �ޱ�
		char cmd[50] = { 0 };//���ڿ� �ޱ����ؼ� �����Ͽ����ϴ�.
		fscanf(in, "%s", cmd);//���ڿ��� �ްڽ��ϴ�.
		treeNode *root = NULL;//root �����ϰڽ��ϴ�.
		for (int j = 0; j < nodeNumber; j++) {//����� ������ŭ �ݺ��ϰڽ��ϴ�.
			int data = 0;//������ �����Ͱ��� ���� �����Ͽ����ϴ�.
			fscanf(in, "%d", &data);//������ ������ ���� �б� 
			root = BST_insert(root, data);//���� ������ ���� bstƮ���� �׸��� ���ؼ� �ۼ�
		}
		int aimNumber = 0;//���° Ž������ ������ ���� �����Ͽ����ϴ�.
		sscanf(cmd + 4, "%d", &aimNumber);//dfs(n)�� ��� n���� aimNumber�̶�� ������ ��� ���� �ۼ��߽��ϴ�.
		int count = 1;//count�� ���° ���� �˱� ���ؼ� �ۼ��߽��ϴ�
		int answer = 0;//asnwer�� n��° Ž������ �����ϱ� ���� �ۼ��Ͽ����ϴ�.
		if (cmd[0] == 'd') {//dfs�� �����ؾ��ϴ� ����Դϴ�.
			DFS(root, &count, aimNumber, &answer);//dfs�Լ��� �̵�
		}
		else {//bfs�� �����ؾ� �ϴ� ����Դϴ�.
			BFS(root, &count, aimNumber, &answer);//bfs�Լ��� �̵�
		}
		printf("%d\n", answer);//�������� �Ｎ���� ���ñ� ���ϰ� �ܼ�â�� ��������ϴ�.
		fprintf(ot, "%d\n", answer);//output.txt���Ͽ� ����� ���
	}
	fclose(in);//���ϴݱ�
	fclose(ot);//���ϴݱ�
	return 0;//0��ȯ, ����
}