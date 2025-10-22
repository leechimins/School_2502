// 컴퓨터학과 3학년 20221590 이지민

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

// 리스트의 항목 출력
void print_list(ListNode* head) // 변경하지 말라
{
	ListNode* p;

	if (head != NULL)
	{
		p = head;
		do {
			p = p->link;
			printf("%d->", p->data);
		} while (p != head);
	}
	printf("NULL\n");
}

ListNode* insert_last(ListNode* head, element data) // 변경하지 말라
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
		head = node;		// (3)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

ListNode* delete_key(ListNode* head, element key) // 이 함수를 작성
{
	ListNode* removed = head->link;
	ListNode* prev = head;
	int is_in = 0;
	do {
		if (removed->data == key) {
			is_in = 1;
			break;
		}
		prev = removed;
		removed = removed->link;
	} while (removed != head->link);

	// 지울 요소가 없는 경우
	if (is_in == 0)
		return head;

	// 요소가 1개인 경우
	if (removed == prev) {
		free(removed);
		return NULL;
	}

	prev->link = removed->link;
	free(removed);

	if (removed == head)
		return prev;

	return head;
}

int main(void) // 변경하지 말라
{
	ListNode* list = NULL;

	int data, key;

	scanf("%d", &data);
	while (data != -1) {
		list = insert_last(list, data);
		scanf("%d", &data);
	}

	scanf("%d", &key);
	list = delete_key(list, key);
	print_list(list);

	return 0;
}