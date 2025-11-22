// 컴퓨터학과 3학년 20221590 이지민

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "minheap.h"
#include "unionfind.h"

#define MAX_VERTICES 100
#define INF 9999

typedef struct GraphType {
	int n;					// 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void graph_init(GraphType* g)
{
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++)
		for (int j = 0; j < MAX_VERTICES; j++)
			g->adj_mat[i][j] = INF;
}

void read_graph(GraphType* g, char* filename)
{
	int number, u, v, w;
	FILE* fp = fopen(filename, "rt");
	if (fp == NULL) {
		printf("file open error!\n");
		return;
	}

	fscanf(fp, "%d", &number);
	g->n = number;
	while (fscanf(fp, "%d %d %d\n", &u, &v, &w) != EOF) {
		g->adj_mat[u][v] = w;
		g->adj_mat[v][u] = w;
	}

	fclose(fp);
}

/*  */
void write_graph(GraphType* g, char* filename)
{
	FILE* fp;

	if (filename == NULL) fp = stdout;
	else {
		fp = fopen(filename, "w");
		if (fp == NULL) {
			printf("file %s open error!\n", filename);
			return;
		}
	}

	fprintf(fp, "%d\n", g->n);
	for (int i = 0; i < g->n; i++)
		for (int j = i + 1; j < g->n; j++)
			if (g->adj_mat[i][j] != INF)
				fprintf(fp, "%d %d %d\n", i, j, g->adj_mat[i][j]);

	if (filename != NULL) fclose(fp);
}

// 인접 행렬이나 인접 리스트에서 간선들을 읽어서 최소 히프에 삽입 
// 현재는 예제 그래프의 간선들을 삽입한다.
void insert_all_edges(HeapType* h, GraphType* g)
{
	init(h);
	for (int i = 0; i < g->n; i++) {
		for (int j = i + 1; j < g->n; j++) {
			if (g->adj_mat[i][j] != INF) {
				element e;
				e.key = g->adj_mat[i][j];
				e.u = i;
				e.v = j;
				insert_min_heap(h, e);
			}
		}
	}
}

// kruskal의 최소 비용 신장 트리 프로그램
void kruskal(GraphType* g, GraphType* t)
{
	HeapType h;
	insert_all_edges(&h, g);
	set_init(g->n);

	int selected = 0;
	while (selected < g->n - 1 && is_empty(&h)) {
		element e = delete_min_heap(&h);
		int s1 = set_find(e.u);
		int s2 = set_find(e.v);
		if (s1 != s2) {
			set_union(s1, s2);
			t->adj_mat[e.u][e.v] = e.key;
			t->adj_mat[e.v][e.u] = e.key;
			selected++;
		}
	}
}

int main(void)
{
	GraphType g, t;		// 입력 그래프, 결과 트리

	graph_init(&g);
	//read_graph(&g, "input1.txt");
	read_graph(&g, "input2.txt");

	graph_init(&t);
	t.n = g.n;

	kruskal(&g, &t);

	printf("파일로 출력:\n");
	write_graph(&t, "output.txt");
	write_graph(&t, NULL);	// to stdout

	return 0;
}