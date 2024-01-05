#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//N���� ���� A[1], A[2], ��, A[N]�� �־��� ���� ��, �� �ȿ� X��� ������ �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

//ù° �ٿ� �ڿ��� N(1 �� N �� 100,000)�� �־�����. ���� �ٿ��� N���� ���� A[1], A[2], ��, A[N]�� �־�����. ���� �ٿ��� M(1 �� M �� 100,000)�� �־�����. ���� �ٿ��� M���� ������ �־����µ�, �� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�. ��� ������ ������ -231 ���� ũ�ų� ���� 231���� �۴�.


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N �� Ž���� ���� ( ������ �迭 ) 
	int N, M;
	
	cin >> N;
	vector<int> answer (N);

	for (int i = 0; i < N; i++)
	{
		cin >> answer[i]; //���� answer�� 0 ~ N-1 ���� ���� 
	}

	sort(answer.begin(), answer.end()); //#include <algorithm> �� �ִ� sort �Լ� ����ؼ� �����ϱ� **



	// M �� �Է¹��� N�� ���������տ��� Ž�� �� �� ( Target )

	cin >> M;

	for (int i = 0; i < M; i++)		//M���� �Է¹����鼭 �ϳ��ϳ��� Ž���ϰ� ����� return �ϱ�
	{
		int target;
		cin >> target;
		bool find = false;
		int Left = 0;
		int Right = answer.size() - 1;

		//���������� ������ �ؾ��ϴ� �Ϳ� ���� ! �Ź� for�� �Ҷ� ���� ���� �ʱ�ȭ 

		while (Left<=Right)
		{
			int mid = (Left + Right) / 2;

			int midValue = answer[mid];

			//mid �� midvalue ���� while���ȿ� �����ؾ��ϴ� �Ϳ� ���� . while ���ȿ��� ��� ���鼭 ���� ������Ʈ �ؾ���.

			if (target == midValue)
			{
				find = true;
				break;
			}
			else if (target> midValue)
			{
				Left = mid + 1;
			}
			else if (target < midValue)
			{
				Right = Right - 1;
			}
			else
			{
				find = false;
				break;
			}
		}

		if (find)
		{
			cout << 1 << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}

	}


}