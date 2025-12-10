#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define TRUE 1
#define FALSE 0

typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}

// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_min_heap(HeapType* h, element item) // 이전 문제1)에서 작성한 함수 사용
{
	int i = ++(h->heap_size);

	while ((i > 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
int maxIndex(int a, int b) // 필요하면 사용
{
	if (a < b)
		return b;
	else
		return a;
}
// find
int find(HeapType* h, int root, int key) // 필요하면 사용
{
	if (h->heap_size < root)
		return 0;
	if (h->heap[root].key == key)
		return root;
	else if (h->heap[root].key > key)
		return 0;
	else
		return maxIndex(find(h, root * 2, key), find(h, root * 2 + 1, key));
}

void modify_priority_min_heap(HeapType* h, int oldkey, int newkey) // 이 함수를 작성
{
	int index = find(h, 1, oldkey);
	int i = index;
	element item = { newkey }, temp;

	if (newkey < oldkey) {
		while ((i > 1) && (item.key < h->heap[i / 2].key)) {
			h->heap[i] = h->heap[i / 2];
			i /= 2;
		}
		h->heap[i] = item;
		return;
	}

	int parent = index, child = index * 2;
	temp = item;
	item = h->heap[1];

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
			child++;
		if (temp.key <= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
}
void print_heap(HeapType* h) // 변경하지 말라
{
	int s, i;

	for (s = 1; s <= h->heap_size; s *= 2) {	// s = 1, 2, 4, 8, ...
		for (i = s; i < s * 2 && i <= h->heap_size; i++) 	// e.g., when s = 4, i = 4, 5, 6, 7
			printf("%d ", h->heap[i].key);
		printf("\n");
	}
}

// 주함수 
int main(void) // 변경하지 말라
{
	element e;
	int index;
	int key, oldKey, newKey;
	HeapType heap;	// 히프 생성
	int n;

	init(&heap);		// 초기화

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		element e;
		scanf("%d", &e.key);
		insert_min_heap(&heap, e);
	}
	print_heap(&heap);

	// 문제 2)
	scanf("%d %d", &oldKey, &newKey);
	modify_priority_min_heap(&heap, oldKey, newKey);
	print_heap(&heap);
}

/*예제
6
5 3 1 7 9 2
5 10
*/


/* 뼈대코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define TRUE 1
#define FALSE 0

typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}

// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_min_heap(HeapType* h, element item) // 이전 문제1)에서 작성한 함수 사용
{

}
int maxIndex(int a, int b) // 필요하면 사용
{
	if (a < b)
		return b;
	else
		return a;
}
// find
int find(HeapType* h, int root, int key) // 필요하면 사용
{
	if (h->heap_size < root)
		return 0;
	if (h->heap[root].key == key)
		return root;
	else if (h->heap[root].key > key)
		return 0;
	else
		return maxIndex(find(h, root * 2, key), find(h, root * 2 + 1, key));
}

void modify_priority_min_heap(HeapType* h, int oldkey, int newkey) // 이 함수를 작성
{
	// 코드 작성
}
void print_heap(HeapType* h) // 변경하지 말라
{
	int s, i;

	for (s = 1; s <= h->heap_size; s *= 2) {	// s = 1, 2, 4, 8, ...
		for (i = s; i < s * 2 && i <= h->heap_size; i++) 	// e.g., when s = 4, i = 4, 5, 6, 7
			printf("%d ", h->heap[i].key);
		printf("\n");
	}
}

// 주함수
int main(void) // 변경하지 말라
{
	element e;
	int index;
	int key, oldKey, newKey;
	HeapType heap;	// 히프 생성
	int n;

	init(&heap);		// 초기화

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		element e;
		scanf("%d", &e.key);
		insert_min_heap(&heap, e);
	}
	print_heap(&heap);

	// 문제 2)
	scanf("%d %d", &oldKey, &newKey);
	modify_priority_min_heap(&heap, oldKey, newKey);
	print_heap(&heap);
}
*/