#pragma once

//�迭�� ������� �����Ǵ� ������ ���� �����͸� ��� ����ü�� ǥ��
//��尡 �����ϴ� ��ġ�� �迭�� �ε����� �˼��־ ��ũ�帮��Ʈó�� ��,�� ��忡 ���� �����Ͱ� �ʿ� ����

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
} Node;

//���� ����ü

typedef struct tagArrayStack
{
	int Capacity;		//�뷮
	int Top;			//�ֻ��� ����� ��ġ
	Node* Nodes;		//��� �迭 (�����͸� �迭�λ��)
}ArrayStack;