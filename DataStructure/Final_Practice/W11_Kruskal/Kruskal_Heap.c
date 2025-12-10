#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TURE 1
#define FALSE 0

#define MAX_V 100
#define MAX_E 50

#define INF 9999
#define NONE -1

int parent[MAX_V];
int num[MAX_V];	// 집합의 크기

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
	int key, u, v;
} element;

typedef struct {
	element heap[MAX_E];
	int heap_size;
} HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_min_heap(HeapType* h, element item)
{
	int i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void insert_heap_edge(HeapType* h, int u, int v, int w) {
	element e = { w, u, v };
	insert_min_heap(h, e);
}

void read_graph(HeapType* h, char* filename) {
	int w, u, v;

	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
		return;

	while (fscanf(fp, "%d %d %d\n", &u, &v, &w) != EOF)
		insert_heap_edge(h, u, v, w);

	fclose(fp);
}

void kruskal(int n) {
	int edge_accepted = 0;
	int uset, vset;
	element e;

	HeapType h;
	init(&h);
	read_graph(&h, "input.txt");
	
	set_init(n);

	while (edge_accepted < n - 1) {
		e = delete_min_heap(&h);
		uset = set_find(e.u);
		vset = set_find(e.v);
		if (uset != vset) {
			printf("%d, %d [%d]\n", e.u, e.v, e.key);
			edge_accepted++;
			set_union(uset, vset);
		}

	}
}

int main(void) {
	kruskal(7);

	return 0;
}