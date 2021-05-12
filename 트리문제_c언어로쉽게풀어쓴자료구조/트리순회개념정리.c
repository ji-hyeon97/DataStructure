//1번 <재귀>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
}treenode;
treenode n1 = { 1,NULL,NULL };
treenode n2 = { 4,&n1,NULL };
treenode n3 = { 16,NULL,NULL };
treenode n4 = { 25,NULL,NULL };
treenode n5 = { 20,&n3,&n4 };
treenode n6 = { 15,&n2,&n5 };
treenode *root = &n6;
inorder(treenode *root) {//중위순회
	if (root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
preorder(treenode *root) {//전위순회
	if (root) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
postorder(treenode *root) {//후위순회
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}
int main() {
	printf("중위순회 : ");
	inorder(root);
	printf("\n");
	printf("전위순회 : ");
	preorder(root);
	printf("\n");
	printf("후위순회 : ");
	postorder(root);
	printf("\n");
	return 0;
}

//2번 <스택 트리 중위순회>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define max_size 100
typedef struct treenode {
	int data;
	struct treenode *left, *right;
}treenode;
int top = -1;
treenode *stack[max_size];
void push(treenode *p) {
	if (top < max_size - 1) {
		stack[++top] = p;
	}
}
treenode *pop() {
	treenode *p = NULL;
	if (top >= 0) {
		p = stack[top--];
	}
	return p;
}
void inorder(treenode *root) {
	while (1) {
		for (; root; root = root->left) {
			push(root);
		}
		root = pop();
		if (!root) {
			break;
		}
		printf("%d ", root->data);
		root = root->right;
	}
}
int main() {
	treenode n1 = { 1,NULL,NULL };
	treenode n2 = { 4,&n1,NULL };
	treenode n3 = { 16,NULL,NULL };
	treenode n4 = { 25,NULL,NULL };
	treenode n5 = { 20,&n3,&n4 };
	treenode n6 = { 15,&n2,&n5 };
	treenode *root = &n6;
	inorder(root);
	return 0;
}
.
//3번 <레벨순회>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define max_size 100
typedef struct treenode {
	int data;
	struct treenode *left, *right;
}treenode;
typedef struct queuetype {
	int queue[max_size];
	int front, rear;
}queuetype;
void init(queuetype *q) {
	q->front = q->rear=0 ;
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
void level_inorder(treenode *n) {
	queuetype q;
	init(&q);
	if (n == NULL) {
		return;
	}
	else {
		enqueue(&q, n);
		while (!empty(&q)) {
			n = dequeue(&q);
			printf("%d ", n->data);
			if (n->left) {
				enqueue(&q, n->left);
			}
			if (n->right) {
				enqueue(&q, n->right);
			}
		}
	}
	return;
}
int main() {
	treenode n1 = { 1,NULL,NULL };
	treenode n2 = { 4,&n1,NULL };
	treenode n3 = { 16,NULL,NULL };
	treenode n4 = { 25,NULL,NULL };
	treenode n5 = { 20,&n3,&n4 };
	treenode n6 = { 15,&n2,&n5 };
	treenode *root = &n6;
	level_inorder(root);
	return 0;
}

//4번
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define max_size 100
typedef struct treenode {
	int data;
	struct treenode *left, *right;
}treenode;
int get_node_count(treenode *node) {//노드 개수
	int count = 0;
	if (node != NULL) {
		count = 1+ get_node_count(node->left) + get_node_count(node->right);
	}
	return count;
}
int Max(int a, int b) {//트리 높이
	if (a > b) {
		return a;
	}
	if (a < b) {
		return b;
	}
}

int get_height(treenode *node) {//트리 높이
	int height = 0;
	if (node != NULL) {
		height = 1 + Max(get_height(node->left),get_height(node->right));
	}
	return height;
}
int get_single_node(treenode *node) {//단말노드 개수
	int count = 0;
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL) {
			return 1;
		}
		else {
			count = get_single_node(node->left) + get_single_node(node->right);
		}
	}
	return count;
}
int main() {
	treenode n1 = { 1,NULL,NULL };
	treenode n2 = { 4,&n1,NULL };
	treenode n3 = { 16,NULL,NULL };
	treenode n4 = { 25,NULL,NULL };
	treenode n5 = { 20,&n3,&n4 };
	treenode n6 = { 15,&n2,&n5 };
	treenode *root = &n6;
	printf("노드 개수 %d 입니다\n", get_node_count(root));
	printf("트리 높이 %d 입니다.\n", get_height(root));
	printf("단말노드 개수 %d 입니다.\n", get_single_node(root));
	return 0;
}
//연습
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define max_size 100
typedef struct treenode {
	int valid;
	int data;
	struct treenode *left;
	struct treenode *right;
}treenode;
treenode tree[max_size];
void init() {
	for (int i = 0; i < max_size; i++) {
		tree[i].valid = 0;
		tree[i].data = -1;
		tree[i].left = tree[i].right = NULL;
	}
}
int empty(int index) {
	return tree[index].valid == 0;
}
void insert(int index, int data) {
	if (empty(index)) {
		tree[index].data = data;
		tree[index].valid = 1;
		if (index == 0) {
			return;
		}
		int parent_index = (index - 1) / 2;
		if (index % 2 == 0) {
			tree[parent_index].right = &tree[index];
		}
		else {
			tree[parent_index].left = &tree[index];
		}
		return;
	}
	if (data < tree[index].data) {
		insert(index * 2 + 1, data);
	}
	else {
		insert(index * 2 + 2, data);
	}	
}	
void dfs_preorder(int index) {
	printf("%d ",tree[index].data);
	if (tree[index].left != NULL) {
		dfs_preorder(index * 2 + 1);
	}
	if (tree[index].right != NULL) {
		dfs_preorder(index * 2 + 2);
	}
} 
treenode *queue[max_size];
int front, rear;
void init_q() {
	for (int i = 0; i < max_size; i++) {
		queue[i] = NULL;
	}
	front = rear = -1;
}
int empty_q() {
	if (front == -1 && rear == -1) {
		return 1;
	}
	return 0;
}
void enqueue(treenode* node) {
	queue[++rear] = node;
	if (front == -1) {
		front++;
	}
}
treenode *dequeue() {
	treenode *node = queue[front];
	if (front == rear) {
		front = rear = -1;
	}
	else {
		front++;
	}
	return node;
}
void bfs() {
	treenode *node = &tree[0];
	init_q();
	while (node != NULL) {
		printf("%d ", node->data);
		if (node->left != NULL) {
			enqueue(node->left);
		}
		if (node->right != NULL) {
			enqueue(node->right);
		}
		if (!empty_q()) {
			node = dequeue();
		}
		else {
			node = NULL;
		}
	}
}
void bfsArray(int a) {
	for (int i = 0; i < max_size; i++) {
		if (tree[i].valid) {
			printf("%d ", tree[i].data);
		}
	}
	printf("\nrea %d ", tree[a].data);
} 
int main() {
	init();
	insert(0, 825);
	insert(0, 162);
	insert(0, 768);
	insert(0, 724);
	insert(0, 635);	
	dfs_preorder(0);
	printf("\n");
	bfs();
	printf("\n");
	bfsArray(19);
	return 0;
}
//연습2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define max_size 100
typedef struct treenode{
	int data;
	struct treenode *left;
	struct treenode *right;
}treenode;
int top = -1;
int stack[max_size];
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
void inorder(treenode *root) {
	while (1) {
		for (; root; root = root->left) {
			push(root);
		}
		root = pop();
		if (!root) {
			break;
		}
		//printf("%d ", root->data);
		root = root->right;
	}
}
treenode *root = NULL;
void init() {
	treenode *root = NULL;
	root->data = NULL;
	root->left = root->right = NULL;
}
treenode *BST_insert(treenode *root, int data){
	if (root == NULL)	{
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
treenode* BST_search(treenode* root, int data){
	if (root == NULL) {
		return NULL;
	}
	if (root->data == data) {
		return root;
	}
	else if (root->data > data) {
		return BST_search(root->left, data);
	}
	else {
		return BST_search(root->right, data);
	}
}
void BST_print(treenode* root){
	if (root == NULL) {
		return;
	}	
	printf("%d ", root->data);
	BST_print(root->left);
	BST_print(root->right);
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
void level_inorder(treenode *n) {
	queuetype q;
	init_q(&q);
	if (n == NULL) {
		return;
	}
	else {
		enqueue(&q, n);
		while (!empty(&q)) {
			n = dequeue(&q);
			printf("%d \n", n->data);
			if (n->left) {
				enqueue(&q, n->left);
			}
			if (n->right) {
				enqueue(&q, n->right);
			}
		}
	}
	return;
}
int main(){
	root = BST_insert(root, 825);
	root = BST_insert(root, 162);
	root = BST_insert(root, 768);
	root = BST_insert(root, 724);
	root = BST_insert(root, 635); 
	root = BST_insert(root, 935);
	level_inorder(root,3);
	BST_print(root);
}
