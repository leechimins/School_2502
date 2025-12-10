#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX 50

int visited[MAX];

typedef int element;	// 요소의 타입
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

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct {
	int n;
	GraphNode* adj_list[MAX];
} GraphType;

GraphType* create() {
	return (GraphType*)malloc(sizeof(GraphType));
}

void init(GraphType* g) {
	g->n = 0;
	for (int v = 0; v < MAX; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v) {
	if ((g->n + 1) > MAX) {
		fprintf(stderr, "그래프 정점 개수 초과");
		return;
	}
	(g->n)++;
}

void insert_edge(GraphType* g, int u, int v) {
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프 정점 번호 오류");
		return;
	}
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;

	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = u;
	node->link = g->adj_list[v];
	g->adj_list[v] = node;
}

void delete_one_edge(GraphType* g, int s, int e) {
	GraphNode* node = g->adj_list[s];
	GraphNode* pre = NULL;

	while (node != NULL) {
		if (node->vertex == e) {
			if (pre == NULL)
				g->adj_list[s] = node->link;
			else
				pre->link = node->link;
			free(node);
			return;
		}
		pre = node;
		node = node->link;
	}
}

void delete_edge(GraphType* g, int u, int v) {
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프 정점 번호 오류");
		return;
	}

	delete_one_edge(g, u, v);
	delete_one_edge(g, v, u);
}

void read_graph(GraphType* g, char* filename) {
	int n, u, v;

	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
		return;

	fscanf(fp, "%d\n", &n);
	for (int i = 0; i < n; i++)
		insert_vertex(g, i);

	while (fscanf(fp, "%d %d\n", &u, &v) != EOF)
		insert_edge(g, u, v);

	fclose(fp);
}

void write_graph(GraphType* g, char* filename) {
	FILE* fp;

	if (filename == NULL)
		fp = stdout;
	else {
		fp = fopen(filename, "w");
		if (fp == NULL)
			return;
	}

	fprintf(fp, "%d\n", g->n);
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트 ", i);
		while (p != NULL) {
			printf("-> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}

	if (filename != NULL)
		fclose(fp);
}

void print_adj_mat(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트 ", i);
		while (p != NULL) {
			printf("-> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

void bfs_list(GraphType* g, int v) {
    LinkedQueueType q;
    queue_init(&q);

    visited[v] = TRUE;
    printf("%d ", v);
    enqueue(&q, v);

    while (!is_empty(&q)) {
        v = dequeue(&q);
		for (GraphNode* w = g->adj_list[v]; w; w = w->link) {
            if (!visited[w->vertex]) {
                visited[w->vertex] = TRUE;
                printf("%d ", w->vertex);
                enqueue(&q, w->vertex);
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
    bfs_list(g, 0);
    printf("\n");

    free(g);
    return 0;
}