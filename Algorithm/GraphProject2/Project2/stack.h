#pragma once
#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct stack
{
	//int data[5];
	int* data; //�������� �Ҵ�� �޸��� �ּҸ� �����ϴ� ������(8����Ʈ)
	int top; //����� �����
	int capacity; //�Ҵ� �� �޸��� �ִ� ũ��
}stack;

void createStack(stack* stk, int size);
void push(stack* stk, int value);
int pop(stack* stk);
void stackPrint(stack* stk);
void stackClear(stack* stk);
int isStackFull(stack* stk);
int isStackEmpty(stack* stk);
