#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

#define ARR_SIZE 10

typedef struct treeNode
{
	int value;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* setBinTree(int* arr, int parentIdx, int maxSize);
void displayTreeInorder(treeNode* t);
void displayTreePreorder(treeNode* t);
void displayTreePostorder(treeNode* t);
treeNode* memoryFree(treeNode* t);

int main()
{
	int arr[ARR_SIZE] = { 6, 4, 8, 2, 5, 7, 9, 1, 3, 10 };
	treeNode* root = NULL;

	//배열을 complete이진트리 구조로 설정
	//트리구조를 만든 후, 루트의 주소를 리턴
	root = setBinTree(arr, 0, ARR_SIZE); //배열이름, 루트의인덱스, 배열의크기

	printf("중위순회(Inorder) : ");
	displayTreeInorder(root);

	printf("\n전위순회(Preorder) : ");
	displayTreePreorder(root);

	printf("\n후위순회(Preorder) : ");
	displayTreePostorder(root);

	printf("\n동적으로 할당 된 메모리 제거\n");
	root = memoryFree(root);

	return 0;
}

treeNode* setBinTree(int* arr, int parentIdx, int maxSize)
{
	int leftIdx = 2 * parentIdx + 1;
	int rightIdx = leftIdx + 1;
	treeNode* newNode;
	newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->value = arr[parentIdx];
	newNode->left = NULL;
	newNode->right = NULL;

	if (leftIdx < maxSize) //재귀호출의 종료조건
	{
		newNode->left = setBinTree(arr, leftIdx, maxSize); //왼쪽 자식 노드를 만들기 위해 재귀호출
	}
	if (rightIdx < maxSize) //재귀호출의 종료조건
	{
		newNode->right = setBinTree(arr, rightIdx, maxSize); //오른쪽 자식 노드를 만들기 위해 재귀호출
	}

	return newNode;
}

void displayTreeInorder(treeNode* t)
{
	//중위순회
	if (t != NULL)
	{
		displayTreeInorder(t->left); //왼쪽 노드의 주소로 재귀호출
		printf("%d ", t->value);
		displayTreeInorder(t->right); //오른쪽 노드의 주소로 재귀호출
	}
}

void displayTreePreorder(treeNode* t)
{
	//전위순회
	if (t != NULL)
	{
		printf("%d ", t->value);
		displayTreePreorder(t->left); //왼쪽 노드의 주소로 재귀호출		
		displayTreePreorder(t->right); //오른쪽 노드의 주소로 재귀호출
	}
}

void displayTreePostorder(treeNode* t)
{
	//후위순회
	if (t != NULL)
	{
		displayTreePostorder(t->left); //왼쪽 노드의 주소로 재귀호출		
		displayTreePostorder(t->right); //오른쪽 노드의 주소로 재귀호출
		printf("%d ", t->value);
	}
}

treeNode* memoryFree(treeNode* t)
{
	//후위순회로 제거
	if (t != NULL)
	{
		memoryFree(t->left);
		memoryFree(t->right);
		printf("%d제거\n", t->value);
		free(t);
	}
	return NULL;
}