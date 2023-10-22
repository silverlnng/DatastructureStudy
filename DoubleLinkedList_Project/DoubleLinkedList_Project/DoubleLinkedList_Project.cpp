// DoubleLinkedList_Project.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "DoubleLinkedList_Project.h"



Node* DLL_CreateNode(ElementType NewData) // 노드를 생성하는 함수
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;
    
    return NewNode;
}

void DLL_AppendNode(Node** Head, Node* NewNode)
{
    //AppendNode 는 마지막에 노드를 추가시킬때만 사용하는것
    //Head를 포인터를 가르키는 포인터 로 정의한것에 주의하자

    if ((*Head) == NULL)
    {
        *Head = NewNode;
    }
    else 
    {
        //Tail 을 찾아 newnode를 연결
        Node* Tail = (*Head);
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode; 

        NewNode->PrevNode = Tail; // 연결을 2번씩
    }
}

void DLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        //제거할 노드가 헤드라면
        *Head = Remove->NextNode;
        //헤드를 헤드다음노드로 재설정

        if ((*Head) != NULL)
        {
            (*Head)->PrevNode = NULL;
            //새로 변경된 헤드와 원래 헤드 노드(제거할 노드) 연결을 끊기
            Remove->PrevNode = NULL;
            Remove->NextNode = NULL;
        }

    }
	else
	{
		Node* Temp = Remove;
		if (Remove->PrevNode != NULL)
		{
			Remove->PrevNode->NextNode = Temp->NextNode;
		}
		if (Remove->NextNode != NULL)
		{
			Remove->NextNode->PrevNode = Temp->PrevNode;
		}

	}
    
}


int main()
{
    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
