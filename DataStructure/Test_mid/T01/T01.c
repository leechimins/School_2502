// 컴퓨터학과 3학년 20221590 이지민

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;
// 초기화 함수
void init(LinkedStackType* s) // 변경하지 말라
{
	s->top = NULL;
}
// 공백 상태 검출 함수
int is_empty(LinkedStackType* s) // 변경하지 말라
{
	return (s->top == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedStackType* s) // 변경하지 말라
{
	return 0;
}
// 삽입 함수
void push(LinkedStackType* s, element item) // 변경하지 말라
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}
void print_stack(LinkedStackType* s) // 변경하지 말라
{
	for (StackNode* p = s->top; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
// 삭제 함수
element pop(LinkedStackType* s) // 변경하지 말라
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}
// 피크 함수
element peek(LinkedStackType* s) // 변경하지 말라
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		return s->top->data;
	}
}

int main(void)
{
	LinkedStackType stack;
	init(&stack);
	element input;
	int result = 0;

	scanf("%d", &input);
	while (input != -1) {
		if (input == 0)
			pop(&stack);
		else
			push(&stack, input);
		scanf("%d", &input);
	}

	while (is_empty(&stack) == 0)
		result += pop(&stack);

	printf("%d", result);

	return 0;
}