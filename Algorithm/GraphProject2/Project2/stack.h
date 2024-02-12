#pragma once
#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct stack
{
	//int data[5];
	int* data; //동적으로 할당된 메모리의 주소를 저장하는 포인터(8바이트)
	int top; //저장된 꼭대기
	int capacity; //할당 된 메모리의 최대 크기
}stack;

void createStack(stack* stk, int size);
void push(stack* stk, int value);
int pop(stack* stk);
void stackPrint(stack* stk);
void stackClear(stack* stk);
int isStackFull(stack* stk);
int isStackEmpty(stack* stk);
