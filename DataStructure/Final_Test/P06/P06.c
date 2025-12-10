#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode
{
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;	// 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

//--- begin of 스택 정의
typedef int element;
typedef struct StackNode {
    element item;
    struct StackNode* link;
} StackNode;

typedef struct {
    StackNode* top;
} LinkedStackType;
// 초기화 함수
void init(LinkedStackType* s)
{
    s->top = NULL;
}
int is_empty(LinkedStackType* s)
{
    return (s->top == NULL);
}
// 삽입 함수
void push(LinkedStackType* s, element item)
{
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    if (temp == NULL) {
        fprintf(stderr, "메모리 할당에러\n");
        return;
    }
    else {
        temp->item = item;
        temp->link = s->top;
        s->top = temp;
    }
}
// 삭제 함수
element pop(LinkedStackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        StackNode* temp = s->top;
        element item = temp->item;
        s->top = s->top->link;
        free(temp);
        return item;
    }
}
//---- end of 스택 정의

//--- begin of 그래프 정의
// 그래프 초기화
void graph_init(GraphType* g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

// 방향 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType* g, int u, int v)
{
    GraphNode* node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}
//--- end of 그래프 정의
int visited[MAX_VERTICES]; // 0으로 자동 초기화

void dfs_list_iterative(GraphType* g, int v) // 이 함수를 작성
{
    LinkedStackType s;
    s.top = NULL;

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

int main(void) // 변경하지 말라
{
    GraphType g;
    int u, v;

    graph_init(&g);
    scanf("%d", &g.n);
    scanf("%d %d", &u, &v);
    while (u != -1) {
        insert_edge(&g, u, v);
        insert_edge(&g, v, u);
        scanf("%d %d", &u, &v);
    }

    //printf("Enter 정점:");
    scanf("%d", &v);

    dfs_list_iterative(&g, v);
}

/*예제
5
0 1
0 2
1 2
1 3
1 4
3 4
-1 -1
0
*/

/*뼈대코드

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode
{
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;	// 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

//--- begin of 스택 정의
typedef int element;
typedef struct StackNode {
    element item;
    struct StackNode* link;
} StackNode;

typedef struct {
    StackNode* top;
} LinkedStackType;
// 초기화 함수
void init(LinkedStackType* s)
{
    s->top = NULL;
}
int is_empty(LinkedStackType* s)
{
    return (s->top == NULL);
}
// 삽입 함수
void push(LinkedStackType* s, element item)
{
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    if (temp == NULL) {
        fprintf(stderr, "메모리 할당에러\n");
        return;
    }
    else {
        temp->item = item;
        temp->link = s->top;
        s->top = temp;
    }
}
// 삭제 함수
element pop(LinkedStackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        StackNode* temp = s->top;
        element item = temp->item;
        s->top = s->top->link;
        free(temp);
        return item;
    }
}
//---- end of 스택 정의

//--- begin of 그래프 정의
// 그래프 초기화
void graph_init(GraphType* g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

// 방향 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType* g, int u, int v)
{
    GraphNode* node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}
//--- end of 그래프 정의
int visited[MAX_VERTICES]; // 0으로 자동 초기화

void dfs_list_iterative(GraphType* g, int v) // 이 함수를 작성
{

}

int main(void) // 변경하지 말라
{
    GraphType g;
    int u, v;

    graph_init(&g);
    scanf("%d", &g.n);
    scanf("%d %d", &u, &v);
    while (u != -1) {
        insert_edge(&g, u, v);
        insert_edge(&g, v, u);
        scanf("%d %d", &u, &v);
    }

    //printf("Enter 정점:");
    scanf("%d", &v);

    dfs_list_iterative(&g, v);
}
*/