#include <iostream>
#include <vector>

using namespace std;
long long cnt = 0;

vector<int> sort(vector<int>& a) {

	vector<int> less, greater;

	if (a.size() <= 1) return a;

	int pivot = a[(a.size() - 1) / 2];
	// �Ǻ��� �迭�� �������� ����
	// pivot=5 -> 3
	// float���� int������ cast (��������)

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
//���� �ٸ� �ڿ��� N���� �̷���� �迭 A�� �־����� ��, �̸� sort �Լ��� �̿��ؼ� �������� ��, cnt�� ����ִ� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

//ù° �ٿ� N(1 �� N �� 500,000)�� �־�����. ��° �ٿ��� �迭 A�� ����ִ� ���� �������� ������ �־�����. �־����� ���� 1���� N������ ���� �̷���� �����̴�

//�Է����� �־��� ���� sort �Լ��� �̿��� �������� ��, cnt�� ����ִ� ���� ����Ѵ�.



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
//	// �Ǻ��� �迭�� �������� ����
//	// pivot=5 -> 3
//	// float���� int������ cast (��������)
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

