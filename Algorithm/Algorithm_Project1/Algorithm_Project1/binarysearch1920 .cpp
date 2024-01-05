#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

//첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N 은 탐색의 범위 ( 정렬할 배열 ) 
	int N, M;
	
	cin >> N;
	vector<int> answer (N);

	for (int i = 0; i < N; i++)
	{
		cin >> answer[i]; //벡터 answer에 0 ~ N-1 까지 대입 
	}

	sort(answer.begin(), answer.end()); //#include <algorithm> 에 있는 sort 함수 사용해서 정렬하기 **



	// M 은 입력받은 N의 데이터집합에서 탐색 할 값 ( Target )

	cin >> M;

	for (int i = 0; i < M; i++)		//M값을 입력받으면서 하나하나씩 탐색하고 결과를 return 하기
	{
		int target;
		cin >> target;
		bool find = false;
		int Left = 0;
		int Right = answer.size() - 1;

		//지역변수에 선언을 해야하는 것에 주의 ! 매번 for을 할때 마다 값을 초기화 

		while (Left<=Right)
		{
			int mid = (Left + Right) / 2;

			int midValue = answer[mid];

			//mid 와 midvalue 값도 while문안에 선언해야하는 것에 주의 . while 문안에서 계속 돌면서 값을 업데이트 해야함.

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