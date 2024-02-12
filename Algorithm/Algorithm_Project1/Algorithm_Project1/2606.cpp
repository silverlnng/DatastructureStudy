#include <iostream>
#include <stdlib.h> 

using namespace std;

typedef struct graph
{
	int verCount; //정점의 개수
	int** arr; //동적 할당 된 2차원 배열의 주소 저장
}graph;

void graphInitialize(graph* p, int count)
{
	int i;
	p->verCount = count;
	p->arr = (int**)malloc(sizeof(int*) * count); // <= 포인터 배열을 할당한 것

	// <= 이건 1차원 배열을 할당한 것
	for (i = 0; i < count; i++)
		//p->arr[i] = (int*)malloc(sizeof(int) * count);	
		p->arr[i] = (int*)calloc(count, sizeof(int)); //calloc(개수, 바이트크기);

}
void addUndirectedEdge(graph* p, int src, int dest) //무방향 그래프
{
	p->arr[src][dest] = 1;
	p->arr[dest][src] = 1;
	// 무방향은 양방향이니까 0,1 이나 1,0이나 똑같은 
}

void display(graph* p)
{
	int i, j;

	printf("\n\n *** 간선 연결 현황 ***\n\n");
	for (i = 0; i < p->verCount; i++) //vertex의 개수만큼 반복
	{
		printf("출발지 %d => ", i);
		for (j = 0; j < p->verCount; j++)
		{
			printf("%d ", p->arr[i][j]);
		}
		puts("");
	}
}

void memoryFree(graph* p)
{
	int i;
	// 꼭 2차원 배열부터 해제 해줘야 함!!
	for (i = 0; i < p->verCount; i++)
	{
		printf("%d행 동적 메모리 해제\n", i);
		free(p->arr[i]); //free(포인터); 포인터가 가리키는 메모리가 해제
	}

	free(p->arr);
	printf("포인터 배열 동적 메모리 해제\n");
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	graph grp;

	int vertex, edgeCount;

	cin >> vertex;

	graphInitialize(&grp, vertex);

	cin >> edgeCount;

	while (--edgeCount)
	{
		int from, to;
		cin >> from>> to;
		addUndirectedEdge(&grp, from, to);
	}

	//출력부분


	return 0;
}


