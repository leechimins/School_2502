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

int get_height(TreeNode* node) {
	int height = 0;
	if (node)
		height = 1 + (((get_height(node->left)) > (get_height(node->right))) ? (get_height(node->left)) : (get_height(node->right)));
	return height;
}

int count_unbalanced_node(TreeNode* node) // 이 함수를 작성한다
{
	int count = 0, left, right;
	if (node) {
		left = get_height(node->left);
		right = get_height(node->right);

		if (right - left >= 2 || left - right >= 2)
			count = 1 + count_unbalanced_node(node->left) + count_unbalanced_node(node->right);
		else
			count = count_unbalanced_node(node->left) + count_unbalanced_node(node->right);
	}

	return count;
}

int main(void) // main은 변경하지 말라. 
{
	int key;

	TreeNode* root = NULL;

	scanf("%d", &key);
	while (key != -1) {
		root = insert_node(root, key); // 이진탐색트리를 만든다
		scanf("%d", &key);
	}

	printf("%d\n", count_unbalanced_node(root));
}
// 5 3 8 7 5 6 -1