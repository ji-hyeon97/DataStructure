#define _CRT_SECURE_NO_WARNINGS
#define max_element 200
#include <stdio.h>
#include<stdlib.h>
typedef struct {
	int key;
}element;
typedef struct {
	element heap[max_element];
	int heap_size;
}heapType;
heapType *create() {
	return (heapType *)malloc(sizeof(heapType));
}
void init(heapType *h) {
	h->heap_size = 0;
}
//현재 요소의 개수가 heap_size 인 히프 h에 item 삽입
//삽입함수
void insert_max_heap(heapType *h, element item) {
	int i;
	i = ++(h->heap_size);
	//트리를 거슬러 올라가면서 부모 노드와 비교
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;//새로운 노드 삽입
}
//삭제함수
element delete_max_heap(heapType *h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		//현재 자식노드중 더 작은 자식노드 찾기
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key) {
			child++;
		}
		if (temp.key >= h->heap[child].key) {
			break;
		}
		//한단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child = child * 2;
	}
	h->heap[parent] = temp;
	return item;
}
int main() {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	heapType *heap;
	heap = create();
	init(heap);
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
	e4 = delete_max_heap(heap);
	printf("%d\n", e4.key);
	e5 = delete_max_heap(heap);
	printf("%d\n", e5.key);
	e6 = delete_max_heap(heap);
	printf("%d\n", e6.key);
	free(heap);
	return 0;
}

//힙 오름차순 정렬
#define _CRT_SECURE_NO_WARNINGS
#define max_element 200
#include <stdio.h>
#include<stdlib.h>
typedef struct {
	int key;
}element;
typedef struct {
	element heap[max_element];
	int heap_size;
}heapType;
heapType *create() {
	return (heapType *)malloc(sizeof(heapType));
}
void init(heapType *h) {
	h->heap_size = 0;
}
//현재 요소의 개수가 heap_size 인 히프 h에 item 삽입
//삽입함수
void insert_max_heap(heapType *h, element item) {
	int i;
	i = ++(h->heap_size);
	//트리를 거슬러 올라가면서 부모 노드와 비교
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;//새로운 노드 삽입
}
//삭제함수
element delete_max_heap(heapType *h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		//현재 자식노드중 더 작은 자식노드 찾기
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key) {
			child++;
		}
		if (temp.key >= h->heap[child].key) {
			break;
		}
		//한단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child = child * 2;
	}
	h->heap[parent] = temp;
	return item;
}
void heap_sort(element a[], int n) {
	int i;
	heapType *h;
	h = create();
	init(h);
	for (int i = 0; i < n; i++) {
		insert_max_heap(h, a[i]);
	}
	for (int i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}
	free(h);
}
#define size 8
int main() {
	element list[size] = { 23,56,11,9,56,99,27,34 };
	heap_sort(list, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i].key);
	}
	return 0;
}

//정리
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
