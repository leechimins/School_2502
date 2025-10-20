#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 100

typedef int element;
typedef struct {
	element data[MAX];
	int top;
} StackType;

void init(StackType* s) { s->top = -1; }

int is_empty(StackType* s) { return s->top == -1; }

int is_full(StackType* s) { return s->top == MAX - 1; }

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "Stack is full\n");
		return;
	}
	s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	return s->data[s->top];
}

void display(StackType* s) {
	for (int i = 0; i <= s->top; i++)
		printf("%d | ", s->data[i]);
	printf("\n");
}

int main(void) {
	StackType stack;
	init(&stack);
	
	push(&stack, 10);
	display(&stack);
	push(&stack, 20);
	display(&stack);
	push(&stack, 30);
	push(&stack, 40);
	display(&stack);

	printf("pop: %d\n", pop(&stack));
	display(&stack);

	printf("peek: %d\n", peek(&stack));
	display(&stack);

	return 0;
}