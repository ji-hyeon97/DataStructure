//��ȸ��������
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
inorder(treenode *root) {//������ȸ
	if (root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
preorder(treenode *root) {//������ȸ
	if (root) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
postorder(treenode *root) {//������ȸ
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}
int main() {
	printf("������ȸ : ");
	inorder(root);
	printf("\n");
	printf("������ȸ : ");
	preorder(root);
	printf("\n");
	printf("������ȸ : ");
	postorder(root);
	printf("\n");
	return 0;
}