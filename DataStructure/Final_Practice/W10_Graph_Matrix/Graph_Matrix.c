#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
	int n;
	int adj_mat[MAX][MAX];
} GraphType;

GraphType* create() {
	return (GraphType*)malloc(sizeof(GraphType));
}

void init(GraphType* g) {
	g->n = 0;
	for (int r = 0; r < MAX; r++)
		for (int c = 0; c < MAX; c++)
			g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType* g, int v) {
	if ((g->n + 1) > MAX) {
		fprintf(stderr, "그래프 정점 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프 정점 번호 오류");
		return;
	}
	g->adj_mat[u][v] = 1;
	g->adj_mat[v][u] = 1;
}

void delete_edge(GraphType* g, int u, int v) {
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프 정점 번호 오류");
		return;
	}
	g->adj_mat[u][v] = 0;
	g->adj_mat[v][u] = 0;
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
	for (int i = 0; i < g->n; i++)
		for (int j = i; j < g->n; j++)
			if (g->adj_mat[i][j])
				fprintf(fp, "%d %d\n", i, j);

	if (filename != NULL)
		fclose(fp);
}

void print_adj_mat(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++)
			printf("%d ", g->adj_mat[i][j]);
		printf("\n");
	}
}

int main(void) {
	GraphType* g = create();
	init(g);

	read_graph(g, "input.txt");

	print_adj_mat(g);
	write_graph(g, NULL);

	free(g);
	return 0;
}