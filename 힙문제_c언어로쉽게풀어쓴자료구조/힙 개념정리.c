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
//���� ����� ������ heap_size �� ���� h�� item ����
//�����Լ�
void insert_max_heap(heapType *h, element item) {
	int i;
	i = ++(h->heap_size);
	//Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ��
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;//���ο� ��� ����
}
//�����Լ�
element delete_max_heap(heapType *h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		//���� �ڽĳ���� �� ���� �ڽĳ�� ã��
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key) {
			child++;
		}
		if (temp.key >= h->heap[child].key) {
			break;
		}
		//�Ѵܰ� �Ʒ��� �̵�
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