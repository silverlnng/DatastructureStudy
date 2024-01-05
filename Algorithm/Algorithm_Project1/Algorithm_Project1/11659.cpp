#include <iostream>
#include <vector>
using namespace std;

// 첫째 줄에 수의 개수 N과 합을 구해야 하는 횟수 M이 주어진다.
//  둘째 줄에는 N개의 수가 주어진다. 수는 1,000보다 작거나 같은 자연수이다. 
// 셋째 줄부터 M개의 줄에는 합을 구해야 하는 구간 i와 j가 주어진다.

//문제점 시간초과 : 이중 FOR 문 

//처음에 값을 다 더한뒤 , 어떤 처리를 해주어서 1번의 계산으로 구간합을 구해보기 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M ;

	cin>>N>>M;	//첫번째 줄

	vector<int> vec (N+1);

	vector<int> vecSum (N+1);

	for (int i = 1; i <= N; i++)
	{
		cin >> vec[i];	//두번째 줄 
	}

	//구간합을 미리 만들기 => 
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
		//그래서 여기서 for문으로 매번 구간합을 구하지 않음

		cout << vecSum[last]-vecSum[first-1] <<"\n";
	}

	//합을 구해야하는 구간 

	return 0;
}