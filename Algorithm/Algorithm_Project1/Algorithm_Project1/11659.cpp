#include <iostream>
#include <vector>
using namespace std;

// ù° �ٿ� ���� ���� N�� ���� ���ؾ� �ϴ� Ƚ�� M�� �־�����.
//  ��° �ٿ��� N���� ���� �־�����. ���� 1,000���� �۰ų� ���� �ڿ����̴�. 
// ��° �ٺ��� M���� �ٿ��� ���� ���ؾ� �ϴ� ���� i�� j�� �־�����.

//������ �ð��ʰ� : ���� FOR �� 

//ó���� ���� �� ���ѵ� , � ó���� ���־ 1���� ������� �������� ���غ��� 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M ;

	cin>>N>>M;	//ù��° ��

	vector<int> vec (N+1);

	vector<int> vecSum (N+1);

	for (int i = 1; i <= N; i++)
	{
		cin >> vec[i];	//�ι�° �� 
	}

	//�������� �̸� ����� => 
	for (int i = 1; i <= N; i++)
	{
		vecSum[i] = vecSum[i-1] +vec[i];
	}


	for (int i = 0; i < M; i++)
	{
		int first, last, sum = 0;

		cin >> first >> last;

		/*for (int i = first-1; i <= last-1; i++)
		{
			sum += vec[i];
		}*/
		//�׷��� ���⼭ for������ �Ź� �������� ������ ����

		cout << vecSum[last]-vecSum[first-1] <<"\n";
	}

	//���� ���ؾ��ϴ� ���� 

	return 0;
}