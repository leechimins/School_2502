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

// 그래프 초기화 
void graph_init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
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

void print_degree(int degree[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", degree[i]);

	printf("\n");
}

// 위상정렬을 수행한다.
void topo_sort0(GraphType* g) // 위상정렬 구하는 부분은 일시적으로 생략함
{
	int i;
	GraphNode* node;

	// 모든 정점의 진입 차수를 계산
	int* in_degree = (int*)malloc(g->n * sizeof(int));
	int* out_degree = (int*)malloc(g->n * sizeof(int));
	for (i = 0; i < g->n; i++)			// 초기화
		in_degree[i] = 0;
	for (i = 0; i < g->n; i++)			// 초기화
		out_degree[i] = 0;
	for (i = 0; i < g->n; i++) {
		node = g->adj_list[i];//정점 i에서 나오는 간선들
		while (node != NULL) {
			in_degree[node->vertex]++;
			node = node->link;
		}
	}

	// 이하 코드 작성: out_degree 배열의 값을 구한다
	for (i = 0; i < g->n; i++) {
		node = g->adj_list[i];//정점 i에서 나오는 간선들
		while (node != NULL) {
			out_degree[i]++;
			node = node->link;
		}
	}

	//print_degree(in_degree, g->n); 
	print_degree(out_degree, g->n);
	// 이하는 생략
}

int main(void) // 변경하지 말라
{
	GraphType g;
	int u, v;
	int n;

	graph_init(&g);
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		insert_vertex(&g, i);

	scanf("%d %d", &u, &v);
	while (u != -1) {
		insert_edge(&g, u, v);
		scanf("%d %d", &u, &v);
	}

	topo_sort0(&g);
	// 동적 메모리 반환 코드 생략
	return 0;
}

/*예제
4
0 1
0 2
2 3
-1 -1
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

// 그래프 초기화
void graph_init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
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

void print_degree(int degree[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", degree[i]);

	printf("\n");
}

// 위상정렬을 수행한다.
void topo_sort0(GraphType* g) // 위상정렬 구하는 부분은 일시적으로 생략함
{
	int i;
	GraphNode* node;

	// 모든 정점의 진입 차수를 계산
	int* in_degree = (int*)malloc(g->n * sizeof(int));
	int* out_degree = (int*)malloc(g->n * sizeof(int));
	for (i = 0; i < g->n; i++)			// 초기화
		in_degree[i] = 0;
	for (i = 0; i < g->n; i++)			// 초기화
		out_degree[i] = 0;
	for (i = 0; i < g->n; i++) {
		GraphNode* node = g->adj_list[i];//정점 i에서 나오는 간선들
		while (node != NULL) {
			in_degree[node->vertex]++;
			node = node->link;
		}
	}

	// 이하 코드 작성: out_degree 배열의 값을 구한다



	//print_degree(in_degree, g->n);
	print_degree(out_degree, g->n);
	// 이하는 생략
}

int main(void) // 변경하지 말라
{
	GraphType g;
	int u, v;
	int n;

	graph_init(&g);
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		insert_vertex(&g, i);

	scanf("%d %d", &u, &v);
	while (u != -1) {
		insert_edge(&g, u, v);
		scanf("%d %d", &u, &v);
	}

	topo_sort0(&g);
	// 동적 메모리 반환 코드 생략
	return 0;
}
*/