#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
}TreeNode;

//----이하 스택을 위한 코드----
typedef TreeNode* element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
}StackNode;

typedef struct {
	StackNode* top;
}LinkedStackType;

void init(LinkedStackType* s) // 변경하지 말라
{
	s->top = NULL;
}

int is_empty(LinkedStackType* s) // 변경하지 말라
{
	return (s->top == NULL);
}

void push(LinkedStackType* s, element item) // 변경하지 말라
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->data = item;
		temp->link = s->top;
		s->top = temp;
	}
}

element pop(LinkedStackType* s) // 변경하지 말라
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		element item = temp->data;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}

element peek(LinkedStackType* s) // 변경하지 말라
{
	if (is_empty(s)) {
		return 0;
		//fprintf(stderr, "스택이 비어있음\n"); exit(1);
	}
	else {
		return s->top->data;
	}
}
//--- 이상 스택을 위한 코드 ---

TreeNode* new_node(int item) // 변경하지 말라
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = item;
	temp->left = temp->right = NULL;
	temp->is_thread = 0; // 추가: 0으로 초기화
	return temp;
}

// key를 이진 탐색 트리 root에 삽입한다. key값이 이미 있는 경우도 삽입한다.
TreeNode* insert_node(TreeNode* node, int key) // 변경하지 말라
{
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (key < node->data)
		node->left = insert_node(node->left, key);
	else // if (key > node->data)
		node->right = insert_node(node->right, key);

	// 변경된 루트 포인터를 반환한다. 
	return node;
}

int makeThreadedBT(TreeNode* root) // 이 함수를 threaded binary tree로 만드는 부분으로 작성한다
{
	int count = 0;

	LinkedStackType s;
	init(&s);

	while (1) {
		for (; root; root = root->left)
			push(&s, root);
		if (is_empty(&s))
			break;
		root = pop(&s);
		if (root->right == NULL) {
			root->is_thread = 1;
			root->right = peek(&s);
			if (root->right != NULL)
				count++;
			root = NULL;
		}
		else
			root = root->right;
	}

	return count;
}
TreeNode* find_successor(TreeNode* p) // 변경하지 말라
{
	// q는 p의 오른쪽 포인터
	TreeNode* q = p->right;
	// 만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
	if (q == NULL || p->is_thread == TRUE)
		return q;

	// 만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동
	while (q->left != NULL) q = q->left;
	return q;
}

void thread_inorder(TreeNode* t) // 변경하지 말라
{
	TreeNode* q;

	q = t;
	while (q->left) q = q->left;// 가장 왼쪽 노드로 간다.
	do {
		printf("%d->", q->data);// 데이터 출력
		q = find_successor(q); // 후속자 함수 호출
	} while (q);			// NULL이 아니면
}
int main(void) // 변경하지 말라
{
	int key;
	TreeNode* root;

	// 아래의 6줄은 이진탐색트리를 만드는 코드이다
	root = NULL;
	scanf("%d", &key);
	while (key != -1) {
		root = insert_node(root, key);
		scanf("%d", &key);
	}

	printf("%d", makeThreadedBT(root)); // Threaded Binary Tree를 만들고 Threaded Node를 반환하는 함수
	printf("\n");
	thread_inorder(root); // Threaded Binary Tree가 잘 만들어졌나 확인하기 위한
}