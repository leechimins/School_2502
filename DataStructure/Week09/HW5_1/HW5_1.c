// 컴퓨터학과 3학년 20221590 이지민
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void init(HeapType* h) { h->heap_size = 0; }

void insert_max_heap(HeapType* h, element item) {
	int pos = ++(h->heap_size);
	while (pos > 1 && (item.key > h->heap[pos / 2].key)) {
		h->heap[pos] = h->heap[pos / 2];
		pos /= 2;
	}
	h->heap[pos] = item;
}

void preorder(HeapType* h, int root) {
	if (root <= h->heap_size) {
		printf("%d ", h->heap[root].key);
		preorder(h, root * 2);
		preorder(h, root * 2 + 1);
	}
}

void print_heap(HeapType* h) {
	/*for (int i = 1, level = 2; i <= h->heap_size; i++) {
		if (i % level == 0) {
			level *= 2;
			printf("\n");
		}
		printf("%d ", h->heap[i].key);
	}*/

	int level = 2, i = 1;

	for (; level <= h->heap_size; level *= 2) {
		for (; i < level; i++)
			printf("%d ", h->heap[i].key);
		printf("\n");
	}

	for (; i <= h->heap_size; i++)
		printf("%d ", h->heap[i].key);
}

element delete_max_heap(HeapType* h) {
	element root = h->heap[1];
	element last = h->heap[(h->heap_size)--];
	int parent = 1, child = 2;

	while (child <= h->heap_size) {
		if (child < h->heap_size && h->heap[child].key < h->heap[child + 1].key)
			child++;
		if (last.key >= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = last;

	return root;
}

int find(HeapType* h, int root, int key) {
	if (root > h->heap_size || h->heap[root].key < key)
		return 0;

	if (h->heap[root].key == key)
		return root;

	int result = find(h, root * 2, key) + find(h, root * 2 + 1, key);
	return result;
}

int find2(HeapType* h, int key) {
	for (int i = 1; i <= h->heap_size; i++) {
		if (h->heap[i].key < key)
			return 0;

		if (h->heap[i].key == key)
			return i;
	}
	return 0;
}

void print_sorted_value(HeapType h) {
	element item;
	while (h.heap_size > 0) {
		item = delete_max_heap(&h);
		printf("%d ", item.key);
	}
}

void modify_priority(HeapType* h, int oldKey, int newKey) {
	int index = find(h, 1, oldKey);
	element item = { newKey };

	if (newKey < oldKey) {
		int parent = index, child = index * 2;

		while (child <= h->heap_size) {
			if (h->heap[child].key < h->heap[child + 1].key)
				child++;
			if (item.key >= h->heap[child].key)
				break;
			h->heap[parent] = h->heap[child];
			parent = child;
			child *= 2;
		}
		h->heap[parent] = item;
	}
	else {
		while (index > 1 && (item.key > h->heap[index / 2].key)) {
			h->heap[index] = h->heap[index / 2];
			index /= 2;
		}
		h->heap[index] = item;
	}
}


int main(void) {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 }, eA = { 9 }, eB = { 19 }, eC = { 39 };
	element e4, e5, e6;
	int index;
	int key, oldKey, newKey;
	HeapType heap;
	init(&heap);
	printf("Step1: 삽입된 10, 5, 30 에 추가적으로 9, 19, 39 를 <삽입> 한다");
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);
	insert_max_heap(&heap, eA);
	insert_max_heap(&heap, eB);
	insert_max_heap(&heap, eC);

	printf("\nStep2: preorder, print_heap 함수 테스트\n");
	preorder(&heap, 1);
	printf("\n\n");
	print_heap(&heap);
	
	e4 = delete_max_heap(&heap);
	printf("\n 삭제: 루트가 삭제됨\n", e4.key);
	print_heap(&heap);

	printf("\nStep3: find 함수 테스트\n");
	printf("찾을 key 입력(-1 for exit):");
	scanf("%d", &key);
	while (key != -1) {
		if ((index = find2(&heap, key)) == 0)
			printf("%d 는 없음\n", key);
		else
			printf("%d 은 [%d]에 있음\n", key, index);
		printf("찾을 key 입력(-1 for exit):");
		scanf("%d", &key);
	}

	printf("\nStep4: print_sorted_value 함수 테스트\n");
	print_sorted_value(heap);

	printf("\nStep5: modify_priority 함수 테스트\n");
	printf("바꿀 key 입력(-1 for exit):");
	scanf("%d", &oldKey);
	while (oldKey != -1) {
		printf("새 key 입력:");
		scanf("%d", &newKey);
		modify_priority(&heap, oldKey, newKey);
		print_heap(&heap);
		printf("바꿀 key 입력(-1 for exit):");
		scanf("%d", &oldKey);
	}

	return 0;
}