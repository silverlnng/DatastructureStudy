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
	//if (pQue->size == pQue->capacity) //���̻� ������ �� ���ٸ�???
	if (isQueueFull(pQue))
	{
		printf("\n\n\t\tqueue overflow\n");
		return;
	}

	pQue->data[pQue->rear % pQue->capacity] = value;
	pQue->rear++;
	pQue->size++; //���� ������ 1����

	//pQue->data[pQue->rear++] = value;
	//pQue->size++; //���� ������ 1����

	//if (pQue->rear == pQue->capacity) //������ �ε����� �����ϸ�?? 
	//	pQue->rear = 0; //�ε����� 0���� �缳��
}

int dequeue(queue* pQue)
{
	int delVal;

	//if (pQue->size == 0) //����� ������ ���� ���??
	if (isQueueEmpty(pQue))
		return -1; //���� ����

	delVal = pQue->data[pQue->front % pQue->capacity]; //������ �� ���� ��, front 1 ����
	pQue->front++;
	pQue->size--; //���� ������ 1����	

	//delVal = pQue->data[pQue->front++]; //������ �� ���� ��, front 1 ����
	//pQue->size--; //���� ������ 1����	

	//if (pQue->front == pQue->capacity) //������ �ε����� �����ϸ�??
	//	pQue->front = 0; //�ε����� 0���� �缳��

	return delVal; //������ �� ����
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

	//����� ����(size)��ŭ �ݺ��ϸ鼭 ���
	for (i = pQue->front; i < pQue->front + pQue->size; i++)
	{
		printf("%d ", pQue->data[i % pQue->capacity]); //[4 % 5][5 % 5][6 % 5]
	}
	puts("");
}

void queueClear(queue* pQue)
{
	//�������� ������ ��ó�� �ڵ� ����(�������� �������� ������ �̷����� �ʴ´�.)
	pQue->rear = 0;
	pQue->front = 0;
	pQue->size = 0;
}

int isQueueFull(queue* pQue)
{
	//if (pQue->size == pQue->capacity) //����á�ٸ�??
	//	return 1;
	//else
	//	return 0;

	return pQue->size == pQue->capacity;
}

int isQueueEmpty(queue* pQue)
{
	return pQue->size == 0;
}