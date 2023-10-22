#pragma once
typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;     //별명을 선언

Node* DLL_CreateNode(ElementType NewData);
void DLL_DestroyNode(Node* Node);
void DLL_AppendNode(Node** Head, Node* NewNode );
void DLL_InsertAfter(Node* Current, Node* NewNode);
void DLL_RemoveNode(Node** Head, Node* Remove);
Node* DLL_GetNodeAt(Node* Head, int Location);