#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define max 100
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}node;
node heap[max];
int idxLast;
void init() {
	for (int i = 0; i < max; i++) {
		heap[i].data = -1;
		heap[i].left = heap[i].right = NULL;
	}
	idxLast = -1;
}
void swap(int idxA, int idxB) {
	int temp = heap[idxA].data;
	heap[idxA].data = heap[idxB].data;
	heap[idxB].data = temp;
}
void reheapUp(int idxNewnode) {
	if (idxNewnode != 0) {
		int idxParent = (idxNewnode - 1) / 2;
		if (heap[idxNewnode].data > heap[idxParent].data) {
			swap(idxNewnode, idxParent);
		}
	}
}
void reheapDown(int idxRoot) {
	if (heap[idxRoot].left != NULL) {
		int *leftKey = &heap[idxRoot].left->data;
		int *rightKey = NULL;
		if (heap[idxRoot].right != NULL) {
			rightKey = &heap[idxRoot].right->data;
		}
		int idxLarger;
		if (rightKey == NULL || *leftKey > *rightKey) {
			idxLarger = idxRoot * 2 + 1;
		}
		else {
			idxLarger = idxRoot * 2 + 2;
		}
		if (heap[idxRoot].data < heap[idxLarger].data) {
			swap(idxRoot, idxLarger);
			reheapDown(idxLarger);
		}
	}
}
void add(int data) {
	idxLast++;
	heap[idxLast].data = data;
	if (idxLast % 2 == 0) {
		heap[(idxLast - 1) / 2].right = &heap[idxLast];
	}
	else {
		heap[(idxLast - 1) / 2].left = &heap[idxLast];
	}
	reheapUp(idxLast);
}
int del() {
	int ret = heap[0].data;
	heap[0].data = heap[idxLast].data;
	if (idxLast % 2 == 0) {
		heap[(idxLast - 1) / 2].right = NULL;
	}
	else {
		heap[(idxLast - 1) / 2].left = NULL;
	}
	idxLast--;
	reheapDown(0);
	return ret;
}
int main() {
	init();
	add(78);
	add(56);
	add(32);
	add(45);
	add(8);
	add(23);
	add(19);
	for (int i = 0; i < 3; i++) {
		printf("%d\n", del());
	}
	return 0;
}