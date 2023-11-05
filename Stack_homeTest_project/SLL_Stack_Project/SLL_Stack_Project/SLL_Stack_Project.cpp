// SLL_Stack_Project.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value; //값
	struct node* next; // 다음 노드의 주소를 저장하는 포인터 변수(8byte)
}node; //연결 리스트의 저장 단위

node* head = NULL; //첫 노드의 주소를 저장하는 포인터 //전역변수 //어디서든 접근 가능한 변수
node* top = NULL; //스택의 top을 저장할 포인터 ==리스트에서는 tail 이다

void insertNodeTail(int data);
void removeNodeTail();
void displayNode();
int inputInteger();
int getNodeCount();
void removeNodeAll();

int main()
{
	int choice, value, k;
	node* findNode; //검색한 노드의 주소를 저장하는 포인터(8바이트)
	while (1)
	{
		system("cls");
		printf("\n\n  *** 단일 연결 리스트(Singly Linked List) ***\n\n");
		printf("=====================================\n");
		printf(" 2. 맨 뒤 삽입\n");
		printf("=====================================\n");
		printf(" 6. 마지막 노드 제거\n");
		printf("=====================================\n");
		printf("10. 단일 연결 리스트 출력(노드 순회)\n");
		printf("11. 노드의 개수 구하기\n");
		printf(" 0. 프로그램 종료\n");
		printf("=====================================\n");
		printf("\n메뉴 선택 : ");
		scanf_s("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case 2:
			value = inputInteger(); //정수 입력 함수 호출
			insertNodeTail(value); //맨 뒤에 노드를 추가하는 함수
			break;		
		case 6:
			removeNodeTail();
			break;		
		case 10:
			displayNode();
			break;
		case 11:
			//getNodeCount함수 : 노드의 개수를 구해 리턴하는 함수
			printf("\n\n\t\t생성된 노드의 개수는  %d개 입니다.\n", getNodeCount());
			break;		
		case 0:
			removeNodeAll(); //memory leak을 방지하기 위해 생성 된 노드 모두 제거
			exit(0); //프로그램 강제 종료
		}//end switch

		//switch문을 빠져 나오면 일시 대기 시킨다.
		printf("\n\n\t\t");
		system("pause"); //일시 대기

	}//end while
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

void insertNodeTail(int data) //O(N)//스택에서 push는 tail 맨뒤에 하나씩 붙여주고 이게 top이 된다
{
	node* curNode;
	node* newNode = new node; //구조체 변수 선언(노드 생성)
	newNode->value = data;
	newNode->next = NULL;

	if (head == NULL) //연결리스트가 구성 되지 않은 상태??
	{
		head = newNode; //새로 생성된 노드를 head로 설정
		top = newNode;
		printf("\n\n\t\t1. 노드 맨 뒤 삽입 : 첫 노드로 연결");
		return;
	}

	curNode = head;
	while (curNode->next != NULL) //방문한 노드의 다음 노드가 있다면??? 
	{
		curNode = curNode->next; //다음 노드로 이동
	}

	curNode->next = newNode; //마지막 노드에 새로 생성된 노드를 연결
	top = newNode;			//스택의 top을 제일 최근에 들어온 노드로 설정하기
	printf("\n\n\t\t2. 노드 맨 뒤 삽입 : 일반적인 경우 순회한 뒤 삽입");
}

void removeNodeTail()	//스택에서 pop은 top =tail 만 지울수있음
{
	node* curNode;
	//case 1. 노드가 없는 경우?
	if (head == NULL)
		return;

	//case 2. 노드가 한 개인 경우?
	if (head->next == NULL)
	{
		delete head;//노드 제거
		head = NULL;
		top = NULL;
		printf("\n\n\t\tcase 1. 맨 뒤 노드 제거 : 노드가 한 개인 경우\n");
		return;
	}

	//case 3. 일반적인 경우
	curNode = head;

	//마지막 노드 이전에서 멈춤
	while (curNode->next->next != NULL)
	{
		curNode = curNode->next;
	}

	//마지막 노드 제거
	delete curNode->next; //free(포인터);
	curNode->next = NULL; //이전 노드의 다음은 NULL
	top = curNode;
	printf("\n\n\t\tcase 1. 맨 뒤 노드 제거 : 일반적인 경우\n");
}

void displayNode() //O(N) : 노드의 개수만큼 반복 : 순회 코드는 무조건 O(N)
{
	node* curNode; //방문 노드의 주소를 저장하는 포인터(8바이트)

	if (head == NULL) //아직 연결 된 노드가 없다면???
	{
		printf("\n\n\t\t연결리스트가 구성 되지 않아 출력 할 노드가 없습니다.\n");
		return;
	}

	printf("\n\nSingly Linked List Display : ");

	//head포인터 : 첫 노드의 주소를 저장하는 포인터
	curNode = head; //첫 노드의 주소를 저장
	while (curNode->next != NULL) //방문한 노드의 다음 노드가 있다면? 반복! //마지막 노드는 포함 되지 않는다.
	{
		printf("%d => ", curNode->value);
		curNode = curNode->next;
	}
	printf("%d\n", curNode->value); //마지막 노드를 출력

	/*printf("%d ", curNode->value);
	curNode = curNode->next;

	printf("%d ", curNode->value);
	curNode = curNode->next;

	printf("%d ", curNode->value);
	curNode = curNode->next;*/


}

int inputInteger()
{
	int value;
	printf("\n삽입 할 정수 입력 : ");
	scanf_s("%d", &value);
	while (getchar() != '\n');

	return value; //입력 값 리턴
}


int getNodeCount() //O(N)
{
	//int count = 0;
	//node* curNode; //방문 노드의 주소를 저장하는 포인터(8바이트)
	//if(head == NULL)
	//	return 0; //개수는 0개

	//curNode = head; //첫 노드의 주소를 방문 노드로 설정

	//마지막 노드는 while문을 수행하지 않는다.
	//while (curNode->next != NULL) //방문 노드의 다음 노드가 있다면???
	//{	
	//	++count; //개수를 증가
	//	curNode = curNode->next;
	//}

	//return count + 1; //마지막 노드의 개수를 1 포함


	int count = 0;
	node* curNode; //방문 노드의 주소를 저장하는 포인터(8바이트)
	if (head == NULL)
		return 0; //개수는 0개

	curNode = head; //첫 노드의 주소를 방문 노드로 설정

	while (curNode != NULL) //방문 노드가 있다면???
	{
		++count; //개수를 증가
		curNode = curNode->next;
	}

	return count;
}

void removeNodeAll()
{
	node* delNode;
	if (head == NULL)
	{
		printf("\n\n\t\t연결 리스트가 구성 되지 않아 삭제할 노드가 없습니다.\n");
		return;
	}

	while (head != NULL) //첫 노드가 있다면???
	{
		//첫노드 제거
		delNode = head;
		head = head->next;
		free(delNode);
	}
	printf("\n\n\t\t모든 노드를 제거했습니다.\n");
}