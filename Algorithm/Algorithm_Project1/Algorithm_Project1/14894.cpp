#include <iostream>
#include <vector>

using namespace std;
long long cnt = 0;

vector<int> sort(vector<int>& a) {

	vector<int> less, greater;

	if (a.size() <= 1) return a;

	int pivot = a[(a.size() - 1) / 2];
	// 피봇을 배열의 중점으로 설정
	// pivot=5 -> 3
	// float값은 int값으로 cast (버림으로)

	int n = a.size();
	// n = 5 => 4

	for (int i = 0; i < n; i++) {

		cnt += 1;
		//5->9
		if (a[i] < pivot) 
		{
			less.push_back(a[i]);
			// 4,3,1,2 =>4 3 1 2 1 2 
		}
		else if (a[i] > pivot) 
		{
			greater.push_back(a[i]);
			// =>4
		}
	}

	sort(less);

	sort(greater);

	vector<int> ans;

	ans.insert(ans.end(), less.begin(), less.end());

	ans.push_back(pivot);

	ans.insert(ans.end(), greater.begin(), greater.end());

	return ans;
}
//서로 다른 자연수 N개로 이루어진 배열 A가 주어졌을 때, 이를 sort 함수를 이용해서 정렬했을 때, cnt에 들어있는 값을 구하는 프로그램을 작성하시오.

//첫째 줄에 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 배열 A에 들어있는 수가 공백으로 구분해 주어진다. 주어지는 수는 1부터 N까지의 수로 이루어진 순열이다

//입력으로 주어진 수를 sort 함수를 이용해 정렬했을 때, cnt에 들어있는 값을 출력한다.



int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;

	vector<int> A{};
	int TempNum{};

	for (int i = 0; i < N; i++)
	{
		cin >> TempNum;
		A.push_back(TempNum);
	}

	sort(A);

	cout << cnt;

	return 0;
	
}


//// a = {4, 3, 5, 1, 2}
//// less = {4, 3, 1, 2}
//vector<int> sort(vector<int>& a) {
//
//	vector<int> less, greater;
//
//	if (a.size() <= 1) return a;
//
//	int pivot = a[(a.size() - 1) / 2];
//	// 피봇을 배열의 중점으로 설정
//	// pivot=5 -> 3
//	// float값은 int값으로 cast (버림으로)
//
//	int n = a.size();
//	// n = 5 => 4
//
//	for (int i = 0; i < n; i++) {
//
//		cnt += 1;
//		//5->9
//		if (a[i] < pivot) 
//		{
//			less.push_back(a[i]);
//			// 4,3,1,2 =>4 3 1 2 1 2 
//		}
//		else if (a[i] > pivot) 
//		{
//			greater.push_back(a[i]);
//			// =>4
//		}
//	}
//
//	sort(less);
//
//	sort(greater);
//
//	vector<int> ans;
//
//	ans.insert(ans.end(), less.begin(), less.end());
//
//	ans.push_back(pivot);
//
//	ans.insert(ans.end(), greater.begin(), greater.end());
//
//	return ans;
//}

