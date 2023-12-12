#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef struct tagDisj○intset
{
	struct tagDisj○intset* Parent;
	int Data;
} Disj○intset;


int main()
{
    std::cout << "Hello World!\n";
    int n{};
    int m{};
    cin >> n>>m;


	int* setParent = new int[n + 1];
	int** set = new int* [n + 1];
	////
	for (int i = 0; i <= n; i++) {
		setParent[i] = i;
		*set[i] = setParent[i];
	}
	

	while (--m) //맨처음에 입력받은 N 만큼 입력을 받고 저장 해두기
	{
		int first ,second,third;
		cin >> first >> second >> third;
		//입력받는 값이 0,1 이냐에 따라 다른 함수 구현하기 
		if (first == 0)
		{

		}
		else
		{

		}
	}

	

}

//집합을 합치는 함수 => 실제로 안합치고 부모 포인터만 설정해줌
void UnionSet(int a, int b)
{
	// a , b를 받아서 더 작은 값 쪽으로 더 큰값의 부모를 변경해줌

}

void FindParent(int x)
{

}

//두원소가 같은 집합에 포함되어있는지를 확인하는 함수 
//두원소가 포함되어있는 집합을 찾고 부모가 같은지 다른지 비교하기
