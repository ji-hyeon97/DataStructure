#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define max_size 100
typedef struct treenode {
	int data;
	struct treenode *left, *right;
}treenode;
int small(treenode *node, int value) {
	if (node == NULL) {
		return 0;
	}
	if (node->data < value) {
		printf("%d보다 작은 노드 : %d\n", value, node->data);
	}
	small(node->left, value);
	small(node->right, value);
}
int main() {
	treenode n1 = { 4,NULL,NULL };
	treenode n2 = { 2,NULL,NULL };
	treenode n3 = { 8,NULL,NULL };
	treenode n4 = { 6,NULL,NULL };
	treenode n5 = { 5,&n1,&n2 };
	treenode n6 = { 1,&n3,&n4 };
	treenode n7 = { 3,&n5,&n6 };
	treenode *root = &n7;
	int n;
	printf("값을 입력하시오 :");
	scanf("%d", &n);
	small(root, n);
	return 0;
}
