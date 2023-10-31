
#include <iostream>
#include "Stack_Project_Array.h"

int main()
{
    std::cout << "Hello World!\n";
}

//스택의 생성
void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
    //스택을 자유저장소에 생성
    *Stack = new ArrayStack;

    //입력된 capacity 만큼의 노드를 자유저장소에 생성
    //이때 Nodes가 Node*(노드를 가르키는 포인터)
    (*Stack)->Nodes = new Node[Capacity];

    //capacity 및 top 초기화 
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = 0;

}

void AS_DestroyStack(ArrayStack* Stack)
{
    delete Stack->Nodes;

    delete Stack;
}

//삽입연산 
void AS_Push(ArrayStack* Stack, ElementType Data)
{
    int Position = Stack->Top;  //초기화 해놔서 맨처음 이라면 Stack->Top ="0"

    Stack->Nodes[Position].Data = Data;

    Stack->Top++;

}

//제거연산
ElementType AS_Pop(ArrayStack* Stack)
{
    int Position = --(Stack->Top);

    return Stack->Nodes[Position].Data;
    //제거연산은 최상위 노드의 데이터를 호출자에게 반환 ????
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
