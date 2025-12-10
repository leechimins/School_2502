#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

int visited[MAX_VERTICES];

typedef int element;
typedef struct StackNode {
    element data;
    struct StackNode* link;
} StackNode;

typedef struct {
    StackNode* top;
} LinkedStackType;

void init_stack(LinkedStackType* s) {
    s->top = NULL;
}

int is_empty(LinkedStackType* s) {
    return (s->top == NULL);
}

void push(LinkedStackType* s, element item) {
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    temp->data = item;
    temp->link = s->top;
    s->top = temp;
}

element pop(LinkedStackType* s) {
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

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void graph_init(GraphType* g) {
    g->n = 0;
    for (int v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) return;
    g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
    if (u >= g->n || v >= g->n) return;
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void dfs_iterative(GraphType* g, int v) {
    LinkedStackType s;
    init_stack(&s);

    push(&s, v);

    while (!is_empty(&s)) {
        int current = pop(&s);
        if (visited[current] == FALSE) {
            visited[current] = TRUE;
            printf("%d ", current);
            for (GraphNode* w = g->adj_list[current]; w != NULL; w = w->link)
                if (visited[w->vertex] == FALSE)
                    push(&s, w->vertex);
        }
    }
}

int main(void) {
    GraphType g;
    graph_init(&g);

    for (int i = 0; i < 5; i++)
        insert_vertex(&g, i);

    insert_edge(&g, 0, 4);
    insert_edge(&g, 0, 2);
    insert_edge(&g, 0, 1);

    insert_edge(&g, 1, 2);
    insert_edge(&g, 1, 0);

    insert_edge(&g, 2, 4);
    insert_edge(&g, 2, 3);
    insert_edge(&g, 2, 0);
    insert_edge(&g, 2, 1);

    printf("스택 사용 DFS\n");
    dfs_iterative(&g, 0);
    printf("\n");

    return 0;
}