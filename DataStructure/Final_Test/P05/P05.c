#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType {
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES]; /* 시작정점으로부터의 최단경로 거리 */
int found[MAX_VERTICES];    /* 방문한 정점 표시 */
int previous[MAX_VERTICES]; /* [응용] 경로 역추적을 위한 이전 정점 저장 배열 */

int choose(int distance[], int n, int found[]) {
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

void print_status(GraphType* g)
{
    printf("distance: ");
    for (int i = 0; i < g->n; i++) {
        if (distance[i] == INF)
            printf(" * ");
        else
            printf("%2d ", distance[i]);
    }
    printf("\n");
    printf("        found:    ");
    for (int i = 0; i < g->n; i++)
        printf("%2d ", found[i]);
    printf("\n\n");
}

// [응용] 최단 경로 출력을 위한 재귀 함수
void print_path(int start, int end) {
    if (start == end) {
        printf("%d-[%d]", start, distance[start]);
        return;
    }
    print_path(start, previous[end]);
    printf("->%d", end);
}

void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	for (i = 0; i<g->n; i++) /* 초기화 */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;    /* 시작 정점 방문 표시 */
	distance[start] = 0;
	for (i = 0; i<g->n-1; i++) {
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w<g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w]<distance[w])
					distance[w] = distance[u] + g->weight[u][w];
	}
}

int main(void) {
    int n, u, v, w;
    scanf("%d", &n);
    GraphType g = { n };

    for (int i = 0; i < g.n; i++) {
        g.weight[i][i] = 0;
        for (int j = i + 1; j < g.n; j++) {
            g.weight[i][j] = INF;
            g.weight[j][i] = INF;
        }
    }

    scanf("%d %d", &u, &v);
    while (u != -1) {
        scanf("%d", &w);
        g.weight[u][v] = w;
        g.weight[v][u] = w;
        scanf("%d %d", &u, &v);
    }

    int start_node;
    scanf("%d", &start_node);
    shortest_path(&g, start_node);

    for (int i = 0; i < g.n; i++) {
        if (i != start_node) {
            print_path(start_node, i);
            printf("(%d)\n", distance[i]);
        }
    }

    return 0;
}

/*예제
5
0 1 10
0 3 60
1 3 30
1 2 45
1 4 50
2 3 5
2 4 20
-1 -1
4
*/

/*뼈대코드 없음*/