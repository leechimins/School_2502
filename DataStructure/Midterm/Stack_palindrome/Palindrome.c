#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef char element;
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
	int result = 1, len = 0, i = 0;
	char word[MAX + 1];

	scanf("%s", &word);
	len = strlen(&word);

	StackType stack;
	init(&stack);

	while (i < len / 2)
		push(&stack, word[i++]);

	if (len % 2)
		i++;

	while (i < len) {
		if (pop(&stack) != word[i++])
			result = 0;
	}

	if (result)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}