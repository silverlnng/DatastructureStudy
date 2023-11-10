#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct queue
{
	//int data[5];
	int* data;		//동적할당된 메모리의 주소를 저장하는 포인터(8바이트)
	int rear;		//삽입할 배열의 인덱스
	int front;		//삭제할 배열의 인덱스
	int size;		//배열에 저장된 원소의 개수
	int capacity;	//배열의 최대 용량(배열의 크기)
}queue;

void createQueue(queue* pQue, int count);
void enqueue(queue* pQue, int value);
int dequeue(queue* pQue);
void queuePrint(queue* pQue);
void queueClear(queue* pQue);
int isFull(queue* pQue); //큐가 가득 찼다면 있다면 1, 아니라면 0리턴
int isEmpty(queue* pQue); //큐가 비어 있다면 1, 아니라면 0리턴

int main()
{
	queue que; //구조체 변수 선언(24바이트)
	int choice, count, value;

	printf("할당하고 싶은 큐의 크기를 입력 하세요 : ");
	scanf("%d", &count);
	while (getchar() != '\n');

	createQueue(&que, count);

	while (1)
	{
		system("cls");
		printf("\n\n\t\t****  배열을 이용한 원형 큐 ***\n\n");
		printf("1. enqueue    2. dequeue    3. print    4. clear   0. terminate\n");
		printf("choice : [ ]\b\b");
		scanf("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case 1:
			printf("\n\ninteger enqueue : ");
			scanf("%d", &value);
			while (getchar() != '\n');
			enqueue(&que, value);
			break;
		case 2:

			value = dequeue(&que); //dequeue 후 삭제된 값 저장
			if (value == -1)
				printf("\n\n\t\tqueue underflow\n");
			else
				printf("\n\n\t\t%d dequeue\n", value);
			break;
		case 3:
			queuePrint(&que);
			break;
		case 4:
			queueClear(&que);
			break;
		case 0:
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}

void createQueue(queue* pQue, int count)
{
	pQue->data = (int*)malloc(sizeof(int) * count);
	pQue->rear = 0;
	pQue->front = 0;
	pQue->size = 0;
	pQue->capacity = count;
}

void enqueue(queue* pQue, int value)
{
	//if (pQue->size == pQue->capacity) //더이상 저장할 수 없다면???
	if (isFull(pQue))
	{
		printf("\n\n\t\tqueue overflow\n");
		return;
	}

	pQue->data[pQue->rear % pQue->capacity] = value;
	pQue->rear++;//rear 1 증가
	pQue->size++; //저장 개수를 1증가

	//pQue->data[pQue->rear++] = value;
	//pQue->size++; //저장 개수를 1증가

	//if (pQue->rear == pQue->capacity) //마지막 인덱스에 도달하면?? 
	//	pQue->rear = 0; //인덱스를 0으로 재설정
}

int dequeue(queue* pQue)
{
	int delVal;

	//if (pQue->size == 0) //저장된 개수가 없는 경우??
	if (isEmpty(pQue))
		return -1; //삭제 실패

	delVal = pQue->data[pQue->front % pQue->capacity];
	pQue->front++; //front 1 증가
	pQue->size--; //저장 개수는 1감소	

	//delVal = pQue->data[pQue->front++]; //삭제된 값 저장 후, front 1 증가
	//pQue->size--; //저장 개수는 1감소	

	//if (pQue->front == pQue->capacity) //마지막 인덱스에 도달하면??
	//	pQue->front = 0; //인덱스를 0으로 재설정

	return delVal; //삭제된 값 리턴
}

void queuePrint(queue* pQue)
{
	int i;
	system("cls");
	printf("queue display(FIFO : Fisrt In First Out) : ");

	//if (pQue->size == 0)
	if (isEmpty(pQue))
	{
		printf("\n\n\t\tqueue empty\n");
		return;
	}

	//저장된 개수(size)만큼 반복하면서 출력
	for (i = pQue->front; i < pQue->front + pQue->size; i++)
	{
		printf("%d ", pQue->data[i % pQue->capacity]); //[4 % 5][5 % 5][6 % 5]
	}
	puts("");
}

void queueClear(queue* pQue)
{
	//논리적으로 삭제된 것처럼 코드 구현(데이터의 물리적인 삭제는 이뤄지지 않는다.)
	pQue->rear = 0;
	pQue->front = 0;
	pQue->size = 0;
}

int isFull(queue* pQue)
{
	//if (pQue->size == pQue->capacity) //가득찼다면??
	//	return 1;
	//else
	//	return 0;

	return pQue->size == pQue->capacity;
}

int isEmpty(queue* pQue)
{
	return pQue->size == 0;
}