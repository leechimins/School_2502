#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX 50

int visited[MAX];

typedef int element;
typedef struct QueueNode {
    element data;
    struct QueueNode* link;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} LinkedQueueType;

void queue_init(LinkedQueueType* q) {
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(LinkedQueueType* q) {
    return (q->front == NULL);
}

void enqueue(LinkedQueueType* q, element data) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = data;
    node->link = NULL;

    if (is_empty(q)) {
        q->front = node;
        q->rear = node;
    }
    else {
        q->rear->link = node;
        q->rear = node;
    }
}

element dequeue(LinkedQueueType* q) {
    if (is_empty(q)) {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }

    QueueNode* temp = q->front;
    element data = temp->data;

    q->front = q->front->link;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

typedef struct {
    int n;
    int adj_mat[MAX][MAX];
} GraphType;

GraphType* create() {
    return (GraphType*)malloc(sizeof(GraphType));
}

void init(GraphType* g) {
    g->n = 0;
    for (int r = 0; r < MAX; r++) {
        for (int c = 0; c < MAX; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}

void insert_vertex(GraphType* g, int v) {
    if ((g->n + 1) > MAX) {
        fprintf(stderr, "Graph: Vertex count exceeded\n");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "Graph: Vertex index error\n");
        return;
    }
    g->adj_mat[u][v] = 1;
    g->adj_mat[v][u] = 1;
}

void read_graph(GraphType* g, char* filename) {
    int n, u, v;
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) return;

    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++) {
        insert_vertex(g, i);
    }

    while (fscanf(fp, "%d %d", &u, &v) != EOF) {
        insert_edge(g, u, v);
    }

    fclose(fp);
}

void write_graph(GraphType* g, char* filename) {
    FILE* fp;

    if (filename == NULL) {
        fp = stdout;
    }
    else {
        fp = fopen(filename, "w");
        if (fp == NULL) return;
    }

    fprintf(fp, "%d\n", g->n);
    for (int i = 0; i < g->n; i++) {
        for (int j = i; j < g->n; j++) {
            if (g->adj_mat[i][j]) {
                fprintf(fp, "%d %d\n", i, j);
            }
        }
    }

    if (filename != NULL) {
        fclose(fp);
    }
}

void bfs_mat(GraphType* g, int v) {
    LinkedQueueType q;
    queue_init(&q);

    visited[v] = TRUE;
    printf("%d ", v);
    enqueue(&q, v);

    while (!is_empty(&q)) {
        v = dequeue(&q);
        for (int w = 0; w < g->n; w++) {
            if (g->adj_mat[v][w] && !visited[w]) {
                visited[w] = TRUE;
                printf("%d ", w);
                enqueue(&q, w);
            }
        }
    }
}

int main(void) {
	GraphType* g = create();
	init(g);

	read_graph(g, "input.txt");
	write_graph(g, NULL);

	printf("\n너비 우선 탐색(BFS)\n");
	bfs_mat(g, 0);
	printf("\n");

	free(g);
	return 0;
}