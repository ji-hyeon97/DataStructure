//순회개념정리
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