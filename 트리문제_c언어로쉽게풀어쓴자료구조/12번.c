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
	if (a > b) {
		return a;
	}
	if (a < b) {
		return b;
	}
}
int mystery(treenode *p) {
	if (p == NULL) {
		return 0;
	}
	else if (p->left == NULL && p->right == NULL) {
		return p->data;
	}
	else {
		return Max(mystery(p->left), mystery(p->right));
	}
}
int main() {
	treenode n1 = { 4,NULL,NULL };
	treenode n2 = { 2,NULL,NULL };
	treenode n3 = { 8,NULL,NULL };
	treenode n4 = { 6,NULL,NULL };
	treenode n5 = { 5,&n1,&n2 };
	treenode n6 = { 1,&n3,&n4 };
	treenode n7 = { 1,&n5,&n6 };
	treenode *root = &n7;
	printf("12번문항의 답은:%d 입니다.\n", mystery(root));
	return 0;
}
