#include "queue.h"

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
	if (isQueueFull(pQue))
	{
		printf("\n\n\t\tqueue overflow\n");
		return;
	}

	pQue->data[pQue->rear % pQue->capacity] = value;
	pQue->rear++;
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
	if (isQueueEmpty(pQue))
		return -1; //삭제 실패

	delVal = pQue->data[pQue->front % pQue->capacity]; //삭제된 값 저장 후, front 1 증가
	pQue->front++;
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
	if (isQueueEmpty(pQue))
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

int isQueueFull(queue* pQue)
{
	//if (pQue->size == pQue->capacity) //가득찼다면??
	//	return 1;
	//else
	//	return 0;

	return pQue->size == pQue->capacity;
}

int isQueueEmpty(queue* pQue)
{
	return pQue->size == 0;
}