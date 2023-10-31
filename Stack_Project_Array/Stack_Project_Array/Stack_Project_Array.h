#pragma once

//배열을 기반으로 구현되는 스택의 노드는 데이터만 담는 구조체로 표현
//노드가 존재하는 위치는 배열의 인덱스로 알수있어서 링크드리스트처럼 앞,뒤 노드에 대한 포인터가 필요 없다

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
} Node;

//스택 구조체

typedef struct tagArrayStack
{
	int Capacity;		//용량
	int Top;			//최상위 노드의 위치
	Node* Nodes;		//노드 배열 (포인터를 배열로사용)
}ArrayStack;