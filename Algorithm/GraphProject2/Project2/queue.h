#pragma once
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
int isQueueFull(queue* pQue); //큐가 가득 찼다면 있다면 1, 아니라면 0리턴
int isQueueEmpty(queue* pQue); //큐가 비어 있다면 1, 아니라면 0리턴

