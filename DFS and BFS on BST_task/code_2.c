#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4047)
#pragma warning(disable:4024)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_size 100
typedef struct treenode {
	int data;
	struct treenode *left;
	struct treenode *right;
}treenode;
treenode *root = NULL;
int dfs_list[100];
int bfs_list[100];
int top = -1;
treenode *stack[max_size];
void push(treenode *root) {
	if (top < max_size - 1) {
		stack[++top] = root;
	}
}
treenode *pop() {
	treenode *root = NULL;
	if (top >= 0) {
		root = stack[top--];
	}
	return root;
}
void init() {
	root->data = 0;
	root->left = root->right = NULL;
}
treenode *BST_insert(treenode *root, int data) {
	if (root == NULL) {
		root = (treenode*)malloc(sizeof(treenode));
		root->left = root->right = NULL;
		root->data = data;
		return root;
	}
	else {
		if (root->data > data) {
			root->left = BST_insert(root->left, data);
		}
		else {
			root->right = BST_insert(root->right, data);
		}
	}
	return root;
}

void dfs_(treenode *root, int k) {
	int dc = 1;
	while (1) {
		for (; root; root = root->left) {
			++dc;
			push(root);
			if (dc == k + 1) {
				dfs_list[k] = root->data;
				return;
			}
		}
		root = pop();
		if (!root) {
			break;
		}
		root = root->right;
	}
}
typedef struct queuetype {
	int queue[max_size];
	int front, rear;
}queuetype;
void init_q(queuetype *q) {
	q->front = q->rear = 0;
	return;
}
int empty(queuetype *q) {
	return (q->rear == q->front);
}
int full(queuetype *q) {
	return ((q->rear + 1) % max_size == q->front);
}
void enqueue(queuetype *q, int item) {
	if (full(q)) {
		exit(1);
	}
	else {
		q->rear = (q->rear + 1) % max_size;
		q->queue[q->rear] = item;
	}
	return;
}
int dequeue(queuetype *q) {
	if (empty(q)) {
		exit(1);
	}
	else {
		q->front = (q->front + 1) % max_size;
		return q->queue[q->front];
	}
}
void bfs_(treenode *root, int k) {
	int bc = 1;
	queuetype q;
	init_q(&q);
	if (root == NULL) {
		return;
	}
	else {
		enqueue(&q, root);
		while (!empty(&q)) {
			root = dequeue(&q);
			++bc;
			if (bc == k + 1) {
				bfs_list[k] = root->data;
				return;
			}
			if (root->left) {
				enqueue(&q, root->left);
			}
			if (root->right) {
				enqueue(&q, root->right);
			}
		}
	}
	return;
}
int dfs(int a) {
	return dfs_list[a];
}
int bfs(int a) {
	return bfs_list[a];
}
int main() {
	int n;//50받음	
	char read[50];//dfs or bfs읽음
	FILE *in = fopen("input.txt", "r");
	FILE *ot = fopen("output.txt", "w");
	while (feof(in) == 0) {
		fscanf(in, "%d", &n);
		for (int i = 0; i < n; i++) {
			treenode *root = NULL;
			int a;//root에 들어갈 숫자 개수	
			fscanf(in, "%d %s", &a, &read);
			for (int i = 0; i < a; i++) {
				int c = 0;
				fscanf(in, "%d ", &c);
				root = BST_insert(root, c);
			}
			int k = 0;//몇번째 탐색값을 정할지 위해 선언하였습니다.
			k = read[4] - '0';
			if (read[0] == 'd') {
				dfs_(root, k);
				printf("%d\n", dfs(k));
				fprintf(ot, "%d\n", dfs(k));
			}
			else {
				bfs_(root, k);
				printf("%d\n", bfs(k));
				fprintf(ot, "%d\n", bfs(k));
			}
		}
	}
	fclose(in);
	fclose(ot);
	return 0;
}