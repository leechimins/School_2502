#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef int element;

// ====== 스택 구조 정의 ======
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// ====== 스택 연산 함수 ======
void init(StackType* s) { s->top = -1; }
int is_empty(StackType* s) { return (s->top == -1); }
int is_full(StackType* s) { return (s->top == MAX_STACK_SIZE - 1); }

void push(StackType* s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "Stack Overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = item;
}

element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack Underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(StackType* s) {
    if (is_empty(s)) return -1;
    return s->data[s->top];
}

// ====== 연산자 우선순위 ======
int precedence(char op) {
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

// ====== 1. 중위 → 후위 변환 ======
void infix_to_postfix(char* infix, char* postfix) {
    StackType s;
    init(&s);
    int j = 0;
    char ch, top_op;

    for (int i = 0; i < strlen(infix); i++) {
        ch = infix[i];

        if (isspace(ch)) continue;              // 공백 무시
        else if (isdigit(ch))                   // 피연산자 (숫자)
            postfix[j++] = ch;
        else if (ch == '(')
            push(&s, ch);
        else if (ch == ')') {
            while (!is_empty(&s) && (top_op = pop(&s)) != '(')
                postfix[j++] = top_op;
        }
        else { // 연산자일 때
            while (!is_empty(&s) && precedence(ch) <= precedence(peek(&s)))
                postfix[j++] = pop(&s);
            push(&s, ch);
        }
    }

    // 남은 연산자 스택에서 꺼내기
    while (!is_empty(&s))
        postfix[j++] = pop(&s);

    postfix[j] = '\0';
}

// ====== 2. 후위표기식 계산 ======
int eval_postfix(char* exp) {
    StackType s;
    init(&s);
    char ch;
    int op1, op2, value;

    for (int i = 0; i < strlen(exp); i++) {
        ch = exp[i];

        if (isdigit(ch)) {          // 피연산자라면
            value = ch - '0';
            push(&s, value);
        }
        else {                      // 연산자라면
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) {
            case '+': push(&s, op1 + op2); break;
            case '-': push(&s, op1 - op2); break;
            case '*': push(&s, op1 * op2); break;
            case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

// ====== main 함수 ======
int main(void) {
    char infix[MAX_EXPR_SIZE];
    char postfix[MAX_EXPR_SIZE];

    printf("중위식 입력: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);
    printf("후위식 변환 결과: %s\n", postfix);

    int result = eval_postfix(postfix);
    printf("계산 결과: %d\n", result);

    return 0;
}