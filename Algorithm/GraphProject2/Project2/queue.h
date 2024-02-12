#pragma once
#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct queue
{
	//int data[5];
	int* data;		//�����Ҵ�� �޸��� �ּҸ� �����ϴ� ������(8����Ʈ)
	int rear;		//������ �迭�� �ε���
	int front;		//������ �迭�� �ε���
	int size;		//�迭�� ����� ������ ����
	int capacity;	//�迭�� �ִ� �뷮(�迭�� ũ��)
}queue;

void createQueue(queue* pQue, int count);
void enqueue(queue* pQue, int value);
int dequeue(queue* pQue);
void queuePrint(queue* pQue);
void queueClear(queue* pQue);
int isQueueFull(queue* pQue); //ť�� ���� á�ٸ� �ִٸ� 1, �ƴ϶�� 0����
int isQueueEmpty(queue* pQue); //ť�� ��� �ִٸ� 1, �ƴ϶�� 0����

