#include "DoubleLinkedList_Project.h"
#include <iostream>

int main()
{

    int i = 0;
    int count = 0;
    Node* List = NULL;
    Node* NewNode = NULL;
    Node* Current = NULL;

    //��� 5���� �߰�
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


    // ����Ʈ�� 3��° ��� �ڿ� �����Ͱ� 2000�� ��带 �����ϱ� 
    // ����Ʈ�� 3��° ��� �ڿ�  = index �� 2�� ��尡 3��°
    // 1)   ���� index �� 2�� ��带 ã�´�. -> DLL_GetNodeAt
    // 2)   ������ ��带 �����Ѵ�. -> DLL_CreateNode
    // 3)   index�� 2�� ��� �ڿ� �����Ѵ�. -> DLL_InsertAfter
    std::cout << "����Ʈ�� 3��° ��� �ڿ� �����Ͱ� 2000�� ��带 �����ϱ� "<<std::endl;

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
