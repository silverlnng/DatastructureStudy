#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef struct tagDisj��intset
{
	struct tagDisj��intset* Parent;
	int Data;
} Disj��intset;


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
	

	while (--m) //��ó���� �Է¹��� N ��ŭ �Է��� �ް� ���� �صα�
	{
		int first ,second,third;
		cin >> first >> second >> third;
		//�Է¹޴� ���� 0,1 �̳Ŀ� ���� �ٸ� �Լ� �����ϱ� 
		if (first == 0)
		{

		}
		else
		{

		}
	}

	

}

//������ ��ġ�� �Լ� => ������ ����ġ�� �θ� �����͸� ��������
void UnionSet(int a, int b)
{
	// a , b�� �޾Ƽ� �� ���� �� ������ �� ū���� �θ� ��������

}

void FindParent(int x)
{

}

//�ο��Ұ� ���� ���տ� ���ԵǾ��ִ����� Ȯ���ϴ� �Լ� 
//�ο��Ұ� ���ԵǾ��ִ� ������ ã�� �θ� ������ �ٸ��� ���ϱ�
