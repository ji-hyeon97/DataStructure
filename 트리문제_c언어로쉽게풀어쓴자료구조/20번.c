#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define max_size 100
typedef struct treenode {
	int data;
	struct treenode *left, *right;
}treenode;
treenode *new_node(int item) {
	treenode *temp = (treenode*)malloc(sizeof(treenode));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}
treenode *insert_node(treenode *node, int key) {
	if (node == NULL) {
		return new_node(key);
	}
	if (key < node->data) {
		node->left = insert_node(node->left, key);
	}
	else if (key > node->data) {
		node->right = insert_node(node->right, key);
	}
	return node;
}
void plus_one(treenode* root) {
	if (root == NULL) {
		return;
	}
	plus_one(root->right);
	root->data++;
	printf("%d ", root->data);
	plus_one(root->left);
	
}
int main(){
	int key[11] = {11,3,4,1,56,5,6,2,98,32,23 };
	treenode *root = NULL;
	for (int i = 0; i < 11; i++) {
		root = insert_node(root, key[i]);
	}
	plus_one(root);
	return 0;
}
