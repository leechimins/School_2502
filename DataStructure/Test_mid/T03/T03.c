// 컴퓨터학과 3학년 20221590 이지민

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void display(ListNode* head) //변경하지 말라
{
	if (head != NULL) {
		printf("%d->", head->data);
		display(head->link);
	}
}

ListNode* insert_last(ListNode* head, int value) //변경하지 말라
{

	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;
	p->link = NULL;

	// (2)
	if (head == NULL) // 공백 리스트이면
		head = p;
	else {
		while (temp->link != 0)
			temp = temp->link;

		temp->link = p;
	}
	return head;	// 변경된 헤드 포인터 반환
}

void increase(ListNode* head)  //변경하지 말라
{
	ListNode* temp;
	for (temp = head; temp != NULL; temp = temp->link) {
		temp->data++;
	}
}

ListNode* listInTurn(ListNode* head1, ListNode* head2) // 이 함수만 작성한다
{
	ListNode* result = NULL;
	while (head1 != NULL && head2 != NULL) {
		result = insert_last(result, head1->data);
		result = insert_last(result, head2->data);
		head1 = head1->link;
		head2 = head2->link;
	}
	while (head1 != NULL) {
		result = insert_last(result, head1->data);
		head1 = head1->link;
	}
	while (head2 != NULL) {
		result = insert_last(result, head2->data);
		head2 = head2->link;
	}
	return result;
}

int main(void) // 변경하지 말라
{
	ListNode* list1 = NULL;
	ListNode* list2 = NULL;
	ListNode* list3 = NULL;
	int n;

	scanf("%d", &n);
	while (n != -1) {
		list1 = insert_last(list1, n);
		scanf("%d", &n);
	}

	scanf("%d", &n);
	while (n != -1) {
		list2 = insert_last(list2, n);
		scanf("%d", &n);
	}

	list3 = listInTurn(list1, list2);

	// list1, list2의 각 노드를 1씩 증가시킨후 list1, list2를 출력한다
	increase(list1); increase(list2);
	display(list1); printf("\n");
	display(list2); printf("\n");

	// list3를 출력한다. 독자적으로 만들어졌는지 확인
	display(list3);
}