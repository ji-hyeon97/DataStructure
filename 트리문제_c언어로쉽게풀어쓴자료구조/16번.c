#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define max_size 100
typedef struct treenode {
	int data;
	struct treenode *left, *right;
}treenode;
int one_node(treenode *node) {
	if (node == NULL) {
		return 0;
	}
	int count = 0;
	if ((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL)) {
		count++;
	}
	count = count + one_node(node->left) + one_node(node->right);
	return count;
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
	treenode a1 = { 4,NULL,NULL };
	treenode a2 = { 4,&a1,NULL };
	treenode *root1 = &a2; 
	printf("자식이 하나인 노드의 개수 : %d개 입니다.\n", one_node(root));
	printf("자식이 하나인 노드의 개수 : %d개 입니다.\n", one_node(root1));
	return 0;
}
