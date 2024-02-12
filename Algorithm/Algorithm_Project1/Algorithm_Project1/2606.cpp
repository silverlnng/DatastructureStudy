#include <iostream>
#include <stdlib.h> 

using namespace std;

typedef struct graph
{
	int verCount; //������ ����
	int** arr; //���� �Ҵ� �� 2���� �迭�� �ּ� ����
}graph;

void graphInitialize(graph* p, int count)
{
	int i;
	p->verCount = count;
	p->arr = (int**)malloc(sizeof(int*) * count); // <= ������ �迭�� �Ҵ��� ��

	// <= �̰� 1���� �迭�� �Ҵ��� ��
	for (i = 0; i < count; i++)
		//p->arr[i] = (int*)malloc(sizeof(int) * count);	
		p->arr[i] = (int*)calloc(count, sizeof(int)); //calloc(����, ����Ʈũ��);

}
void addUndirectedEdge(graph* p, int src, int dest) //������ �׷���
{
	p->arr[src][dest] = 1;
	p->arr[dest][src] = 1;
	// �������� ������̴ϱ� 0,1 �̳� 1,0�̳� �Ȱ��� 
}

void display(graph* p)
{
	int i, j;

	printf("\n\n *** ���� ���� ��Ȳ ***\n\n");
	for (i = 0; i < p->verCount; i++) //vertex�� ������ŭ �ݺ�
	{
		printf("����� %d => ", i);
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
	// �� 2���� �迭���� ���� ����� ��!!
	for (i = 0; i < p->verCount; i++)
	{
		printf("%d�� ���� �޸� ����\n", i);
		free(p->arr[i]); //free(������); �����Ͱ� ����Ű�� �޸𸮰� ����
	}

	free(p->arr);
	printf("������ �迭 ���� �޸� ����\n");
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

	//��ºκ�


	return 0;
}


