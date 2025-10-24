// 컴퓨터학과 3학년 20221590 이지민

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* new_node(int item) // 변경하지 말라
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// key를 이진 탐색 트리 root에 삽입한다. key값이 이미 있는 경우도 삽입한다.
TreeNode* insert_node(TreeNode* node, int key) // 변경하지 말라
{
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else // if (key > node->key) (A) 이분을 주석처리함으로써 key와 node->key가 같은 경우 이는 오른쪽 서브트리에 삽입한다 
		node->right = insert_node(node->right, key);

	// 변경된 루트 포인터를 반환한다. 
	return node;
}
void inorder(TreeNode* root) { // 변경하지 말라
	if (root) {
		inorder(root->left);	// 왼쪽서브트리 순회
		printf("%d ", root->key); 	// 노드 방문
		inorder(root->right);	// 오른쪽서브트리 순회
	}
}
// 전위 순회
void preorder(TreeNode* root) { // 변경하지 말라
	if (root) {
		printf("%d ", root->key); 	// 노드 방문
		preorder(root->left);	// 왼쪽서브트리 순회
		preorder(root->right);	// 오른쪽서브트리 순회
	}
}
void printCheck(TreeNode* node) // 변경하지 말라
{
	preorder(node); printf("\n");
	inorder(node); printf("\n");
}

int replace_key(TreeNode* node, int oldKey, int newKey) // 이 함수를 작성한다
{
	int count = 0;
	if (node) {
		if (oldKey < node->key)
			count = replace_key(node->left, oldKey, newKey);
		else if (oldKey > node->key)
			count = replace_key(node->right, oldKey, newKey);
		else {
			node->key = newKey;
			count = 1 + replace_key(node->left, oldKey, newKey) + replace_key(node->right, oldKey, newKey);
		}
	}

	return count;
}

int main(void) // main은 변경하지 말라.
{
	int key, oldKey, newKey;

	TreeNode* root = NULL;

	scanf("%d", &key);
	while (key != -1) {
		root = insert_node(root, key);
		scanf("%d", &key);
	}

	scanf("%d %d", &oldKey, &newKey);
	printf("%d\n", replace_key(root, oldKey, newKey));

	printCheck(root);
}