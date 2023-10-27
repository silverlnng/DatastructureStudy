#include "DoubleLinkedList_Project.h"
#include <iostream>

int main()
{

    int i = 0;
    int count = 0;
    Node* List = NULL;
    Node* NewNode = NULL;
    Node* Current = NULL;

    //노드 5개를 추가
    for (i = 0; i < 5; i++)
    {
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List, NewNode);
    }

    count = DLL_GetNodeCount(List);

    for (i = 0; i < count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        std::cout <<"list_"<< i <<":"<< Current->Data<< std::endl;
    }


    // 리스트의 3번째 노드 뒤에 데이터가 2000인 노드를 삽입하기 
    // 리스트의 3번째 노드 뒤에  = index 가 2인 노드가 3번째
    // 1)   지금 index 가 2인 노드를 찾는다. -> DLL_GetNodeAt
    // 2)   삽입할 노드를 생성한다. -> DLL_CreateNode
    // 3)   index가 2인 노드 뒤에 삽입한다. -> DLL_InsertAfter
    std::cout << "리스트의 3번째 노드 뒤에 데이터가 2000인 노드를 삽입하기 "<<std::endl;

    Current = DLL_GetNodeAt(List, 2);
    NewNode = DLL_CreateNode(2000);
    DLL_InsertAfter(Current, NewNode);
    count = DLL_GetNodeCount(List);
    for (i = 0; i < count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        std::cout << "list_" << i << ":" << Current->Data << std::endl;
    }


}
