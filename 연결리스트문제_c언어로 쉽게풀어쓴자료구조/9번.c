//단순연결리스트 입력값->출력값
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode {
	int data;
	struct ListNode *link;
}ListNode;
ListNode* insert(ListNode* head, ListNode* pre, int value) { //practice
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
void insert_last(ListNode **head, int value) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	ListNode *pre = *head;
	p->data = value;
	p->link = NULL;
	if (*head == NULL) {
		*head = p;
		return;
	}
	while (pre->link != NULL) {
		pre = pre->link;
	}
	pre->link = p;
	return;
}
ListNode* delete_first(ListNode *head) { //practice
	ListNode* removed;
	if (head == NULL) {
		return NULL;
	}
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}
ListNode* delete(ListNode *head, ListNode* pre) { //pratice
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
void answer(ListNode* head) {
	for (ListNode *p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("\n");
}
int main(void) {
	ListNode* list = NULL;
	int n, t;
	printf("노드의 개수 : ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("노드 %d 데이터 : ", i + 1);
		scanf_s("%d", &t);
		insert_last(&list, t);
	}
	answer(list);
	return 0;
}