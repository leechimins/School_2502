// 컴퓨터학과 3학년 20221590 이지민

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType {
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];
int previous[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for (i = 0; i < n; i++)
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    return minpos;
}

void graph_init(GraphType* g) {
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++)
        for (c = 0; c < MAX_VERTICES; c++)
            g->weight[r][c] = INF;
}

void read_graph(GraphType* g, char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다.\n");
        return;
    }

    int n;
    fscanf(fp, "%d", &n);
    g->n = n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) g->weight[i][j] = 0;
            else g->weight[i][j] = INF;
        }
    }

    int u, v, w;
    while (fscanf(fp, "%d %d %d", &u, &v, &w) != EOF) {
        g->weight[u][v] = w;
        g->weight[v][u] = w;
    }
    fclose(fp);
}

void print_path(int start, int end) {
    if (start == end) {
        printf("%d", start);
        return;
    }
    print_path(start, previous[end]);
    printf("->%d", end);
}

void shortest_path(GraphType* g, int start)
{
    int i, u, w;
    for (i = 0; i < g->n; i++)
    {
        distance[i] = g->weight[start][i];
        found[i] = FALSE;
        previous[i] = start;
    }
    found[start] = TRUE;
    distance[start] = 0;
    previous[start] = -1;

    for (i = 0; i < g->n - 1; i++) {
        u = choose(distance, g->n, found);

        if (u == -1) break;

        found[u] = TRUE;
        for (w = 0; w < g->n; w++)
            if (!found[w])
                if (distance[u] + g->weight[u][w] < distance[w]) {
                    distance[w] = distance[u] + g->weight[u][w];
                    previous[w] = u;
                }
    }
}

int main(void)
{
    GraphType g;
    int start_node = 0;

    graph_init(&g);
    read_graph(&g, "input.txt");

    shortest_path(&g, start_node);

    printf("\n-------- 실행 결과 --------\n");
    for (int i = 0; i < g.n; i++) {
        if (i != start_node && distance[i] != INF) {
            print_path(start_node, i);
            printf(" (%d)\n", distance[i]);
        }
    }

    return 0;
}