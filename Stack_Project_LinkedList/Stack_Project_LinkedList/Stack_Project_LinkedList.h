#pragma once

//리스트는 인덱스로 노드로 접근하는게  아니다
// => 링크드 리스트로 스택을 구현하려면 노드는 자신의 위에 위치하는 노드에 대한 포인터를 갖고 있어야 한다

typedef struct tagNode
{
	char* Data;				//포인터
	struct tagNode* NextNode;
} Node ;

typedef struct tagLinkedListStack
{
	Node* List;
	Node* Top;
} LinkedListStack ;