#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define max_size 100
typedef struct treenode {
	int data;
	struct treenode *left, *right;
}treenode;
int sum(treenode *node) {
	if (node == NULL) {
		return 0;
	}
	int answer = node->data;
	answer = answer + sum(node->left) + sum(node->right);
	return answer;
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
	printf("노드의 합은 %d입니다.\n", sum(root));	
	return 0;
}