#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	map<string, string> sitePassword;
	vector<string> searchSite;
	cin >> N >> M;

	string a, b;
	for (int i = 1; i <= N; i++)
	{
		string temp;
		cin>>temp;

		istringstream ss1(temp);
		ss1.str();
		ss1 >> a >> b;
		sitePassword.insert({a,b});
	}

	for (int i = 1; i < M; i++)
	{
		string searchSite;
		cin >> searchSite;
		
		auto foundPassword = sitePassword.find(searchSite);
		cout << foundPassword->second<< "\n";
	}
	



	return 0;
}