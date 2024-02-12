#include "stack.h"

void createStack(stack* stk, int size)
{
	stk->data = (int*)malloc(sizeof(int) * size);
	stk->top = -1;
	stk->capacity = size;
}

void push(stack* stk, int value)
{
	//if (stk->top == stk->capacity - 1) //더이상 저장할 수 없는 상태
	if (isStackFull(stk))
	{
		//printf("\n\n\t\tstack overflow\n");
		//return;

		//메모리 공간이 부족한 경우 2배 증가
		stk->capacity *= 2;
		//새 메모리의 주소 = realloc(기존 메모리의 주소, 할당할 메모리의 크기);
		stk->data = (int*)realloc(stk->data, sizeof(int) * stk->capacity);
		//printf("\n\n\t\t메모리를 2배 확장했습니다.\n");			
	}

	stk->data[++stk->top] = value;
}

int pop(stack* stk)
{
	//if (stk->top == -1)//더이상 삭제할 수 없는 경우
	if (isStackEmpty(stk))
	{
		return -1; //underflow 
	}

	//실제 삭제되는 것이 아닌 논리적인 삭제다.
	//감소된 top의 위치에 새로운 값이 push되면 실제 물리적인 삭제가 이뤄진다.
	return stk->data[stk->top--]; //삭제된 값 리턴
}

void stackPrint(stack* stk)
{
	int i;

	system("cls");
	printf("stack display(LIFO : Last In First Out) : ");
	for (i = stk->top; i >= 0; i--)
		printf("%d ", stk->data[i]);
	puts("");
}

void stackClear(stack* stk)
{
	//물리적인 삭제가 아니다.(실제 데이터는 사라지지 않는다.)
	//논리적으로 삭제 된 것처럼 코드를 구현!!!
	stk->top = -1;
}

int isStackFull(stack* stk)
{
	//if (stk->top == stk->capacity - 1) //스택이 가득 찼다면??
	//	return 1;
	//else
	//	return 0;

	return stk->top == stk->capacity - 1; //연산결과 리턴
}

int isStackEmpty(stack* stk)
{
	//if (stk->top == -1) //스택이 비어 있다면??
	//	return 1;
	//else 
	//	return 0;

	return stk->top == -1;
}