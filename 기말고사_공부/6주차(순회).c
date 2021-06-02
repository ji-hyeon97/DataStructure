#pragma warning(disable:4996)
#include<stdio.h>
#define MAX 100
typedef struct node {
	int valid;
	char *data;
	struct node *left;
	struct node *right;
}NODE;

NODE tree[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		tree[i].valid = 0;
		tree[i].data = NULL;
		tree[i].left = tree[i].right = NULL;
	}
}

void insert(int idx, char* data) {
	tree[idx].data = data;
	tree[idx].valid = 1;
	int parentIdx = (idx - 1) / 2;
	if (parentIdx < 0)
		return;
	if (idx % 2 == 0) {
		tree[parentIdx].right = &tree[idx];
	}
	else {
		tree[parentIdx].left = &tree[idx];
	}
}
void dfs_preorder(int idx) {
	printf("%s ", tree[idx].data);
	if (tree[idx].left != NULL) {
		dfs_preorder(idx * 2 + 1);
	}
	if (tree[idx].right != NULL) {
		dfs_preorder(idx * 2 + 2);
	}
}
void dfs_inorder(int idx) {
	if (tree[idx].left != NULL) {
		dfs_inorder(idx * 2 + 1);
	}
	printf("%s ", tree[idx].data);
	if (tree[idx].right != NULL) {
		dfs_inorder(idx * 2 + 2);
	}
}
void dfs_postorder(int idx) {
	if (tree[idx].left != NULL) {
		dfs_postorder(idx * 2 + 1);
	}
	if (tree[idx].right != NULL) {
		dfs_postorder(idx * 2 + 2);
	}
	printf("%s ", tree[idx].data);
}
NODE* queue[MAX];
int front, rear;
void initQ() {
	for (int i = 0; i < MAX; i++) {
		queue[i] = NULL;
	}
	front = rear = -1;
}
void enqueue(NODE *node) {
	queue[++rear] = node;
	if (front == -1) {
		front++;
	}
}
int isEmpty() {
	if (front == -1 && rear == -1)
		return 1;
	return 0;
}
NODE* dequeue() {
	NODE *node = queue[front];
	if (front == rear) {
		front = rear = -1;
	}
	else {
		front++;
	}
	return node;
}
void bfs(int idx) {
	NODE *curNode = &tree[0];
	initQ();
	while (curNode != NULL) {
		printf("%s ", curNode->data);
		if (curNode->left != NULL) {
			enqueue(curNode->left);
		}
		if (curNode->right != NULL) {
			enqueue(curNode->right);
		}
		if (!isEmpty()) {
			curNode = dequeue();
		}
		else {
			curNode = NULL;
		}
	}
}
void bfsArray() {
	for (int i = 0; i < MAX; i++) {
		if (tree[i].valid)
			printf("%s ", tree[i].data);
	}
}
int main() {
	init();
	insert(0, "+");
	insert(1, "x");
	insert(2, "d");
	insert(3, "a");
	insert(4, "+");
	insert(9, "b");
	insert(10,"c");
	dfs_inorder(0);
	printf("\n");
	bfs(0);
	printf("\n");
	bfsArray();
	return 0;
}