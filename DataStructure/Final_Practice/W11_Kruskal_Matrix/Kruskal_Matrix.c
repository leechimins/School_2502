#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TURE 1
#define FALSE 0

#define MAX 100
#define INF 9999
#define NONE -1

int parent[MAX];

void set_init(int n) {
	for (int i = 0; i < n; i++)
		parent[i] = NONE;
}

int set_find(int curr) {
	while (parent[curr] != NONE)
		curr = parent[curr];
	return curr;
}

void set_union(int a, int b) {
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2)
		parent[root1] = root2;
}

typedef struct {
	int start, end, weight;
} Edge;

typedef struct {
	int n;	// °£¼± °¹¼ö
	Edge edges[MAX * 2];
} GraphType;

void init(GraphType* g) {
	g->n = 0;
	for (int i = 0; i < MAX * 2; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}

void insert_edge(GraphType* g, int s, int e, int w) {
	g->edges[g->n].start = s;
	g->edges[g->n].end = e;
	g->edges[g->n].weight = w;
	g->n++;
}

int compare(const void* a, const void* b) {
	Edge* x = (Edge*)a;
	Edge* y = (Edge*)b;
	return (x->weight - y->weight);
}

void kruskal(GraphType* g) {
	int edge_accepted = 0;
	int uset, vset;
	Edge e;

	set_init(g->n);
	qsort(g->edges, g->n, sizeof(Edge), compare);

	for (int i = 0; i < g->n && edge_accepted < (g->n - 1); i++) {
		e = g->edges[i];
		uset = set_find(e.start);
		vset = set_find(e.end);
		if (uset != vset) {
			printf("%d, %d [%d]\n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(uset, vset);
		}
	}
}

void read_graph(GraphType* g, char* filename) {
	int s, e, w;

	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
		return;

	while (fscanf(fp, "%d %d %d\n", &s, &e, &w) != EOF)
		insert_edge(g, s, e, w);

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
		if (g->edges[i].weight != INF)
			fprintf(fp, "%d %d %d\n", g->edges[i].start, g->edges[i].end, g->edges[i].weight);

	if (filename != NULL)
		fclose(fp);
}

int main(void) {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	read_graph(g, "input.txt");
	write_graph(g, NULL);

	kruskal(g);

	free(g);
	return 0;
}