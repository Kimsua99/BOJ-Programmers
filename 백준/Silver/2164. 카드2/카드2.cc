#include <iostream>
#include <queue>
using namespace std;


int main(void)
{
	int N;
	queue<int> q;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		q.push(i);//일단 1부터 n까지의 카드를 큐에 넣음.
	}

	while(q.size() > 1)//큐 안의 카드 개수가 1이 될 때 까지 반복
	{
		q.pop();//제일 위의 카드를 빼냄.
		q.push(q.front());// 가장 위에 있는 카드를 가장 아래에 넣음.
		q.pop();
	}

	cout << q.front();//마지막에 남게 되는 카드
}