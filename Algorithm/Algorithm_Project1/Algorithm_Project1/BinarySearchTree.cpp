#include "BinarySearchTree.h"


BSTNode* BST_CreateNode(ElementType NewData)
{
    BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void BST_DestroyNode(BSTNode* Node)
{
    free(Node);
}

void BST_DestroyTree(BSTNode* Tree)
{
    if (Tree->Right != NULL)
        BST_DestroyTree(Tree->Right);

    if (Tree->Left != NULL)
        BST_DestroyTree(Tree->Left);

    Tree->Left = NULL;
    Tree->Right = NULL;

    BST_DestroyNode(Tree);
}

BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target)
{
    if (Tree == NULL)
        return NULL;

    if (Tree->Data == Target)
        return Tree;
    else if (Tree->Data > Target)
        return BST_SearchNode(Tree->Left, Target);
    else
        return BST_SearchNode(Tree->Right, Target);
}


BSTNode* BST_SearchMinNode(BSTNode* Tree)
{
    if (Tree == NULL)
        return NULL;

    if (Tree->Left == NULL)
        return Tree;
    else
        return BST_SearchMinNode(Tree->Left);
}

void BST_InsertNode(BSTNode* Tree, BSTNode* Child)
{
    if (Tree->Data < Child->Data)
    {
        if (Tree->Right == NULL)
            Tree->Right = Child;
        else
            BST_InsertNode(Tree->Right, Child);

    }
    else if (Tree->Data > Child->Data)
    {
        if (Tree->Left == NULL)
            Tree->Left = Child;
        else
            BST_InsertNode(Tree->Left, Child);
    }
}

BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target)
{
    BSTNode* Removed = NULL;

    if (Tree == NULL)
        return NULL;

    if (Tree->Data > Target)
        Removed = BST_RemoveNode(Tree->Left, Tree, Target);
    else if (Tree->Data < Target)
        Removed = BST_RemoveNode(Tree->Right, Tree, Target);
    else /*  ��ǥ ���� ã�� ���. */
    {
        Removed = Tree;

        /*  �� ����� ��� �ٷ� ���� */
        if (Tree->Left == NULL && Tree->Right == NULL)
        {
            if (Parent->Left == Tree)
                Parent->Left = NULL;
            else
                Parent->Right = NULL;
        }
        else
        {
            /*  �ڽ��� ���� �� �ִ� ��� */
            if (Tree->Left != NULL && Tree->Right != NULL)
            {
                /*  �ּҰ� ��带 ã�� ������ �� ������ ��忡 ��ġ��Ų��. */
                BSTNode* MinNode = BST_SearchMinNode(Tree->Right);
                MinNode = BST_RemoveNode(Tree, NULL, MinNode->Data);
                Tree->Data = MinNode->Data;
            }
            else
            {
                /*  �ڽ��� �ϳ��� �ִ� ��� */
                BSTNode* Temp = NULL;
                if (Tree->Left != NULL)
                    Temp = Tree->Left;
                else
                    Temp = Tree->Right;

                if (Parent->Left == Tree)
                    Parent->Left = Temp;
                else
                    Parent->Right = Temp;
            }
        }
    }

    return Removed;
}

void BST_InorderPrintTree(BSTNode* Node)
{
    if (Node == NULL)
        return;

    /*  ���� ���� Ʈ�� ��� */
    BST_InorderPrintTree(Node->Left);

    /*  ��Ʈ ��� ��� */
    printf("%d ", Node->Data);

    /*  ������ ���� Ʈ�� ��� */
    BST_InorderPrintTree(Node->Right);
}


int main(void)
{
    /*  ��� ���� */
    BSTNode* Tree = BST_CreateNode(123);
    BSTNode* Node = NULL;

    /*  Ʈ���� ��� �߰� */
    BST_InsertNode(Tree, BST_CreateNode(22));
    BST_InsertNode(Tree, BST_CreateNode(9918));
    BST_InsertNode(Tree, BST_CreateNode(424));
    BST_InsertNode(Tree, BST_CreateNode(17));
    BST_InsertNode(Tree, BST_CreateNode(3));

    BST_InsertNode(Tree, BST_CreateNode(98));
    BST_InsertNode(Tree, BST_CreateNode(34));

    BST_InsertNode(Tree, BST_CreateNode(760));
    BST_InsertNode(Tree, BST_CreateNode(317));
    BST_InsertNode(Tree, BST_CreateNode(1));

    Node = BST_SearchNode(Tree, 17);
    if (Node != NULL)
        printf("%d \n", Node->Data);
    else
        puts("�׷� ��� �����");

    /*  Ʈ�� ��� */
    BST_InorderPrintTree(Tree);
    printf("\n");

    /*  Ư�� ��� ���� */
    printf("Removing 98...\n");

    Node = BST_RemoveNode(Tree, NULL, 98);
    BST_DestroyNode(Node);

    BST_InorderPrintTree(Tree);
    printf("\n");

    /*  �� ��� ���� */
    printf("Inserting 111...\n");

    BST_InsertNode(Tree, BST_CreateNode(111));
    BST_InorderPrintTree(Tree);
    printf("\n");

    /*  Ʈ�� �Ҹ��Ű�� */
    BST_DestroyTree(Tree);

    return 0;
}

