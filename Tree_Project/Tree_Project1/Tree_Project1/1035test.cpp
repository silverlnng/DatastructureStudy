#include <iostream>

using namespace std;

//첫째 줄에 피연산자의 개수(1 ≤ N ≤ 26) 가 주어진다.그리고 둘째 줄에는 후위 표기식이 주어진다. (여기서 피연산자는 A~Z의 영대문자이며, A부터 순서대로 N개의 영대문자만이 사용되며, 길이는 100을 넘지 않는다) 그리고 셋째 줄부터 N + 2번째 줄까지는 각 피연산자에 대응하는 값이 주어진다. 3번째 줄에는 A에 해당하는 값, 4번째 줄에는 B에 해당하는값, 5번째 줄에는 C ...이 주어진다, 그리고 피연산자에 대응 하는 값은 100보다 작거나 같은 자연수이다.
//
//후위 표기식을 앞에서부터 계산했을 때, 식의 결과와 중간 결과가 - 20억보다 크거나 같고, 20억보다 작거나 같은 입력만 주어진다.


int main()
{
	int N{};
	cin >> N;
	// 피연산자의 갯수를 미리 정해서 입력받는다
	int* array = new int[N]; 

	// 후위표기식을 입력받는다 => 후위표기식은 string으로 받는다
	// 입력받은 후위표기식이 연산자인지 피연산자인지 구별을 해야한다

	string expressionTree;
	cin >> expressionTree;


	while (--N) //맨처음에 입력받은 N 만큼 입력을 받고 저장 해두기
	{
		int temp;
		cin >> temp;
		array[N] = temp;
		//이때 입력받은값을 expressionTree 피연산자에 대입해야한다 => 그래서 저장해두기 
	}

	for (int i = 0; i < expressionTree.length(); i++)
	{
		char token = expressionTree[i];
		switch (token)
		{
			//연산자인 경우
		case '+':
			break;
		case '-':
			break;
		case '*':
			break;
		case '/':
			break;

			//피연산자인 경우
		default:
			//피연산자 char 형에 어떻게 int 값을 전달 ??
			//expressionTree[i] = temp[i];
			break;
		}
	}


	return 0;
}