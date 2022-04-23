#include <iostream>
#include <queue>
using namespace std;

int main(void) 
{

	int N, K;

	queue<int> q;

	cin >> N >> K;

	cout << "<";

	for (int i = 1; i <= N; i++)//1부터 N 까지의 수를 큐에 넣음.  
	{
		q.push(i);
	}

	while (!q.empty()) //큐가 빌 때까지 계속 돌아
	{

		for (int j = 1; j < K ; j++)//K-1번 돌아
		{

			q.push(q.front());//1 ~ K-1번째의 수를 큐의 제일 뒤에 채움.

			q.pop();// 앞에 있는 동일한 수는 팝해서 없앰. -> 맨 앞이 뒤로 가는 형식

		}

		cout << q.front();// 제일 앞에 있는 수를 출력

		q.pop();// 다음으로 이동

		if (!q.empty())//비지 않았으면 , 붙이고 while문 다시 돌아

			cout << ", ";

	}

	cout << ">";

}
