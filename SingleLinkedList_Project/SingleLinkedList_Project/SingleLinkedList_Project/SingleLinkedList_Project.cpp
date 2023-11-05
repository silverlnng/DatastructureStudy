// SingleLinkedList_Project.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct node
{
	int value; //값
	struct node* next; // 다음 노드의 주소를 저장하는 포인터 변수(8byte)
}node; //연결 리스트의 저장 단위

node* head = NULL; //첫 노드의 주소를 저장하는 포인터 //전역변수 //어디서든 접근 가능한 변수

void insertNodeFront(int data);
void displayNode();
int getNodeCount();
void removeNodeFront();
void removeNodeAll();
node* searchNode(int target);
int inputInteger();
void insertNodeTail(int data);
int removeNodeKth(int k);
int insertNodeKth(int data, int k);
int insertNodeAscend(int data);
void removeNodeTail();
int removeNoveValue(int data);

int main()
{
	int choice, value, k;
	node* findNode; //검색한 노드의 주소를 저장하는 포인터(8바이트)
	while (1)
	{
		system("cls");
		printf("\n\n  *** 단일 연결 리스트(Singly Linked List) ***\n\n");
		printf("=====================================\n");
		printf(" 1. 맨 앞 삽입\n");
		printf(" 2. 맨 뒤 삽입\n");
		printf(" 3. 앞에서부터 K번째 삽입\n");
		printf(" 4. 오름차순 정렬 삽입\n");
		printf("=====================================\n");
		printf(" 5. 첫 노드 제거\n");
		printf(" 6. 마지막 노드 제거\n");
		printf(" 7. 전체 노드 제거\n");
		printf(" 8. 특정 값 제거\n");
		printf(" 9. 앞에서부터 K번째 노드 제거\n");
		printf("=====================================\n");
		printf("10. 단일 연결 리스트 출력(노드 순회)\n");
		printf("11. 노드의 개수 구하기\n");
		printf("12. 노드 검색\n");
		printf(" 0. 프로그램 종료\n");
		printf("=====================================\n");
		printf("\n메뉴 선택 : ");
		scanf("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case 1:
			value = inputInteger(); //정수 입력 함수 호출
			insertNodeFront(value); //맨 앞에 노드를 추가하는 함수
			break;
		case 2:
			value = inputInteger(); //정수 입력 함수 호출
			insertNodeTail(value); //맨 뒤에 노드를 추가하는 함수
			break;
		case 3:
			printf("\n\n앞에서부터 몇 번째 노드를 삽입 하시겠습니까? ");
			scanf("%d", &k);
			while (getchar() != '\n');

			value = inputInteger(); //정수 입력 함수 호출

			//insertNodeKth : 삽입 성공 시 1 리턴, 실패 시 0리턴
			if (insertNodeKth(value, k))
				printf("\n\n\t\t노드가 %d번째에 삽입 됐습니다.\n", k);
			else
				printf("\n\n\t\t노드 삽입을 실패 했습니다.\n");
			break;
		case 4:
			value = inputInteger(); //정수 입력 함수 호출

			//insertNodeAscend : 삽입 성공 시 1 리턴, 실패 시 0리턴
			if (insertNodeAscend(value))
				printf("\n\n\t\t오름차순 정렬 삽입했습니다.\n");
			else
				printf("\n\n\t\t오름차순 정렬 삽입을 실패 했습니다.\n");
			break;
		case 5:
			removeNodeFront();
			break;
		case 6:
			removeNodeTail();
			break;
		case 7:
			removeNodeAll();
			break;
		case 8:
			printf("\n\n삭제 할 값을 입력 하세요 : ");
			scanf("%d", &value);
			while (getchar() != '\n');

			if (removeNoveValue(value))
				printf("\n\n\t\t삭제를 성공했습니다.\n");
			else
				printf("\n\n\t\t삭제를 실패했습니다.\n");
			break;
		case 9:
			printf("\n\n\t\t몇 번째 노드를 삭제 하시겠습니까? ");
			scanf("%d", &value);
			while (getchar() != '\n');
			//removeNodeKth함수 : 삭제 성공 시 1리턴, 삭제 실패 시 0리턴
			if (removeNodeKth(value))
				printf("\n\n\t\t삭제를 성공 했습니다.\n");
			else
				printf("\n\n\t\t삭제를 실패 했습니다.\n");
			break;
		case 10:
			displayNode();
			break;
		case 11:
			//getNodeCount함수 : 노드의 개수를 구해 리턴하는 함수
			printf("\n\n\t\t생성된 노드의 개수는  %d개 입니다.\n", getNodeCount());
			break;
		case 12:
			printf("\n\n검색할 정수 입력 : ");
			scanf("%d", &value);
			while (getchar() != '\n');

			//searchNode함수 :  검색 노드가 있다면 검색 노드의 주소를 리턴, 검색 노드가 없다면 NULL을 리턴
			findNode = searchNode(value);
			if (findNode == NULL)
				printf("\n\n\t\t검색한 노드는 존재하지 않습니다.\n");
			else
				printf("\n\n\t\t검색한 노드의 주소는 %p입니다.\n", findNode);
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

//O(1) : 상수 시간의 복잡도 : 생성된 노드의 개수와 상관 없이 일정한 횟수의 연산으로 문제 해결
void insertNodeFront(int data)
{
	//newNode포인터 : 새로 생성된 구조체 변수(노드)의 주소를 저장(8byte)
	node* newNode = (node*)malloc(sizeof(node)); //노드 생성
	newNode->value = data;
	newNode->next = NULL;

	if (head == NULL) //아직 연결 된 노드가 없다면???
	{
		head = newNode;//새로 생성된 노드의 주소를 head에 저장
		printf("\n\n\t\t노드 맨 앞 삽입 : 첫 노드로 연결\n");
		return; //함수 종료
	}

	//맨 앞에 노드를 추가
	newNode->next = head;
	head = newNode;
	printf("\n\n\t\t노드 맨 앞 삽입 : 일반적인 경우\n");
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

void removeNodeFront() //O(1) : 생성된 노드의 개수와 상관 없이 일정한 횟수의 연산으로 문제 해결
{
	node* delNode; //삭제할 노드의 주소를 저장하는 포인터(8바이트)
	//맨 앞 노드 삭제
	if (head == NULL)
	{
		printf("\n\n\t\t연결 리스트가 구성 되지 않아 삭제할 노드가 없습니다.\n");
		return;
	}

	delNode = head; //1. 첫 노드를 삭제할 노드로 설정
	head = head->next; //2. head를 다음 노드로 변경
	free(delNode); //free(포인터); //포인터가 가리키는 메모리 제거 //3. 첫 노드를 제거

	printf("\n\n\t\t첫 노드를 제거 했습니다.\n");
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

node* searchNode(int target)
{
	node* curNode;
	if (head == NULL)
		return NULL;

	//순회하면서 target을 검색해서 노드의 주소를 리턴
	curNode = head;
	while (curNode != NULL) //방문한 노드가 있다면??
	{
		if (curNode->value == target)
		{
			return curNode; //노드의 주소를 리턴
		}

		curNode = curNode->next; //방문한 노드를 이동
	}

	return NULL; //검색한 값이 없는 경우
}

int inputInteger()
{
	int value;
	printf("\n삽입 할 정수 입력 : ");
	scanf("%d", &value);
	while (getchar() != '\n');

	return value; //입력 값 리턴
}

void insertNodeTail(int data) //O(N)
{
	node* curNode;
	node* newNode = (node*)malloc(sizeof(node)); //구조체 변수 선언(노드 생성)
	newNode->value = data;
	newNode->next = NULL;

	if (head == NULL) //연결리스트가 구성 되지 않은 상태??
	{
		head = newNode; //새로 생성된 노드를 head로 설정
		printf("\n\n\t\t1. 노드 맨 뒤 삽입 : 첫 노드로 연결");
		return;
	}

	curNode = head;
	while (curNode->next != NULL) //방문한 노드의 다음 노드가 있다면??? 
	{
		curNode = curNode->next; //다음 노드로 이동
	}

	curNode->next = newNode; //마지막 노드에 새로 생성된 노드를 연결
	printf("\n\n\t\t2. 노드 맨 뒤 삽입 : 일반적인 경우 순회한 뒤 삽입");
}

int removeNodeKth(int k)
{
	int i;
	node* delNode, * prevNode;
	//case 1. head가 NULL인 경우
	if (head == NULL)
	{
		printf("\n\n\t\t1. k번째 노드 제거 : 연결리스트가 구성되지 않은 경우 삭제 실패\n");
		return 0;
	}

	//case 2. k == 1인 경우 -> head가 변경돼야 하기 때문에
	if (k == 1)
	{
		//첫 노드 제거
		delNode = head;
		head = head->next;
		free(delNode);
		printf("\n\n\t\t2. k번째 노드 제거 : 첫 노드 제거 삭제 성공\n");
		return 1;
	}

	//case 3. 일반적인 경우
	//prevNode를 삭제할 이전 노드에서 멈춤
	prevNode = head;
	for (i = 1; i < k - 1; i++)
		prevNode = prevNode->next;

	delNode = prevNode->next; //삭제할 노드를 설정

	//재연결
	prevNode->next = delNode->next;
	free(delNode);
	printf("\n\n\t\t3. k번째 노드 제거 : 일반적인 경우(마지막 노드 포함) 삭제 성공\n");
	return 1;
}

int insertNodeKth(int data, int k)
{
	node* newNode, * curNode;
	int i;

	int count = getNodeCount(); //노드의 개수를 구해 리턴하는 함수

	if (k < 1 || k > count + 1)
	{
		printf("\n\n\t\tK번째 노드는 삽입 할 수 없는 위치 입니다.\n");
		printf("\t\t1 ~ %d번째 노드까지 삽입할 수 있습니다.\n", count + 1);
		return 0; //삽입 실패
	}

	newNode = (node*)malloc(sizeof(node)); //구조체 변수(노드) 생성
	newNode->value = data;
	newNode->next = NULL;


	//case 1. head가 NULL인 경우
	if (head == NULL)
	{
		head = newNode;
		printf("\n\n\t\tcase 1. %d번째 노드 연결\n", k);
		return 1; //삽입 성공
	}

	//case 2. k == 1인 경우 => head값이 변경돼야 하기 때문에
	if (k == 1)
	{
		newNode->next = head;
		head = newNode;
		printf("\n\n\t\tcase 2. %d번째 노드 연결\n", k);
		return 1;
	}

	//case 3. 일반적인 경우 => 중간 삽입 => 순회!!!
	curNode = head;
	for (i = 1; i <= k - 2; i++) //삽입 위치 전에서 curNode 멈춤
		curNode = curNode->next;

	//연결
	newNode->next = curNode->next;
	curNode->next = newNode;
	printf("\n\n\t\tcase 3. %d번째 노드 연결(마지막 노드까지 포함)\n", k);
	return 1; //삽입 성공
}

int insertNodeAscend(int data)
{
	node* newNode, * curNode, * prevNode;
	newNode = (node*)malloc(sizeof(node));//구조체 변수(노드) 생성
	newNode->value = data;
	newNode->next = NULL;

	//case 1. head가 NULL인 경우
	if (head == NULL)
	{
		head = newNode;
		printf("\n\n\t\tcase 1. 오름차순 정렬 삽입 : head == NULL\n");
		return 1; //삽입 성공
	}

	//case 2. 가장 작은 값 삽입
	if (head->value > newNode->value) //첫 노드의 값 > 새 노드의 값
	{
		newNode->next = head;
		head = newNode;
		printf("\n\n\t\tcase 2. 오름차순 정렬 삽입 : 가장 작은 값 삽입 => head변경\n");
		return 1;
	}

	//case 3. 일반적인 경우
	prevNode = curNode = head;
	while (curNode->next != NULL)
	{
		curNode = curNode->next;
		if (curNode->value > newNode->value)
		{
			//연결
			newNode->next = curNode;
			prevNode->next = newNode;
			printf("\n\n\t\tcase 3. 오름차순 정렬 삽입 : 일반적인 경우\n");
			return 1;
		}
		prevNode = prevNode->next;
	}

	//case 4. 가장 큰 값을 삽입한 경우
	curNode->next = newNode;
	printf("\n\n\t\tcase 4. 오름차순 정렬 삽입 : 가장 큰 값 삽입\n");
	return 1;
}
void removeNodeTail()
{
	node* curNode;
	//case 1. 노드가 없는 경우?
	if (head == NULL)
		return;

	//case 2. 노드가 한 개인 경우?
	if (head->next == NULL)
	{
		free(head);//노드 제거
		head = NULL;
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
	free(curNode->next); //free(포인터);
	curNode->next = NULL; //이전 노드의 다음은 NULL
	printf("\n\n\t\tcase 1. 맨 뒤 노드 제거 : 일반적인 경우\n");
}

int removeNoveValue(int data)
{
	node* delNode, * prevNode;
	//case 1. 노드가 없는 경우
	if (head == NULL)
		return 0;

	//case 2. 삭제할 노드가 첫 노드인 경우
	if (head->value == data)
	{
		delNode = head;
		head = head->next;
		free(delNode); //첫노드 제거
		printf("\n\n\t\t특정 값 삭제 : 첫 노드 제거 => head 변경\n");
		return 1;
	}

	//case 3. 일반적인 경우(중간 제거)
	prevNode = delNode = head;

	while (delNode->next != NULL) //삭제할 노드의 다음 노드가 있다면?
	{
		delNode = delNode->next; //삭제할 노드 이동
		if (delNode->value == data) //삭제할 노드야??
		{
			//연결 후, 제거
			prevNode->next = delNode->next;
			free(delNode);
			printf("\n\n\t\t특정 값 삭제 : 일반적인 경우(마지막 노드 포함)\n");
			return 1;
		}
		prevNode = prevNode->next;
	}

	return 0; //삭제할 값이 존재하지 않는 경우 삭제 실패
}