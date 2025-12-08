#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define TRUE 1
#define FALSE 0
int visited[MAX];

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
}

void delete_edge(GraphType* g, int u, int v) {
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프 정점 번호 오류");
		return;
	}

	GraphNode* node = g->adj_list[u];
	while (node->link != NULL) {
		if (node->link->vertex == v) {
			GraphNode* temp = node->link;
			node->link = temp->link;
			free(temp);
			break;
		}
		node = node->link;
	}
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

void dfs_list(GraphType* g, int v) {
	GraphNode* w;
	visited[v] = TRUE;
	printf("정점 %d -> ", v);
	for (w = g->adj_list[v]; w; w = w->link)
		if (!visited[w->vertex])
			dfs_list(g, w->vertex);
}

int main(void) {
	GraphType* g = create();
	init(g);

	read_graph(g, "input.txt");

	print_adj_mat(g);
	write_graph(g, NULL);

	printf("\n깊이 우선 탐색(DFS)\n");
	dfs_list(g, 0);
	printf("\n");

	free(g);
	return 0;
}