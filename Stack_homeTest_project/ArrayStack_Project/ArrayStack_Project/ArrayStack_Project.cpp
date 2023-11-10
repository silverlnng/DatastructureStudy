#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

#define MAX_SIZE 5

typedef struct stack
{
	int arr[MAX_SIZE];
	int top;
}stack;

void createStack(stack* p);
void push(stack* p, int element);
int pop(stack* p);
void displayStack(stack* p);
void clearStack(stack* p);

int main()
{
	int choice, value;
	stack stk; //구조체 변수 선언(스택 생성)

	createStack(&stk);

	while (1)
	{
		system("cls");
		printf("\n\n\t\t*** Stack with Array ***\n\n");
		printf("\t\t1. push    2. pop    3. print    4. clear    0. exit\n");
		printf("\t\tchoice : [ ]\b\b");
		scanf("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case 1:
			printf("\n\n\t\t정수 입력 : ");
			scanf("%d", &value);
			while (getchar() != '\n');

			push(&stk, value);
			break;
		case 2:
			value = pop(&stk); //삭제된 값을 리턴
			if (value == -1)
				printf("\n\n\t\tstack underflow\n");
			else
				printf("\n\n\t\t%d pop\n", value);
			break;
		case 3:
			displayStack(&stk);
			break;
		case 4:
			clearStack(&stk);
			break;
		case 0:
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}

void createStack(stack* p)
{
	p->top = -1;
}

void push(stack* p, int element)
{
	if (p->top == MAX_SIZE - 1)
	{
		printf("\n\n\t\tstack overflow\n");
		return;
	}
	p->arr[++(p->top)] = element;
	//top++;
}

void displayStack(stack* p)
{
	int i;
	printf("\n\n\t\tstack display(LIFO) : ");
	for (i = p->top; i >= 0; i--)
		printf("%d ", p->arr[i]);
	puts(""); //줄바꿈
}

void clearStack(stack* p)
{
	p->top = -1;
}

int pop(stack* p)
{
	if (p->top == -1) //underflow
	{
		return -1;
	}
	//물리적인 삭제가 아니다. 논리적인 삭제
	//(p->top)--;
	return p->arr[(p->top)--];
}

//이런 구조의 배열 기반 스택의 단점 중 하나는 용량을 조절하기가 어렵다는 것입니다. 하지만 불가능한 것은
//아니지요.자, 이제 문제입니다.다음의 Push() 함수를 스택의 용량이 모두 소진되었을 때 현재 용량의
//30 % 만큼을 더 늘리도록 개선하세요.
void push_fixCapacity (stack* p, int element)
{
	if (p->top == MAX_SIZE - 1)
	{
		printf("\n\n\t\tstack overflow\n");
		MAX_SIZE * 1.3;
		return;
	}
	p->arr[++(p->top)] = element;
}


//만약 배열 기반 스택 예제 프로그램의 Push() 함수만 용량이 늘어나도록 수정
//한다면 스택은 커지기만 하고 줄어들지는 않아 결국에는 메모리를 낭비하는 결과를 만들게 됩니다.따라서 
//Pop() 함수도 실제 사용량이 줄어들면 용량을 줄이도록 개선해야 합니다.이번 문제는 다음의 Pop() 함수를
//사용량이스택용량의70% 미만으로 내려가면 용량을 줄이도록수정하는것입니다.

int pop_fixCapacity(stack* p)
{
	if (p->top == -1) //underflow
	{
		return -1;
	}
	//물리적인 삭제가 아니다. 논리적인 삭제
	//(p->top)--;
	return p->arr[(p->top)--];
}