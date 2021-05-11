#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define max_size 100
typedef struct treenode {
	int data;
	struct treenode *left, *right;
}treenode;
int Max(int a, int b) {
	if (a < b) {
		return b;
	}
	else {
		return a;
	}
}
int Min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}
int explore_max(treenode *node) {
	if (node == NULL) {
		return -100000;
	}
	else {
		int max_value = node->data;
		max_value = Max(max_value, explore_max(node->left));
		max_value = Max(max_value, explore_max(node->right));
		return max_value;
	}
}
int explore_min(treenode *node) {
	if (node == NULL) {
		return 100000;
	}
	else {
		int min_value = node->data;
		min_value = Min(min_value, explore_min(node->left));
		min_value = Min(min_value, explore_min(node->right));
		return min_value;
	}
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
	printf("최소값 : %d\n", explore_min(root));
	printf("최대값 : %d\n", explore_max(root));
	return 0;
}
