#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

#pragma warning (disable : 4996)

//연결 리스트(인접 리스트)를 이용한 간선 저장
typedef struct node
{
	int value;
	struct node* next;
}node;

typedef struct graph
{
	node* head; //출발 노드의 주소를 저장하는 포인터
	int vertexCount; //정점의 개수
}graph;

void createGraph(graph* pGrp, int count);
void unDirectedEdge(graph* pGrp, int src, int dest);
void directedEdge(graph* pGrp, int src, int dest);
void displayEdge(graph* pGrp);
void memoryFree(graph* pGrp);
void DFS_stack(graph* pGrp, int src);
void BFS_queue(graph* pGrp, int src);
void DFS_reculsive(graph* pGrp, int src);
void DFS_calc(graph* pGrp, int src, int* visisted);

int main()
{
	graph grp; //구조체 변수 선언

	createGraph(&grp, 10);

	unDirectedEdge(&grp, 0, 1); //무방향그래프의 간선 저장
	unDirectedEdge(&grp, 0, 2); //무방향그래프의 간선 저장
	unDirectedEdge(&grp, 0, 3); //무방향그래프의 간선 저장
	unDirectedEdge(&grp, 1, 2); //무방향그래프의 간선 저장
	unDirectedEdge(&grp, 1, 4); //무방향그래프의 간선 저장
	unDirectedEdge(&grp, 2, 3); //무방향그래프의 간선 저장
	unDirectedEdge(&grp, 2, 4); //무방향그래프의 간선 저장
	unDirectedEdge(&grp, 2, 5); //무방향그래프의 간선 저장
	unDirectedEdge(&grp, 3, 5); //무방향그래프의 간선 저장
	unDirectedEdge(&grp, 4, 5); //무방향그래프의 간선 저장
	unDirectedEdge(&grp, 4, 8); //무방향그래프의 간선 저장
	unDirectedEdge(&grp, 5, 6); //무방향그래프의 간선 저장
	unDirectedEdge(&grp, 6, 7); //무방향그래프의 간선 저장
	unDirectedEdge(&grp, 6, 8); //무방향그래프의 간선 저장
	unDirectedEdge(&grp, 7, 8); //무방향그래프의 간선 저장
	unDirectedEdge(&grp, 8, 9); //무방향그래프의 간선 저장

	displayEdge(&grp);

	DFS_stack(&grp, 0); //출발정점을 넘김
	BFS_queue(&grp, 0);
	DFS_reculsive(&grp, 0);

	memoryFree(&grp);

	return 0;
}

void createGraph(graph* pGrp, int count)
{
	int i;
	pGrp->vertexCount = count;
	pGrp->head = (node*)malloc(sizeof(node) * count);//출발정점 노드 생성

	for (i = 0; i < count; i++) //정점의 개수만큼 반복
	{
		pGrp->head[i].value = i; //출발정점의 값을 저장
		pGrp->head[i].next = NULL; //출발정점의 다음 노드는 NULL(도착지가 없음)
	}
}

void directedEdge(graph* pGrp, int src, int dest)
{
	//방향 그래프
	node* newNode;
	newNode = (node*)malloc(sizeof(node)); //도착지 노드 생성
	newNode->value = dest;
	newNode->next = NULL;

	if (pGrp->head[src].next == NULL) //첫노드로 연결되는거야??
	{
		pGrp->head[src].next = newNode;
		return;
	}
	//이미 연결된 도착지가 있는 경우??? 맨 앞 추가 => O(1)
	newNode->next = pGrp->head[src].next;
	pGrp->head[src].next = newNode;
}

void unDirectedEdge(graph* pGrp, int src, int dest)
{
	//무방향 그래프 : 양방향 : 방향그래프가 2개
	directedEdge(pGrp, src, dest); //방향그래프1
	directedEdge(pGrp, dest, src); //방향그래프2
}

void displayEdge(graph* pGrp)
{
	//연결리스트 순회
	int i;
	node* curNode;

	for (i = 0; i < pGrp->vertexCount; i++)
	{
		printf("출발지 정점 : %d => ", pGrp->head[i].value);
		curNode = pGrp->head[i].next;
		while (curNode != NULL)
		{
			printf("%4d", curNode->value);
			curNode = curNode->next;
		}
		puts("");
	}
}

void memoryFree(graph* pGrp)
{
	node* delNode;
	int i;

	for (i = 0; i < pGrp->vertexCount; i++)
	{
		while (pGrp->head[i].next != NULL)
		{
			delNode = pGrp->head[i].next; //첫 노드를 삭제할 노드로 설정
			pGrp->head[i].next = delNode->next; //head를 변경
			printf("도착지 노드 %d제거\n", delNode->value);
			free(delNode); //delNode제거
		}
	}

	printf("출발지 노드 배열 제거\n");
	free(pGrp->head); //head가 가리키는 메모리를 제거
}

void DFS_stack(graph* pGrp, int src)
{
	//1. push -> 방문체크
	//2. 스택이 비어 있는지 확인???
	//3. 비어있지 않다면??? pop -> 순회(출력)

	node* curNode;
	int popValue; //삭제된 값 저장
	//int*visited = (int*)malloc(sizeof(int) * pGrp->vertexCount); //boolean visited array
	int* visited = (int*)calloc(pGrp->vertexCount, sizeof(int)); //boolean visited array
	stack stk; //구조체 변수 선언(스택 생성)
	createStack(&stk, pGrp->vertexCount); //스택 초기화

	push(&stk, src); //출발 정점 push
	visited[src] = 1; //방문체크
	printf("DFS(Depth First Search) with Stack : ");

	while (!isStackEmpty(&stk)) //스택이 비어 있다면? 1을 리턴
	{
		popValue = pop(&stk); //스택 pop
		printf("%d ", popValue); //꺼내면서 출력!!!
		curNode = pGrp->head[popValue].next; //인접 정점 방문

		while (curNode != NULL)
		{
			if (visited[curNode->value] == 0) //방문한 적이 없어??
			{
				push(&stk, curNode->value);//push
				visited[curNode->value] = 1; //방문체크
			}
			curNode = curNode->next;
		}
	}
	puts("");
	free(stk.data); //스택 메모리 제거
	free(visited); //방문 배열 제거
}
void BFS_queue(graph* pGrp, int src)
{
	//1. enqueue -> 방문체크
	//2. 큐가 비어 있는지 확인???
	//3. 비어있지 않다면??? dequeue -> 순회(출력)

	node* curNode;
	int popValue; //삭제된 값 저장
	//int*visited = (int*)malloc(sizeof(int) * pGrp->vertexCount); //boolean visited array
	int* visited = (int*)calloc(pGrp->vertexCount, sizeof(int)); //boolean visited array
	queue que; //구조체 변수 선언(큐 생성)
	createQueue(&que, pGrp->vertexCount);

	enqueue(&que, src); //출발 정점 enqueue
	visited[src] = 1; //방문체크
	printf("BFS(Breadth First Search) with Queue : ");

	while (!isQueueEmpty(&que)) //큐가 비어 있다면? 1을 리턴
	{
		popValue = dequeue(&que); //큐에서 dequeue
		printf("%d ", popValue); //꺼내면서 출력!!!
		curNode = pGrp->head[popValue].next; //인접 정점 방문

		while (curNode != NULL) //인접 정점 노드가 있다면??
		{
			if (visited[curNode->value] == 0) //방문한 적이 없어??
			{
				enqueue(&que, curNode->value);//enqueue
				visited[curNode->value] = 1; //방문체크
			}
			curNode = curNode->next;
		}
	}
	puts("");
	free(que.data); //큐 메모리 제거
	free(visited); //방문 배열 제거
}

void DFS_reculsive(graph* pGrp, int src)
{
	int* visited = (int*)calloc(pGrp->vertexCount, sizeof(int));

	printf("DFS with reculsive call : ");
	printf("%d ", pGrp->head[src].value); //방문(출력)

	DFS_calc(pGrp, src, visited); //재귀호출 함수
	puts("");
	free(visited); //방문 배열 제거
}

void DFS_calc(graph* pGrp, int src, int* visited)
{
	node* curNode;

	visited[src] = 1; //출발지 방문 체크

	curNode = pGrp->head[src].next; //도착지
	while (curNode)//도착지가 있다면???
	{
		if (visited[curNode->value] == 0)
		{
			printf("%d ", curNode->value);//도착지가 방문(출력)
			DFS_calc(pGrp, curNode->value, visited); //도착지가 출발지가 되도록 재귀호출
		}
		curNode = curNode->next;
	}
}