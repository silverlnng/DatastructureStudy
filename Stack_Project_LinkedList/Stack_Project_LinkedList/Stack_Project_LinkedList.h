#pragma once

//����Ʈ�� �ε����� ���� �����ϴ°�  �ƴϴ�
// => ��ũ�� ����Ʈ�� ������ �����Ϸ��� ���� �ڽ��� ���� ��ġ�ϴ� ��忡 ���� �����͸� ���� �־�� �Ѵ�

typedef struct tagNode
{
	char* Data;				//������
	struct tagNode* NextNode;
} Node ;

typedef struct tagLinkedListStack
{
	Node* List;
	Node* Top;
} LinkedListStack ;