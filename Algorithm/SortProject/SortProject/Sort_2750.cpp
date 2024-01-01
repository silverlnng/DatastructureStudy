#include <iostream>
#include <string.h>
using namespace std;
//ù° �ٿ� ���� ���� N(1 �� N �� 1,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���� �־�����. �� ���� ������ 1,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

void insertion(int* pArr, int size);
void display(int* pArr, int size);

int main()
{
	int N{};
	cin >> N;

	int* array = new int[N];
	
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		array[i] = temp;
	}

	insertion(array, N);
	display(array, N);
	delete array;
	return 0;
}

void insertion(int* pArr, int size)
{
	int i, j, temp;

	for (i = 1; i < size; i++)
	{
		temp = pArr[i];
		for (j = i; j > 0 && (pArr[j - 1] > temp); j--)
		{
			pArr[j] = pArr[j - 1];
		}
		pArr[j] = temp;
	}
}

void display(int* pArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << pArr[i] << endl;
	}
}