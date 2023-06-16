#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

int board[101][101] = { 0 };
bool vis[101] = { 0 };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int node, link;

queue <int> q;
int answer;
int bfs(int a)
{
	q.push(a);
	vis[a] = true;

	while (!q.empty())
	{
		a = q.front();
		q.pop();
		for (int i = 1; i <= node; i++)
		{
			if (board[a][i] == 1 && vis[i] == false)//현재 정점과 연결되어있고 방문 안한 경우
			{
				q.push(i);
				vis[i] = true;
				answer++;
			}
		}
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> node;
	cin >> link;

	int a, b;

	for (int i = 0; i < link; i++)
	{
		cin >> a >> b;
		board[a][b] = 1;
		board[b][a] = 1;
	}
	cout << bfs(1);
	return 0;
}
