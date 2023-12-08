#include <iostream>

using namespace std;

//ù° �ٿ� �ǿ������� ����(1 �� N �� 26) �� �־�����.�׸��� ��° �ٿ��� ���� ǥ����� �־�����. (���⼭ �ǿ����ڴ� A~Z�� ���빮���̸�, A���� ������� N���� ���빮�ڸ��� ���Ǹ�, ���̴� 100�� ���� �ʴ´�) �׸��� ��° �ٺ��� N + 2��° �ٱ����� �� �ǿ����ڿ� �����ϴ� ���� �־�����. 3��° �ٿ��� A�� �ش��ϴ� ��, 4��° �ٿ��� B�� �ش��ϴ°�, 5��° �ٿ��� C ...�� �־�����, �׸��� �ǿ����ڿ� ���� �ϴ� ���� 100���� �۰ų� ���� �ڿ����̴�.
//
//���� ǥ����� �տ������� ������� ��, ���� ����� �߰� ����� - 20�ﺸ�� ũ�ų� ����, 20�ﺸ�� �۰ų� ���� �Է¸� �־�����.
typedef struct treeNode
{
	string value;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* setBinTree(string arr, int parentIdx);
void displayTreePostorder(treeNode* t);

int main()
{
	treeNode* root = NULL;
	int N{};
	cin >> N;
	// �ǿ������� ������ �̸� ���ؼ� �Է¹޴´�
	int* array = new int[N]; 

	// ����ǥ����� �Է¹޴´� => ����ǥ����� string���� �޴´�
	// �Է¹��� ����ǥ����� ���������� �ǿ��������� ������ �ؾ��Ѵ�

	string expressionTree;
	cin >> expressionTree;


	while (--N) //��ó���� �Է¹��� N ��ŭ �Է��� �ް� ���� �صα�
	{
		int temp;
		cin >> temp;
		array[N] = temp;
		//�̶� �Է¹������� expressionTree �ǿ����ڿ� �����ؾ��Ѵ� => �׷��� �����صα� 
	}

	//for (int i = 0; i < expressionTree.length(); i++)
	//{
	//	char token = expressionTree[i];

	//	//Ʈ������ �����ϰ� ������ Ʈ���� ����ϱ� ??

	//	switch (token)
	//	{
	//		//�������� ���
	//	case '+':
	//		break;
	//	case '-':
	//		break;
	//	case '*':
	//		break;
	//	case '/':
	//		break;

	//		//�ǿ������� ���
	//	default:
	//		//�ǿ����� char ���� ��� int ���� ���� ??
	//		break;
	//	}
	//}

	root = setBinTree(expressionTree, 0);
	displayTreePostorder(root);
	return 0;
}

treeNode* setBinTree(string arr, int parentIdx)
{
	int maxSize = arr.length();
	int leftIdx = 2 * parentIdx + 1;
	int rightIdx = leftIdx + 1;
	treeNode* newNode;
	newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->value = arr[parentIdx];
	newNode->left = NULL;
	newNode->right = NULL;

	if (leftIdx < maxSize) //���ȣ���� ��������
	{
		newNode->left = setBinTree(arr, leftIdx); //���� �ڽ� ��带 ����� ���� ���ȣ��
	}
	if (rightIdx < maxSize) //���ȣ���� ��������
	{
		newNode->right = setBinTree(arr, rightIdx); //������ �ڽ� ��带 ����� ���� ���ȣ��
	}

	return newNode;
}

void displayTreePostorder(treeNode* t)
{
	//������ȸ
	if (t != NULL)
	{
		displayTreePostorder(t->left); //���� ����� �ּҷ� ���ȣ��		
		displayTreePostorder(t->right); //������ ����� �ּҷ� ���ȣ��
		printf("%s", t->value);
	}
}