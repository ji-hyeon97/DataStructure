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
	else {
		return b;
	}
}
int get_height(treenode *node) {
	int height = 0;
	if (node != NULL) {
		height = 1 + Max(get_height(node->left), get_height(node->right));
	}
}
int isBalanced(treenode *node) {
	if (node == NULL) {
		return 1;
	}
	int leftHeight = get_height(node->left);
	int rightHeight = get_height(node->right);
	if((leftHeight - rightHeight) <= 1 && (leftHeight - rightHeight) >= -1)
		return 1;
	return 0;

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
	treenode a1 = { 1,NULL,NULL };
	treenode a2 = { 2,&a1,NULL };
	treenode a3 = { 3,&a2,NULL };
	treenode *root1 = &a3;
	printf("1이 나오면 균형트리 0이 나오면 균형트리 아님\n");
	printf("13번문항의 답은:%d 입니다. <균형트리 n> \n", isBalanced(root));
	printf("13번문항의 답은:%d 입니다. <균형트리아님 a> \n", isBalanced(root1));
	return 0;
}
