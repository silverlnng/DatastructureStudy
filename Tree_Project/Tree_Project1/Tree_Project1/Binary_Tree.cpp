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

	//�迭�� complete����Ʈ�� ������ ����
	//Ʈ�������� ���� ��, ��Ʈ�� �ּҸ� ����
	root = setBinTree(arr, 0, ARR_SIZE); //�迭�̸�, ��Ʈ���ε���, �迭��ũ��

	printf("������ȸ(Inorder) : ");
	displayTreeInorder(root);

	printf("\n������ȸ(Preorder) : ");
	displayTreePreorder(root);

	printf("\n������ȸ(Preorder) : ");
	displayTreePostorder(root);

	printf("\n�������� �Ҵ� �� �޸� ����\n");
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

	if (leftIdx < maxSize) //���ȣ���� ��������
	{
		newNode->left = setBinTree(arr, leftIdx, maxSize); //���� �ڽ� ��带 ����� ���� ���ȣ��
	}
	if (rightIdx < maxSize) //���ȣ���� ��������
	{
		newNode->right = setBinTree(arr, rightIdx, maxSize); //������ �ڽ� ��带 ����� ���� ���ȣ��
	}

	return newNode;
}

void displayTreeInorder(treeNode* t)
{
	//������ȸ
	if (t != NULL)
	{
		displayTreeInorder(t->left); //���� ����� �ּҷ� ���ȣ��
		printf("%d ", t->value);
		displayTreeInorder(t->right); //������ ����� �ּҷ� ���ȣ��
	}
}

void displayTreePreorder(treeNode* t)
{
	//������ȸ
	if (t != NULL)
	{
		printf("%d ", t->value);
		displayTreePreorder(t->left); //���� ����� �ּҷ� ���ȣ��		
		displayTreePreorder(t->right); //������ ����� �ּҷ� ���ȣ��
	}
}

void displayTreePostorder(treeNode* t)
{
	//������ȸ
	if (t != NULL)
	{
		displayTreePostorder(t->left); //���� ����� �ּҷ� ���ȣ��		
		displayTreePostorder(t->right); //������ ����� �ּҷ� ���ȣ��
		printf("%d ", t->value);
	}
}

treeNode* memoryFree(treeNode* t)
{
	//������ȸ�� ����
	if (t != NULL)
	{
		memoryFree(t->left);
		memoryFree(t->right);
		printf("%d����\n", t->value);
		free(t);
	}
	return NULL;
}